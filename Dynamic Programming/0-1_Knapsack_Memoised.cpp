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

vector<int>value,weight;
vector<vector<int>>dp;

int knapsack(int n,int w,int i){
    if(i==0 or w<=0)
     return 0;
    if(dp[i][w]!=-1)
     return dp[i][w];
    int a=0;
    if(weight[i-1]>w){
        a=knapsack(n,w,i-1);
    }else{
        a=max(knapsack(n,w,i-1),value[i-1]+knapsack(n,w-weight[i-1],i-1));
    }
    return dp[i][w]=a;
}

void solve(){
    int n,w;
    cin>>n>>w;
    value.resize(n);
    weight.resize(n);
    dp.resize(n+1,vector<int>(w+1,-1));
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<knapsack(n,w,n)<<'\n';
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