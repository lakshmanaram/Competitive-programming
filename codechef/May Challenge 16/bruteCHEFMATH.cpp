#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> f;
vector<map<pair<long long,int>, long long > > ans(10);
long long ans_func(long long x, int k, int fi){
    if(ans[k].find(make_pair(x,f.size()-1-fi)) != ans[k].end())
        return ans[k][make_pair(x,f.size()-1-fi)];
    if(k==0 || x == 0){
            if(ans[0].find(make_pair(x,0)) != ans[0].end() && f[fi] >= x)
                return ans[0][make_pair(x,0)];
            return 0;
    }
    long long temp_ans = 0,temp;
    for(int i=fi;i>=0;i--){
        if(x<f[i])
            continue;
        temp = ans_func(x-f[i],k-1,i);
        temp_ans += temp;
        temp_ans %= mod;
        //cout<<x<<" "<<f[i]<<" "<<temp_ans<<endl;
    }
    ans[k][make_pair(x,fi)] = temp_ans;
    return temp_ans%mod;
}
int main(){
    vector<long long> precomp;
    precomp.push_back(1);
    precomp.push_back(1);
    precomp.push_back(2);
    precomp.push_back(4);
    precomp.push_back(10);
    precomp.push_back(23);
    precomp.push_back(56);
    precomp.push_back(134);
    precomp.push_back(328);
    precomp.push_back(795);
    long long maxval = 1000000001;
    f.push_back(1);
    f.push_back(2);
    ans[0][make_pair(1,0)] = 1;
    ans[0][make_pair(2,0)] = 1;
    long long temp = 3;
    while(temp<=maxval){
        for(int i=0;i<min(2+(f.size()/2),precomp.size());i++){
            ans[i][make_pair(temp,0)] = precomp[i];
        }
        f.push_back(temp);
        temp += f[f.size()-2];
    }
    ans[2][make_pair(3,0)] = 1;
    int q;
    cin>>q;
    while(q--){
        int k;
        long long x;
        cin>>x>>k;
        cout<<ans_func(x,k-1,f.size()-1)<<endl;
        //cout<<"-----------------------------"<<endl;
    }
    return 0;
}
