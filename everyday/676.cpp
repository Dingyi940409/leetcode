#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 暴力解法
// 逐个比较字母，只要有一个字符串只有一个字母差别，就返回true
class MagicDictionary
{
public:
    MagicDictionary()
    {
    }
    map<int,vector<string>> m;
    void buildDict(vector<string> dictionary)
    {
        for(int i = 0;i<dictionary.size();i++)
        {
            if(m.find(dictionary[i].size())!=m.end())
            {
                m[dictionary[i].size()].push_back(dictionary[i]);
            }
            else
            {
                vector<string> v;
                v.push_back(dictionary[i]);
                m[dictionary[i].size()] = v;
            }
        }
    }

    bool search(string searchWord)
    {
        auto index = m.find(searchWord.size());
        if(index == m.end())
            return false;

        vector<string> l = index->second;
        for(int i = 0;i<l.size();i++)
        {
            int count = 0;
            string a = l[i];
            for(int j = 0;j<a.size();j++)
            {
                if(a[j] != searchWord[j])
                {
                    count++;
                }
            }
            if(count == 1)
                return true;
        }
        return false;
    }
};