#include "HtmlAnalyse.h"
/*
 *��������������õ�  ��ƨ�Ķ��� �����Σ�
 coding by lq20131130
 */
void DisPlayTagArry(int * i_TagArry){

        int i_pos=0;
        while(i_TagArry[i_pos]!=-2){
        
            cout<<i_pos+1<<"��"<<i_TagArry[i_pos]<<endl;
            i_pos++;
        }
}
//         i_ArryNum=0;
//         while (1)
//         {
//             if(i_ArryPos[i_ArryNum]!=-2){
//             
//                 cout<<i_ArryNum[i_ArryPos]<<" "<<endl;
//                 i_ArryNum++;
//                 }
//                 if(i_ArryPos[i_ArryNum]==0){
//                     
//                     break;
//                 }
//         }