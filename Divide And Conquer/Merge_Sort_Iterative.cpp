// here we use bottom to up approach and here we first merge 2 subarrays ,each of size 1 and then increase this size by 2
// and the remaining elements are handeled by taking the min of (n-1 and right_end).

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

int n;
vector<int>a(n);

void Merge(int low , int mid , int high){
    int n1 = mid - low + 1;
    int n2 = high - (mid+1) + 1;
    vector<int>a1(n1),a2(n2);
    for(int i=0;i<n1;i++){
        a1[i] = a[low + i];
    }
    for(int i=0;i<n2;i++){
        a2[i] = a[mid + 1 + i];
    }
    int i = 0 , j = 0 , k = low ;
    while(i < n1 and j < n2){
        if(a1[i] <= a2[j]){
            a[k] = a1[i];
            i++;k++;
        }else{
            a[k] = a2[j];
            j++;k++;
        }
    }
    while(i < n1){
        a[k] = a1[i];
        i++;k++;
    }
    while(j < n2){
        a[k] = a2[j];
        j++;k++;
    }
}

void MergeSort(){
    for(int curr_size = 1 ; curr_size < n ; curr_size *= 2){
        for(int left_start = 0 ; left_start < n ; left_start += curr_size * 2){
            int mid = min(n-1,left_start + curr_size - 1); 
            int right_end = min(n-1,left_start + 2*curr_size - 1); /// this is to include those elements whose group of curr_size could not be formed.
            Merge(left_start , mid , right_end);
        }
    }
}

void solve(){
    cin>>n;
    a.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MergeSort();
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<'\n';
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