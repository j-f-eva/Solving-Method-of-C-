#include<iostream>
#include<algorithm>

using namespace std;

bool max_low(int belt[], int ves, int c, int a)
{
    int sum = 0;
    for(int i= 0 ; i<c; i++)
    {
        sum+=belt[i];
        if(sum>a)
        {
            sum=0;    ///drum jump
            ves--;
            i--;
        }
        if(ves==0)
        {
            return false;
        }
    }
    return true;
}

int traverse(int arrays[], int l, int h, int belt[], int ves, int c )    //searching binary
{
    if(l==h)
    {
        return arrays[l] ;
    }

    int mid = (l+h)/2 ;
    int a = arrays[mid] ;

    if(max_low(belt, ves, c, a))

    {
        traverse(arrays, l, mid,belt, ves, c);
    }
    else
    {

        traverse(arrays, mid+1, h, belt, ves, c);
    }
}

int main()
{
    int ves, c, new_sum = 0;
    cin>>c>>ves ;
    int belt[c];

    for(int i=0; i<c; i++)   //input array
    {
        cin>>belt[i];
        new_sum+= belt[i];

    }

    int arrays[new_sum];  //for binary searching

    for(int i=0; i<new_sum; i++)
    {
        arrays[i] = i+1;
    }

    int l=1, h=new_sum;
    int res = traverse(arrays, l, h, belt, ves, c);
    cout<<res<<endl;
    return 0;
}
