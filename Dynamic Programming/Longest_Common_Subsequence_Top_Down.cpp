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

vector<vector<int>>dp;
string ans="";

void print_lcs(string s1,string s2,int n,int m){
    if(n==0 or m==0)
     return;
    if(s1[n-1]==s2[m-1]){
        ans.push_back(s1[n-1]);
        print_lcs(s1,s2,n-1,m-1);
    }else{
        if(dp[n][m-1]>dp[n-1][m]){
            print_lcs(s1,s2,n,m-1);
        }else{
            print_lcs(s1,s2,n-1,m);
        }
    }
}

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    dp.resize(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"length of lcs is "<<dp[n][m]<<'\n';
    print_lcs(s1,s2,n,m);
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
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