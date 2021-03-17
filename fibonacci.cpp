
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int fib_recursion(int n)
{
    if(n<=1)
    {
        return n;
    }

    return fib_recursion(n-1) + fib_recursion(n-2) ;
}

int fib_dp(int n, int* f)
{
    f[0] = 0;
    f[1] = 1;

    for(int i=2; i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
}

int main()
{
    cout<<"Using Recursion\n";
    cout<<fib_recursion(7)<<"\n";
    cout<<"Using Dynamic Programming\n";
    int* f = new int[8];
    fib_dp(7,f);
    for(int i=0; i<8; i++)
    {
        cout<<f[i]<<"->" ;
    }
return 0;
}
