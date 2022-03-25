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
vector<int>degree;

void dfs(ll source){
    visited[source]=true;
    for(auto neigh:adj[source]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    visited.resize(n,false);
    degree.resize(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;degree[v]++;
    }
    for(int i=0;i<n;i++){
        if(degree[i]>0){
            dfs(i);
            break;
        }
    }
    bool found=false;
    for(int i=0;i<n;i++){
        if(degree[i]>0 and visited[i]==false){
            found=true;
            break;
        }
    }
    if(found){
        cout<<"not a euler graph"<<endl;
        return;
    }
    int odd_degree_cnt=0;
    for(int i=0;i<n;i++){
        if(degree[i]>0){
            odd_degree_cnt+=(degree[i]%2);
        }
    }
    if(odd_degree_cnt==0){
        cout<<"it is a eulerian graph"<<endl;
    }else if(odd_degree_cnt==2){
        cout<<"it is a semi eulerian graph"<<endl;
    }else{
        cout<<"it is not a eulerian graph"<<endl;
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