#include "OperateMysql.h"

/*
<2011--2012>ѧ��0
<1>  ѧ��1
<������>����2
<��ȫ����>�γ�����3
<��ѧԺ>����ѧԺ4
<����>�γ�����5
<94>�γ̳ɼ�6
<0.5>ѧ��7
<>����
*/
void GetTableQueue(vector<TableType> &T_Haed,string s_buf,string s_StudentId,int &i_DbId){

	int i_StartPos=0;
	int i_EndPos=0;
	int i_count=0;
	TableType T_Temp;

	while(1){
		T_Temp.Db_id=i_DbId;
		T_Temp.Student_id=s_StudentId;
		i_StartPos=s_buf.find('<',i_StartPos);
		i_EndPos=s_buf.find('>',i_StartPos);
		i_count=0;//�������ṹ�������ĸ���д����
		if (i_EndPos==i_StartPos+1)
		{	
			i_StartPos=i_EndPos;
			continue ;
		}
		while(i_count<=7){

			i_StartPos=s_buf.find('<',i_StartPos);
			i_EndPos=s_buf.find('>',i_StartPos);
			if (i_StartPos==-1||i_EndPos==-1)
			{
				break;
			}
			switch (i_count)
			{
			case 0:
				T_Temp.Schaool_year=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 1:
				T_Temp.Tream=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 2:
				T_Temp.Student_name=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 3:
				T_Temp.Class_name=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 4:
				T_Temp.College_name=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 5:
				T_Temp.Class_type=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 6:
				T_Temp.Test_score=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			case 7:
				T_Temp.Credit=s_buf.substr(i_StartPos+1,i_EndPos-i_StartPos-1);
				break;
			}
			i_count++;
			i_StartPos=i_EndPos;
		}
		i_DbId++;
		if (i_StartPos==-1||i_EndPos==-1)
		{
			break;
		}
		T_Haed.push_back(T_Temp);//����������
	}
}