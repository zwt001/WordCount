#include <stdio.h>
#include <string.h>

int main(int number,char *input[])//number表示输入的参数的个数，*input[]为指针数组，每一个指针指向一个字符串 
{
	FILE *fp;
	int count=0;//count表示最后统计的文件中的单词或字符个数
	if((fp=fopen(input[2],"r")) == NULL)//打开文件失败 
	{
		printf("打开文件失败！"); 
		return 0; 
	} 
	if(input[1][1] == 'c')//统计字符 
	{
	 	char newinput;//newinput用于存放读取的文件内容转换成的字符
		while((newinput = fgetc(fp))!= EOF)//读取文件中的字符中直到文件结尾 
		{
			count++;
		} 
		printf("字符数：%d\n",count); 
	}
    else if(input[1][1] == 'w')//统计单词 
	{
	 	char newinput[10000];//newinput用于存放读取的文件内容转换成的字符数组
		while(fscanf(fp,"%s",newinput) != EOF)//读取文件中的所有字符内容存进newinput数组中直到文件结尾 
		{
			count++;
			for(int i=1;i<strlen(newinput)-1;i++)
			{
				if(newinput[i] == ',' && newinput[i-1] != ',' && newinput[i+1] != ',')
				{
					count++;
				}
			}
		 } 
		 printf("单词数：%d\n",count); 
	}
    fclose(fp);//关闭当前文件流
    return 0;	
}
