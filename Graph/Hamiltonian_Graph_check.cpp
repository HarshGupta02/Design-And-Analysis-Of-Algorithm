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
vector<bool>visited;
ll cnt = 0;
ll n,m;
ll start = 0;
vector<ll>path;

bool dfs(ll source){
    path.push_back(source);
    visited[source] = true;
    cnt ++;
    for(auto neigh:adj[source]){
        if(!visited[neigh]){
            return dfs(neigh);
        }else{
            if(neigh == start and cnt == n){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n,false);
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(start)){
        cout << "contains a hamiltonian cycle" << nline;
        for(auto it:path){
            cout << it << " ";
        }
        cout << 0;
        cout << nline;
    }
    else{
        for(auto it:visited){
            if(!it){
                cout << "neither has hamiltonian path nor hamiltonian circuit" << nline;
                return;
            }
        }
        cout << "The graph has hamiltonian path only" << nline;
        for(auto it:path){
            cout << it << " ";
        }
        cout << nline;
    }
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