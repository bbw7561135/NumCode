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

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;//vla 可变数组
    for(int i=1;i<=5;i++)
    {
        vi.push_back(i); //1 2 3 4 5
    }

    vi.insert(vi.begin()+2,-1); //insert at vi[2]

    for(int i=0;i<vi.size();i++) //1 2 -1 3 4 5
    {
        cout << vi[i] << endl;
    }

    vi.erase(vi.begin()+2);//erase -1
    for(int i=0;i<vi.size();i++) //1 2 3 4 5 again
    {
        cout << vi[i] << endl;
    }

    vi.erase(vi.begin(),vi.begin()+2);//[left,right) so it will delete vi[0] and vi[1] here
    for(int i=0;i<vi.size();i++) //3 4 5
    {
        cout << vi[i] << endl;
    }
    //vi.clear()=vi.erase(vi.begin(),vi.end())
    return 0;
}


//set集合

#include <iostream>
#include <set>

using namespace std;

int main()
{

    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);//实际上无效 因为集合不重复

    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        cout << *it << endl; //2 3 5
    } //自动去重 自动递增排序
    //find(v) 返回set中对应值为v的迭代器 set<int>::iterator it = st.find(2)
    st.erase(st.find(2));//st.erase(2);//erase 2 in set
    //不确定情况下用find找 再用erase
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        cout << *it << endl; //3 5
    } //自动去重 自动递增排序
    st.insert(7);
    st.insert(9);
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        cout << *it << endl; //3 5 7 9
    } //自动去重 自动递增排序

    set<int>:: iterator ip = st.find(7);
    st.erase(ip,st.end());//[left,right) so it will delete 7 9
    //end指向的是最后一个元素的下一个元素
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        cout << *it << endl; //3 5
    } //自动去重 自动递增排序
    cout << st.size() << endl;
    st.clear();//delete all element
    cout << st.size() << endl;
    return 0;
}


//string
