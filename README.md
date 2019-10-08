# Numerical Codes with OpenMP
### 徐士良常用数值程序+OpenMP<br>


#### 001.cpp 一维多项式求值
#### 002.cpp 二维多项式求值
#### 003.cpp 多项式相乘
#### 004.cpp C++复习I 字符串操作参考string类和sstream类 特别是后者可以让字符串与数值转换方便
#### 005.cpp C++复习II 指针部分可以参考自己文件夹中的<让你不再害怕指针>文档 C++中引用和指针有差别
#### 006.cpp OpenMP&C复习
#### 007.cpp 数据结构
#### 008.cpp STL复习

#### iostram.h == iostream + using namespace std 但是前者不提倡使用
#### 需要用cin来输入字符串时 用cin.getline替代
#### 字符串转数值除了sstream类 还可以用cstdlib里面的atoi atol atof
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
