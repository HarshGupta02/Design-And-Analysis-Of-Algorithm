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
    int n,target;
    cin>>n>>target;
    vector<int>values(n);
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    vector<vector<int>>dp(target+1,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            if(i>=values[j]){
                dp[i][j]+=dp[i-values[j]][j]; // we can select the same coin again.
            }
            if(j>=1){
                dp[i][j]+=dp[i][j-1];
            }
        }
    }
    for(int i=0;i<=target;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<dp[target][n-1]<<'\n';
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