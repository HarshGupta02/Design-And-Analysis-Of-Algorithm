/* 
the intuition behind this algorithm is the fact that atleast one node has indegree 0. now first process all the nodes with
indegree 0 which ensures that there is no dependancy before it.

time complexity = O(V+E)
*/


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
vector<int>ans;
vector<int>inDegree;
queue<int>q;

void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    inDegree.resize(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front();
        ans.push_back(top);
        q.pop();
        for(auto neigh:adj[top]){
            inDegree[neigh]--;
            if(inDegree[neigh]==0){
                q.push(neigh);
            }
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
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