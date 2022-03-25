// time complexity = O(E*E) where E = no of edges.

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
vector<pair<int,int>>ans;

void dfs(int source){
    visited[source]=true;
    for(auto neigh:adj[source]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

int Find_Starting_Vertex(int n){
    int target;
    for(int i=0;i<n;i++){
        if(degree[i]%2==1){
            return i;
        }
    }
    return 0;
}

void Remove_Edge(int u,int v){
    auto it1 = find(adj[u].begin(),adj[u].end(),v);
    *it1 = -1;
    auto it2 = find(adj[v].begin(),adj[v].end(),u);
    *it2 = -1;
}

void Add_Edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Dfs_Count(int source,bool visited_flury[]){
    visited_flury[source]=true;
    int cnt = 1;
    for(auto neigh:adj[source]){
        if(neigh!=-1 and visited_flury[neigh]==false){
            cnt+=Dfs_Count(neigh,visited_flury);
        }
    }
    return cnt;
}

bool IsValid(int u,int v,int n){
    int cnt=0;
    for(auto neigh:adj[u]){
        if(neigh!=-1){
            cnt++;
        }
    }
    if(cnt==1){
        return true;
    }
    bool visited_flury[n];
    memset(visited_flury,false,n);
    int cnt1 = Dfs_Count(u,visited_flury);
    Remove_Edge(u,v);
    memset(visited_flury,false,n);
    int cnt2 = Dfs_Count(u,visited_flury);
    Add_Edge(u,v);
    if(cnt1 > cnt2)
     return false;
    return true;
}

void Euler_Tour_Util(int fst,int n){
    for(auto neigh:adj[fst]){
        if(neigh!=-1 and IsValid(fst,neigh,n)){
            ans.push_back({fst,neigh});
            Remove_Edge(fst,neigh);
            Euler_Tour_Util(neigh,n);
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
        cout<<"not a eulerian circuit"<<endl;
        return;
    }
    int odd_degree_cnt=0;
    for(int i=0;i<n;i++){
        odd_degree_cnt+=(degree[i]%2);
    }
    if(odd_degree_cnt > 2){
        cout<<"not a eulerian circuit"<<endl;
        return;
    }
    int fst = Find_Starting_Vertex(n);
    Euler_Tour_Util(fst,n);
    for(auto it:ans){
        cout<<it.first<<"->"<<it.second<<'\n';
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