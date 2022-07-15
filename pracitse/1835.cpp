#include <iostream>
#include <map>
#include <vector>
using namespace std;


// 位运算
// 在位运算中可以把& 当作 乘法，^ 当作加法
// & 优先级 高于 ^
// A & B ^ A & C == A & ( B ^ C)
class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int arr1ret = 0;
        for (int i = 0; i < arr1.size(); i++)
            arr1ret = arr1ret ^ arr1[i];

        int arr2Ret = 0;
        for (int j = 0; j < arr2.size(); j++)
            arr2Ret = arr2Ret ^ arr2[j];


        return arr2Ret & arr1ret;
    }
};