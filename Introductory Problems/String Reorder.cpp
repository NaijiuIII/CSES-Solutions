#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    string s;
    cin>>s;
    int n=s.size();
 
    vector<int> a(26,0);
    for (char c:s){
        a[c-'A']++;
    }
     
    string res="";
    for (int i=0;i<n;i++){
        bool found=false;
        vector<char> used(26,false);
        if (i>0) used[res[i-1]-'A']=true;
        for (int j=0;j<26;j++){
            if (a[j]&&!used[j]){
                int maxone=0;
                int remain=n-i-1;
 
                a[j]--;
                for (int k=0;k<26;k++) maxone=max(maxone,a[k]);
 
                if (maxone<=(remain+1)/2){
                    res+=(char)(j+'A');
                    found=true;
                    break;
                }
 
                a[j]++;
            }
        }
 
        if (!found){
            cout<<-1<<'\n';
            return 0;
        }
    }
     
    cout<<res<<'\n';
 
    return 0;
}