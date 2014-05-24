#include "HtmlAnalyse.h"

void FilterEnd(string & s_buf,string s_Start,string s_end){

	int i_StartPos=0;
	int i_EndPos=0;
	while(i_EndPos!=-1&&i_StartPos!=-1){

		i_StartPos=s_buf.find(s_Start,i_StartPos);
		i_EndPos=s_buf.find(s_end,i_StartPos);
		if (i_StartPos==-1)
		{
				break;
		}
		s_buf=s_buf.replace(i_StartPos,i_EndPos+s_end.size()-i_StartPos,"");
		i_StartPos=i_EndPos; 
	}
}