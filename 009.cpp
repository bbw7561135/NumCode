/*

#### iostram.h == iostream + using namespace std 但是前者不提倡使用
#### 需要用cin来输入字符串时 用cin.getline替代
#### 字符串转数值除了sstream类 还可以用cstdlib里面的atoi atol atof 配合cin.getline
#### 字符串还有cstring里面的strcat strcmp strcpy strlen等
#### int* p 指针声明时候用的* 表明它是一个指针 与 * p的* (引用操作符)不一样
#### int * p1, * p2 声明指针时候别忘记* int * p1, p2 中只有p1是指针 p2是int
#### int num[20] num实际上是个指针 但是是一个指针常量 指向一个大小为20的int数组的首地址 所以num不能做左值
#### 也就是说 int * p  p=num可以 但是num=p不行！
#### 指针的加减法与一般算术加减不一样 给指针加1 实际是让该指针指向下一个与它被定义的数据类型相同的元素
#### char * p1 假设p1的值为100 则p1++ 是101 char大小为1
#### short * p2 假设p2的值为200 则p2++ 是102 short大小为2
#### 涉及到指针操作时候 操作符优先级十分重要 需要时常参考优先级表以及明白C++的结合顺序 或者使用()括号避免不想要的结果
#### 函数名本身也是个指针 引出函数指针及其使用方法
#### 用new分配动态内存 如果失败 返回NULL指针 失败时最好输出语句提醒  否则容易出现不想要的结果
#### new和delete搭配使用 注意数组时 delete []arr C中没有new和delete需要用 malloc和free 其他还有calloc和realloc
#### C中的结构概念在C++中已经被扩展到与类class相同的程度 只是它所有的元素都是公开的 意即默认public 
#### C++中的结构也可以有自己的成员函数！！！union在C++也可以有自己的函数成员并且默认也是public！！！
#### 结构指针访问成员需要用-> 普通结构对象用.访问成员
#### typedef  existing_type new_type_name 为已有的类型给定一个新的名字 特别是与指针有关时候 方便记忆 不容易混淆
#### union与结构的差别是联合中所有的量占同样的一段内存 大小为声明中最长元素的大小 联合常在结构体中出现-匿名联合 可参考书籍 不常用
#### 枚举enum 可参考书籍 不常用
#### 类比C中的struct结构高级 不仅包含数据 也可以包含函数！
#### private成员---类的其他成员 友元类可以访问 默认都是private属性
#### protected成员---类的其他成员 友元类 子类 可以访问
#### public成员---任何可以看到这个类的地方都可以访问
#### 类名--对象名（实例） 结构名--对象名（实例） 要区分
#### 在类之外定义其成员函数用：：双冒号 在类内部定义函数(不是声明) 编译器会当成inline内联函数处理 不适合复杂函数
#### 构造函数与类名相同 并且会在实例声明或者分配内存时自动调用 自动调用！！！
#### 构造函数原型中不需要写返回类型 也不需要声明是void 定义中也不用写return 这就是构造函数的特殊之处
#### 析构函数刚好相反 在实例被从内存中释放时候自动调用 自动调用！！！
#### 析构函数也必须与类名相同 但是前面多个~前缀 如果类里面用到new 可以在析构函数里面安排delete完成释放
#### 构造函数也可以被重载 与普通函数重载的要求一致 比如参数类型不同 参数个数不同等
#### 默认构造函数（空构造和拷贝构造）只有在没有其他构造函数被明确定义情况下才会存在
#### 但凡定义了一个构造函数 默认的两个构造函数都会消失！
#### 声明新实例的时候 如果不传入参数 不要写()括号！！！
#### 类的指针也使用间接操作符->
#### 操作符重载 可参考书籍 不常用
#### 关键字this指针通常被用在一个class内部 指正在被执行的该class的实例在内存中的地址 它是一个指针 其值永远是自身实例的地址

*/

// vectors: overloading operators example
//简单操作符的重载 特别注意操作符重载a+b的意思等价于a(b) b+a则是b(a)看似结果一样 但原理不同
#include <iostream>
using namespace std;
class CVector 
{
      public:
        int x,y;
        CVector () {}; //空构造函数不能少 否则CVector c将会报错！
      //但空语句块不好 CVector () {x=0;y=0;}更合理 注意y=0后面也有分号
        CVector (int,int);//拷贝构造函数
      //上述两个构造函数都是我们人为给出 覆盖默认的空构造函数和拷贝函数
      //但是如果只定义CVector (int,int) 默认空构造函数也不起效 也就是不会用系统默认的 所以要自己定义构造函数 两个都要定义
        CVector operator + (CVector);
};//delimeter
    
CVector::CVector (int a, int b)
{
        x = a;
        y = b;
}
    
CVector CVector::operator+ (CVector param)
{
        CVector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return (temp);
}
    
int main () {
        CVector a (3,1);
        CVector b (1,2);
        CVector c;
        c = a + b;
        cout << c.x << "," << c.y << endl;
        return 0;
}

