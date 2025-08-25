#include <iostream>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);

    int num;
    cin>>num;
    int n;
    for (int i=0; i<num; i++)
    {
        cin>>n;
        if(n%3==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    
}