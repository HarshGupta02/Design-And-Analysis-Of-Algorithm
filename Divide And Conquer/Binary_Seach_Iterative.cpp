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

int n,x;
vector<int>a;

int BinarySearch(){
    int ans = -1;
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == x){
            ans = mid;
            break;
        }
        if(a[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

void solve(){
    cin>>n>>x;
    a.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<BinarySearch()<<'\n';
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