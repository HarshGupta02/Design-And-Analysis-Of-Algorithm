/// our main aim is to sort the costs of the cuts in descending order as as cuts will increase so the number of 
/// segments will also increase so the cost of cuts in later stage should be as minimum as possible.

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
    ll m,n;
    cin>>m>>n;
    m--;n--;
    vector<ll>y(m);
    vector<ll>x(n); 
    for(int i=0;i<m;i++){
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(y.rbegin(),y.rend());
    sort(x.rbegin(),x.rend());
    ll ans=0;
    ll hc=1,vc=1;
    ll i=0,j=0;
    while(i<m and j<n){
        if(y[i]>x[j]){
            ans+=y[i]*vc;
            ans%=MOD;
            hc++;
            i++;
        }else{
            ans+=x[j]*hc;
            ans%=MOD;
            vc++;
            j++;
        }
    }
    while(i<m){
        ans+=y[i]*vc;
        ans%=MOD;
        i++;
    }
    while(j<n){
        ans+=x[j]*hc;
        ans%=MOD;
        j++;
    }
    cout<<ans%MOD<<'\n';
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