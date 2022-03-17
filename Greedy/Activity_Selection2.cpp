// time complexity = O(N*logN)

#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start,finish;
};

bool cmp(Activity a,Activity b){
    if(a.finish!=b.finish){
        return (a.finish < b.finish);
    }else{
        return (a.start < b.start);
    }
}

int main(){
    int n;
    cin>>n;
    vector<Activity>v(n);  /// (8*n) bytes , this vector takes.
    for(int i=0;i<n;i++){
        int st;
        cin>>st;
        v[i].start=st;
    }
    for(int i=0;i<n;i++){
        int fin;
        cin>>fin;
        v[i].finish=fin;
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=1;
    int last_start=v[0].start;
    int last_finish=v[0].finish;
    for(int i=1;i<n;i++){
        int curr_start=v[i].start;
        int curr_finish=v[i].finish;
        if(curr_start>=last_finish){ 
            cnt++;
            last_start=curr_start;
            last_finish=curr_finish;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}