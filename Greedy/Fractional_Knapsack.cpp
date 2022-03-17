/// here we sort the items on the basis of value per weight in descending order as we occupy min space
/// of the knapsack and maximise the profit.

#include<bits/stdc++.h>
using namespace std;

struct Item{
    double value,weight,perKg;
};

bool cmp(Item a,Item b){
    return (a.perKg > b.perKg);
}

int main(){
    double n;
    cin>>n;
    vector<Item>v(n);
    for(int i=0;i<n;i++){
        double val,wgt;
        cin>>val>>wgt;
        v[i].value=val;
        v[i].weight=wgt;
        v[i].perKg=val/wgt;
    }
    int total;
    cin>>total;
    sort(v.begin(),v.end(),cmp);
    double ans=0;
    int i=0;
    while(total>0 and i<n){
        if(v[i].weight<=total){
            total-=v[i].weight;
            ans+=v[i].value;
            i++;
            continue;
        }
        ans+=v[i].perKg * total;
        break;
    }
    cout<<ans<<'\n';
    return 0;
}