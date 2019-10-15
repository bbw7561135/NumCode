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


#include <iostream>
using namespace std;

//题目：企业发放的奖金根据利润提成。利润(I)低于或等于10万元时，奖金可提10%；利润高 于10万元，低于20万元时，
//低于10万元的部分按10%提成，高于10万元的部分，可可提 成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；
//40万到60万之间时高于 40万元的部分，可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，
//高于 100万元时，超过100万元的部分按1%提成，从键盘输入当月利润I，求应发放奖金总数

//请利用数轴来分界，定位。注意定义时需把奖金定义成长整型

int main()
{
    long int i;
    cout << "input profit: " << endl;
    cin >> i;
    int bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
    bonus = 0;
    bonus1 = 100000*0.1;
    bonus2 = bonus1 + 100000*0.075;
    bonus4 = bonus2 + 200000*0.05;
    bonus6 = bonus4 + 200000*0.03;
    bonus10 = bonus6 + 400000*0.015;
    if(i<=100000)
    {
        bonus = i*0.1;
    }
    else if(i<=200000)
    {
        bonus = bonus1 + (i-100000)*0.075;
    }
    else if(i<=400000)
    {
        bonus = bonus2 + (i-200000)*0.05;
    }
    else if(i<=600000)
    {
        bonus = bonus4 + (i-400000)*0.03;
    }
    else if(i<=1000000)
    {
        bonus = bonus6 + (i-600000)*0.015;
    }
    else
    {
        bonus = bonus10 + (i-1000000)*0.01;
    }
    cout << bonus << endl;
    return 0;

}

