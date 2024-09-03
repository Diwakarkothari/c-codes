#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
        1
        0 1
        0 1 0
        1 0 1 0
        1 0 1 0 1
        0 1 0 1 0 1 
    */
    bool b=1;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<b<<" ";
            if(b==1)
                b=0;
            else
                b=1;
        }
        cout<<endl;
    }
    return 0;
}