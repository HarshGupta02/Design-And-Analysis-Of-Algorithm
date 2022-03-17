/// we first sort all activities on the basis of finish time and then select an activity if it's start time >= finish time of 
/// last executed activity.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>start(n);
    vector<int>finish(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>finish[i];
    }
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int cnt=1;
    int last_start=v[0].second;
    int last_finish=v[0].first;
    for(int i=1;i<n;i++){
        int curr_start=v[i].second;
        int curr_finish=v[i].first;
        if(curr_start>=last_finish){
            cnt++;
            last_start=curr_start;
            last_finish=curr_finish;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}