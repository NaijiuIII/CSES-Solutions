#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> x(n);
    int sum=0;
    for (int i=0;i<n;i++){
        cin>>x[i];
        sum+=x[i];
    }

    vector<int> dp(sum+1,0);
    dp[0]=1;

    for (int i=0;i<n;i++){
        for (int j=sum;j>=x[i];j--){
            dp[j]=dp[j]|dp[j-x[i]];
        }
    }
    
    vector<int> num;
    for (int i=1;i<=sum;i++){
        if (dp[i]==1) num.push_back(i);
    }

    cout<<num.size()<<'\n';
    for (int i=0;i<num.size();i++){
        if (i) cout<<' ';
        cout<<num[i];
    }
    cout<<'\n';
    return 0; 
}