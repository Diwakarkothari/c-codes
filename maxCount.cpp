#include<iostream>
using namespace std;

int main()
{
    int n=14;
    int arr[n]={1,1,2,2,2,2,2,5,5,5,5,6,6,6};
    int count=1;
    int maxi=1;
    int ans;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
            count++;
        else
        {
            int temp=maxi;
            maxi=max(count,maxi);
            if(maxi!=temp)
                ans=arr[i-1];
            count=1;
        }
    }
    cout<< ans<<" "<<maxi<<endl;
    return 0;
}