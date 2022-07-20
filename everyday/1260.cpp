#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> allNum;
        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[i].size();j++)
                allNum.push_back(grid[i][j]);
        
        vector<int> m(allNum.size(),0);

        if(k == allNum.size()|| k%allNum.size() == 0)
            return grid;
        
        k = k > allNum.size() ? k % allNum.size() : k;

        int all = allNum.size();
        for(int i = 0;i<all;i++)
        {
            if(i+k<all)
                m[i+k] = allNum[i];
            if(i+k>all)
                m[i+k-all] = allNum[i];
            if(i+k==all)
                m[0] = allNum[i];
        }
        int index= 0;
        for(int i =0;i<grid.size();i++)
            for(int j = 0;j<grid[i].size();j++)
            {
                grid[i][j] = m[index];
                index++;
            }
        return grid;
    }
};

int main()
{
    vector<vector<int>> a;
    vector<int> a1;
    a1.push_back(3);
    a1.push_back(8);
    a1.push_back(1);
    a1.push_back(9);
    vector<int> a2;
    a2.push_back(19);
    a1.push_back(7);
    a1.push_back(2);
    a1.push_back(5);
    vector<int> a3;
    a2.push_back(4);
    a1.push_back(6);
    a1.push_back(11);
    a1.push_back(10);
    vector<int> a4;
    a2.push_back(12);
    a1.push_back(0);
    a1.push_back(21);
    a1.push_back(13);
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    a.push_back(a4);

    Solution s;
    s.shiftGrid(a,4);
    return 0;
}