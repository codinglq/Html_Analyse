#include "HtmlAnalyse.h"
#include "HtmlNodeOperate.h"
/*
*药药切克闹，我是html你说草
解析html文件程序 抓取标签中的内容
coding by lq
竟然一个类都没有写。。。。。。。。。
**/
int main(){

	
	int i_StartStudentId=20120000;
	int i_EndStudentId= 20122000;
	clock_t t_start=clock();
	int i_count=1;
	while (i_StartStudentId<=i_EndStudentId)
	{
		ThereNoEnd(i_StartStudentId);
		cout<<"处理"<<i_count<<"个文件"<<endl;
		i_StartStudentId++;
		i_count++;
	}
	clock_t t_end=clock();
	cout<<"共处理了"<<i_count<<"个文件"<<endl;
	cout<<"总话费时间"<<(t_end-t_start)/1000<<"s"<<endl;
	return 0;
}
