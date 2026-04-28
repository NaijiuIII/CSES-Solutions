#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> pos;
    for (int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
 
    int cnt=1;
    for (int i=2;i<=n;i++){
        if (pos[i]<pos[i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}