#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    vector<vector<char>> a(n,vector<char>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<char>> res(n,vector<char>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            vector<char> used(4,false);
            used[a[i][j]-'A']=true;
            if (i>0) used[res[i-1][j]-'A']=true;
            if (j>0) used[res[i][j-1]-'A']=true;
            for (int k=0;k<4;k++){
                if (!used[k]){
                    res[i][j]='A'+k;
                    break;
                }
            }
        }
    }
     
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}