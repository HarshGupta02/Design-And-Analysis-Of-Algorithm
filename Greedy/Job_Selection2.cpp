//// here we make a visited array of size n as there can be only n slots possible for the job.
//// it can be possible that the deadline of a job can be greater than the the value of n.

//// look for 1. dp+binary search , 2. priority queue , 3. Disjoint set union.

/// Time Complexity = O(N*N); space complexity = O(N)

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
    vector<Job>v(n);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v[i].deadline=d;
    }
    for(int i=0;i<n;i++){
        int pft;
        cin>>pft;
        v[i].profit=pft;
    }
    vector<bool>visited(n+1,false);
    sort(v.begin(),v.end(),cmp);
    int cost=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        int curr_deadline = v[i].deadline;
        int curr_profit = v[i].profit;
        for(int j=min(n,curr_deadline);j>=1;j--){
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