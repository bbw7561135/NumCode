#include <iostream>

using namespace std;

int main()
{
    int updates = 6;
    int* p_updates;
    p_updates = &updates;

    //express values in two ways
    cout << "Values: updates  = " << updates <<endl;
    cout << " *updates  = " << *p_updates << endl;

    //express address in two ways
    cout << "Address updates = " << &updates <<endl;
    cout << " updates = " << p_updates << endl;

    //use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    return 0;
}

//Values: updates  = 6
// *updates  = 6
//Address updates = 0x6dfee8
// updates = 0x6dfee8
//Now updates = 7

#include <iostream>

using namespace std;

int main()
{

    double* p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    //treat p3 like noraml array but p3 is atcually pointer
    cout << "p3[1] is " << p3[1] << endl;

    p3 = p3 + 1;//normal array name can not do it while pointer can
    //here 1 refers to 8 byte as *p3 is double type //for int it is 4 byte
    //now p3 pointers to p3[1] //
    cout << "now p3[0] is " << p3[0] << endl; //0.5
    cout << "now p3[1] is " << p3[1] << endl;
    p3 = p3 - 1;
    cout << "p3[0] is " << p3[0] << endl;
    return 0;
}

//p3[1] is 0.5
//now p3[0] is 0.5
//now p3[1] is 0.8
//p3[0] is 0.2

#include <iostream>

using namespace std;

int main()
{

    double wages[3] = {10000.0,20000.0,30000.0};
    short  stacks[3] = {3,2,1};

    //Here are two ways to get the address of an array
    double* pw = wages; //name of an array = address
    short* ps = &stacks[0]; //the first element's address is also the address of an array
    //stacks = &stacks[0] = address of the first element of array
    //数组名字被解释为第一个元素的地址 但对数组名字用取地址符& 得到的值虽然和第一个地址相同 但它代表的是整个数组的地址 只不过首地址是
    //第一个元素地址 
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << " add 1 to the pw point." << endl;
    cout << "pw = " << pw << ", *pw = " << *pw << endl;

    cout << "ps = " << ps << ", *pss = " << *ps << endl;
    ps = ps + 1;
    cout << " add 1 to the ps point." << endl;
    cout << "ps = " << ps << ", *ps = " << *ps << endl;

    cout << "access two elements via array notation." << endl;
    cout << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements via pointer notation." << endl;
    cout << "*stacks = " << *stacks
         << ", *(stacks+1) = " << *(stacks+1) << endl;
    //another difference between pointer and array name
    cout << sizeof(wages) << " = size of wages array." << endl;
    cout << sizeof(pw) << " = size of pw pointer." << endl;
    return 0;
}


//pw = 0x6dfec0, *pw = 10000
// add 1 to the pw point.
//pw = 0x6dfec8, *pw = 20000
//ps = 0x6dfeba, *pss = 3
// add 1 to the ps point.
//ps = 0x6dfebc, *ps = 2
//access two elements via array notation.
//stacks[0] = 3, stacks[1] = 2
//access two elements via pointer notation.
//*stacks = 3, *(stacks+1) = 2
//24 = size of wages array.
//4 = size of pw pointer.


#include <iostream>

using namespace std;

int main()
{

    short tell[3];
    cout << tell << endl;//the address of the first element
    cout << &tell << endl;//the addresses of all
    int age = 39;
    const int* pt = &age; //pt指向一个常量 意思不是说age本身是常量
    //而是无法通过pt改变这个量 比如 *pt = *pt + 1会报错
    //这样可以防止指针无意中修改了age值 但实际上age本身不是常量 可以通过
    //age = age + 1 来改变
    const float g_earth = 9.80;
    const float* pe = &g_earth; //这是OK的 将const变量的地址赋给const指针 即不能用g_earth来改变值
    //用pe也不能改变
    //但是不能将congst的地址赋给非const指针
    // const float *gmoom=1.63；
    //float* pm = &gmoom 因为如果这样可行 那么pm可以改gmoom的值 与gmoom本身const属性矛盾
    return 0;
}


#include <iostream>
using namespace std;

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03*lns+0.0004*lns*lns;
}

void estimate(int lines, double (*pf)(int))
{
    cout << lines << "lines will take ";
    cout << (*pf)(lines) << " hours." <<endl;
}

int main()
{
    //函数指针
    int code = 100;
    cout << "Betsy's estimate: " << endl;
    estimate(code,betsy);
    cout << "Pam's estimate: " << endl;
    estimate(code,pam);
    //double (*pf)(int) = pf pointer to a function which return double while require int
    //double *pf(int) = pf(int) is a function which return a double* pointer
    //函数名本身就是函数的地址 process(think)=process函数在其内部调用think函数
    //thought(think()) thought函数先调用think函数获得返回值 用这个返回值作为输入参数
    return 0;
}


//Betsy's estimate:
//100lines will take 5 hours.
//Pam's estimate:
//100lines will take 7 hours.


#include <iostream>
#include <vector>
#include <array>
using namespace std;



int main()
{
    //模板类 vector 动态数组 new创建动态数组的替代品
    //实际上 vector的确是使用new和delete管理内存 但内化了
    //C++ 11新增array 比vector效率高 更接近原始数组

    //C and original C++ array
    double a1[4] = {1.2,2.4,3.6,4.8};

    //C++98 STL
    vector<double> a2(4);
    a2[0] = 1.0/3.0;//no simple way to initialize
    a2[1] = 1.0/5.0;//loop like original C array
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    //C++11
    array<double,4> a3 = {3.14,2.72,1.62,1.41};
    array<double,4> a4 = a3;

    //use array notation
    cout << "a1[2] = " << a1[2] << "at " << &a1[2] << endl;
    cout << "a2[2] = " << a2[2] << "at " << &a2[2] << endl;
    cout << "a3[2] = " << a3[2] << "at " << &a3[2] << endl;
    cout << "a4[2] = " << a4[2] << "at " << &a4[2] << endl;
    return 0;
}


//a1[2] = 3.6at 0x6efec8
//a2[2] = 0.142857at 0x30538
//a3[2] = 1.62at 0x6efe98
//a4[2] = 1.62at 0x6efe78



#include <iostream>

using namespace std;

const double* f1(const double ar[], int n) // const double [] const double * is also OK
{
    return ar;
}

const double* f2(const double* ar, int)
{
    return ar+1; //1 is 8 byte
}

const double* f3(const double ar[], int)
{
    return ar+2;
}
//the prototype of f1 f2 f3 are the same
///////////////////////////////////////

int main()
{
    //函数指针高级版

    double av[3]={1112.3,1542.6,2227.9};
    //point to a function
    const double* (*p1)(const double*, int) = f1;
    //声明函数指针时候把函数原型中的函数名字替换为(*p)即可  函数指针是一个指针
    //需要赋给它表示函数地址的变量 而函数名字本身(f1,f2,f3)就是表示其地址
    auto p2 = f2; //C++11自动推断类型 p2和怕p1一样是函数指针
    //auto注意点在收藏夹C&Fortran里面
    //调用函数时候 (*pf)(5)等价于pf(5) 但前者更直观表达了代码正在使用函数指针！
    cout << "using pointers to functions: " << endl;
    cout << "Address Value : " << endl;
    cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    //(*p1)(av,3)=f1(av,3) 而f1的返回值是指向const double的指针 const的意思是指针不能改变它指向的值
    //所以*(*p1)(av,3) 是取得这个值
    cout << p2(av,3) << ": " << *p2(av,3) << endl;
    //调用函数时候 (*pf)(5)等价于pf(5)

    //函数指针数组 无法用auto来作为数组初始化
    const double* (*pa[3])(const double*,int) = {f1,f2,f3};
    //pa是指针数组 存了3个函数指针
    //但可以用auto判断单个元素
    auto pb = pa; //pa首元素赋给了pb pb指向f1 等价于pa
    cout << "\nUsing an array of pointers to functions." << endl;
    cout << "Address Value : " << endl;
    for(int i=0;i<3;i++)
    {
        cout<<pa[i](av,3)<< ": " << *pa[i](av,3) << endl;
        cout << (*pa[i])(av,3) << ": " << *(*pa[i])(av,3) << endl;
    }

    for(int i=0;i<3;i++)
    {
        cout<<pb[i](av,3)<< ": " << *pb[i](av,3) << endl;
        cout << (*pb[i])(av,3) << ": " << *(*pb[i])(av,3) << endl;
    }

    //指向pa的指针
    cout << "\nUsing pointer to an array of points." << endl;
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
    //*pc=pa so (*pc)[0](av,3) = pa[0](av,3)
    //*(*pc)[0](av,3) = *pa[i](av,3)
    return 0;
}

//using pointers to functions:
//Address Value :
//0x6dfec0: 1112.3
//0x6dfec8: 1542.6
//
//Using an array of pointers to functions.
//Address Value :
//0x6dfec0: 1112.3
//0x6dfec0: 1112.3
//0x6dfec8: 1542.6
//0x6dfec8: 1542.6
//0x6dfed0: 2227.9
//0x6dfed0: 2227.9
//0x6dfec0: 1112.3
//0x6dfec0: 1112.3
//0x6dfec8: 1542.6
//0x6dfec8: 1542.6
//0x6dfed0: 2227.9
//0x6dfed0: 2227.9
//
//Using pointer to an array of points.
//0x6dfec0: 1112.3



#include <iostream>

using namespace std;



const double* f1(const double ar[], int n) // const double [] const double * is also OK
{
    return ar;
}

const double* f2(const double* ar, int)
{
    return ar+1; //1 is 8 byte
}

const double* f3(const double ar[], int)
{
    return ar+2;
}
//the prototype of f1 f2 f3 are the same
///////////////////////////////////////

int main()
{
    //typedef 为变量创建别名 减少输入量 当代码更简洁
    //typedef相比预处理#define更有优势
    //#define Float_Pointer float *
    //Float_Point a,b
    //系统会把a看成 float*类型 而b是float类型 而我们要的是ab都是float*类型
    double av[3] = {66.0,77.0,88.0};
    typedef short st;//short = st
    typedef const double*(*pf_fun)(const double*, int);//pf_fun现在就是整个复杂表达式的别名
    //pf_fun表示函数指针
    st a = 5;
    cout << "a is " << a << endl;
    pf_fun p1 = f1;//p1是函数指针 所以应该把函数地址赋给它 而函数名字就是函数地址
    cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    //(*p1)(av,3)=f1(av,3) 而f1的返回值是指向const double的指针 const的意思是指针不能改变它指向的值
    //所以*(*p1)(av,3) 是取得这个值
    pf_fun pa[3] = {f1,f2,f3};
    for(int i=0;i<3;i++)
    {
        cout<<pa[i](av,3)<< ": " << *pa[i](av,3) << endl;
        cout << (*pa[i])(av,3) << ": " << *(*pa[i])(av,3) << endl;
    }
    return 0;
}

//a is 5
//0x6dfec8: 66
//0x6dfec8: 66
//0x6dfec8: 66
//0x6dfed0: 77
//0x6dfed0: 77
//0x6dfed8: 88
//0x6dfed8: 88


#include <iostream>

using namespace std;

//函数模板原型
template <typename DataType>
void Swap(DataType &a, DataType &b)
{
    DataType temp;
    temp = a;
    a = b;
    b = temp;
}

//Datatype那么赋值这些操作就行不通

int main()
{
    //函数模板
    int i = 10;
    int j = 20;
    cout << "before swap: i = " << i << endl;
    cout << "before swap: j = " << j << endl;
    Swap(i,j);
    cout << "after swap: i = " << i << endl;
    cout << "after swap: j = " << j << endl;

    double x = 5.0;
    double y = 12.0;
    cout << "before swap: x = " << x << endl;
    cout << "before swap: y = " << y << endl;
    Swap(x,y);
    cout << "after swap: x = " << x << endl;
    cout << "after swap: y = " << y << endl;
    return 0;
}


//before swap: i = 10
//before swap: j = 20
//after swap: i = 20
//after swap: j = 10
//before swap: x = 5
//before swap: y = 12
//after swap: x = 12
//after swap: y = 5
