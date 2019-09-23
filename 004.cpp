#include <iostream>

using namespace std;

int main()
{
    int updates = 6;
    int* p_updates;
    p_updates = &updates;

    //express values in two ways
    cout << "Values: updates  = " << updates <<endl;
    cout << " *updates  = " << *p_updates << endl;

    //express address in two ways
    cout << "Address updates = " << &updates <<endl;
    cout << " updates = " << p_updates << endl;

    //use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    return 0;
}

//Values: updates  = 6
// *updates  = 6
//Address updates = 0x6dfee8
// updates = 0x6dfee8
//Now updates = 7

#include <iostream>

using namespace std;

int main()
{

    double* p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    //treat p3 like noraml array but p3 is atcually pointer
    cout << "p3[1] is " << p3[1] << endl;

    p3 = p3 + 1;//normal array name can not do it while pointer can
    //here 1 refers to 8 byte as *p3 is double type //for int it is 4 byte
    //now p3 pointers to p3[1] //
    cout << "now p3[0] is " << p3[0] << endl; //0.5
    cout << "now p3[1] is " << p3[1] << endl;
    p3 = p3 - 1;
    cout << "p3[0] is " << p3[0] << endl;
    return 0;
}

//p3[1] is 0.5
//now p3[0] is 0.5
//now p3[1] is 0.8
//p3[0] is 0.2

#include <iostream>

using namespace std;

int main()
{

    double wages[3] = {10000.0,20000.0,30000.0};
    short  stacks[3] = {3,2,1};

    //Here are two ways to get the address of an array
    double* pw = wages; //name of an array = address
    short* ps = &stacks[0]; //the first element's address is also the address of an array
    //stacks = &stacks[0] = address of the first element of array
    //数组名字被解释为第一个元素的地址 但对数组名字用取地址符& 得到的值虽然和第一个地址相同 但它代表的是整个数组的地址 只不过首地址是
    //第一个元素地址 
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << " add 1 to the pw point." << endl;
    cout << "pw = " << pw << ", *pw = " << *pw << endl;

    cout << "ps = " << ps << ", *pss = " << *ps << endl;
    ps = ps + 1;
    cout << " add 1 to the ps point." << endl;
    cout << "ps = " << ps << ", *ps = " << *ps << endl;

    cout << "access two elements via array notation." << endl;
    cout << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements via pointer notation." << endl;
    cout << "*stacks = " << *stacks
         << ", *(stacks+1) = " << *(stacks+1) << endl;
    //another difference between pointer and array name
    cout << sizeof(wages) << " = size of wages array." << endl;
    cout << sizeof(pw) << " = size of pw pointer." << endl;
    return 0;
}


//pw = 0x6dfec0, *pw = 10000
// add 1 to the pw point.
//pw = 0x6dfec8, *pw = 20000
//ps = 0x6dfeba, *pss = 3
// add 1 to the ps point.
//ps = 0x6dfebc, *ps = 2
//access two elements via array notation.
//stacks[0] = 3, stacks[1] = 2
//access two elements via pointer notation.
//*stacks = 3, *(stacks+1) = 2
//24 = size of wages array.
//4 = size of pw pointer.
