#include "HtmlAnalyse.h"

char* c_buf_GetFile(const char *FileName){//执行失败就返回空指针

    FILE * fp=NULL;
    int i_FileSize;
    char *c_buf=NULL;
    fp=fopen(FileName,"rb");
    if (!fp)
    {
        cout<<"文件打开失败"<<endl;
		return NULL;
        exit(-1);
    }else{
        fseek(fp,0L,SEEK_END);
        i_FileSize=ftell(fp);
        fseek(fp,0L,SEEK_SET);
        c_buf=(char *)malloc(sizeof(char)*i_FileSize);
        fread(c_buf,i_FileSize*sizeof(char),1,fp);
        fclose(fp);
        return c_buf;
    }
    return NULL;
}
/************************************************************************/
/* 将穿写入文件中ok？                                                           */
/************************************************************************/
void c_buf_IntoFile(const char *FileName,char * c_buf){
		
		if (!c_buf)
		{
				cout<<"写入的串是空的！"<<endl;
				exit(-1);
		}
		FILE * fp=NULL;
		fp=fopen(FileName,"wb");
		if (!fp)
		{
				cout<<"写入文件失败！"<<endl;
			
				exit(-1);
		}
		fwrite(c_buf,strlen(c_buf),1,fp);
		fclose(fp);
		cout<<"文件写入成功！"<<endl;
}
// FILE * fp=NULL;
// int i_FileSize;
// int i_ArryNum=0;
// int *i_ArryPos=NULL;
// // int i_LastPos;
// int i_Start=0;
// char *c_buf=NULL;
// int i_PosTable=-1;
// string s_str;
// fp=fopen("D:\\test.txt","rb");
// if (!fp)
// {
//     cout<<"文件打开失败"<<endl;
//     exit(-1);
// }
// fseek(fp,0L,SEEK_END);
// i_FileSize=ftell(fp);
// fseek(fp,0L,SEEK_SET);
// 
// c_buf=(char *)malloc(sizeof(char)*i_FileSize);
// 
// fread(c_buf,i_FileSize*sizeof(char),1,fp);
// fclose(fp);