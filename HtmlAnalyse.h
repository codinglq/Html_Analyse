#ifndef _HTML_ANALYSE_
#define _HTML_ANALYSE_

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

void InitTagArry(int *i_TagArry);//初始化标签队列

int b_FindQueue(vector<string> OtherTagQueue,string s_Tag);//判断当前查找到的标签是否过滤
int JudgeFilterPoint(int &i_StartPos,int &i_EndPos,string &s_buf,vector<string>OtherTagQueue );//判断s_buf中从i_Start开始查找定位点是否需要过滤
int FilterPoint(int &i_Start,int &i_end,string s_buf);//过滤start和end之间的东西，全部不要,然后更改start和end位置
int FilterTagOther(string  & s_buf,int &i_StartPos,int &i_EndPos);//过滤不需要的标签


char* FilterTagMore(int * i_TagArray,char *c_buf,char *c_Tag);//过滤标签上的属性  获得正规标签第三个标签式需要过滤的标签的做匹配项的左对齐串
int * GetTagPos(string &s_Html,char *c_Tag);//取得文件中标签的位置，只扫描一次
void DisPlayTagArry(int * i_TagArry);
void FilterEnd(string & s_buf,string s_Start,string s_end);//过滤掉start和end之间的所有串

char * c_buf_GetFile(const char *FileName);//将文件中的串放到一个char的数组中 并且返回这个串的手地址
void c_buf_IntoFile(const char *FileName,char * c_buf);

int ThereNoEnd(int i_StudentId);//开始学生的学号 ，结束学生的学号

#endif


