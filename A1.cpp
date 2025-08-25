#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
       int j;
       string str;
       cin>>j;
       cin>>str;
       string str2 = string(str.rbegin(), str.rend());

       if(str.compare(str2)<=0 || j==0)
       cout<<str<<endl;
       else cout<<str2+str<<endl;

    }
}