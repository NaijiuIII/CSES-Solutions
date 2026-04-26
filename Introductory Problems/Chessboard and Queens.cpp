#include <bits/stdc++.h>
using namespace std;

 
 
vector<string> a(8);
int solve=0;
vector<char> col(9,false);
vector<char> d1(15,false);
vector<char> d2(15,false);
 
void dfs(int i){
    if (i>8){
        solve++;
        return;
    }
    for (int j=1;j<=8;j++){
        if (!col[j]&&!d1[i-j+7]&&!d2[i+j]&&a[i-1][j-1]!='*'){
            col[j]=true;
            d1[i-j+7]=true;
            d2[i+j]=true;
            dfs(i+1);
            col[j]=false;
            d1[i-j+7]=false;
            d2[i+j]=false;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    for (int i=0;i<8;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<solve<<endl;
    return 0;
}