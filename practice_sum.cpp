#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int num;
    int n,k,p;
    cin>>num;
    for (int i=0; i<num; i++)
    {
        cin>>n;
        cin>>k;
        cin>>p;
        k=abs(k);
        p=abs(p);
        int req = abs(k/p) + (int)(k%p>0);
        if(req>n)
        cout<<-1<< "\n";
        else
        cout<<req<< "\n";
    }
}