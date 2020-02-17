#include<vector>
#include<iostream>
#include<string>
#include<list>

template<typename T, typename V>
std::vector<typename T::iterator> findAll(T& c, V v)
{
    std::vector<typename T::iterator> iteratorList;
    for(auto it = c.begin();it!=c.end();++it)
    {
        if(*it == v)
        {
            iteratorList.push_back(it);
        }
    }

    return iteratorList;
}


template<typename container, typename predicate>
int my_count(container& c, predicate& p)
{
    int count = 0;
    for(auto it = c.begin();it!=c.end();++it)
    {
        if(p(*it))
        {
            ++count;
        }
    }
    return count;
}

template<typename T>
class greater_than
{
    public:
        greater_than(T value):
            m_value{value}
        {

        }
        bool operator()(const T& val){return val > m_value;};
    private:
        T m_value;
};

int main()
{
    std::string str{"abcaddkjfadkja"};
    for(auto it:findAll(str,'a'))
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::list<int> lst{1,2,3,4,5,6};
    for(auto it:findAll(lst,5))
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    greater_than<int> gt(3);
    std::cout << my_count(lst, gt);
    return 0;
}