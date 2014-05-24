#ifndef HTML_NODE_OPERATE
#define HTML_NODE_OPERATE
/************************************************************************/
/* 包含操作node节点的一些函数                                              */
/************************************************************************/
#include "HtmlAnalyse.h"
/************************************************************************/
/* 可挂载标签：<td>**************************************************/
/*不可挂载标签<table></table><tr></tr></td>******************/
/*换行标签<tr></tr>**************************************************/
/************************************************************************/
typedef struct NodeType{
		
	string TagClass;//节点类型
	string TagRight;//节点的左匹配项exple <table>
	string TagLeft;//节点的右匹配项 exple </table>
	bool b_flg;//是否是可挂载节点
	//换行节点？？？？？？？？？？？？
};//生成一个节点类型向量表，我都不知道该叫什么了。。。。。。
typedef struct TagNode{

    string TagClass;//标识html节点类型(<table></table>)(<tr></tr>)<td></td>
    bool b_NodeClass;//这个表示 是否是可挂载节点
	bool b_Way;//这个是标识节点时左匹配项还是右匹配项  false是左匹配项 true是右匹配项
    string s_TagNode_buf;//这个是节点挂载项的内容
	//用不用整个标识 来表示 换行节点呢？？？？？？？？？？
};

int JudgeMountNode(vector<NodeType>NodeQueue,string s_CurrNodeTag,int &i_Count,bool &b_Way);//判断当前的标签是不是可挂载标签
void NodeToStack(string s_buf,vector<NodeType> NodeQueue,stack<TagNode> &stack_Node);//这个返回值应该是处理好的那个栈。。。或者不用返回
void CaptureText(stack<TagNode> stack_Node,stack<string> &stack_Text);//抓取文本内容

#endif

