#include "HtmlNodeOperate.h"
/************************************************************************/
/* �����ڶ���ģ�飬��Ҫʤ����coding by lq 20131203              */
/*������  �Լ�����ҳ���˵ĺ�"�ɾ�"�� ��  �ð� �������Լ�*******/
/************************************************************************/
/************************************************************************/
/* ����û����ƺõĽṹ  ��                                                    */
/************************************************************************/
int JudgeMountNode(vector<NodeType>NodeQueue,string s_CurrNodeTag,int &i_Count,bool &b_Way){

	i_Count=0;
	while (i_Count<NodeQueue.size())
	{	
		if (s_CurrNodeTag==NodeQueue.at(i_Count).TagLeft||s_CurrNodeTag==NodeQueue.at(i_Count).TagRight)
		{	
			if(s_CurrNodeTag==NodeQueue.at(i_Count).TagLeft){
				
				b_Way=false;//��ƥ����
				return NodeQueue.at(i_Count).b_flg;
				break;
			}else{
				b_Way=true;//��ƥ����
				return false;
			}
		}else{
			i_Count++;
		}
	}
	return false;//return -1 ���ǳ����� ��֪������ô�������� ����~~~ ���Կ��԰� ������
}
void NodeToStack(string s_buf,vector<NodeType> NodeQueue,stack<TagNode> &stack_Node){

	int i_StartPos=0;
	int i_EndPos=0;
	string s_TagTemp;
	int i_Count=0;
	bool b_Way=false;
	if (!s_buf.size())
	{//��һ�����  ����  
		cout<<"�����s_buf�ǿյ� ��������NodeToStack"<<endl;
		exit(-1);
	}
	while((i_EndPos!=-1)&&(i_StartPos!=-1)){
	
		i_StartPos=s_buf.find('<',i_StartPos);
		i_EndPos=s_buf.find('>',i_StartPos);
		s_TagTemp=s_buf.substr(i_StartPos,i_EndPos-i_StartPos+1);
		////////////////////��Ҫ��ɨ��һ���ǩ���Ա�//////cout<<"ȡ�ñ�ǩ:"<<s_TagTemp<<endl;////////////////////////////////////�ж��ǲ��ǿɹ��ر�ǩ////////////////////////
		if(JudgeMountNode(NodeQueue,s_TagTemp,i_Count,b_Way)){
			/* ����ǿɹ��ؽڵ� �Ͳ��������ǩ�Ľڵ� Ȼ������ڵ����ջ��*/
			TagNode TagNode_Temp;
			TagNode_Temp.b_NodeClass=true;//����Ǳ�ʾ����ƥ����� ���Ǳ�ʾ�Ƿ�ɹ���  ��ʵ ����
			TagNode_Temp.TagClass=NodeQueue.at(i_Count).TagClass;
			i_StartPos=s_buf.find('<',i_EndPos);
			TagNode_Temp.s_TagNode_buf=s_buf.substr(i_EndPos+1,i_StartPos-i_EndPos-1);
			TagNode_Temp.b_Way=b_Way;
			stack_Node.push(TagNode_Temp);
			i_StartPos=s_buf.find('<',i_EndPos);
		}else{
			TagNode TagNode_Temp;
			TagNode_Temp.b_NodeClass=false;
			TagNode_Temp.TagClass=NodeQueue.at(i_Count).TagClass;
			TagNode_Temp.s_TagNode_buf="";//���ǹ��ؽڵ� ��ô������ǿյĺ��� ������string����������Ȼ�Ƿ��� ������ʱ����ô�Լ��ɿ�
			TagNode_Temp.b_Way=b_Way;
			stack_Node.push(TagNode_Temp);
			i_StartPos=s_buf.find('<',i_EndPos);
		}
	}
}
/************************************************************************/
/* ���������Ŀ������һ�°� �����ˡ�������                            */
/* ��˵�е�������ȵĸ�����Ҫ���� ����                               */
/*��ʱ�Ȳ����ǻ��нڵ������ �Ƚ�����ץ������˵�ɣ�����        */
/************************************************************************/
void CaptureText(stack<TagNode> stack_Node,stack<string>&stack_Text){
	
	//stack<string>stack_Text;
	stack<TagNode> stack_Temp;

B:	while(stack_Node.size()){

		stack_Temp.push(stack_Node.top());
		stack_Node.pop();
	A:	if (stack_Temp.top().TagClass==stack_Node.top().TagClass)//�������ջ�еĵ�һ������ƥ��ջ�еĵ�һ�������ͬһ�����͵� ���һ���ջ�еĵ�һ���������ƥ���ƥ��ջ�еĵ�һ���ڵ�����ƥ�����ô�͹�Լ
		{
			if(stack_Node.top().b_Way==false&&stack_Temp.top().b_Way==true){

				if (stack_Node.top().b_NodeClass)//����ǿɹ��ؽڵ㣬��ô�ͽ��ɹ��ؽڵ��еĴ��洢���� ������ɾ������ջ��ƥ��ջ�е�ͷ���
				{
					stack_Text.push("<"+stack_Node.top().s_TagNode_buf+">");//�й�����Ĺ�Լ
					stack_Node.pop();
					stack_Temp.pop();//���ﻹҪ�ж�����ջ��ջ���Ƿ���Ҫ��Լ
					if (stack_Node.size()&&stack_Temp.size())
					{
							goto A;
					}
					if (!stack_Temp.size()&&!stack_Node.size())
					{
							break;
					}
					if (!stack_Temp.size()&&stack_Node.size())
					{	
						goto B;
					}
					
				}
				else{
					stack_Node.pop();//�޹�����Ĺ�Լ
					stack_Temp.pop();
					if (stack_Node.size()&&stack_Temp.size())
					{
						goto A;
					}
					if (!stack_Temp.size()&&stack_Node.size())
					{	
						goto B;
					}
					if(!stack_Node.size()&&!stack_Temp.size()){
						
						break;
					}
				}
			}
		}
	}
// 	while (stack_Text.size())
// 	{
// 			cout<<stack_Text.top()<<endl;
// 			stack_Text.pop();
// 	}
	//stack_Text.top();
}