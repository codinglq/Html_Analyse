#include "OperateMysql.h"
/************************************************************************/
/* ����˼��������ǲ������ݿ��Ŷ                                         */
/************************************************************************/

COperateMysql::COperateMysql(void)
{
		res=NULL;
}
COperateMysql::~COperateMysql(void)
{
}
int COperateMysql::MakeConnect(char * c_Name,char *c_Passwd,char *c_Host,char *c_dbName){

	con=mysql_init((MYSQL*)0);
	if (con!=NULL&&mysql_real_connect(con,c_Host,c_Name,c_Passwd,c_dbName,3306,NULL,0))
	{	
		if (!mysql_select_db(con,c_dbName))
		{
			cout<<"���ݿ�ѡ��ɹ�"<<endl;
			con->reconnect=1;
			c_Query="set names GBK";
			i_ReturnValue=mysql_real_query(con,c_Query,strlen(c_Query));
			if (i_ReturnValue)
			{
				cout<<"��������ʧ��"<<mysql_error(con)<<endl;
			}
			else{
				cout<<"�������óɹ�"<<endl;
			}
		}
	}
	else{
		cout<<"�޷������ݿ�"<<endl;
	}
	return 0;
}

void COperateMysql::CloseConnect(){

	mysql_free_result(res);
	mysql_close(con);
	cout<<"���ݿ��Ѿ��ر�"<<endl;
}

int COperateMysql::Query(char * c_SqlQuery,int i_flg){

	i_ReturnValue=mysql_real_query(con,c_SqlQuery,strlen(c_SqlQuery));
	if (i_ReturnValue)
	{
			cout<<"sql���ִ��ʧ��"<<mysql_error(con)<<endl;
			return 0;
	}
	else{
		//cout<<"sql���ִ�гɹ���"<<c_SqlQuery<<endl;
	}
	if (i_flg)
	{
		res=mysql_store_result(con);
		if (res==0)
		{
				return 0;
		}
		row=mysql_fetch_row(res);
		while(row=mysql_fetch_row(res)){
			for (t=0;t<mysql_num_fields(res);t++)
			{	
				cout<<row[t]<<" ";
			}
			cout<<endl;
		}
	}
}