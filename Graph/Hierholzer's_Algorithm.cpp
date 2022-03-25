// time complexity = O(E)

// here we have assumed that the given graph is an euler graph that is, it contains euler circuit.

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
stack<int>current_path;
stack<int>ans;
map<pair<int,int>,int>mp;
static int cnt = 0;

void print_ans(){
    while(!current_path.empty()){
        int top = current_path.top();
        current_path.pop();
        ans.push(top);
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

void dfs(int source,int m){
    current_path.push(source);
    if(cnt==m){
        print_ans();
        return;
    }
    for(auto neigh:adj[source]){
        if(mp[{source,neigh}]==1){
            cnt++;
            mp[{source,neigh}]=0;
            dfs(neigh,m);
        }
    }
    current_path.pop();
    ans.push(source);   
}

void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        mp[{u,v}]=1;
    }
    dfs(0,m);
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