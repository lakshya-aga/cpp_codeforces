
#include <iostream>

#include <vector>
using namespace std;

struct DSU {
    vector<int> p, r;
    int comp;
    DSU(int n) : p(n), r(n) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    }
    int find(int v) {
        return (p[v] == v) ? v : p[v] = find(p[v]);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        comp--;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector< vector<int> > graph;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        graph.push_back({a,b});
    }

    
    for(int i=1; i<=n; i++)
    {
       int deg=0;
       int cost=0;
       DSU dsu(n);
       vector< vector<int> > graph_temp;
       vector< vector<int> > graph_ans;
       for(auto edge : graph)
       {
        if(edge[0]!=i && edge[1]!=i)
        {
            graph_temp.push_back({edge[0],edge[1]});
            
        }
        else deg++;
       }
       int remove=--deg;
        vector< vector<int> > candidateList;
        for(int k=1; k<n; k++)
        if(k!=i && k+1!=i)
        candidateList.push_back({k,k+1});
        candidateList.push_back({i-1,i+1});
        for(auto edge: graph_temp)
            dsu.join(edge[1], edge[0]);
        for(auto edge: candidateList)
        {
            if(deg==0)
            break;
            else if(dsu.join(edge[1], edge[0]))
            {
                deg--;
                cost+=max(edge[0]-edge[1],edge[1]-edge[0]);
                graph_ans.push_back(edge);
            }
        }
        cout<<cost<<" "<<remove<<endl;
        for(auto edge: graph_ans)
        cout<<edge[0]<<" "<<edge[1]<<endl;
        cout<<endl;
       
    }
}
int main()
{
    
    int n;
    cin>>n;
    while(n>0)
    {
        solve();
        n--;
    }
}