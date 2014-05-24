#include "HtmlAnalyse.h"
/////////////////////////////////////
/*这个是用来在文件中定位标签位置的真实他娘的费事coding by lq20131130*/
/////////////////////////////////////
int* GetTagPos(string &s_Html,char *c_Tag){

    if(c_Tag){
        int i_Start=0;
        int i_PosTag=-1;
        int i_ArryNum=0;
        int *i_TagArry=NULL;
        i_TagArry=(int *)malloc(sizeof(int)*(s_Html.length()));
        int i;
        // cout<<"s_html.length()"<<s_Html.length()<<endl;
        for (i=0;i<s_Html.length();i++)
        {
            i_TagArry[i]=-2;
        }

        while(i_Start<s_Html.length()){


            //    i_PosTable=s_str.find("<table",i_PosTable);
            if(i_PosTag!=-1){

                i_TagArry[i_ArryNum]=i_PosTag;   
                i_ArryNum++; 
                i_Start=i_PosTag+sizeof(c_Tag);
                i_PosTag=s_Html.find(c_Tag,i_Start);
            }else{

                i_PosTag=s_Html.find(c_Tag,i_Start);
                i_Start++;
            }
        }
        return i_TagArry;
    }
    cout<<"gettagpos函数需要传入标签"<<endl;
    return NULL;
}
//  cout<<"s_str"<<s_str<<endl;
// cout<<"c_buf"<<c_buf<<endl;

/*while(i_Start<i_FileSize){


//    i_PosTable=s_str.find("<table",i_PosTable);
if(i_PosTable!=-1){

i_ArryPos[i_ArryNum]=i_PosTable;   
i_ArryNum++; 
i_Start=i_PosTable+sizeof("<table");
i_PosTable=s_str.find("<table",i_Start);
}else{

i_PosTable=s_str.find("<table",i_Start);
i_Start++;
}
}*/