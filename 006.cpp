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
    }
    return total;
}



int main()
{
    int ans,m =10;
    int days[m] = {1,2,3,4,5,6,7,8,9,10};

    ans = sum(days,days+m);
    cout << ans << endl;

    return 0;
}




