#include "OperateMysql.h"

int ReadFileToBuf(string &s_buf,const char *c_FileName){
	
	char *c_buf=NULL;
	int i_FileSize=0;
	FILE *fp=NULL;
	fp=fopen(c_FileName,"rt");
	if (!fp)
	{
			cout<<"�ļ���ʧ�ܣ������Ƕ�ȡ��󴮵�sql���ĵط�"<<endl;
			return 0;//�����ʧ�ܾͺ������
			exit(-1);
	}
	fseek(fp,0L,SEEK_END);
	i_FileSize=ftell(fp);
	fseek(fp,0L,SEEK_SET);
	c_buf=(char *)malloc(i_FileSize);
	memset(c_buf,NULL,i_FileSize);
	fread(c_buf,i_FileSize,1,fp);
	strcat(c_buf,"\0");
	fclose(fp);
	s_buf=c_buf;
	cout<<"�ļ���С"<<i_FileSize<<"�ֽ�"<<endl;
	return 1;
	//cout<<c_buf<<endl;
}