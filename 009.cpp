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
#### 默认的复制构造函数拷贝的都是非静态数据成员 静态成员可以是数据也可以是函数 静态成员不依赖于某个实例 而是所有实例所共有
#### 对一个类的所有实例具有相同的量  所以默认的复制构造函数在拷贝时候就没有拷贝非静态数据成员
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
    
CVector CVector::operator+ (CVector param)//这里都是传值 而不是传址 数据大时候有开销 可以使用 CVector& param传引用
{                                         //如果不修改参数 前面还可以加const限定
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


// this
#include <iostream>
using namespace std;

class CDummy
{
      public:
        int isitme (CDummy& param);
};

int CDummy::isitme (CDummy& param) //这里的&表示param是CDummy的引用
{
        if (&param == this) return 1;//这里的param是取地址
        else return 0;
}
    
int main () {
        CDummy a;
        CDummy* b = &a;
        if ( b->isitme(a) )
            cout << "yes, &a is b"<<endl;
        return 0;
}



// vectors: overloading operators example
#include <iostream>
using namespace std;
class CVector 
{
      public:
        int x,y;
        CVector () {};
        CVector (int,int);
        CVector operator + (CVector);
        CVector operator = (CVector);
};//delimeter
    
CVector::CVector (int a, int b)
{
        x = a;
        y = b;
}
    
CVector CVector::operator+ (CVector param) //也可以用类外的全局函数来重载操作符 但此时无法访问类的私有成员 除非是友元
{
        CVector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return (temp);
}

CVector CVector::operator= (CVector param)
{

        x = param.x;
        y = param.y;
        return *this;//this用在这里可以避免使用临时对象
      //this指的就是调用这个operator=函数的那个实例 比如a=b等价于a(b) 那么a就是this指向的对象
}
    
int main () {
        CVector a (3,1);
        CVector b (1,2);
        CVector c;
        CVector d;
        c = a + b;
        d = a;
        cout << c.x << "," << c.y << endl;
        cout << d.x << "," << d.y << endl;
        return 0;
}


// this
#include <iostream>
using namespace std;

class CDummy
{
      public:
        static int n; //静态成员与全局变量享有相同属性 但它额外有类的范围 ANSI-C++标准为了防止它被重复声明
        CDummy () { n++; };//规定在类声明中只能够包含静态成员的原型声明 不能包括其定义
        ~CDummy () { n--; };
};

int CDummy::n=0;//静态成员定义要放在这里 全局范围内 它本质上是个全局变量 只是它额外有类的属性
int main ()
{
        CDummy a; //n=1
        CDummy b[5];//n=6
        CDummy * c = new CDummy;//n=7
        cout << a.n << endl;//n=7 作为实例的数据来引用n
        delete c;//n=6 
        cout << CDummy::n << endl;//作为类的数据成员直接引用
        return 0;
}

//有静态数据成员就有静态函数成员
//静态函数成员也是全局函数 调用方式和类的函数成员一样
//但是只能够引用静态数据 不能用非静态成员 也不能够用this指针 因为this指针实际上用了一个实例指针
//而静态函数不是任何实例的成员 它只属于类 是类的直接成员


//友元函数
#include <iostream>
using namespace std;

class CRectangle
{
        int width, height;
      public:
        void set_values (int, int);
        int area (void) {return (width * height);}
        friend CRectangle duplicate (CRectangle);//虽然在类里面声明但不是类的成员可以从下面的定义中看出来
};
    
void CRectangle::set_values (int a, int b)
{
        width = a;
        height = b;
}
    
CRectangle duplicate (CRectangle rectparam)
{
        CRectangle rectres;
        rectres.width = rectparam.width*2;//have access to rect privared width
        rectres.height = rectparam.height*2;//because of friendship
        return (rectres); //返回的是一个CR类的对象 而不是通常的单个数据
}

int main ()
{
        CRectangle rect, rectb;
        rect.set_values (2,3);
        rectb = duplicate (rect);
        cout << rectb.area()<<endl;//在duplicate声明和调用时候 并没有把其当作class CR的成员 它不是 它只是友元函数
        return 0;
}

//友元函数可以实现两个不同类之间的操作 本质上它不是面向对象编程方法 如果可能 尽量使用类的成员函数完成操作
//友元类 A的友元类B B能够访问A的私有成员 类似友元函数
#include <iostream>
using namespace std;

class CSquare; //这里需要一个空声明 因为CR里面引CS 如果没有声明就不对 或者把CS的声明提到CR前面 跟函数的规则一样

class CRectangle
{
        int width, height;
      public:
        int area (void) {return (width * height);}
        void convert (CSquare a);
};

class CSquare
{
      private:
        int side;
      public:
        void set_side (int a){side=a;}
        friend class CRectangle; //谁定义谁开放自己 这里CSquare定义友元 那么就开放自己让CR访问 但不是相互的 这里仅代表CS对CR开放
      //如果要CR对CS开放 需要在CR里面声明友元类CS
};
    
void CRectangle::convert (CSquare a)
{
        width = a.side;
        height = a.side;
}

int main ()
{
        CSquare sqr;
        CRectangle rect;
        sqr.set_side(4);
        rect.convert(sqr);
        cout << rect.area()<<endl;
        return 0;
}

//继承是类的重要特征 继承能狗基于一个类（基类）生成另一个类（子类） 继承某些成员函数 同时加上自己专属的成员
//
#include <iostream>
using namespace std;

class CPolygon
{
      protected://protected 子类可以访问 private友元可以访问
        int width, height;
      public:
        void set_values (int a, int b) { width=a; height=b;}
};

class CRectangle: public CPolygon //公有继承 也可以改为protected或privtae
{
        public:
        int area (void){ return (width * height); } //不同边形面积计算不一致
};

class CTriangle: public CPolygon
{
      public:
        int area (void){ return (width * height / 2); }
};

int main ()
{
        CRectangle rect;
        CTriangle trgl;
        rect.set_values (4,5);
        trgl.set_values (4,5);
        cout << rect.area() << endl;//类CR和CT都包含CP的成员width height和set_values()
        cout << trgl.area() << endl;//标识符protected和private的区别在继承时体现
        return 0;//基类的protected成员可以被子类的其他成员所使用 但基类的private成员就不行 所以CP中的width和height声明为protected
}

//访问权限 pub    pro    pri
//本类成员 yes    yes    yes
//子类成员 yes    yes    no
//非成员   yes    no     no

//CR和CT继承的成员与基类拥有相同的访问权限 比如基类中的width是protected 那么CR和CT中也是protected 原因是我们是用公有继承public
//class 子类：public 基类 这里的public即是表示共有继承 pub表示子类从基类所继承的成员必须获得最低程度保护 也就是上面那个表所列的子类访问权限
//最低程度保护除了pub外 还可以用pro和pri
//class 子类：protected 基类 这会使得protected成为子类从基类继承成员的最低访问限制 也就是原来基类中的public成员到基类都变成protected成员
//当然 这些只对继承而来的成员有效 子类依旧可以定义自己的pub pri pro成员
//最常用的pub和pri pri继承等于将基类完全封装 除了子类自身外 其他任何程序都不能访问继承的成员 连子类的子类（孙类）和友元也不可以
//没有默认说明情况下 所有class声明的都是pri属性（包括子类继承） 所有struct都是pub属性
//子类继承了基类的所有成员 除了构造函数 析构函数 operator=（）成员 以及友元
//虽然基类的构造函数和析构函数没有被继承 但当子类的一个实例被生成或者销毁时候 基类的默认构造函数（没有任何参数的构造函数）和析构函数自动被调用
//如果基类没有默认构造函数（也就是你自己定义了构造函数） 当子类新实例生成时候 你希望基类某个重载的构造函数被调用 你需要在子类的每一个构造函数
//的定义中指定它

#include <iostream>
using namespace std;

class mother
{
      public:
        mother ()
          { cout << "mother: no parameters\n"; }
        mother (int a)
          { cout << "mother: int parameter\n"; }
};

class daughter : public mother
{
      public:
        daughter (int a)
          { cout << "daughter: int parameter\n\n"; }
};

class son : public mother
{
      public:
        son (int a) : mother (a) //指定调用母亲类中带参数的构造函数
          { cout << "son: int parameter\n\n"; }
};

int main ()
{
        daughter cynthia (1); //女儿类新实例生成时 母亲类的默认构造函数被调用 就是没有参数那个
        son daniel(1); //但是儿子类新实例生成时 母亲类是带参数的构造函数被调用 因为儿子类在定义中指定了
        return 0;
}



//多重继承
#include <iostream>
using namespace std;

class CPolygon
{
      protected:
        int width, height;
      public:
        void set_values (int a, int b)
          { width=a; height=b;}
};

class COutput
{
      public:
        void output (int i);
};

void COutput::output (int i)
{
        cout << i << endl;
}

class CRectangle: public CPolygon, public COutput
{
      public:
        int area (void)
          { return (width * height); }
};

class CTriangle: public CPolygon, public COutput
{
      public:
        int area (void)
          { return (width * height / 2); }
};

int main ()
{
        CRectangle rect;
        CTriangle trgl;
        rect.set_values (4,5);
        trgl.set_values (4,5);
        rect.output (rect.area());
        trgl.output (trgl.area());
        return 0;
}




//多态
//继承的好处之一是一个指向子类的指针与一个指向基类的指针是兼容的
#include <iostream>
using namespace std;

class CPolygon
{
protected:
    int width, height;
public:
    void set_values (int a, int b)
    {
        width=a; height=b;
    }
};

class CRectangle: public CPolygon
{
public:
    int area (void) {
	return (width * height);
    }
};

class CTriangle: public CPolygon
{
public:
    int area (void) {
	return (width * height / 2);
    }
};

int main ()
{
    CRectangle rect;
    CTriangle trgl;
    CPolygon * ppoly1 = &rect; //子类地址赋给基类指针
    CPolygon * ppoly2 = &trgl; //两者是兼容的 但是因为指针是指向基类的 所以我们只能引用CR和CT中从基类中继承的成员
    ppoly1->set_values (4,5); //意思就是可以用p1和p2调用setvalues 因为是基类继承来了
    ppoly2->set_values (4,5);//但是不能用p1p2调用area 因为那不是继承来的
    cout << rect.area() << endl;
    cout << trgl.area() << endl;
    return 0;
}


//接上述 如果想用p1p2 也就是基类指针承认area 必须在基类中声明它 而不能只在子类中进行声明
//但是我们area本身与子类有关 三角形 矩形的area计算方式不同 也就是我们希望在基类中声明一个area 以便被基类指针访问
//同时其具体定义留待子类中进行细化 我们可以加关键字virtual 也就是 虚拟成员函数

#include <iostream>
using namespace std;

class CPolygon
{
    protected:
        int width, height;
    public:
        void set_values (int a, int b)  {
            width=a;
            height=b;
        }
        virtual int area (void) { return (0); } 
};

class CRectangle: public CPolygon
{
    public:
        int area (void) { return (width * height); }
};
class CTriangle: public CPolygon {
    public:
        int area (void) {
            return (width * height / 2);
        }
};

int main ()
{
    CRectangle rect;
    CTriangle trgl;
    CPolygon poly;
    CPolygon * ppoly1 = &rect;
    CPolygon * ppoly2 = &trgl;
    CPolygon * ppoly3 = &poly;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    ppoly3->set_values (4,5);
    cout << ppoly1->area() << endl;
    cout << ppoly2->area() << endl;
    cout << ppoly3->area() << endl; //若基类中没有vitrual声明 都将调用基类的area函数
//关键字virtual的作用就是使用基类指针时候 子类中与基类同名的成员函数 会调用相应子类中的同名函数 而不是基类
//虽然area在基类中被定义为virtual 但是基类实例仍可以自由调用area
    return 0;
}


//抽象基类
//基本的抽象类和上述的CP很像 区别在于之前的CP我们已经为类的实例定义了一个area函数 而在抽象类中 可以不定义 简单地在函数声明后面写=0即可
//即 virtual int area（void）=0 而之前是virtual int area (void) { return (0); } 
//类似 virtual int area（void）=0称为纯虚函数 包含纯虚函数的类称为抽象基类
//抽象基类最大的特点是不能有实例 但可以定义指向它的指针
//所以假定A是抽象基类 那么 A inst就是非法 而 A* instp 是可以的
//因为纯虚函数还没有被实现 所以不可能生成一个不包含所有成员定义的实例 所以 A inst不可以
//但是这个函数在子类中被完整定义了 所以生成一个指向其子类实例的指针是完全合法的 因为子类指针和基类指针是兼容的 所以 A* inst可行
//
#include <iostream>
using namespace std;

class CPolygon
{
    protected:
        int width, height;
    public:
        void set_values (int a, int b) {
            width=a;
            height=b;
        }
        virtual int area (void) =0;
};

class CRectangle: public CPolygon
{
    public:
        int area (void) { return (width * height); }
};

class CTriangle: public CPolygon {
    public:
        int area (void) {
            return (width * height / 2);
        }
};

int main ()
{
    CRectangle rect;
    CTriangle trgl;
    CPolygon * ppoly1 = &rect;
    CPolygon * ppoly2 = &trgl;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    cout << ppoly1->area() << endl;
    cout << ppoly2->area() << endl;
    return 0;
}


























