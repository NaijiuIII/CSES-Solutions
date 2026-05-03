#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
 
    vector<long long> step(n+1,1e9);
    step[n]=0;
    for (int i=n;i>=0;i--){
        vector<int> num;
        int x=i;
        while (x>0){
            if (x%10!=0) num.push_back(x%10);
            x/=10;
        }
         
        for (int j:num){
            if (i-j>=0) step[i-j]=min(step[i-j],step[i]+1);
        }
    }
    cout<<step[0]<<'\n';
    return 0;
}