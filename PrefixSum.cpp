#include <iostream>
#include<vector>
using namespace std;
int main()
{

    int arr[]={1,2,3,4};
    int n=4;
    vector<int> ans(n);
    
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    
    ans[n-1]=sum;
    for(int i=n-2;i>=0;i--)
    {
        ans[i] = sum-arr[i+1];
        sum=sum-arr[i+1];
    }
    
    for(int i :  ans)
        cout<<i<<" ";

    return 0;
}