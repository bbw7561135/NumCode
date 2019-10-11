// 防止头文件被重复引用 应当用 ifndef define endif结构产生预处理块
// 用#include<XX.h>格式来引用头文件 编译器将从标准库目录开始引用
// 用#include "XX.h"格式来引用头文件 编译器将从用户的工作目录开始搜索
// 头文件中只存放声明 而不存放定义（也叫做实现 implementation）
// C++语法中 类的成员函数可以在声明时候就给出定义 编译器自动视其为内联函数 但不建议那么做 声明就是声明 定义就是定义 要分开
// 不提倡使用全局变量 尽量不要在头文件中出现extern int value这类声明

//头文件结构示例 .h

//版权和版本声明

#ifndef XX_H //防止重复定义
#define XX_H

#include <math.h> //标准库文件

#include "myheader.h" //非标准库文件

void Function(); //全局函数声明

class Box
{

}; //类声明

#endif

//定义文件的结构示例 .cpp

//版本和版权声明

#include "XX.h" //引用头文件

//全局函数的定义或实现
void Funtion()
{

}

//类成员函数的实现体

void Box::Draw(...)
{

}


//头文件用来调用库功能 同时可以加强类型安全检查 总之是好的

//目录结构 大型程序 头文件专门放在include目录 定义文件放在source目录 并且可以是多级目录

//每个类声明之后 每个函数定义结束之后都加空行

//在某个函数体内 逻辑上密切相关的语句之间不加空行 其他地方应该加空行分隔 但是编程每个人都有自己的style不强求 清晰明白就行

//一行代码最好只做一件事 如只定义一个变量或只写一条语句 代码容易阅读 方便写注释 对声明指针特别有用

//if for while do 语句各自占一行 执行语句不得紧跟其后 不论执行语句有多少都要加{} 防止书写错误

//尽量在定义的时候初始化变量 

//关键字之后要留空格 比如const case virtual这些 if for while这些关键字之后也应该留一个空格

//函数名之后不要留空格 直接跟左括号(

// 二元操作符前后要留空格 3 + 4 一元操作符前后不留空格 比如 &a i++

//-> . []等操作符前后不加空格

// {}各占一列并对齐 与调用它们的语句左对齐

//指针修饰符靠近哪个的问题 是int* a 还是int *a 建议是 int *a 也就是应该将修饰符* &紧靠变量名

//注释精要为上 改代码就修改相应的注释

//类的声明中 pub开始 还是pri开始写 因人而异

//变量命名建议匈牙利法 主要思想是在变量和函数名前面加入前缀增加人们对程序的理解 现在的ide都有自动补全功能 变量多几个字并不麻烦
//特别是指针这些变量 多个p可以清楚明了

//不要出现仅靠大小写区分的变量或函数 x X FOO foo等

//不要出现标识符完全相同的局部变量和全局变量 虽然两者的作用域不同不会发生语法错误 但是会造成误解

//避免名字中出现数字编号

//类名和函数名用驼峰法 GetValue（） 而变量和参数用小写 num

//常量用全大写字母

//静态变量前面加s_

//如果不得已使用全局变量 记得加g_

//类的数据成员加前缀m_ 避免与类的函数成员的参数同名
// void Object::SetValue(int width, int height)
// {
//    m_width = width;
//    m_height = height;
// }

// 如果代码行中的运算符比较多 用括号确定表达式的操作顺序 避免使用默认的优先级 优先级比较难记

//不要写太复杂的复合表达式

//不要将布尔变量直接与TRUE FALSE 或者 1 0 进行比较
//也就是如果布尔变量为flag 它与零值比较的标准if语句为 if(flag) //flag is true
// if(!flag) //flag is false
//其他都是不良风格 比如 if(flag==TRUE) if(flag==1)

//整型变量与0比较时 用 == 或者 ！= if(value==0) if(value != 0) 而不要模仿布尔值的用法 if(value) if(!value) 会让人误会value是布尔变量

//浮点数与0的比较不可用== 或者！= 要转化为<= 或者 >=某个误差范围eps

//指针变量与零值的比较用 ==NULL ！=NULL

//注意=和==的差别 p=NULL 与 p==NULL有差别 有时候为了防止这个 有人写成NULL==P 来表示比较 因为NULL=p过不了编译器

//多重循环中 有可能的话 将最长的循环放在最内层 最短的循环放在最外层 减少CPU跨切循环层的次数

//不要在循环体内修改循环变量 防止for循环失去控制

//每个case语句结尾别忘记break及最后的default分支 switch比多重嵌套if好

//goto语句有利有弊 但是最好用的地方是在多重循环中一下子跳出循环 管你几重循环 但是少用慎用

//在C++程序中只使用const取代define

//类中的const需要慎重 很多情况可能不是你期望的 可以用枚举替代 但是枚举大小有限 或者利用构造函数设计 参考林锐高质量C++编程

//C语言函数参数有值传递 指针传递 C++多了引用传递 引用看似像指针 使用方式却像值传递 需要时参考书籍

//函数参数书写请完整 不要贪图省事只写类型而不写名字 参数命名要恰当 顺序要合理 要容易理解

//如果参数是指针 且仅作输入用 则应在类型前面加const 以防止指针在函数体内被意外修改

//如果输入参数以值传递方式传递 用const &引用传递 节省临时对象的构造和析构过程 提高效率

//避免太多参数 控制在5个内 尽量不要使用类型和数目不确定的参数

//不要省略返回值的类型 函数功能要单一 不要设计多用途的函数 函数规模宜小

//引用是C++的概念 容易与指针混淆 int m int&n=m 那么n是m的引用 m是被引用物 对n的任何操作就是对m的操作 引用在创建的时候就得被初始化

//并且引用一旦被初始化就不能改变引用的关系 上面的描述没有体现引用的价值 引用的主要功能是传递函数的参数和返回值 引用传递的性质像指针传递

//但是引用又不能像指针那样对内存随意操作 引用比较安全（只能操作被引用物）同时又兼顾效率 不需要像值传递那样建立拷贝

//静态存储区---程序编译时就已分配好 在整个程序运行期间都存在 全局变量 static变量都存在静态存储区

//栈---程序运行期间函数内部局部变量就在栈上 函数执行完毕存储单元自动释放 效率高 但是容量有限

//堆---动态分配内存 new malloc就是从堆上申请 生存期由用户决定 使用非常灵活 问题最多

//先分配 再初始化 别越界 用完释放 释放后记得把相应指针设为NULL 别出现野指针

//malloc和new要确保申请OK后使用 如果返回NULL 表示申请失败 别使用NULL指针

//new来的数组记得赋初值 不要越界

//数组赋值可以用循环 字符串数组赋值和比较可以用strcpy strcmp

//return语句不要返回指向栈内存的指针 栈的内存在函数结束时自动消亡

//指针使用时 如果指向字符串 特别是常量字符串要小心 因为常量字符串存储在静态存储区

//函数实现和动态申请内存有关 并返回申请动态内存的要特别小心出错 参考林锐高质量C++编程第七章

//malloc free //new delete要配对使用 使用要点参考林锐

//多用指针 程序效率提高 用调试器逐步跟踪程序发现问题本质

//并非所有的对象都会使用拷贝构造函数和赋值函数 倘若类中有指针变量 就要仔细思考默认的拷贝构造函数和赋值函数有没有错误
//两者采用位拷贝而不是值拷贝 有必要最好自己写

//需要使用大于32767的整数用long 全局变量和函数可以有多处"声明" 但是定义只能出现一次 




