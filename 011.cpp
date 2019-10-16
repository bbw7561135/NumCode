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
//找出1000以内的所有完数



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
        for(i=1;i<j/2+1;i++)
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
