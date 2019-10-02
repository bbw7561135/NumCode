//STL 标准模板库

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    for(int i=1;i<=5;i++)
    {
        vi.push_back(i);//在vector末尾添加x
    }
    //vi.begin为vi的首元素地址 而it指向这个地址
    //vi.end不是最后一个元素的地址 而是最后一个元素的后面一个地址
    //而且vector迭代器不支持it<vi.end的写法 要用it != vi.end()
    //for(it=vi.begin();it!=vi.end();it++)
    //在STL中 只有vector和string支持使用vi.begin()+3这样的写法
    vector<int> ::iterator it = vi.begin();
    for(int i=0;i<5;i++)
    {
        cout << *(it+i) << endl;
    }
    for(int i=0;i<vi.size();i++) //vi.size()
    {
        cout << vi[i] << endl;
    }
    return 0;
}i


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    for(int i=1;i<=3;i++)
    {
        vi.push_back(i);
    }

    vi.pop_back();//delete last element

    for(int i=0;i<vi.size();i++) //vi.size() is unsigned
    {
        cout << vi[i] << endl;
    }

    vi.clear(); //clear all element
    cout << "size is " << vi.size() << endl;

    return 0;
}


