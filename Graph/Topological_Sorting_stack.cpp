/*
topological sorting is a linear ordering of vertices such that if there is an edge u->v then u appears before v in that
ordering. a topological sort works only for DAG(directed acyclic graph).
*/

/* The intuition behind this algorithm is that before returning from the dfs call it is inserted into the stack and then
it is returned which ensures that v comes before u (u->v) .*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

vector<vector<int>>adj;
vector<bool>visited;
stack<int>st;

void dfs(int source){
    visited[source]=true;
    for(auto neigh:adj[source]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
    st.push(source);
    return;
}

void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    visited.resize(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    fast_cin();
    ll test_cases=1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}