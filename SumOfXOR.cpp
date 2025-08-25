#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define LIMIT 998244353


long long f(long long i, long long j, long long arr[], long long n)
{
    long long ans = arr[j];
    if(i>0)
    ans = (ans^arr[i-1]);
    return ans;

}
void sumOfXOR(vector<long long>inputs, long long n)
{
    long long arrXOR[n];
    long long ans = 0;
    arrXOR[0] = inputs[0];
    for(long long i=1; i<n; i++)
    {
        arrXOR[i] = (arrXOR[i-1]^inputs[i]);
        // cout<< arrXOR[i-1]<< "\t";
    }
    // cout<<arrXOR[n-1]<<endl;
    for(long long i=0; i<n; i++)
    {
        for(long long j=i; j<n; j++)
        {
            ans = (ans%LIMIT + ((j-i+1) * f(i,j, arrXOR, n)%LIMIT) )%LIMIT ;
            // cout<<(j-i+1)<<"*"<<f(i,j, arrXOR, n)<<endl;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    long long n;
    // cout<<"Enter number of inputs"<<endl;
    cin>>n;
    //Number of inputs
    long long input;
    vector<long long> inputs;
    for(long long i=0; i<n; i++)
    {
        cin>>input;
        inputs.push_back(input);
    }
    sumOfXOR(inputs, n);
    return 0;
}

