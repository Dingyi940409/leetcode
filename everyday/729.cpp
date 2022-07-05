#include <iostream>
#include <map>
using namespace std;
/*
主要解题思路为：
依据二分法，来判断开始时间在表里面的位置，然后判断时间

map中的 lower_bound 是查找map中 第一个 大于等于 x 的值.返回过结果是一个指针.

可以根据该方法,来判断输入是否符合条件标准


*/
class MyCalendar
{
public:
    map<int, int> list;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (list.size() == 0)
        {
            list.insert(make_pair(start, end));
            return true;
        }
        auto index = list.lower_bound(start);
        if (index != list.end())
        {
            if (index->first < end)
                return false;
        }

        if (index != list.begin())
        {
            index--;
            if (index->second > start)
                return false;
        }

        list.insert(make_pair(start, end));
        return true;
    }
};