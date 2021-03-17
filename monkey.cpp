//monkey test
#include<iostream>
#include<algorithm>
using namespace std;

bool monkey_test(int denotes[],int n, int k)
{
    for(int i =0; i<n;i++)
    {
        if(denotes[i]==k)
        {
            k-- ;
        }
        else if(denotes[i]>k)
        {
            return false ;
        }
    }
    return true ;
}

int main()
{
    int high,temp=0,n;
    cin>>n ;
    int denotes[n] ;

    for(int i=0; i<n; i++)
    {
        cin>>high ;
        denotes[i] = high -temp;
        temp= high ;

    }

    int array[high];

    for(int i=0; i<high; i++)
    {
        array[i] = i+1;
    }

    int h = high-1, low= 0;
    while(low<h) ;
    {
        int mid= (low+h)/2 ;
        int k= array[mid];

        if(monkey_test( denotes,n,k))
    {
        h= mid;
    }

     else
    {
        low = mid +1;
    }
}
cout<<array[h]<<endl ;
    return 0;
}
