#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define int long long
void solve()
{
    int size;
    cin>>size;
    int arr[size], cnt1[size+1], cnt2[size+1];
    for(int j=0; j<=size; j++)
        cnt1[j]=cnt2[j]=0;
    
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
        if(arr[i]<size)
        cnt2[arr[i]]++;
    }
    int mex2 = 0, mex1=0;
    while(cnt2[mex2])
    mex2++;
    for(int i=0; i<size; i++)
    {
        cnt1[arr[i]]++;
        cnt2[arr[i]]--;

        if(cnt2[arr[i]]==0 && arr[i]<mex2)
        mex2 = arr[i];

        while(cnt1[mex1])
        mex1++;
        while(mex2>0 && !cnt2[mex2-1])
        mex2--;

        if(mex1==mex2)
        {
            std::cout<<2<<endl;
            std::cout<<1<<" "<<i+1<<endl;
            std::cout<<i+2<<" "<<size<<endl;
            return;
        }
    }
        std::cout << "-1\n";

}

signed main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        solve();
    return 0;
}