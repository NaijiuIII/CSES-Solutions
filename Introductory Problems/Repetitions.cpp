#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    string s;
    cin>>s;
    int n=s.size();
 
    int len=1,maxlen=1;
    for (int i=1;i<n;i++){
        if (s[i]==s[i-1]){
            len++;
        }
        else{
            maxlen=max(maxlen,len);
            len=1;
        }
    }
    maxlen=max(len,maxlen);
    cout<<maxlen<<endl;
    return 0;
}