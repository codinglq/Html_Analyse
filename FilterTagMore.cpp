#include "HtmlAnalyse.h"
/*������20131130����ʮһ���㶨����  �ҿ�
 *coding by lq
 *���һ�� �ҵ� ����㷨Ч���е㡣�������е�Ͱ�  �����ع��Ż�һ�°�20131201 write by lq
 **/
char * FilterTagMore(int * i_TagArray,char *c_buf,char *c_Tag){
    string s_buf=c_buf;
    char *c_r_buf=(char *)malloc(sizeof(char)*s_buf.length());
    if (!i_TagArray)
    {
        cout<<"����Ĵ��ǿյİ�"<<endl;
        exit(-1);
    } 
    else
    {
        cout<<"��������ʼ����"<<endl;
        int i_TagPos=0;
        int i_Filter=0;
        int i_LastLen=0;
        //��λ���˵�
        while(i_TagArray[i_TagPos]!=-2){//ƥ����н����� -2
           // cout<<strlen(c_Tag)<<endl;
             int j=s_buf.find('>',i_TagArray[i_TagPos]);
            if (s_buf.find('>',(i_TagArray[i_TagPos]-i_LastLen))==(i_TagArray[i_TagPos]-i_LastLen+strlen(c_Tag)))
            {
                i_TagPos++;//���λ�ò��ù���  //���˵����
            }else{
                //��Ҫ���˲��ҹ��˵�
                i_Filter=s_buf.find('>',i_TagArray[i_TagPos]-i_LastLen);
                s_buf=s_buf.replace(i_TagArray[i_TagPos]-i_LastLen+strlen(c_Tag),i_Filter-(i_TagArray[i_TagPos]-i_LastLen)-strlen(c_Tag),"");
               /* i_LastLen=i_LastLen+i_Filter-i_TagArray[i_TagPos]-strlen(c_Tag);*/
               i_LastLen=i_LastLen+i_Filter-(i_TagArray[i_TagPos]-i_LastLen)-strlen(c_Tag);
                i_TagPos++;
            }
            /*  s_buf=s_buf.replace(i_TagArray[i_TagPos]+4);*/
        }
        // i_TagPos++;
    }
    strcpy(c_r_buf,s_buf.c_str());
    return c_r_buf;
} 

/************************************************************************/
/* FileterTagOther����˼�� �����Լ�����Ҫ�ı�ǩ                     */
/************************************************************************/
int FilterTagOther(string  & s_buf,int &i_StartPos,int &i_EndPos){

	if((i_StartPos<i_EndPos)&&(s_buf.size())){

		s_buf.replace(i_StartPos,(i_EndPos-i_StartPos)+1,"");
		//i_StartPos++;//������ i_StartPos�Լ��Ѿ�������һ
		i_EndPos=i_StartPos;
	}else{
		cout<<"i_StartPos>=i_EndPos ERROR!!!!"<<endl;
	}
	return i_StartPos;
}
/************************************************************************/
/* �ж�s_Tag�Ƿ���ڶ����� Ȼ��Ϳ��Ծ����Ƿ������              */
/************************************************************************/
int b_FindQueue(vector<string> OtherTagQueue,string s_Tag){
		
	int i_QueueSize=0;
	while (i_QueueSize<OtherTagQueue.size())
	{
			if (s_Tag==OtherTagQueue.at(i_QueueSize))
			{	
				return 1;
				break;
			}else{
				i_QueueSize++;
			}
	}
	return 0;
}
/***************************************************************************************************************************************************************/
/* int JudgeFilterPoint(int &i_Start,int &i_End,string s_buf,vector<string>OtherTagQueue);//�ж�s_buf�д�i_Start��ʼ���Ҷ�λ���Ƿ���Ҫ���� */
/***************************************************************************************************************************************************************/
int JudgeFilterPoint(int &i_StartPos,int &i_EndPos,string &s_buf,vector<string>OtherTagQueue){
		
		if (s_buf.size()&&(i_StartPos>=0))
		{
				//int i_bufSize=0;
				while(i_StartPos!=-1&&i_EndPos!=-1){
				int i_QueueSize=0;
				if (s_buf.substr(i_StartPos,1)!="<")
				{
						i_EndPos=s_buf.find('<',i_StartPos);
						s_buf.replace(i_StartPos,i_EndPos-i_StartPos,"");
				}else{
				i_StartPos=s_buf.find('<',i_StartPos);//���Ҷ�λ��
				i_EndPos=s_buf.find('>',i_StartPos);//�����涨λ��
				if (i_StartPos==-1&&i_EndPos==-1)
				{	
					break;//��ѯ������λ����涨λ��͹����ɣ�
				}
				if (!b_FindQueue(OtherTagQueue,s_buf.substr(i_StartPos,i_EndPos-i_StartPos+1)))
				{	
					FilterTagOther(s_buf,i_StartPos,i_EndPos);
					//i_bufSize++;
				}else{
				//i_bufSize++;
					//i_StartPos++;
					i_StartPos=i_StartPos=s_buf.find('<',i_StartPos+1);
						}
					}
				}
		}
		else{
			cout<<"�е����Ŷ  �����JudgeFilterPoint������"<<endl;
		}
		return i_StartPos;
}
/************************************************************************/
/*���ڹ��˵�ֻʣ�±���ˣ�����Ӧ���ܹ��õ㴦���˰�                */
/************************************************************************/