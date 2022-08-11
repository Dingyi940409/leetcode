#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;

// 暴力解法
// string reformat(string s)
// {
//     stack<char> num;
//     stack<char> str;
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         if (isdigit(s[i]))
//             num.push(s[i]);
//         else
//             str.push(s[i]);
//     }
//     int lengthgap = num.size() - str.size();
//     if (abs(lengthgap) >= 2)
//         return "";
//     string ret;

//     if (num.size() > str.size())
//     {
//         while (!str.empty())
//         {
//             ret = ret + num.top();
//             ret = ret + str.top();
//             num.pop();
//             str.pop();
//         }
//         ret = ret + num.top();
//     }
//     else
//     {
//         if (num.size() < str.size())
//         {
//             while (!num.empty())
//             {
//                 ret = ret + str.top();
//                 ret = ret + num.top();
//                 num.pop();
//                 str.pop();
//             }
//             ret = ret + str.top();
//         }
//         else
//         {
//             while (!str.empty())
//             {
//                 ret = ret + num.top();
//                 ret = ret + str.top();
//                 num.pop();
//                 str.pop();
//             }
//         }
//     }

//     return ret;
// }

string reformat(string s)
{
    int num = 0;
    int cnum = 0;
    string ret = s;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            num++;
        else
            cnum++;
    }
    if (abs(cnum - num) > 2)
        return "";
    if (cnum > num)
    {
        cnum = 0;
        num = 1;
    }
    else
    {
        cnum = 1;
        num = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            ret[num] = s[i];
            num += 2;
        }
        else
        {
            ret[cnum] = s[i];
            cnum += 2;
        }
    }
    return ret;
}

int main()
{
    string a = reformat("ab123");
    cout << a << endl;

    a = reformat("a0b1c2");
    cout << a << endl;

    a = reformat("covid2019");
    cout << a << endl;
}