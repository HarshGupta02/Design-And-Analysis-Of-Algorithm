#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<ll>>adj;
vector<ll>indegree;
ll n , m;

void AllTopologicalSortUtil(vector<ll> &res,vector<bool>visited){
    bool flag = false;
    for(int i = 0;i < n ; i++){
        if(indegree[i] == 0 and !visited[i]){
            for(auto neigh : adj[i]){
                indegree[neigh]--;
            }
            res.push_back(i);
            visited[i] = true;
            AllTopologicalSortUtil(res , visited);
            res.pop_back();
            visited[i] = false;
            for(auto neigh : adj[i]){
                indegree[neigh]++;
            }
            flag = true;
        }
    }
    if(!flag){
        for(int i=0;i<res.size();i++){
            cout << res[i] << " ";
        }
        cout << nline;
    }
}

void AllTopologicalSort(){
    vector<bool>visited(n,false);
    vector<ll>res;
    AllTopologicalSortUtil(res,visited);
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    indegree.resize(n,0);
    for(int i=0;i<m;i++){
        ll u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    AllTopologicalSort();
}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}