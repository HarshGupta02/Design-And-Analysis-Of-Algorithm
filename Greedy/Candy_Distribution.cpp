/// so we basically first distribute one candy to each child . we segregate the problem into 2 sub problems.
/// first we see the left neighbours and then the right neighbours and take the maximum of the two in the
/// worst case and we ensured min candies by giving just one candy extra with respect to the neighbour of 
/// lower rating.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int>left(n,1);
    vector<int>right(n,1);
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]){
            left[i]=1+left[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1])
         right[i]=1+right[i+1];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(left[i],right[i]);
    }
    cout<<ans<<'\n';
    return 0;
}