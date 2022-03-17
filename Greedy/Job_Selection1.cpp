/// sort the jobs on the basis of maximum profit and then try to select the deadline as close as possible to the 
/// deadline of the current job.

/// Time Complexity = O(N*N); space complexity = O(max deadline).

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Job{
    int deadline,profit;
};

bool cmp(Job a,Job b){
    if(a.profit!=b.profit){
        return (a.profit > b.profit);
    }else{
        return (a.deadline > b.deadline);
    }
}

int main(){
    int n;
    cin>>n;
    int max_deadline=-1;
    vector<Job>v(n);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        max_deadline=max(max_deadline,d);
        v[i].deadline=d;
    }
    for(int i=0;i<n;i++){
        int pft;
        cin>>pft;
        v[i].profit=pft;
    }
    vector<bool>visited(max_deadline,false);
    sort(v.begin(),v.end(),cmp);
    int cost=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        int curr_deadline = v[i].deadline;
        int curr_profit = v[i].profit;
        for(int j=curr_deadline;j>=1;j--){
            if(!visited[j]){
                cost+=curr_profit;
                cnt++;
                visited[j]=true;
                break;
            }
        }
    }
    cout<<cost<<'\n';
    return 0;
}