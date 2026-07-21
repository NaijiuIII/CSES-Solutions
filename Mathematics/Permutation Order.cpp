#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> fac(21);

    fac[0]=1;

    for (int i=1;i<=20;i++){
        fac[i]=fac[i-1]*i;
    }

    int t;
    cin>>t;
    while (t--){
        int op,n;
        cin>>op>>n;

        if (op==1){
            long long k;
            cin>>k;

            k--;
            vector<int> nums;
            for (int i=1;i<=n;i++){
                nums.push_back(i);
            }

            vector<int> ans;

            for (int i=0;i<n;i++){
                long long b=fac[n-i-1];
                int idx=k/b;

                ans.push_back(nums[idx]);
                nums.erase(nums.begin()+idx);

                k%=b;
            }

            for (int i=0;i<n;i++){
                if (i) cout<<' ';
                cout<<ans[i];
            }
            cout<<'\n';
        }

        else{
            vector<int> p(n);

            for (int i=0;i<n;i++){
                cin>>p[i];
            }

            vector<int> nums;

            for (int i=1;i<=n;i++){
                nums.push_back(i);
            }

            long long rank=0;

            for (int i=0;i<n;i++){
                int idx=0;

                while (nums[idx]!=p[i]) idx++;
                rank+=1LL*idx*fac[n-i-1];
                nums.erase(nums.begin()+idx);
            }

            cout<<rank+1<<'\n';
        }
    }
    return 0;
}