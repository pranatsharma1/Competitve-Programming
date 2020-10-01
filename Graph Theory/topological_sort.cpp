#include <bits/stdc++.h>
#define ll long long
#define repe(j, n) for(ll i = j ; i <= n ; i++)
#define rep(j , n) for(ll i = j ; i < n ; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>

using namespace std;

// Topological Sorting (Kahn's BFS based Algorithm)

void addEdge(vector<int> ad[], int u, int v){

    ad[u].push_back(v);
    // ad[v].push_back(u);

}

vector<int> TopologicalSort(int n, vector<int> ad[]) {

    int indegree[n] = {0};
    for(int i = 0; i < n; i++){
        for(auto j : ad[i])
            indegree[j]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }



    while(!q.empty()){

        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for(auto j : ad[temp]){
            indegree[j]--;
            if(indegree[j] == 0)
                q.push(j);
        }
    }

    return ans;


}


int main(){
    vector<int> ad[10];
    addEdge(ad, 5, 0);
    addEdge(ad, 5, 2);
    addEdge(ad, 2, 3);
    addEdge(ad, 4, 0);
    addEdge(ad, 4, 1);
    addEdge(ad, 1, 3);

    vector<int> ans = TopologicalSort(6, ad);
    for(auto i : ans)
        cout << i << " ";

}
