#include<iostream>

using namespace std;

int main()
{
    int n= 4;
    int a=1;
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<i+1;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout<<a;
        }
        a++;
        cout<<"\n";
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}