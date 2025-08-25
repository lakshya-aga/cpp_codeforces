#include <iostream>
 
using namespace std;

void solve()
{
    int n,p;
    int count=0;
    cin>>n;
    cin>>p;
    for(int k=p; k<n; k++)
    {
        int position = n%(k*2-2);
        if(!position)
        position=2*k-2;
        if(position==p || position==(2*k-p))
        count++;
    }
    cout<<count<<endl;
} 
int main()
{
    
    int n;
    cin>>n;
    while(n>0)
    {
        solve();
        n--;
    }
}
