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

void solve(){
    ll n,k;
    cin>>n>>k;
    map<ll,priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>>mp;
    for(int i=0;i<n;i++){
        ll st,fn,p;
        cin>>st>>fn>>p;
        mp[p].push({fn,st});
    }
    ll cnt=0;
    for(auto it:mp){
        ll compartment=it.first;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq = it.second;
        ll last_start=pq.top().second;
        ll last_finish=pq.top().first;
        pq.pop();
        cnt++;
        while(!pq.empty()){
            ll curr_start=pq.top().second;
            ll curr_finish=pq.top().first;
            if(curr_start>=last_finish){
                last_start=curr_start;
                last_finish=curr_finish; 
                pq.pop();
                cnt++;
                continue;
            }
            pq.pop();
        }
    }
    cout<<cnt<<'\n';
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}