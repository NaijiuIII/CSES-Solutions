#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
 
    vector<int> tower;
    for (int i=0;i<n;i++){
        auto pos=upper_bound(tower.begin(),tower.end(),a[i]);
 
        if (pos==tower.end()) tower.push_back(a[i]);
        else *pos=a[i];
    }
 
    cout<<tower.size()<<endl;
    return 0;
}