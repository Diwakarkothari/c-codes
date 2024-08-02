#include<iostream>
using namespace std;
long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long int sum=0;
        long long int maxi=arr[0];
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            maxi=max(maxi,sum);
            if(sum<0)
                sum=0;
        }
        
        return maxi;
    }