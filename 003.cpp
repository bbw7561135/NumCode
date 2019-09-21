#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;



void PolyMul(double* p, int m, double* q , int n, double* s, int k) //多项式相乘求系数
{ //推导在Page8

    int i,j;
    for(i=0;i<k;i++)
    {
        s[i]=0.0;
    }
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            {
                s[i+j] = s[i+j] + p[i]*q[j];
            }

    return;
}


int main()
{
    int m = 6;//P的项数 从常数项开始
    int n = 4;//Q的项数
    int k = m + n -1;//S=P*Q的项数
    double p[m] = {4.0,-6.0,5.0,2.0,-1.0,3.0};
    double q[n] = {2.0,3.0,-6.0,2.0};
    double s[k] ;
    PolyMul(p,m,q,n,s,k);
    for(int i=0;i<k;i++)
    {
        cout << s[i] << endl;
    }

    return 0;

}

//8
//0
//-32
//63
//-38
//1
//19
//-20
//6
