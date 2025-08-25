#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define LIMIT 998244353

void makeItAlternating(vector<string> inputs, long long n);
long long factorial(long long n);

long long factorial(long long n)
{
   long long ans=1;
   for(long long i=1; i<=n; i++)
   ans = (ans*i)%LIMIT;
   return ans;
}
// long long combination(long long n, long long c)
// {
//     return factorial(n)/factorial(c)/factorial(n-c);
// }

void makeItAlternating(vector<string> inputs, long long n)
{
    for(auto s: inputs)
    {
        long long coststart0 = 0;
        long long coststart1 = 0;
        long long ans1=1;
        vector<long long> costs1;
        char target = '1';
        for(long long i=0; i<s.length(); i++)
        {
            long long temp = 0;
            while(s[i]!=target && i<s.length())
            {
                coststart1++;
                i++;
                temp++;
            }
        if(temp!=0)
        ans1 = (ans1 * (temp+1))%LIMIT;
        
        target = (target=='0') ? '1' : '0';
        }

        //Try Combinations followed by permutations. Take N+1CN. Factorial(numberofOps)
        
        ans1 = (ans1*factorial(coststart1))%LIMIT;

        // Calculating costs of making 01010101
        long long ans0=1;
        vector<long long> costs0;
        target = '0';
        for(long long i=0; i<s.length(); i++)
        {
            long long temp = 0;
            while(s[i]!=target && i<s.length())
            {
                coststart0++;
                i++;
                temp++;
            }
        target = (target=='0') ? '1' : '0';
        if(temp!=0)
        ans0 = (ans0 * (temp+1))%LIMIT;

        }
        ans0 = (ans0*factorial(coststart0))%LIMIT;
        // cout<<min(coststart0, coststart1)<<endl;

        long long numWays = 0;
        // cout<<coststart0<<" "<<coststart1<<endl;
        if(coststart0 == coststart1)
        numWays = ans0 + ans1;
        else if(coststart0 < coststart1)
        numWays = ans0;
        else
        numWays = ans1;
        std::cout<<min(coststart0, coststart1)<<"  "<<numWays<<endl;
    }
}

int main()
{
    long long n;
    // cout<<"Enter number of inputs"<<endl;
    cin>>n;
    //Number of inputs
    string input;
    vector<string> inputs;
    for(long long i=0; i<n; i++)
    {
        cin>>input;
        inputs.push_back(input);
    }
    makeItAlternating(inputs, n);
    return 0;
}


// 0  1
// 0  1
// 0  1
// 1  2
// 1  1
// 0  1
// 1  2
// 0  1
// 1  2
// 2  6
// 2  2
// 1  1
// 0  1
// 1  1
// 2  6
// 1  2
// 0  1
// 1  2
// 2  4
// 1  2
// 2  6
// 3  24
// 3  6
// 2  2
// 1  1
// 2  1
// 1  1
// 0  1
// 1  1
// 2  2
// 3  24
// 2  6
// 1  2
// 2  4
// 1  2
// 0  1
// 1  2
// 2  6
// 3  12
// 2  4
// 1  2
// 2  4
// 3  12
// 2  6
// 3  24
// 4  120
// 4  24
// 3  6
// 2  2
// 3  2
// 2  1
// 1  1
// 2  1
// 3  2
// 2  2
// 1  1
// 0  1
// 1  1
// 2  1
// 1  1
// 2  2
// 3  6
// 4  120
// 3  24
// 2  6
// 3  12
// 2  4
// 1  2
// 2  4
// 3  12
// 2  6
// 1  2
// 0  1
// 1  2
// 2  4
// 1  2
// 2  6
// 3  24
// 4  48
// 3  12
// 2  4
// 3  8


















// 1
// 0
// 10
// 11
// 00
// 01
// 100
// 101
// 110
// 111
// 000
// 001
// 010
// 011
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 10000
// 10001
// 10010
// 10011
// 10100
// 10101
// 10110
// 10111
// 11000
// 11001
// 11010
// 11011
// 11100
// 11101
// 11110
// 11111
// 00000
// 00001
// 00010
// 00011
// 00100
// 00101
// 00110
// 00111
// 01000
// 01001
// 01010
// 01011
// 01100
// 01101
// 01110
// 01111
// 100000
// 100001
// 100010
// 100011
// 100100
// 100101
// 100110
// 100111
// 101000
// 101001
// 101010
// 101011
// 101100
// 101101
// 101110






















// 0 1
// 0 1
// 0 1
// 1 2
// 1 2
// 0 1
// 1 2
// 0 1
// 1 2
// 2 6
// 2 6
// 1 2
// 0 1
// 1 2
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 3 24
// 2 6
// 1 2
// 2 8
// 1 2
// 0 1
// 1 2
// 2 6
// 3 24
// 2 6
// 1 2
// 2 8
// 1 2
// 0 1
// 1 2
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 3 24
// 4 120
// 4 120
// 3 24
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 4 120
// 3 24
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 4 192
// 3 36
// 2 8
// 3 48
// 2 8
// 1 2
// 2 8
// 3 36
// 4 216
// 3 36
// 2 6
// 3 36
// 4 192
// 3 24
// 4 120
// 5 720
// 5 720