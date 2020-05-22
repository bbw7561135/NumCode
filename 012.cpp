//初始化数组
int codes[10] = {1,2,3,4,5,6,7,8,9,10}
int codes[10] = {0}; //in C++ all sets to 0
int codes[10] = {1,2}; //只有前两个设置位1 2 其他垃圾值
int codes[10]; //都垃圾值
//利用for循环完成数组初始化赋值
//遍历数组可用下标或指针
//二维数组的遍历利用指针要注意 a[i][j]  *(*(a+i)+j))
//数据结构C语言1000个问题与解答也可以作为handbook 很多实用的例子
//不要返回局部函数变量的地址 因为局部变量存在栈区 栈区开辟的数据由编译器自动释放 函数结束后自动回收
//堆区由程序员分配释放,若程序员不释放,程序结束时由操作系统回收 在C++中主要利用new在堆区开辟内存
//很多细节的地方可以参考仓库里面的Cpp-0-1-Resource