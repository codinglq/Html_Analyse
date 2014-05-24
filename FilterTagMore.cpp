#include "HtmlAnalyse.h"
/*总算在20131130晚上十一点半搞定这里  我靠
 *coding by lq
 *后加一句 我的 这个算法效率有点。。。。有点低啊  后期重构优化一下吧20131201 write by lq
 **/
char * FilterTagMore(int * i_TagArray,char *c_buf,char *c_Tag){
    string s_buf=c_buf;
    char *c_r_buf=(char *)malloc(sizeof(char)*s_buf.length());
    if (!i_TagArray)
    {
        cout<<"传入的串是空的啊"<<endl;
        exit(-1);
    } 
    else
    {
        cout<<"过滤器开始过滤"<<endl;
        int i_TagPos=0;
        int i_Filter=0;
        int i_LastLen=0;
        //定位过滤点
        while(i_TagArray[i_TagPos]!=-2){//匹配队列结束是 -2
           // cout<<strlen(c_Tag)<<endl;
             int j=s_buf.find('>',i_TagArray[i_TagPos]);
            if (s_buf.find('>',(i_TagArray[i_TagPos]-i_LastLen))==(i_TagArray[i_TagPos]-i_LastLen+strlen(c_Tag)))
            {
                i_TagPos++;//这个位置不用过滤  //过滤点后移
            }else{
                //需要过滤查找过滤点
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
/* FileterTagOther顾名思义 过滤自己不想要的标签                     */
/************************************************************************/
int FilterTagOther(string  & s_buf,int &i_StartPos,int &i_EndPos){

	if((i_StartPos<i_EndPos)&&(s_buf.size())){

		s_buf.replace(i_StartPos,(i_EndPos-i_StartPos)+1,"");
		//i_StartPos++;//在这里 i_StartPos自己已经加上了一
		i_EndPos=i_StartPos;
	}else{
		cout<<"i_StartPos>=i_EndPos ERROR!!!!"<<endl;
	}
	return i_StartPos;
}
/************************************************************************/
/* 判断s_Tag是否存在队列中 然后就可以决定是否过滤了              */
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
/* int JudgeFilterPoint(int &i_Start,int &i_End,string s_buf,vector<string>OtherTagQueue);//判断s_buf中从i_Start开始查找定位点是否需要过滤 */
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
				i_StartPos=s_buf.find('<',i_StartPos);//查找定位点
				i_EndPos=s_buf.find('>',i_StartPos);//查找逆定位点
				if (i_StartPos==-1&&i_EndPos==-1)
				{	
					break;//查询不到定位点和逆定位点就滚蛋吧！
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
			cout<<"有点错误哦  在这个JudgeFilterPoint函数中"<<endl;
		}
		return i_StartPos;
}
/************************************************************************/
/*现在过滤的只剩下表格了，这样应该能够好点处理了吧                */
/************************************************************************/