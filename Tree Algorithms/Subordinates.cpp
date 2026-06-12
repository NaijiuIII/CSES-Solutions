#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<vector<int>> emp;
int build(int id){
    if (emp[id].size()==0){
        return 1;
    }

    for (int x:emp[id]){
        tree[id]+=build(x);
    }

    return tree[id]+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    tree.assign(n+1,0);
    emp.resize(n+1);

    int x;
    for (int i=2;i<=n;i++){
        cin>>x;
        emp[x].push_back(i);
    }

    build(1);
    
    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';
        cout<<tree[i];
    }
    cout<<'\n';
    return 0;
}

