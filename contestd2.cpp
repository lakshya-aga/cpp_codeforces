#include <iostream>
using namespace std;

int ans(int i, int a[], int n, int p)
{
    if(i < 2*n)
    return a[i];
    else
    if()
}
int main()
{
    // ios_base::sync_with_stdio(false);
    int num;
    cin>>num;
    long long n,l,r;
    for (long long i=0; i<num; i++)
    {
        cin>>n;
        cin>>l;
        cin>>r;
        long long sum=0;
        long long a[2*n+1];

        for(long long i=0;i<=r;i++)
        a[i] = 0;

        for(long long i=1;i<=n;i++)
        cin>>a[i];

        for(long long i=n+1;i<=2*n;i++)
            {
                a[i]=a[1];
                for(int j=2; j<=i/2; j++)
                a[i] = a[i]!=a[j];
            }
        int p=a[1];
        for(int i=2;i<=n;i++)
            p=p!=a[i];

        
        
        
        for(long long i=l; i<=r; i++)
        {
            sum+=ans(i,a,n,p);
        }
        // cout<<endl;
        cout<<sum<<endl;
    }
}