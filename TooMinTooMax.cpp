#include <iostream>
#include<algorithm>

using namespace std;
int main()
{
    int n, size;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>size;
        int a,b,c,d;
        int arr[size];
        for(int j=0; j<size; j++)
        cin>>arr[j];
        a=b=c=d=arr[0];
        for(int j=1; j<size; j++)
        {
            if(arr[j]>=d)
            {
                c=d;
                d=arr[j];
            }
            else if(arr[j]<=a)
            {
                b=a;
                a=arr[j];
            }
        }
        cout<<(2*(d+c) - 2*(a+b))<<endl;
    }
    return 0;
}