#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    vector<pair<long long,long long>> time;
    for (int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        time.push_back({a,1});
        time.push_back({b,-1});
    }
    sort(time.begin(),time.end());
 
    long long maxnum=0,num=0;
    for (auto cur:time){
        num+=cur.second;
        maxnum=max(maxnum,num);
    }
    cout<<maxnum<<endl;
     
    return 0;
}