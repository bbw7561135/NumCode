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
