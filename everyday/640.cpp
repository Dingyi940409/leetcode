#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

string solveEquation(string equation)
{
    int coefficient = 0, constant = 0;
    int i = 0, length = equation.size(), sign = 1;
    while (i < length)
    {
        // 到了等式右面,需要包所有数字 * -1 移动到左边计算
        if (equation[i] == '=')
        {
            sign = -1;
            i++;
            continue;
        }

        
        int num = 0;
        bool isNum = false;
        int signIn = sign;
        // 先判断接下来是加号还是减号
        if (equation[i] == '-' || equation[i] == '+')
        {
            signIn = (equation[i] == '-') ? -signIn : signIn;
            i++;
        }
        // 获取接下来的字符是否是数字
        while (i < length && isdigit(equation[i]))
        {
            num = num * 10 + equation[i] - '0';
            i++;
            isNum = true;
        }

        // 下一字符是x的话,计算x的系数
        if (equation[i] == 'x')
        {
            coefficient = coefficient + (isNum ? (num * signIn) : signIn);
            i++;
        }
        //否则直接将数字加起来计算出常数的数值
        else
        {
            constant = constant + signIn * num;
        }
    }

    if (coefficient == 0)
        return constant == 0 ? "Infinite solutions" : "No solution";
    
    return string("x=")+to_string(-constant / coefficient);
}

int main()
{
    string retS = solveEquation("x+5-3+x=6+x-2");
    cout << retS << endl;
    return 0;
}