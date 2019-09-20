#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;



double OneDimPolyVal(double* a, int n, double xn) //一维多项式求值 见徐士良第五版第一页推导
{
    int i;
    double u;
    u = a[n-1];
    for(i=n-2;i>=0;i--)
    {
        u = u*xn + a[i];
    }
    return u;
}


int main()
{
    omp_set_num_threads(1);
    int i = 0;
    int n = 7; //多项式的项数
    int m = 6; //待求点的数目
    double a[n] = {-20.0,7.0,-7.0,1.0,3.0,-5.0,2.0}; //多项式的系数 从a0开始一直到an-1
    double x[m] = {0.9,-0.9,1.1,-1.1,1.3,-1.3};//待求的自变量x数组 也就是多少个待求点组成的数组
    cout << " one dimension polynome's value:" << endl;
    #pragma omp parallel for
    for(i=0;i<m;i++)
    {
        double polval = OneDimPolyVal(a,n,x[i]);
        #pragma omp critical
        {
           cout << "id: " <<omp_get_thread_num()<<endl;
           cout << "x = " << x[i] <<endl;
           cout << "p = " << polval <<endl;
           cout << "------------------------" << endl;
        }

    }

    return 0;

}


// one dimension polynome's value:
//id: 0
//x = 0.9
//p = -18.5623
//------------------------
//id: 0
//x = -0.9
//p = -26.7154
//------------------------
//id: 0
//x = 1.1
//p = -19.5561
//------------------------
//id: 0
//x = -1.1
//p = -21.513
//------------------------
//id: 0
//x = 1.3
//p = -20.8757
//------------------------
//id: 0
//x = -1.3
//p = -6.34043
//------------------------

//when use openmp the  output will be somewhat different
//openmp with 2 procs
// one dimension polynome's value:
//id: 0
//x = 0.9
//p = -18.5623
//------------------------
//id: 1
//x = -1.1
//p = -21.513
//------------------------
//id: 0
//x = -0.9
//p = -26.7154
//------------------------
//id: 1
//x = 1.3
//p = -20.8757
//------------------------
//id: 0
//x = 1.1
//p = -19.5561
//------------------------
//id: 1
//x = -1.3
//p = -6.34043
//------------------------
