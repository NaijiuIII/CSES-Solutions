#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> task(n);
    long long reward=0;
    for (int i=0;i<n;i++){
        cin>>task[i].first>>task[i].second;
        reward+=1LL*task[i].second;
    }

    sort(task.begin(),task.end());

    long long f=task[0].first;
    reward-=f;
    for (int i=1;i<n;i++){
        f+=task[i].first;
        reward-=f;
    }

    cout<<reward<<'\n';
    return 0; 
}