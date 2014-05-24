#ifndef HTML_NODE_OPERATE
#define HTML_NODE_OPERATE
/************************************************************************/
/* ��������node�ڵ��һЩ����                                              */
/************************************************************************/
#include "HtmlAnalyse.h"
/************************************************************************/
/* �ɹ��ر�ǩ��<td>**************************************************/
/*���ɹ��ر�ǩ<table></table><tr></tr></td>******************/
/*���б�ǩ<tr></tr>**************************************************/
/************************************************************************/
typedef struct NodeType{
		
	string TagClass;//�ڵ�����
	string TagRight;//�ڵ����ƥ����exple <table>
	string TagLeft;//�ڵ����ƥ���� exple </table>
	bool b_flg;//�Ƿ��ǿɹ��ؽڵ�
	//���нڵ㣿����������������������
};//����һ���ڵ������������Ҷ���֪���ý�ʲô�ˡ�����������
typedef struct TagNode{

    string TagClass;//��ʶhtml�ڵ�����(<table></table>)(<tr></tr>)<td></td>
    bool b_NodeClass;//�����ʾ �Ƿ��ǿɹ��ؽڵ�
	bool b_Way;//����Ǳ�ʶ�ڵ�ʱ��ƥ�������ƥ����  false����ƥ���� true����ƥ����
    string s_TagNode_buf;//����ǽڵ�����������
	//�ò���������ʶ ����ʾ ���нڵ��أ�������������������
};

int JudgeMountNode(vector<NodeType>NodeQueue,string s_CurrNodeTag,int &i_Count,bool &b_Way);//�жϵ�ǰ�ı�ǩ�ǲ��ǿɹ��ر�ǩ
void NodeToStack(string s_buf,vector<NodeType> NodeQueue,stack<TagNode> &stack_Node);//�������ֵӦ���Ǵ���õ��Ǹ�ջ���������߲��÷���
void CaptureText(stack<TagNode> stack_Node,stack<string> &stack_Text);//ץȡ�ı�����

#endif

