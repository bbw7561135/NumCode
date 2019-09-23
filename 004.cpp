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
