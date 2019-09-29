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




