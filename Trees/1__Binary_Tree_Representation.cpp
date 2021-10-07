#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include<bits/stdc++.h>
using namespace std;

#ifdef pranat_sharma1    
    #include "debugger.cpp"
#endif

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define float               long double
#define F                   first
#define S                   second
#define pb                  push_back
#define mp                  make_pair
#define mod                 1000000007
#define endl                "\n"

struct Node
{
    int data;
    Struct Node* left;
    Struct Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void solve()
{
        
    Struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> right = new Node(5);

    /*
            
                1
               / \
              2   3
               \
                5

    */

}   

int32_t main()
{

    fastIO
    cout << setprecision(15) << fixed;

    int t = 1;
    // cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": \n";
        solve();
    }

    return 0;

}