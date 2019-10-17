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


#include <iostream>
#include <cmath>
using namespace std;

//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？ 
//程序分析：在10万以内判断，先将该数加上100后再开方，再将该数加上268后再开方 最后验证是否相等即可

int main()
{
    long int i,x,y,z;
    for(i=1;i<100000;i++)
    {
        x = sqrt(i+100);
        y = sqrt(i+268);
        if(x*x==i+100 && y*y==i+268)
        {
            cout << i << endl;
        }
    }
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：输入某年某月某日，判断这一天是这一年的第几天？ 
//程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天
//特殊情况，闰年且输入月份大于2时需考虑多加一天 闰年的判断标准

int main()
{
    int day;
    int month;
    int year;
    int sum;
    int leap;
    cout << "input year: " << endl;
    cin >> year;
    cout << "input month: " << endl;
    cin >> month;
    cout << "input day: " << endl;
    cin >> day;
    switch(month)
    {
    case 1:sum=0;break;
    case 2:sum=31;break;
    case 3:sum=59;break;
    case 4:sum=90;break;
    case 5:sum=120;break;
    case 6:sum=151;break;
    case 7:sum=181;break;
    case 8:sum=212;break;
    case 9:sum=243;break;
    case 10:sum=273;break;
    case 11:sum=304;break;
    case 12:sum=334;break;
    default:cout<<"data error";break;
    }
    sum = sum + day;
    if(year%400==0 || (year%4==0 && year%100!=0))
    {
        leap=1;
    }
    else
    {
        leap=0;
    }

    if(leap==1&&month>2)
    {
        sum = sum + 1;
    }

    cout << sum << endl;

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：输入三个整数x,y,z，请把这三个数由小到大输出
//程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换， 
//然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。


int main()
{
    int x;
    int y;
    int z;
    int temp;
    cout << "input num1: " << endl;
    cin >> x;
    cout << "input num2: " << endl;
    cin >> y;
    cout << "input num3: " << endl;
    cin >> z;
    if(x>y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(x>z)
    {
        temp = x;
        x = z;
        z = temp;
    }
    if(y>z)
    {
        temp = y;
        y = z;
        z = temp;
    }
    cout << x << '\t' << y << '\t' << z << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：输出9*9口诀
//程序分析：分行与列考虑，共9行9列，i控制行，j控制列


int main()
{
    int i;
    int j;
    int result;
    for(i=1;i<10;i++)
    {
        for(j=1;j<10;j++)
        {
            result = i*j;
            cout << i <<"*" << j << "=" << result << '\t';
        }
        cout << endl;
    }

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，
//假如兔子都不死，问每个月的兔子总数为多少？ 
//程序分析：兔子的规律为数列1,1,2,3,5,8,13,21....


int main()
{
    int f1;
    int f2;
    f1=1;
    f2=1;
    for(int i=1;i<=20;i++)
    {
        cout << f1 << '\t' << f2 << endl;
        f1 = f1 + f2;//new f1 is f3
        f2 = f1 + f2;//new f2 is f4
    }

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：判断101-200之间有多少个素数，并输出所有素数 
//程序分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除， 
//则表明此数不是素数，反之是素数



int main()
{
    int m;
    int i;
    int k;
    int h=0;
    int leap=1;

    for(m=101;m<=200;m++)
    {
        k=sqrt(m+1);//jieduan
        for(i=2;i<=k;i++)
        {
            if(m%i==0)
                {
                    leap=0;//no su shu
                    break;//jump inner loop
                }
        }
        if(leap)
            {
                cout << m << endl;
                h++;
            }
        leap=1;
    }
    cout << "101-200 has " << h << " sushu" << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：打印出<1000所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数
//本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。
//程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。



int main()
{
    int i;
    int j;
    int k;
    int n;

    cout << "water flower number is: " << endl;
    for(n=100;n<=999;n++)
    {
        i = n/100; //baiwei
        j = (n/10)%10;//shiwei
        k = n%10;//gewei
        if(n==i*i*i+j*j*j+k*k*k)
        {
            cout << n << endl;
        }
    }

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
//程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
//如果这个质数k恰等于n，则说明分解质因数的过程已经结束，打印出即可。
//如果n!=k，但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正整数你n, 重复执行第一步。


int main()
{
    int n;
    int i;
    cout << "input a num: " << endl;
    cin >> n;
    cout << n << "= ";
    for(i=2;i<=n;i++)
    {
        while(i!=n)
        {
            if(n%i==0)
                {
                    cout << i << "*";
                    n=n/i;
                }
            else
            {
                break;
            }
        }
    }
    cout << n << endl;//跳出循环后i==n 是最后一个因数 一定要输出
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：输入两个正整数m和n，求其最大公约数和最小公倍数
//程序分析：利用辗除法


int main()
{
    int a;
    int b;
    int num1;
    int num2;
    int temp;

    cout << "input num1:" << endl;
    cin >> num1;
    cout << "input num2:" << endl;
    cin >> num2;

    if(num1<num2)
    {
        temp=num1;
        num1=num2;
        num2=temp;
    }

    a=num1;
    b=num2;

    while(b!=0) //利用辗除法，直到b为0为止
    {
        temp = a%b;
        a=b;
        b=temp;
    }

    cout << "max gongyueshu " << a << endl;
    cout << "min gongbeishu " << num1*num2/a << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程 
//找出1000以内的所有完数 因子不包含本身



int main()
{
    static int k[10];
    int i;
    int j;
    int n;
    int s;

    for(j=2;j<1000;j++)
    {
        n=-1;
        s=j;
        for(i=1;i<j/2+1;i++) //不需要除到j 因为大于一半之后 除了本身 都不可能整除 并且因子也不包含本身
        {
            if((j%i)==0)
            {
                n++;
                s=s-i;
                k[n]=i;
            }
        }
        if(s==0)
        {
            cout << j << "is a wanshu." << endl;
            cout << j << "=";
            for(i=0;i<n;i++)
            {
                cout << k[i] << "+" ;
            }
            cout << k[n] << endl;
        }
    }

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在 
//第10次落地时，共经过多少米？第10次反弹多高？




int main()
{
    double sn = 100.0;
    double hn = sn/2.0;
    int n;

    for(n=2;n<=10;n++)
    {
        sn = sn + 2*hn;
        hn = hn/2;
    }

cout << "total path is " << sn << endl;
cout << "10th back is " << hn << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 
//第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 
//的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。





int main()
{
    int day;
    int x1;
    int x2;

    day=9;
    x2=1;
    while(day>0)
    {
        x1=(x2+1)*2;
        x2=x1;
        day--;
    }

    cout << x1 << endl;
    return 0;
}


include <iostream>
#include <cmath>
using namespace std;

//题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定 比赛名单
//有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出 三队赛手的名单





int main()
{
    char i;//i vs a
    char j;//j vs b
    char k;//k vs c

    for(i='x';i<='z';i++)
    for(j='x';j<='z';j++)
    for(k='x';k<='z';k++)
    {
        if(i!=j && i!=k && j!=k)
        {
            if(i!='x' && k=='y')
            {
                cout << i << "vs a" << endl;
                cout << j << "vs b" << endl;
                cout << k << "vs c" << endl;
            }
        }
    }

    return 0;
}



#include <iostream>
#include <cmath>
using namespace std;

//题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和
//程序分析：请抓住分子与分母的变化规律





int main()
{
    int n;
    int t;
    int num=20;
    double a=2.0;
    double b=1.0;
    double s=0.0;

    for(n=1;n<=num;n++)
    {
        s=s+a/b;
        t=a;
        a=a+b;
        b=t;
    }

    cout << "sum is" << s << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：求1+2!+3!+...+20!的和 





int main()
{

    int n;
    double s=0.0;
    double t=1.0;

    for(n=1;n<=20;n++)
    {
        t=t*n;
        s=s+t;
    }

    cout << "sum is" << s << endl;
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

//题目：利用递归方法求5!

int fact(int k)
{
    int sum;
    if(k==1)
    {
        sum=1;
    }
    else
    {
        sum=k*fact(k-1);
    }
    return sum;

}



int main()
{

    int n;


    for(n=1;n<=5;n++)
    {
        cout << n << '\t' << fact(n) << endl;
    }

    return 0;
}




#include<iostream>
#include<cmath>
using namespace std;

//给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字
//利用求余和除法分解出各个位数即可 回文数也是这个原理 12321

int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int x;

    cout << "input num: " << endl;
    cin >> x;

    a=x/10000; //wanwei
    b=x%10000/1000;//qianwei
    c=x%1000/100;//baiwei
    d=x%100/10;//shiwei
    e=x%10;//gewei
    if(a!=0)
    {
        cout << "5th num: " << e << d << c << b << a << endl;
    }
    else if(b!=0)
    {
        cout << "4th num: " << e << d << c << b << endl;
    }
    else if(c!=0)
    {
        cout << "3th num: " << e << d << c << endl;
    }
    else if(d!=0)
    {
        cout << "2th num: " << e << d << endl;
    }
    else
    {
        cout << "1th num: " << e << endl;
    }

    return 0;
}



//C语言精彩编程百例
//1.数据类型转换 包含计算时的各种类型转换 遵循低级类型向高级类型转换的原则 赋值语句发生类型转换 赋值号右侧的值转换为左侧的值
//2.常用转移字符 \n \t \b \r
//3.关系和逻辑操作符 特别是它们之间的优先级 除了！符号外 其他逻辑和关系运算符的优先级都低于算术运算符 优先级不确定用括号
//4.++ --只能用于变量 不能用于常量 
//5.位运算 6个位运算符 按位与& 按位或| 按位异或^ 取反~
//& 参加运算的两个运算量都为1 则该位为1 否则为0
//| 两个相应位中有一个为1 则该位为1
//^ 参加运算的两个相应位 同号为0 异号为1
//~ 单目运算符 对二进制数取反 0变1 1变0 除了~ 其他都是双目运算符
//上述4个都是位操作算符 针对字节或者bit进行操作 所以仅适用于char或int 不能用于float double这些
//而且是针对每个二进制位的操作







































