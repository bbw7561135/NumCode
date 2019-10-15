#include <iostream>
using namespace std;
//题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？ 
//程序分析：从百位开始分别填 百位是1 那么十位和个位就不能有1 并且十位填完后 个位也不能和十位相同
//利用循环+判断条件可以完成

int main()
{
    int i,j,k;
    for(i=1;i<5;i++)//百位/*以下为三重循环*/ 
    for(j=1;j<5;j++)//十位
    for(k=1;k<5;k++)//个位
    {
        if(i!=k&&i!=j&&j!=k)/*确保i、j、k三位互不相同*/ 
        cout << i << j << k << endl;
    }
    return 0;
}
