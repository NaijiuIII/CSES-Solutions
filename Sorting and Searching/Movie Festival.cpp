#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    vector<pair<long long,long long>> m;
    for (int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        m.push_back({a,b});
    }
    long long lastend=0;
    sort(m.begin(),m.end(),[](const auto&x,const auto&y){
        return x.second<y.second;
    });
 
    long long cnt=0;
    for (auto cur:m){
        if (cur.first>=lastend){
            cnt++;
            lastend=cur.second;
        }
    }
 
    cout<<cnt<<endl;
    return 0;
}