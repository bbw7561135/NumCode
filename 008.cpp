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


#include <iostream>
#include <string>

using namespace std;

int main()
{

    string str = "abcde";
    for(int i=0;i<str.length();i++) //str.length is unsigned
    { //length()==size()
        cout << str[i] << endl;
    }
    //读入和输出整个字符串用cin和cout
    //string str1;
    //cin>>str1;
    //cout << str1 << endl;

    for(string::iterator it = str.begin(); it != str.end();it++)
    {
        cout << *it << endl;
    }

    string str1 = "fghijk";
    string str2;
    str2 = str + str1;
    cout << str2 << endl;
    //还可以比较大小 按照字典序列

    //insert(pos,string) insert string at pos
    str.insert(0,str1);//"XXX" is also ok
    cout << str << endl;
    str = "abcde";
    cout << str << endl;
    str.insert(str.begin()+1,str1.begin(),str1.end());//aXbcde put str2 into X pos
    cout << str << endl;//afghijkbcde
    str.erase(str.begin());//fghijkbcde
    cout << str << endl;
    str.erase(str.begin()+1,str.end());//f //[left,right)
    cout << str << endl;
    str = "abcde";
    cout << str << endl;//abced
    str.erase(1,4);//erase(pos,length) //a 删除从pos开始 长度为length的字符串
    cout << str << endl;
    str.clear();// 清空字符串
    cout << str.length() << endl;
    str = "abcde";
    cout << str << endl;//abced
    cout << str.substr(0,3) << endl;//substr(pos,length) return sub str 从pos开始 长度为length字符子串
    //str.find(str2) 当str2是子串时 返回其第一次出现的位置 如果不是 返回string::npos
    //str.find(str2,pos) 从str的pos开始匹配str2 成功返回第一次的位置 如果不是返回string::npos
    if(str.find("abc") != string::npos)
    {
        cout << str.find("abc") << endl;
    }
    if(str.find("cde",1) != string::npos)
    {
        cout << str.find("cde",1) << endl;
    }
    //str.replace(pos,len,str2) 把str从pos开始长度为len的子串替换为str2
    //str.replace(it1,it2,str2) 把迭代器[it1,it2)范围内的子串替换为str2
    cout << str.replace(0,1,"z") << endl;//zbcde
    return 0;
}

//map映射不太常用 类似字典一样 一一对应

//queue 队列 先进先出

#include <iostream>
#include <queue>

using namespace std;

int main()
{

    queue<int> q;
    for(int i=1; i<=5; i++)
    {
        q.push(i);//入队
    }
    //queue是先进先出的限制性数据结构 在STL中只能通过front访问队首
    //使用back访问队尾
    cout << q.front()<<'\t'<<q.back()<<endl;
    q.pop();//出队 此时为2 3 4 5
    cout << q.front() << endl;
    cout << q.size() << endl;
    //empty() return true or false
    if(q.empty()==true)
    {
        cout << "empty queue." << endl;
    }
    else
    {
        cout << "Not empty." << endl;
    }
    return 0;
}
//高级队列包括双端队列deuqe和优先队列
//优先队列只有top元素 最高优先级的都在前面 不管你push什么进来
//优先队列底层实现是靠堆heap


//stack 后进先出
#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<int> st;
    for(int i=0; i<=5; i++)
    {
        st.push(i);//入栈 lifo
    }
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    //也有empty size 等函数
    //stack用来递归
    return 0;
}

//算法头文件 algorithm

