                       /// parenthesis using recursion

#include<iostream>
using namespace std;

int T(int i,int j,int num[],char op[])
{
    if(i==j)
    {
        return num[i];
    }
    else
    {
        int max= -9999;

        for(int k=i; k<j; k++)
        {
            int val;

            if(op[k]=='+')
            {
                val= T(i,k,num,op) + T(k+1,j,num,op);

            }

            else if(op[k]=='-')
            {
                val= T(i,k,num,op) - T(k+1,j,num,op);

            }

            else if(op[k]=='*')
            {
                val= T(i,k,num,op) * T(k+1,j,num,op);

            }

            if(val>max)
            {
                max = val;
            }

        }

        return max;

    }

}

int main()
{
    int n;
    cout<<"Enter an integer number: "<< endl;
    cin>>n ;
    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];

    }

    char op[n-1] = {'-','*'} ;

    int result = T(0,n-1,num,op) ;
    cout<<"Result is: "<<result<<endl;
}
