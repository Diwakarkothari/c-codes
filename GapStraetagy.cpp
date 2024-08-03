#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4][4] ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    for(int gap=0;gap<4;gap++)
    {
        for(int i=0,j=gap;j<4;i++,j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}