#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void ABBCDorBACD(string s)
{
    
    int ans0 = 0;
    int ansTemp = 0;
    int smallest = -1;
    for(int i = 0; i<s.length(); i++)
    {
    if(s[i]=='A')
    ansTemp++;
    if(s[i]!='A' || i==s.length()-1) {
        ans0 += ansTemp;
        if(ansTemp < smallest || smallest == -1)
        smallest = ansTemp;
        ansTemp = 0;
    }
    }
    if(s[0] == 'B' || s[s.length()-1] == 'B')
    cout << ans0 << endl;
    else
    cout << ans0 - smallest << endl;

}
int main()
{
    int n;
    cin>>n;
    //Number of inputs
    string input;
    
    for(int i=0; i<n; i++)
    {
        cin>>input;
        ABBCDorBACD(input);
    }
}
   

