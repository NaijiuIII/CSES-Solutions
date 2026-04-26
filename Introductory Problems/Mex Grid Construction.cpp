#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));
     
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            set<int> s;
            for (int k=0;k<j;k++){
                s.insert(a[i][k]);
            }
            for (int k=0;k<i;k++){
                s.insert(a[k][j]);
            }
 
            int mex=0;
            while (s.find(mex)!=s.end()){
                mex++;
            }
 
            a[i][j]=mex;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j!=0) cout<<' ';
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}