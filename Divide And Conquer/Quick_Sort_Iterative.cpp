/*
here stack is used to insert the first and last position of the stack and here both the ends of the left and right subarrays
are inserted into the stack so in this implementation , right subarray will be implemented first.
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
    stack<int>stk;
    stk.push(low);
    stk.push(high);
    while(!stk.empty()){
        int hgh = stk.top();
        stk.pop();
        int lw = stk.top();
        stk.pop();
        int p = Partition(lw,hgh);
        if(p - lw > 1){
            stk.push(lw);
            stk.push(p-1);
        }
        if(p + 1 < hgh){
            stk.push(p+1);
            stk.push(hgh);
        }
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