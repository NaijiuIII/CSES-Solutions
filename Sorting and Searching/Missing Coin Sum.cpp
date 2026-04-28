#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    vector<long long> coin(n);
    for (int i=0;i<n;i++){
        cin>>coin[i];
    }
    long long maxsum=0;
    sort(coin.begin(),coin.end());
    for (long long k:coin){
        if (k>maxsum+1){
            break;
        }
        maxsum+=k;
 
    }
    cout<<maxsum+1<<endl;
    return 0;
}