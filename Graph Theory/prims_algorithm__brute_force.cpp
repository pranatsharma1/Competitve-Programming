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

// Time Complexity of this approach is more than O(N^2) since we are iterating on the key array N times

const int N = 1e5 + 5;
vector<pair<int,int>>adj[N];

void solve()
{

    int n, m;
    cin >> n >> m;

    // nodes are from 0 to n - 1
    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;    // 0 - based indexing

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

    }        

    vector<int>key(n, LLONG_MAX);   // stores the distance taken from any other node to reach this node.
    vector<bool>marked(n, false);   // included in MST or not
    vector<int>parent(n, -1);

    key[0] = 0; // because, we always take first node as part of MST
    parent[0] = -1;

    for(int i = 0; i < n - 1; i++) // it runs only n - 1 times because MST contains only n - 1 edges
    {
        // finding the next node to be included in MST
        int mn = LLONG_MAX, node;
        for(int j = 0; j < n; j++)
        {
            if(marked[j] == false and key[j] <= mn)
                mn = key[j], node = j;
        }

        marked[node] = true;    

        for(auto j : adj[node])
        {
            if(marked[j.F] == false and j.S < key[j.F])
                key[j.F] = j.S, parent[j.F] = node;
        }

    }

    cout << "MST of the given graph is :\n";
    for(int i = 1; i < n; i++)
        cout << parent[i] << " -- " << i << endl;
    
    int minCost = 0;
    for(int i = 1; i < n; i++)
    {
        if(key[i] != LLONG_MAX)
            minCost += key[i];
    }
    cout << "Cost of the MST is : " << minCost << endl;

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