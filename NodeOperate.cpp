#include "HtmlNodeOperate.h"
/************************************************************************/
/* 倒数第二个模块，就要胜利了coding by lq 20131203              */
/*我相信  自己把网页过滤的很"干净"吗？ 嗯  好吧 我相信自己*******/
/************************************************************************/
/************************************************************************/
/* 当初没有设计好的结构  哎                                                    */
/************************************************************************/
int JudgeMountNode(vector<NodeType>NodeQueue,string s_CurrNodeTag,int &i_Count,bool &b_Way){

	i_Count=0;
	while (i_Count<NodeQueue.size())
	{	
		if (s_CurrNodeTag==NodeQueue.at(i_Count).TagLeft||s_CurrNodeTag==NodeQueue.at(i_Count).TagRight)
		{	
			if(s_CurrNodeTag==NodeQueue.at(i_Count).TagLeft){
				
				b_Way=false;//左匹配项
				return NodeQueue.at(i_Count).b_flg;
				break;
			}else{
				b_Way=true;//右匹配项
				return false;
			}
		}else{
			i_Count++;
		}
	}
	return false;//return -1 就是出错了 不知道该怎么处理这里 呜呜~~~ 忽略可以吧 。。。
}
void NodeToStack(string s_buf,vector<NodeType> NodeQueue,stack<TagNode> &stack_Node){

	int i_StartPos=0;
	int i_EndPos=0;
	string s_TagTemp;
	int i_Count=0;
	bool b_Way=false;
	if (!s_buf.size())
	{//多一层防护  哈哈  
		cout<<"传入的s_buf是空的 错误发生在NodeToStack"<<endl;
		exit(-1);
	}
	while((i_EndPos!=-1)&&(i_StartPos!=-1)){
	
		i_StartPos=s_buf.find('<',i_StartPos);
		i_EndPos=s_buf.find('>',i_StartPos);
		s_TagTemp=s_buf.substr(i_StartPos,i_EndPos-i_StartPos+1);
		////////////////////需要先扫描一遍便签属性表//////cout<<"取得标签:"<<s_TagTemp<<endl;////////////////////////////////////判断是不是可挂载标签////////////////////////
		if(JudgeMountNode(NodeQueue,s_TagTemp,i_Count,b_Way)){
			/* 如果是可挂载节点 就产生这个标签的节点 然后将这个节点放入栈中*/
			TagNode TagNode_Temp;
			TagNode_Temp.b_NodeClass=true;//这个是表示左右匹配项的 不是表示是否可挂载  其实 差不多吧
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
			TagNode_Temp.s_TagNode_buf="";//不是挂载节点 那么这里就是空的好了 这样的string处理起来虽然是方便 但是有时候不那么自己可控
			TagNode_Temp.b_Way=b_Way;
			stack_Node.push(TagNode_Temp);
			i_StartPos=s_buf.find('<',i_EndPos);
		}
	}
}
/************************************************************************/
/* 做完这个项目，放松一下吧 我累了。。。。                            */
/* 传说中的算符优先的改造版就要来了 哈哈                               */
/*暂时先不考虑换行节点的问题 先将内容抓出来再说吧！哈哈        */
/************************************************************************/
void CaptureText(stack<TagNode> stack_Node,stack<string>&stack_Text){
	
	//stack<string>stack_Text;
	stack<TagNode> stack_Temp;

B:	while(stack_Node.size()){

		stack_Temp.push(stack_Node.top());
		stack_Node.pop();
	A:	if (stack_Temp.top().TagClass==stack_Node.top().TagClass)//如果缓存栈中的第一个结点和匹配栈中的第一个结点是同一种类型的 并且缓存栈中的第一个结点是右匹配项，匹配栈中的第一个节点是左匹配项，那么就规约
		{
			if(stack_Node.top().b_Way==false&&stack_Temp.top().b_Way==true){

				if (stack_Node.top().b_NodeClass)//如果是可挂载节点，那么就将可挂载节点中的串存储出来 别忘记删除缓存栈和匹配栈中的头结点
				{
					stack_Text.push("<"+stack_Node.top().s_TagNode_buf+">");//有挂载项的规约
					stack_Node.pop();
					stack_Temp.pop();//这里还要判断两个栈的栈顶是否需要规约
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
					stack_Node.pop();//无挂载项的规约
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