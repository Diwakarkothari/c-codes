#include<iostream>
using namespace std;
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1)
            return 0;
            
        if(arr[0]==0)
            return -1;
            
        int maxr=arr[0],step=arr[0],jump=1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1 && step)
                return jump;
            maxr=max(i+arr[i],maxr);
            step--;
            if(step<0)
                return -1;
            if(step==0)
            {
                jump++;
                if(i>maxr)
                    return -1;
                step = maxr-i;
            }
        }
    }
};