#include <iostream>
// #include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int num;
    // cout<<"Enter"<<endl;
    cin>>num;
    // num=1;
    long len; 
    int target;
    for (int i=0; i<num; i++)
    {
        cin>>len;
        // len=7;
        cin>>target;
        // target=7;
        int v=0;
        int j=0;
        for (j=0; j<len; j++)
        {
            if((j==len-1 && (v|j)!=target) || ((target|j)!=target))
            {
                v=v|target;
                cout<<target<<" ";
                j++;
                break;
            }
            
            v=v|j;
            cout<<j<<" ";
        }
        while(j<len)
        {
            j++;
            cout<<0<<" ";
        }
        cout<<'\n';
    }
}