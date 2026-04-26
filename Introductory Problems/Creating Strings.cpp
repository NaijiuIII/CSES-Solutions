#include <bits/stdc++.h>
using namespace std;

 
string s;
vector<int> num(26,0);
vector<int> used(26,0);
vector<string> str;
 
void dfs(int depth,string si){
    if (depth==s.size()){
        str.push_back(si);
        return;
    }
 
    for (int i=0;i<26;i++){
        if (used[i]<num[i]){
            used[i]++;
            dfs(depth+1,si+(char)('a'+i));
            used[i]--;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    cin>>s;
    sort(s.begin(),s.end());
    for (char a:s){
        num[a-'a']++;
    }
    dfs(0,"");
    cout<<str.size()<<endl;
    for (string &k:str) cout<<k<<endl;
    return 0;
}