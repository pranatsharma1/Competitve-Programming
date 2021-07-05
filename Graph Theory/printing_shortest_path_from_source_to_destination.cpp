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




void solve()
{

    int n, m;
    cin >> n >> m;


    vector<pair<int,int>>adj[n + 1];
    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

    }

    // here source is 1 and destination is n
    vector<int>dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0, 1});

    vector<int>parent(n + 1, -1);
    parent[1] = 1;
    while(!pq.empty())
    {
        int d = pq.top().F;
        int prev = pq.top().S;

        pq.pop();

        for(auto i : adj[prev])
        {
            if(dist[prev] + i.S < dist[i.F])
            {
                dist[i.F] = dist[prev] + i.S;
                parent[i.F] = prev;
                pq.push({dist[i.F], i.F});
            }
        }
    }

    if(dist[n] == LLONG_MAX)
    {
        cout << -1 << endl; // no path exists
        return ;
    }

    vector<int>path;
    
    int cur = n;    // because destination is n
    while(cur != 1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    for(auto i : path)
        cout << i << " ";
    cout << endl;

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