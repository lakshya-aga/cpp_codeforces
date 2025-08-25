#include <iostream>
// #include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int num;
    cin>>num;
    string s;
    long len;
    for (int i=0; i<num; i++)
    {
        cin>>len;
        cin>>s;
        long long count1=0, count2=0, count3=0;
        for(auto c:s)
        {
            switch(c)
            {
                case('-'): count1++;
                break;
                case('_'):count2++;
                break;
                default:      throw runtime_error("InvalidInput");

            }
        }
        count3=count1/2;
        count1=count1/2+(long long)count1%2;
        long long ans = count3*count1*count2; 
        cout<<ans<<"\n";
    }
}