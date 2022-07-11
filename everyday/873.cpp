#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 暴力解法
int lenLongestFibSubseq(vector<int> &arr)
{
    if (arr.size() <= 2)
        return 0;

    map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
        m[arr[i]] = arr[i];

    int max = 2;

    for (int i = 0; i < arr.size() - max + 1; ++i)
    {
        int p1 = arr[i];
        for (int j = i + 1; j < arr.size() - max + 2; ++j)
        {
            p1 = arr[i];
            int p2 = arr[j];
            int l = 2;
            while (m.find(p1 + p2) != m.end())
            {
                ++l;
                p2 = p1 + p2;
                p1 = p2 - p1;
            }
            max = l > max ? l : max;
        }
    }
    return max > 2 ? max : 0;
}

int main()
{
    //[2,4,7,8,9,10,14,15,18,23,32,50]
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(14);
    arr.push_back(15);
    arr.push_back(18);
    arr.push_back(23);
    arr.push_back(32);
    arr.push_back(50);
    int max = lenLongestFibSubseq(arr);
    cout << max << endl;
}