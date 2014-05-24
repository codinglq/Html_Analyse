#include "HtmlAnalyse.h"

void InitTagArry(int *i_TagArry){

    int i_TagPos=0;//初始化标签数组队列 将里面全部写上-2
    while (i_TagArry[i_TagPos]!=-2)
    {
        i_TagArry[i_TagPos]=-2;
    }
}