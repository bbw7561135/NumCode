#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;



double TwoDimPoly(double* a, int m, int n, double x, double y) //二维多项式求值
{
    int i,j;
    double u,s,xx;
    u=0.0;
    xx=1.0;
    s=0.0;
    for(i=0;i<=m-1;i++) //推导在page5
    {
        s=a[i*n+n-1]*xx;//xx=0.0 means x^0 i.e. S0 i*n=hang n-1=last lie
        for(j=n-2;j>=0;j--)//see page5
            {
                s=s*y+a[i*n+j]*xx; //after the loop si is ok
            } //2d array becomes 1d 实际内存里面2d数组就是1d存储的
        u = u + s; //u = sum all si i.e. final ans
        xx = xx * x;

    }


    return u;
}


int main()
{

    int m = 4; //系数矩阵行数
    int n = 5; //列数
    double a[m][n] = { {1.0,2.0,3.0,4.0,5.0},
                       {6.0,7.0,8.0,9.0,10.0},
                        {11.0,12.0,13.0,14.0,15.0},
                        {16.0,17.0,18.0,19.0,20.0}};
    double x = 0.6; //待求点x坐标
    double y = -1.3;//待求点y坐标
    cout << TwoDimPoly((double *)a,m,n,x,y) << endl; //二维传递数组方法好几种
    //其他都需要给出第二维度的n 但是这个办法不要 缺点是把2D化成了1D see TwoDimPoly

    return 0;

}

//output 39.6655
//openmp需要注意到循环里面的数据竞争和可能出现的意外覆盖 比如xx和s 所以需要额外处理
