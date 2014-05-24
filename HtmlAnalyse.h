#ifndef _HTML_ANALYSE_
#define _HTML_ANALYSE_

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

void InitTagArry(int *i_TagArry);//��ʼ����ǩ����

int b_FindQueue(vector<string> OtherTagQueue,string s_Tag);//�жϵ�ǰ���ҵ��ı�ǩ�Ƿ����
int JudgeFilterPoint(int &i_StartPos,int &i_EndPos,string &s_buf,vector<string>OtherTagQueue );//�ж�s_buf�д�i_Start��ʼ���Ҷ�λ���Ƿ���Ҫ����
int FilterPoint(int &i_Start,int &i_end,string s_buf);//����start��end֮��Ķ�����ȫ����Ҫ,Ȼ�����start��endλ��
int FilterTagOther(string  & s_buf,int &i_StartPos,int &i_EndPos);//���˲���Ҫ�ı�ǩ


char* FilterTagMore(int * i_TagArray,char *c_buf,char *c_Tag);//���˱�ǩ�ϵ�����  ��������ǩ��������ǩʽ��Ҫ���˵ı�ǩ����ƥ���������봮
int * GetTagPos(string &s_Html,char *c_Tag);//ȡ���ļ��б�ǩ��λ�ã�ֻɨ��һ��
void DisPlayTagArry(int * i_TagArry);
void FilterEnd(string & s_buf,string s_Start,string s_end);//���˵�start��end֮������д�

char * c_buf_GetFile(const char *FileName);//���ļ��еĴ��ŵ�һ��char�������� ���ҷ�����������ֵ�ַ
void c_buf_IntoFile(const char *FileName,char * c_buf);

int ThereNoEnd(int i_StudentId);//��ʼѧ����ѧ�� ������ѧ����ѧ��

#endif


