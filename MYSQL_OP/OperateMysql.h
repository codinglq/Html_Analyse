#ifndef OPERATE_MYAQL_H
#define OPERATE_MYAQL_H

#include <Windows.h>
#include <iostream>
#include "mysql.h"
#include <string>
#include <vector>
#include <WinSock.h>

using namespace std;
typedef struct TableType{

	string Schaool_year;//ѧ��
	string Tream;//ѧ��
	string Student_name;//ѧ������
	string Class_name;//�γ�����
	string College_name;//ѧԺ����
	string Class_type;//�γ�����

	int Db_id;//���ݿ���-----------------����ļ�����ȡ��������-------
	string Student_id;//ѧ��ѧ��
	string Test_score;//���Գɼ�
	string Credit;//ѧ��
};
// typedef struct TableQueue{
// 
// 		TableQueue* p_Head;
// 		int i_QueueSize;
// };
int ReadFileToBuf(string &s_buf,const char *c_FileName);
void GetTableQueue(vector<TableType> &T_Haed,string s_buf,string s_StudentId,int &i_DbId);
void  c_EndSql_insert(TableType v_Head,char *c_sql_temp);//����sql���
#endif
class COperateMysql
{
private:
	MYSQL *con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char tmp[400];
	int i_ReturnValue;
	char *c_Query;
	int t;
public:
	COperateMysql(void);
	~COperateMysql(void);
	int MakeConnect(char * c_Name,char *c_Passwd,char *c_Host,char *c_dbName);//�������ݿ����� 
	int Query(char * c_SqlQuery,int i_flg);//����sql���Խ��в�ѯ
	void CloseConnect();
};
/************************************************************************/
/* #include <Windows.h>
#include <iostream>
#include "mysql.h"
#include <WinSock.h>
using namespace std;                                                           */
/************************************************************************/

/****
MYSQL *con;
MYSQL_RES *res;
MYSQL_ROW row;

char tmp[400];

//����mysql
char dbuser[30]="root";
char dbpasswd[30]="asd8956656";
char dbip[30]="localhost";
char dbname[30]="my_school";
char tablename[30]="score_info";
char *query=NULL;

int x;
int y;
int rt;//����ֵ
unsigned int t;
int count=0;

// 	cout<<"����x,y"<<endl;
// 	cin>>x;
// 	cin>>y;
// 	cout<<"�������"<<endl;
con=mysql_init((MYSQL*)0);
if (con!=NULL&&mysql_real_connect(con,dbip,dbuser,dbpasswd,dbname,3306,NULL,0))
{
if (!mysql_select_db(con,dbname))
{
cout<<"���ݿ�ѡ��ɹ�"<<endl;
con->reconnect=1;
query="set names GBK";
rt=mysql_real_query(con,query,strlen(query));
if (rt)
{
cout<<"������query"<<mysql_error(con)<<endl;
}
else{
cout<<"query �ɹ�"<<endl;
}
}
}
else{
cout<<"�޷������ݿ�"<<endl;
}
sprintf(tmp,"select * from %s",tablename);
rt=mysql_real_query(con,tmp,strlen(tmp));
if (rt)
{
cout<<"query����"<<endl;
}
else{
cout<<"query�ɹ�"<<endl;
}
res=mysql_store_result(con);

while(row=mysql_fetch_row(res)){


for (t=0;t<mysql_num_fields(res);t++)
{	
cout<<row[t]<<" ";
}
cout<<endl;
count++;
}
cout<<"����:"<<count<<endl;
cout<<"mysql_free_result"<<endl;
mysql_free_result(res);
mysql_close(con);
*****/


