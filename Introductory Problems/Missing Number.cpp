#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    int x;
    vector<char> used(n+1,false);
    for (int i=0;i<n-1;i++){
        cin>>x;
        used[x]=true;
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}