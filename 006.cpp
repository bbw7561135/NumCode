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




