#include "HtmlAnalyse.h"
#include "HtmlNodeOperate.h"
/*
*ҩҩ�п��֣�����html��˵��
����html�ļ����� ץȡ��ǩ�е�����
coding by lq
��Ȼһ���඼û��д������������������
**/
int main(){

	
	int i_StartStudentId=20120000;
	int i_EndStudentId= 20122000;
	clock_t t_start=clock();
	int i_count=1;
	while (i_StartStudentId<=i_EndStudentId)
	{
		ThereNoEnd(i_StartStudentId);
		cout<<"����"<<i_count<<"���ļ�"<<endl;
		i_StartStudentId++;
		i_count++;
	}
	clock_t t_end=clock();
	cout<<"��������"<<i_count<<"���ļ�"<<endl;
	cout<<"�ܻ���ʱ��"<<(t_end-t_start)/1000<<"s"<<endl;
	return 0;
}
