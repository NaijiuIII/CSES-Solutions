#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    queue<int> q;
    for (int i=1;i<=n;i++){
        q.push(i);
    }
    while (!q.empty()){
        int k=q.front();
        q.pop();
        q.push(k);
         
        k=q.front();
        cout<<k<<' ';
        q.pop();
    }
    return 0;
}