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

