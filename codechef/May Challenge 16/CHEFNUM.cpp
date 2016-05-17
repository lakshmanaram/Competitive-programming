#include<bits/stdc++.h>
using namespace std;
map<vector<int>,long> precomp;
long long mod = 1000000007;
long amazingness(vector<int> a)
{
    if(precomp.find(a)!=precomp.end())
        return precomp[a];
    reverse(a.begin(),a.end());
    if(precomp.find(a)!=precomp.end())
        return precomp[a];
    reverse(a.begin(),a.end());
    map<int,bool> check;
    long ans = 0;
    for ( vector<int>::iterator i = a.begin(); i != a.end(); i++ ) {
        int val = 0;
        for ( vector<int>::iterator j = i; j != a.end(); j++ ) {
            val ^= *j;
            if (check.find(val)==check.end()) {
                ans += val;
                ans %= mod;
                check[val] = true;
            }
        }
    }
    precomp[a] = ans;
    return ans;
}
vector<int> findVec(long long a){
    vector<int> ans;
    int prev = -1;
    while(a){
        if(a%10 != 0 && a%10 != prev){
            prev = a%10;
            ans.push_back(prev);
        }
        a /= 10;
    }
    return ans;
}
int main(){
    vector<long long> ans;
    int t;
    cin>>t;
    vector<long long> l(t),r(t);
    long long maxr = 0;
    for(int i=0;i<t;i++){
        cin>>l[i]>>r[i];
        if(r[i] >maxr)
            maxr = r[i];
    }
    ans.push_back(0);
    for(long long i=1;i<=maxr;i++){
        long long temp = amazingness(findVec(i)) + ans[ans.size()-1];
        temp %= mod;
        ans.push_back(temp);
    }
    for(int i=0;i<t;i++){
        cout<<(ans[r[i]]-ans[l[i]-1])%mod<<endl;
    }
}
