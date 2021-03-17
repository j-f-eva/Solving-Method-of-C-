
//Offline- 1

#include <iostream>
#include <bits/stdc++.h>
#include<cmath>
#include<chrono>
using namespace std;


///implementation of algo-3,using algo-2.


bool basicPrime(int a)
{
    for(int i=2; i<=sqrt(a); i++){ ///checking prime numbers.
        if(a%i==0){
            return false;
        }
    }
    return true;
}

void basicPrint(int value)
{
    cout<<"Basic Prime Number : \n"<<endl;

    for (int i=2; i<=value; i++){

        if(basicPrime(i)==true){


            cout<<i<<" ";
        }
    }

    cout<<"\n\n"<<endl;
}


///checking prime Number using Seive algorithm.


void sievePrimeNumber(int number)
{
    bool array[number];
    memset(array, true, sizeof(array));  //index er value initialize
        for(int i=2; i<=sqrt(number); i++){

          if (array[i]==true){

            for(int j=i*i; j<=number; j=i+j){    ///delete non prime number.

                array[j]=false;
            }
        }
    }
    cout<< "Sieve Prime Number : \n"<<endl;

    for (int i=2; i<=number; i++){

        if (array[i]==true){

            cout<<i<<" ";
        }
    }

    cout<<"\n\n"<<endl;
}


int main ()
{
    auto start = chrono::high_resolution_clock::now();

    basicPrint(1000);
    sievePrimeNumber(1000);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout<<"Run Time: "<<setprecision(20)<<duration.count()<<endl;

}


