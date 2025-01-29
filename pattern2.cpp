#include<iostream>
using namespace std;
int main()
{
    int maxi=10;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<maxi-1;j++)
        {
            cout<<0<<" ";
        }
        cout<<maxi<<" ";
        maxi--;
        cout<<endl;
    }
    return 0;
}