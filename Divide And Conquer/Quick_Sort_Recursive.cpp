/* in this algorithm , we choose a pivot element about which we have to partition the whole array such that the elemets 
before this pivot elements are less than the pivot element and the elements to the right are greater than the pivot
element. then we perform the same qucik sort on the left and right subarray about the their new pivot.
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

int n;
vector<int>a;

int Partition(int low , int high){
    int i = low , j = high;
    int pivot = a[low];
    while(i<j){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    swap(a[j],a[low]);
    return j;
}

void QuickSort(int low , int high){
    if(low < high){
        int pivot = Partition(low,high);
        QuickSort(low , pivot-1);
        QuickSort(pivot+1 , high);
    }
}

void solve(){
    cin>>n;
    a.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(0,n-1);
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