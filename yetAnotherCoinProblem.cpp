#include <iostream>
#define MAX_INT 1000000000
using namespace std;
int arr[1000];
int minCoins(int x)
{
    if(x==1 || x==3 || x==6 || x==10|| x==15)
    {
        arr[x]=1;
    }
    else if(arr[x]==MAX_INT)
    {
        arr[x] = 1+min(min (min(arr[x-1],arr[x-3]), min(arr[x-6],arr[x-10])), arr[x-15]);
    }
    return arr[x];
}
int main()
{
    for(int i=0; i<1000000000; i++)
    arr[i] = MAX_INT;
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        
        int ans = minCoins(x);
    }
    return 0;
}