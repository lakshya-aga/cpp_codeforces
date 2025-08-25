#include <iostream>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);

    int num;
    cin>>num;
    int len; 
    int target=0, less_count=0, greater_count=0, L=0, R=0;
    for (int i=1; i<=num; i++)
    {
        cin>>len;
        int a[len];
        for(int j=0;j<len; j++)
            cin>>a[j];
        target = 0;
        less_count = 0;
        greater_count = 0;
        L=1;
        R=1;
        for (int j=0; j<len; j++)
        {
          less_count = 0;
          greater_count = 0;
          for(int k=j+1; k<len; k++)
          {
            less_count += a[j]>a[k];
            greater_count += a[j]<a[k];
            if(less_count - greater_count > target)
            {
                L=j+1;
                R=k+1;
                target = less_count - greater_count;
            }
          }
        }
        // cout<<'\n'<<target<<" Debug"<<'\n';
        cout<<L<<" "<<R<<'\n';
    }
    
}