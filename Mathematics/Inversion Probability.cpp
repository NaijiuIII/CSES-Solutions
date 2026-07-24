#include <bits/stdc++.h>
using namespace std;

const long long base=1000000000;

struct Big{
    vector<long long> a;

    Big(long long x=0){
        while (x){
            a.push_back(x%base);
            x/=base;
        }
    }

    void trim(){
        while (!a.empty()&&a.back()==0){
            a.pop_back();
        }
    }

    int cmp(const Big& b) const{
        if (a.size()!=b.a.size()){
            return a.size()<b.a.size()?-1:1;
        }

        for (int i=(int)a.size()-1;i>=0;i--){
            if (a[i]!=b.a[i]){
                return a[i]<b.a[i]?-1:1;
            }
        }

        return 0;
    }

    void add(const Big& b){
        int n=max(a.size(),b.a.size());
        a.resize(n,0);

        long long carry=0;

        for (int i=0;i<n;i++){
            long long cur=a[i]+carry;

            if (i<(int)b.a.size()){
                cur+=b.a[i];
            }

            a[i]=cur%base;
            carry=cur/base;
        }

        if (carry){
            a.push_back(carry);
        }
    }

    void sub(const Big& b){
        long long borrow=0;

        for (int i=0;i<(int)a.size();i++){
            long long cur=a[i]-borrow;

            if (i<(int)b.a.size()){
                cur-=b.a[i];
            }

            if (cur<0){
                cur+=base;
                borrow=1;
            }
            else{
                borrow=0;
            }

            a[i]=cur;
        }

        trim();
    }

    void mul(long long x){
        __int128 carry=0;

        for (long long& v:a){
            __int128 cur=(__int128)v*x+carry;

            v=cur%base;
            carry=cur/base;
        }

        while (carry){
            a.push_back(carry%base);
            carry/=base;
        }

        trim();
    }

    Big div(int x) const{
        Big res;
        res.a.resize(a.size());

        long long rem=0;

        for (int i=(int)a.size()-1;i>=0;i--){
            long long cur=rem*base+a[i];

            res.a[i]=cur/x;
            rem=cur%x;
        }

        res.trim();

        return res;
    }
};

bool isprime(int x){
    if (x<2){
        return false;
    }

    for (int i=2;i*i<=x;i++){
        if (x%i==0){
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> r(n);

    for (int i=0;i<n;i++){
        cin>>r[i];
    }

    Big den=1;

    for (int p=2;p<=200;p++){
        if (!isprime(p)){
            continue;
        }

        int x=p;

        while (x*p<=200){
            x*=p;
        }

        den.mul(x);
    }

    Big num=0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int x,y;

            if (r[i]<=r[j]){
                x=r[i]-1;
                y=2*r[j];
            }
            else{
                x=2*r[i]-r[j]-1;
                y=2*r[i];
            }

            Big cur=den.div(y);

            cur.mul(x);
            num.add(cur);
        }
    }

    num.mul(1000000);

    long long l=0;
    long long rr=5000000001LL;

    while (l+1<rr){
        long long mid=(l+rr)/2;

        Big cur=den;
        cur.mul(mid);

        if (cur.cmp(num)<=0){
            l=mid;
        }
        else{
            rr=mid;
        }
    }

    Big cur=den;
    cur.mul(l);

    num.sub(cur);
    num.mul(2);

    int c=num.cmp(den);

    if (c>0||(c==0&&l%2==1)){
        l++;
    }

    cout<<l/1000000<<'.'
        <<setw(6)<<setfill('0')
        <<l%1000000<<'\n';

    return 0;
}