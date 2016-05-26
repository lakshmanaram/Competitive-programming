#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> f;
map<long long, int> ans;
long long ans_func(long long x, int k, int fi){
    if(k==0 && ans.find(x) != ans.end() && f[fi] >= x)
        return ans[x];
    if(k==0 || x <= 0 || fi < 0){
        return 0;
    }
    if(x > (k+1)*f[fi])
        return 0;
    long long temp_ans = 0,temp;
    temp = ans_func(x,k,fi-1);
    temp_ans += temp;
    temp_ans %= mod;
    temp = ans_func(x-f[fi],k-1,fi);
    temp_ans += temp;
    temp_ans %= mod;
    return temp_ans%mod;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int k;
        long long x;
        cin>>x>>k;
        f.clear();
        f.push_back(1);
        f.push_back(2);
        ans[1] = 1;
        ans[2] = 1;
        long long temp = 3;
        while(temp<=x){
            ans[temp] = 1;
            f.push_back(temp);
            temp += f[f.size()-2];
        }
        cout<<ans_func(x,k-1,f.size()-1)<<endl;
    }
    return 0;
}
