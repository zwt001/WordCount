#include <stdio.h>
#include <string.h>

int main(int number,char *input[])//number��ʾ����Ĳ����ĸ�����*input[]Ϊָ�����飬ÿһ��ָ��ָ��һ���ַ��� 
{
	FILE *fp;
	int count=0;//count��ʾ���ͳ�Ƶ��ļ��еĵ��ʻ��ַ�����
	if((fp=fopen(input[2],"r")) == NULL)//���ļ�ʧ�� 
	{
		printf("���ļ�ʧ�ܣ�"); 
		return 0; 
	} 
	if(input[1][1] == 'c')//ͳ���ַ� 
	{
	 	char newinput;//newinput���ڴ�Ŷ�ȡ���ļ�����ת���ɵ��ַ�
		while((newinput = fgetc(fp))!= EOF)//��ȡ�ļ��е��ַ���ֱ���ļ���β 
		{
			count++;
		 } 
		 printf("�ַ�����%d\n",count); 
	}
    else if(input[1][1] == 'w')//ͳ�Ƶ��� 
	{
	 	char newinput[10000];//newinput���ڴ�Ŷ�ȡ���ļ�����ת���ɵ��ַ�����
		while(fscanf(fp,"%s",newinput) != EOF)//��ȡ�ļ��е������ַ����ݴ��newinput������ֱ���ļ���β 
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
		 printf("��������%d\n",count); 
	}
	fclose(fp);
    return 0;
	
}
