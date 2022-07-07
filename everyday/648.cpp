#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力解法 先将前缀字母和对应的所有的字符串塞入到一个map中
// 再将该字符串排序
// 遍历目标字符串，进行匹配。
// 利用 首字母和 string.find 方法进行查找
string replaceWords(vector<string> &dic, string secne)
{
    map<char, vector<string>> list;
    for (auto i = 0; i < dic.size(); i++)
    {
        char c = dic[i][0];
        if (list.find(c) == list.end())
        {
            vector<string> sl;
            sl.push_back(dic[i]);
            list[c] = sl;
        }
        else
        {
            list[c].push_back(dic[i]);
        }
    }

    for (auto i = list.begin(); i != list.end(); i++)
    {
        vector<string> nsl = i->second;
        sort(nsl.begin(), nsl.end());
        i->second = nsl;
    }

    string ret;
    string rets;
    int i = 0;

    while (i != secne.size())
    {
        if (secne[i] != ' ')
        {
            rets = rets + secne[i];
        }
        if(secne[i] == ' ' || i == secne.size()-1)
        {
            if (list.find(rets[0]) == list.end())
            {
                if (ret.size() == 0)
                    ret = ret + rets;
                else
                    ret = ret + ' ' + rets;
            }
            else
            {
                vector<string> ll = list[rets[0]];
                string a;
                int i = 0;
                for (; i < ll.size(); i++)
                {

                    if (rets.find(ll[i]) == 0)
                    {
                        a = ll[i];
                        break;
                    }
                }
                if (a.size() == 0)
                    a = rets;
                if (ret.size() == 0)
                    ret = ret + a;
                else
                    ret = ret + ' ' + a;
            }
            rets = "";
        }
        i++;
    }
    return ret;
}