#include<iostream>
#include<cmath>
using namespace std;

int *find_max_crossing(int *arr, int low, int mid, int high){
    int max_left=-9999, max_right=-9999;
    int left_index, right_index;
    int sum=0;
    for (int i=mid; i>=low; i--){
        sum=sum+arr[i];
        if (sum>max_left){
            max_left=sum;
            left_index=i;
        }
    }

     sum =0;
     for (int i=mid+1; i<=high; i++)
        {
        sum=sum+arr[i];
        if (sum>max_right)
            {
            max_right=sum;
            right_index=i;
        }
    }
    int *res=new int [3];
    res[0]=left_index;
    res[1]=right_index;
    res[2]=max_left+max_right;
    return res;
}

int *find_max_subarray(int *arr, int low, int high){

    if (low==high){
        int *res=new int [3];
        res[0]=low;
        res[1]=high;
        res[2]=arr[low];
        return res;
    }
    else {

        int mid=floor((low+high)/2);
        int *left_result = find_max_subarray(arr,low,mid);
        int *right_result = find_max_subarray(arr,mid+1,high);
        int *crossing_result = find_max_crossing(arr,low,mid,high);

        if (left_result[2]>=right_result[2] && left_result[2]>=crossing_result[2]){
            return left_result;
        }
        else if (right_result[2]>=left_result[2] && right_result[2]>=crossing_result[2]){
            return right_result;
        }
        else {
            return crossing_result;
        }
    }
}

int main ()
{
    int *arr = new int[5];
    for (int i=0;i<5;i++){
        cin>>arr[i];
    }
   int *result= find_max_subarray(arr,0,4);
   cout<< result[0]<< " "<< result[1]<< " "<<result[2];

    return 0;
}
