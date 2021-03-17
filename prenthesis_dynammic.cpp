/// parenthesis using DP

#include<iostream>
using namespace std;

int T(int i,int j,int n,int num[],char op[])
{
    int val[n][n] ;
    int temp_value = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            val[i][j] = -1;      //2d array initially -1

            if(i==j)
            {
                val[i][j] = num[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n ; j++)
        {
            int max = -99999;

            if(i!=j)
            {
                if(i<j)
                {
                    for(int k=i; k<j; k++)
                    {
                        int temp_val;

                        if(op[k]=='+')
                        {
                            temp_val  = val[i][k] + val[k+1][j] ;

                        }

                        else if(op[k]=='-')
                        {
                            temp_val  = val[i][k] - val[k+1][j] ;
                        }

                        else if(op[k]=='*')
                        {
                            temp_val  = val[i][k] * val[k+1][j] ;
                        }
                        if(temp_val> max)
                        {
                            max = temp_val;
                        }

                    }
                    val[i][j] = max ;
                }

                if(i>j)
                {
                    for(int k=j; k<i; k++)
                    {
                        int temp_val;

                        if(op[k]=='+')
                        {
                            temp_val  = val[j][k] + val[k+1][i] ;

                        }

                        else if(op[k]=='-')
                        {
                            temp_val  = val[j][k] - val[k+1][i] ;
                        }

                        else if(op[k]=='*')
                        {
                            temp_val  = val[j][k] * val[k+1][i] ;
                        }
                        if(temp_val> max)
                        {
                            max = temp_val;
                        }

                    }
                    val[i][j] = max ;
                }

            }
        }


    }
    int highest = -999999;

    for(int i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if( val[i][j] >  highest)
            {
                 highest= val[i][j] ;
            }
        }
    }
    return  val[0][n-1];
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

    int result = T(0,n-1,n,num,op) ;
    cout<<"Result is: "<<result<<endl;
}
