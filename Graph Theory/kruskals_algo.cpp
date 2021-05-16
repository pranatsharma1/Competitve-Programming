//--------------------------------Optimizations---------------------------------//

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

//------------------------------------------------------------------------------//

//----------------------------Headers and Namespaces----------------------------//

#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//------------------------------------------------------------------------------//

//----------------------------------Defines-------------------------------------//

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define ll                  long long
#define float               long double
#define vi                  vector<int>
#define pii                 pair<int,int>
#define vpii                vector< pair<int,int> >

#define all(v)              v.begin(),v.end()
#define sz(x)               (int)x.size()
#define minv(a)             *min_element(all(a))
#define maxv(a)             *max_element(all(a))
#define sumv(a)             accumulate(all(a),0LL)

#define pb                  emplace_back
#define mp                  make_pair
#define F                   first
#define S                   second

#define mod                 1000000007
#define endl                "\n"

#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a/(__gcd(a,b)))*b

#define setbits(x)          __builtin_popcountll(x)
#define leadzero(x)         __builtin_clzll(x)
#define trailzero(x)        __builtin_ctzll(x)

#define ordered_set         tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

//------------------------------------------------------------------------------//

//-------------------------------Debgugger--------------------------------------//

#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cout << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif

//------------------------------------------------------------------------------//





//------------------------Highly Sophisticated Code Starts----------------------//

// Time Complexity : O(M*logM) where M is the number of edges
// Space Complexity : O(M) + O(N) + O(N) == O(N)

struct edge
{
    int u, v, wt;
    edge(int x, int y, int weight)
    {
        u = x;
        v = y;
        wt = weight;
    }
};

const int N = 1e5 + 5;
vector<int> parent(N);
vector<int> length(N);

void initializeDSU()
{
    for(int i = 0; i < N; i++)
    {
        parent[i] = i;
        length[i] = 1;
    }
}

int findPar(int node)
{
    if(parent[node] == node)
        return node;
    else
        return parent[node] = findPar(parent[node]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(u != v)
    {
        if(length[u] < length[v])
            swap(u, v);

        parent[v] = u;
        length[u] += length[v];
    }

}

bool cmp(edge a, edge b)
{
    return a.wt < b.wt;
}

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<edge>edges;
    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back(edge(u, v, wt));

    }    
    
    sort(edges.begin(), edges.end(), cmp);
    
    vector<pair<int,int>>mst;
    int minCost = 0;
    
    initializeDSU();
    for(int i = 0; i < (int)edges.size(); i++)
    {
        if(findPar(edges[i].u) != findPar(edges[i].v))
        {
            minCost += edges[i].wt;
            mst.push_back({edges[i].u, edges[i].v});
            Union(edges[i].u, edges[i].v);
        }
    }
    
    cout << "MST for the given graph is :\n";
    for(auto i : mst)
        cout << i.F << " -- " << i.S << endl;
    
    cout << "Cost of this MST is : " << minCost << endl;


}

int32_t main()
{

    fastIO
    cout << setprecision(15) << fixed;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": \n";
        solve();
    }

    return 0;

}