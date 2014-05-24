#include "HtmlAnalyse.h"
#include "HtmlNodeOperate.h"

int ThereNoEnd(int i_StudentId){//将学号范围内的学生成绩分析完

	string s_str;
	char * c_buf=NULL;
	int *i_TagArry;
	clock_t t_start=clock();

	/************************************************************************/
	/* 算法需要优化的地方太多了                                                   */
	/************************************************************************/
	int i_PathSize=strlen("D:\\win32\\20112410.html");
	
	char *c_Path=(char*)malloc(sizeof(char)*i_PathSize+20);
	memset(c_Path,NULL,i_PathSize);
	sprintf(c_Path,"D:\\win32\\%d.html",i_StudentId);
	c_buf=c_buf_GetFile(c_Path);
	cout<<c_Path<<endl;
	if (!c_buf)
	{
			return 0;
	}
	s_str=c_buf;//将这个文件里面的串全部都放到这个string里面
	
	// c_buf=c_buf_GetFile("D:\\Hack_Student_Gread\\20111112.html");
	
	

	//定位过滤tr标签

	i_TagArry= GetTagPos(s_str,"<tr");
	//  DisPlayTagArry(i_TagArry);//将标签的位置输出到屏幕上
	char *c_res=  FilterTagMore(i_TagArry,c_buf,"<tr");
	// cout<<c_res<<endl;
	//定位过滤td标签

	InitTagArry(i_TagArry);
	string s__=c_res;
	i_TagArry=GetTagPos(s__,"<td");
	// DisPlayTagArry(i_TagArry);
	char *c_td=FilterTagMore(i_TagArry,c_res,"<td");
	// cout<<c_td<<endl;
	//定位过滤table标签
	InitTagArry(i_TagArry);
	string s__Table=c_td;
	i_TagArry=GetTagPos(s__Table,"<table");
	//  DisPlayTagArry(i_TagArry);
	char *c_Table=FilterTagMore(i_TagArry,c_td,"<table");

	//  cout<<c_Table<<endl;
	string s_More=c_Table;
	string s_Tagtr="<tr>";
	string s_TagtrEnd="</tr>";
	string s_Tagtd="<td>";
	string s_TagEndtd="</td>";
	string s_Tagtable="<table>";
	string s_TagEndtable="</table>";
	vector<string> OtherTagQueue;
	OtherTagQueue.push_back(s_Tagtr);
	OtherTagQueue.push_back(s_TagtrEnd);
	OtherTagQueue.push_back(s_Tagtd);
	OtherTagQueue.push_back(s_TagEndtd);
	OtherTagQueue.push_back(s_Tagtable);
	OtherTagQueue.push_back(s_TagEndtable);


	int i_StartPos=0,i_EndPos=0;
	JudgeFilterPoint(i_StartPos,i_EndPos,s_More,OtherTagQueue);
	//cout<<s_More.c_str()<<endl;
// 	char *c_temp=(char*)malloc(sizeof(char)*s_More.size()+100);
// 	memset(c_temp,NULL,sizeof(char)*s_More.size());
// 	strcpy(c_temp,s_More.c_str());
//	c_buf_IntoFile("D:\\HtmlStr\\Destr.html",c_temp);

	stack<TagNode> stack_Node;
	vector<NodeType> NodeQueue;
	//创建标签类型表
	NodeType N_tr;
	N_tr.TagClass="tr",N_tr.TagLeft="<tr>",N_tr.TagRight="</tr>",N_tr.b_flg=false;
	NodeType N_table;
	N_table.b_flg=false,N_table.TagClass="table",N_table.TagLeft="<table>",N_table.TagRight="</table>",N_table.b_flg=false;
	NodeType N_td;
	N_td.TagClass="td",N_td.TagLeft="<td>",N_td.TagRight="</td>",N_td.b_flg=true;

	/*将这些标签类型放进表中*/
	NodeQueue.push_back(N_tr);
	NodeQueue.push_back(N_table);
	NodeQueue.push_back(N_td);

	NodeToStack(s_More,NodeQueue,stack_Node);
	stack<string> stack_Text;
	CaptureText(stack_Node,stack_Text);
	clock_t t_end=clock();
	cout<<"时间花费"<<(t_end-t_start)/1000<<"s"<<endl;
	string s_Text;
	while (stack_Text.size())
	{
		s_Text=s_Text+stack_Text.top()/*+"\r\n"*/;
		stack_Text.pop();
	}
	FilterEnd(s_Text,"<学号","<学分>");
	char *c_Text=(char *)malloc(sizeof(char)*s_Text.size()+100);
	memset(c_Text,NULL,sizeof(char)*s_Text.size());
	strcpy(c_Text,s_Text.c_str());
	memset(c_Path,NULL,i_PathSize);
	sprintf(c_Path,"D:\\HtmlStr\\%d.html",i_StudentId);
	c_buf_IntoFile(c_Path,c_Text);
	free(c_buf);
	free(c_res);
	free(c_td);
	free(c_Table);
	//free(c_temp);
	free(c_Text);
	free(c_Path);
	free(i_TagArry);//这里可能有问题20131212
	return 0;
}