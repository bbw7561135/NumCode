#include <iostream>
#include <omp.h>
using namespace std;

int main()
{//百钱百鸡
    omp_set_num_threads(2);
#pragma omp parallel for
    for(int i=0;i<10000;i++)
        {
            int cock,hen,chick;
            for(cock=0;cock<=20;cock++) //公鸡最多20
                for(hen=0;hen<=33;hen++) //母鸡最多33
                    for(chick=0;chick<=99;chick++)//小鸡不能超100
                        if(5*cock+3*hen+chick/3==100)
                            if(chick%3==0 && i==9999)
                                cout << "cock = " << cock
                                    << "hen = " << hen
                                    << "chick = " << chick <<endl;


        }

    return 0;
}


#include <iostream>
using namespace std;


struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
};

int main()
{//指向结构体的指针

    struct student amao =
    {
        001,"Bao",'M',30,99 //"M" is not OK
    };
    struct student* p;
    p = &amao;
    cout << p->name << endl;
    cout << p->age << endl;
    cout << p->sex << endl;
    return 0;
}


#include <iostream>
using namespace std;


void max_min(int a[], int n, int *max, int *min)
{
    int *p;
    *max = *min = *a;//a is the array name also the first address of the 1st element
    //so *a is the 1st element
    for(p=a+1;p<a+n;p++)
    {
        if(*p>*max)
            *max=*p;
        else if (*p<*min)
            *min=*p;
        else
            continue;
    }
}




int main()
{//指针与数组

    int a[10] = {1,3,4,5,76,8,9,92,33,77};
    //int * p;
    //p = a; //equals to p=&a[0]
    int max,min;
    max_min(a,10,&max,&min);
    cout << max << '\t' << min << endl;


    return 0;
}



#include <iostream>
using namespace std;

int *findsame(int *pa, int *pb, int an, int bn)
{
    int *pta, *ptb;
    pta = pa;
    ptb = pb;
    while(pta<pa+an && ptb<pb+bn)
    {
        if(*pta < *ptb)
            pta++;
        else if(*pta > *ptb)
            ptb++;
        else
            return pta;//pta是局部变量指针 但是pta所指的是外部的变量 可以返回
    }
    return 0; //null pointer
}





int main()
{//指针与数组

    int *p;
    int a[] = {1,2,3,4,5};
    int b[] = {2,3,4,5,6};
    p = findsame(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
    if(p)
        cout << *p << endl;


    return 0;
}



#include <iostream>
using namespace std;

float* searchstu(float(*p)[4], int n)
{//*的优先级高于[] 所以float * p[4]表示一个数组p[4] 数组里面元素是float型指针
    //而float (*p)[4]表示指针p指向一个有4个float元素的数组
    //此时p+1 等于越过4个 float元素 see c++ primer plus 245-246
    float *pt;
    pt = *(p+n);//p+n指向第n个学生 包含四个数组 *(p+n)是首元素的地址
    return pt;
}



int main()
{//指针与数组

    float score[][4] = {{60,32,43,65},{23,65,98,98},{34,67,98,35},{23,56,87,92}};
    float *pp; //pp point to an float
    int j=2;
    pp = searchstu(score,j);
    for(int i=0;i<4;i++)
    {
        cout << *(pp+i) << endl;
    }

    return 0;
}
