#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);

    long long num;
    cin>>num;
    long long n;
    for (long long i=0; i<num; i++)
    {
        cin>>n;
        if(floor(sqrt(n*(n+1)/2))==ceil(sqrt(n*(n+1)/2)))
        cout<<-1;
        else
        {
            for(long long j=1; j<=n; j++)
            {
                if(floor(sqrt(j*(j+1)/2))==ceil(sqrt(j*(j+1)/2)))
                {
                cout<<j+1<<" ";
                cout<<j<<" ";
                j++;
                }
                else cout<<j<<" ";
            }
        }
        cout<<'\n';

    }
    
}