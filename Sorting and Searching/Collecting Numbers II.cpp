#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
 
    int m;
    cin>>m;
    vector<int> a(n);
    map<int,int> pos;
    for (int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
 
    vector<int> bre(n+2,0);
    int round=1;
    for (int i=2;i<=n;i++){
        if (pos[i]<pos[i-1]){
            bre[i]=1;
            round++;
        }
    }
 
    while (m--){
        int x,y;
        cin>>x>>y;
         
        int u=a[x-1],v=a[y-1];
 
        set<int> s;
 
        if (u>1) s.insert(u);
        if (u<n) s.insert(u+1);
        if (v>1) s.insert(v);
        if (v<n) s.insert(v+1);
 
        for (int i:s){
            if (bre[i]) round--;
        }
 
        swap(a[x-1],a[y-1]);
        pos[u]=y-1;
        pos[v]=x-1;
 
        for (int i:s){
            bre[i]=(pos[i]<pos[i-1]?1:0);
            if (bre[i]) round++;
        }
        cout<<round<<'\n';
    }
    return 0;
}