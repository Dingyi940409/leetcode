// 快速幂运算
//暴力进行for即可
// x 的n次方等于 x的 n/2次方 * x的n/2 次方,由此可以得出二分法的处理方法
// 需要特别注意的是- 2 的31次方取正会超过int范围，所以需要特别处理

#include<iostream>
using namespace std;

double getRet(int x,long long n)
{
    if(n == 1)
        return x;
    if(n %2 == 0)
    {
        double ret = getRet(x,n/2);
        return ret * ret;
    }
    else
    {
        double ret = getRet(x,n/2);
        return ret * ret * x;
    }
}

double quickPox(double x, int n)
{
    if(n == 0 || x == 1)
        return 1;
    if(n == 1)
        return x;
    
    double ret = getRet(x,abs(n));
    return n > 0 ? ret : 1/ret;
}

int main()
{
    double x;
    int n;
    cin >>x>>n;
    cout<<quickPox(x,n)<<endl;
    return 0;
}
