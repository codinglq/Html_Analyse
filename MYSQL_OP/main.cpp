#include "OperateMysql.h"

int main(void){

	char *c_FileName="D:\\HtmlStr\\20112072.html";
	string s_buf;
	char c_sql_temp[150]={};
	vector<TableType>v_Quere;
	string s_StudentId="20112072";
	char c_StudentId[9]={};
	/*20117126~20118000*/
	int i_StartStudentId=20120000;
	int i_EndStudentId= 20122000;
	/************************************************************************/
	/* i_DbId �����ʶ  Ҫ�㶨                                                     */
	/************************************************************************/
	int i_DbId=1;//�Լ������ݿ�id��ʶ  ���ݿ������
	COperateMysql *con=new COperateMysql();
	con->MakeConnect("root","asd8956656","localhost","my_school");
	//con->Query("insert into student_info values(20213056,\'С��\')",1);
	//	con->Query("select * from student_info",1);
	int i_PathSize=strlen("D:\\HtmlStr\\20112410.html");
	char *c_Path=(char*)malloc(sizeof(char)*i_PathSize+20);
	memset(c_Path,NULL,sizeof(char)*i_PathSize);

	int i_count=0;
	while (i_StartStudentId<=i_EndStudentId)
	{
		sprintf(c_Path,"D:\\HtmlStr\\%d.html",i_StartStudentId);
		sprintf(c_StudentId,"%d",i_StartStudentId);
		s_StudentId=c_StudentId;
		if(ReadFileToBuf(s_buf,c_Path)==0){

		}else{
			i_count=0;
			GetTableQueue(v_Quere,s_buf,s_StudentId,i_DbId);//ѧ�ź����ݿ�id��Ҫ��贫���� ����Ҫ���˵���Щû�е�ѧ�ŵ�html�ļ�
			while (i_count<v_Quere.size())
			{
				c_EndSql_insert(v_Quere.at(i_count),c_sql_temp);
		//		cout<<c_sql_temp<<endl;
				con->Query(c_sql_temp,0);
				i_count++;
			}
		}
		cout<<"ѧ��"<<i_StartStudentId<<"�������"<<endl;
		i_StartStudentId++;
		v_Quere.clear();//���Ȼ���´�����
	}
	// 	ReadFileToBuf(s_buf,c_FileName);
	// 	int i_count=0;
	// 	GetTableQueue(v_Quere,s_buf,s_StudentId,i_DbId);//ѧ�ź����ݿ�id��Ҫ��贫���� ����Ҫ���˵���Щû�е�ѧ�ŵ�html�ļ�
	// 
	// 	while (i_count<v_Quere.size())
	// 	{
	// 		c_EndSql_insert(v_Quere.at(i_count),c_sql_temp);
	// 		cout<<c_sql_temp<<endl;
	// 		con->Query(c_sql_temp,1);
	// 		i_count++;
	// 	}
	//c_EndSql_insert(v_Quere.at(1),c_sql_temp);


	//cout<<s_buf<<endl;
	con->CloseConnect();
	return 0;
}
