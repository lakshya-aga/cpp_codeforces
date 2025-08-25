#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
bool sortByTrailingZeros(int a1, int a2)
{
    while(a1%10==0)
    a1=a1%10;
    while(a2%10==0)
    a2=a2%10;
    return a1<a2;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int param1,m;
        cin>>param1;
        cin>>m;
        int arr[param1];
        for(int j=0; j<param1; j++)
        {
        cout<<param1<<endl;
            cin>>arr[j];
        }
        sort(arr, arr+param1, sortByTrailingZeros);
        int count=0;
        for(int j=0; j<param1; j++)
        {
            if(j%2==0) //Anna's Turn
            {
                int digits1=0, digits2=0;
                while(arr[j]%10==0)
                {
                    cout<<"stuck2";
                    digits1=digits1+1;
                    arr[j]=arr[j]/10;
                }
                digits2=digits1;
                while(arr[j]!=0)
                {
                    digits2=digits2+1;
                    cout<<"stuck3";
                    arr[j]=arr[j]/10;
                }
                count=count+digits2-digits1;

            }
            else
            {
                int digits2=0;
                while(arr[j]!=0)
                {
                cout<<"stuck";
                    digits2=digits2+1;
                    arr[j]=arr[j]/10;
                }
                count=count + digits2;

            }
        }
        if(count>m)
        cout<<"Sasha"<<endl;
        else
        cout<<"Anna"<<endl;
    }
    return 0;
}