#include <iostream>
using namespace std;





int main()
{
    int i,m =10;
    int days[m] = {1,2,3,4,5,6,7,8,9,10};

    for(i=0;i<m;i++)
    {
        cout << "using days[i]" << days[i] << endl;
    }

    for(i=0;i<m;i++)
    {
        cout << "using *(days+i)" << *(days+i) << endl;
    } //指针能表示数组 反正 数组也能表示指针 特别是在使用以数组为参数的函数时

    return 0;
}



#include <iostream>
using namespace std;

int sum(int ar[], int n) //(int* ar, int n) is also ok
{ //ar[]能反映出传入的是一个数组
    int i=0;
    int total = 0;
    for(i=0;i<n;i++)
    {
        total += ar[i]; //*(ar+i) is also ok
    }
    return total;
}



int main()
{
    int ans,m =10;
    int days[m] = {1,2,3,4,5,6,7,8,9,10};

    ans = sum(days,m);
    cout << ans << endl;

    return 0;
}



#include <iostream>
using namespace std;

int sum(int* startAdd, int* endAdd) //(int* ar, int n) is also ok
{

    int total = 0;
    while(startAdd<endAdd)
    {
        total += *startAdd;
        startAdd++; //*(ar+i) is also ok
        //++和*一样优先级 但是C语言满足从右往左结合
        //所以上述等价于 total += *startAdd++
        //意思是先把startAdd指向的值加到total上 在递增指针 注意理解 startAdd++ 和 ++startAdd的差别
    }
    return total;
}



int main()
{
    int ans,m =10;
    int days[m] = {1,2,3,4,5,6,7,8,9,10};

    ans = sum(days,days+m); //days+m事实上指向10后面的一个位置 但是C允许这样的访问
    //所以sum里面的循环条件是startAdd<endAdd
    //虽然C保证了days+m有效 但对其值未作保证 所以程序不能访问该位置
    cout << ans << endl;

    return 0;
}


#include <iostream>
using namespace std;




int main()
{

    int data[2] = {100,200};
    int moredata[2] = {300, 400};
    int *p1, *p2, *p3;

    p1 = data;
    p2 = data;
    p3 = moredata;

    cout << "*p1 *p2 *p3 " << *p1 << *p2 << *p3 << endl;
    cout << "*p1++ *++p2 (*p3)++ " << *p1++ << *++p2 << (*p3)++ << endl;
    cout << "new *p1 *p2 *p3 " << *p1 << *p2 << *p3 << endl;
    //*++p2的意思是 马上把p2指向下一个int地址 然后取值 此后p2就指向下一个地址 也就是200
    //*p1++的意思是 先对p1求值 用完这次后p1指向下一个int地址 也就是200
    //(*p3)++的意思是 对p3求值 然后把这个值用完后+1 p3指向的地址不变 但是值已经从300变为301

    return 0;
}

//*p1 *p2 *p3 100100300
//*p1++ *++p2 (*p3)++ 100200300
//new *p1 *p2 *p3 200200301

//指针和数组的关系在290-300
//指针中const的应用在C primer plus 300页
//const double * pc
//double * const pc
//const double * const pc 三者不同
//指针和多维数组的关系在301


#include <iostream>
using namespace std;




int main()
{

    int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
    cout << "zippo = " << zippo << "zippo + 1 = " << zippo + 1 << endl;
    //zippo指向一个含2个int的内存地址 +1就表示要跳过8个字节 这里是十六进制要注意
    cout << "zippo[0] = " << zippo[0] << "zippo[0] + 1 = " << zippo[0] + 1 << endl;
    //zippo[0]可以看作是一个普通的数组名字 比如ar
    //所以zippo[0]本身就是ar[0]的地址 指向一个int的内存地址 +1表示要跳过4个字节
    cout << "*zippo = " << *zippo << "*zippo + 1 = " << *zippo + 1 << endl;
    //zippo的值是首元素的地址 而首元素是含两个int的数组 所以*zippo=zippo[0]
    //*(zippo+1)=zippo[1]
    cout << "zippo[0][0] = " << zippo[0][0] << endl;
    //zippo[0][0]==*zippo[0]==**zippo
    cout << "*zippo[0] = " << *zippo[0] << endl;
    cout << "**zippo = " << **zippo << endl;
    //zippo[2][1]==*(*(zippo+2)+1)
    cout << "zippo[2][1] = " << zippo[2][1] << endl;
    cout << "*(*(zippo+2)+1) = " << *(*(zippo+2)+1) << endl;
    //303的图很实用 可以帮忙厘清上述关系
    return 0;
}


//zippo = 0x6dfed0     zippo + 1 = 0x6dfed8
//zippo[0] = 0x6dfed0  zippo[0] + 1 = 0x6dfed4
//*zippo = 0x6dfed0    *zippo + 1 = 0x6dfed4
//zippo[0][0] = 2
//*zippo[0] = 2
//**zippo = 2
//zippo[2][1] = 3
//*(*(zippo+2)+1) = 3



#include <iostream>
using namespace std;

//指向二维数组的指针


int main()
{

    int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
    cout << "zippo = " << zippo << "zippo + 1 = " << zippo + 1 << endl;
    cout << "zippo[0] = " << zippo[0] << "zippo[0] + 1 = " << zippo[0] + 1 << endl;
    cout << "*zippo = " << *zippo << "*zippo + 1 = " << *zippo + 1 << endl;
    cout << "zippo[0][0] = " << zippo[0][0] << endl;
    cout << "*zippo[0] = " << *zippo[0] << endl;
    cout << "**zippo = " << **zippo << endl;
    cout << "zippo[2][1] = " << zippo[2][1] << endl;
    cout << "*(*(zippo+2)+1) = " << *(*(zippo+2)+1) << endl;
    int (*pz) [2];//different from int* pz[2] see page304
    //pz == zippo
    pz = zippo;
    cout << "pz = " << pz << "pz + 1 = " << pz + 1 << endl;
    cout << "pz[0] = " << pz[0] << "pz[0] + 1 = " << pz[0] + 1 << endl;
    cout << "*pz = " << *pz << "*pz + 1 = " << *pz + 1 << endl;
    cout << "pz[0][0] = " << pz[0][0] << endl;
    cout << "*pz[0] = " << *pz[0] << endl;
    cout << "**pz = " << **pz << endl;
    cout << "pz[2][1] = " << pz[2][1] << endl;
    cout << "*(*(pz+2)+1) = " << *(*(pz+2)+1) << endl;
    //指针比较复杂 有时候容易搞混忘记 需要多翻 305指针的兼容性
    //如果A是二维数组 那么A[i]就是一维数组 可以将其视为二维数组的一行
    return 0;
}

//zippo = 0x6dfecc zippo + 1 = 0x6dfed4
//zippo[0] = 0x6dfecc zippo[0] + 1 = 0x6dfed0
//*zippo = 0x6dfecc *zippo + 1 = 0x6dfed0
//zippo[0][0] = 2
//*zippo[0] = 2
//**zippo = 2
//zippo[2][1] = 3
//*(*(zippo+2)+1) = 3
//pz = 0x6dfecc pz + 1 = 0x6dfed4
//pz[0] = 0x6dfecc pz[0] + 1 = 0x6dfed0
//*pz = 0x6dfecc  *pz + 1 = 0x6dfed0
//pz[0][0] = 2
//*pz[0] = 2
//**pz = 2
//pz[2][1] = 3
//*(*(pz+2)+1) = 3


#include <iostream>
using namespace std;

#define ROWS 3 //hang
#define COLS 4 //lie


//如何处理二维数组作为函数参数
void sum_rows(int ar[][COLS],int rows)
{//void sum_rows(int ar[][COLS], int) and (int(*ar)[],int rows) are both ok
    int r;
    int c;
    int tot;
    for(r=0;r<rows;r++)
    {
        tot = 0;
        for(c=0;c<COLS;c++)
        {
            tot += ar[r][c];
        }
        cout << "row " << r << ": sum is " << tot << endl;
    }
}


int main()
{

    int junk[ROWS][COLS] = {
    {2,4,6,8},
    {3,5,7,9},
    {12,10,8,6},
    };

    sum_rows(junk,ROWS);

    return 0;
}


//row 0: sum is 20
//row 1: sum is 24
//row 2: sum is 36




//处理二维数组时 可以省略第一维的大小 第二维不可少
//其他多维数组也只能省略第一维 int sum4d(int ar[][10][19][17])
//处理任意大小的二维数组不太方便 因为不能确定维度大小
//方法一是把数组作为一维数组传递 然后让函数计算每行的开始
//方法二是使用C11的变长数组 变长数组不是指能改变数组大小 而是指在创建数组时候可以使用变量指定数组的维度
//意即可以用变量指定数组维度 但是变长数组有一些限制 比如不能用static或extern修饰 也不能在声明时初始化
//而且只有C语言支持 C++里面可用指针或者STL里面的vector实现变长数组 参加收藏夹C++变长数组


#include <stdio.h>
#include <stdlib.h>



int sum_2d(int rows, int cols, int ar[rows][cols])
{//void sum_rows(int ar[][COLS], int) and (int(*ar)[],int rows) are both ok
    int r;
    int c;
    int tot=0;
    for(r=0;r<rows;r++)
    for(c=0;c<cols;c++)
        tot += ar[r][c];
    return tot;
}




int main()
{

    int i,j;
    int rs=3;
    int cs=10;
    int vla[rs][cs];//变长数组VLA

    for(i=0;i<rs;i++)
    for(j=0;j<cs;j++)
        vla[i][j]=i*j+j;

    int res=0;
    res = sum_2d(rs,cs,vla);
    printf("%d",res);
    return 0;
}




//最本质的办法 动态申请数组

#include <stdio.h>
#include <stdlib.h>






int main()
{

    double* ptd;
    int max;
    int i = 0;

    max = 10;
    ptd = (double*) malloc(max*sizeof(double));
    if(ptd==NULL)
        printf("allocate fails.");
    else
        for(i=0;i<max;i++)
    {
        ptd[i]=i+2.0;
    }

    for(i=0;i<max;i++)
    {
        printf("%f\n",ptd[i]);
    }
    free(ptd);
    return 0;
}



//结构
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITLE 40
#define MAXAUTHOR 40
#define MAXBOOKS 2


struct book
{
    char title[MAXTITLE];
    char author[MAXAUTHOR];
    float value;
};

struct person
{
    struct book own;
    char names[MAXAUTHOR];
    float income;
};


int main()
{
    //初始化器
    struct book gift = {
    .value = 1.26,
    .author = "Amao",
    .title = "My  struggling life"
    };
    struct book surprise = {
    .value = 6.66
    };
    //   char book[50];
   //char *author;
    //  strcpy(book,"amao");
   //book = "amao";//这样的赋值是错误的。
   //author = "liucixin";//这样赋值可以
    struct book library[MAXBOOKS];
    library[0].value = 5.0;
    strcpy(library[0].author,"adong");
    strcpy(library[0].title,"JinPingMei");
    printf("%f\n",gift.value);//结构成员运算符.
    printf("%f\n",surprise.value);
    printf("%f\n",library[0].value);
    printf("%s\n",library[0].author);
    printf("%c\n",library[0].author[1]);

    //嵌套结构
    struct person amao = {
    .own = {"Ak47","Russia",7.77},
    .names = "China",
    .income = 67000
    };
    printf("%s\n",amao.names);
    return 0;
}







