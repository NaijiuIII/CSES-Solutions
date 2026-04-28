#include<bits/stdc++.h>
using namespace std;

int main(){
    long long mod=1e9+7;
 
    int n;
    cin>>n;
    map<long long,int> cnt;
 
    int x;
    for (int i=0;i<n;i++){
        cin>>x;
        cnt[x]++;
    }
    long long sum=1;
    for (auto &p:cnt){
        sum=(sum*(p.second+1))%mod;
    }
 
    cout<<sum-1<<endl;
}