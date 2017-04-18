#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;
ll pow(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
ll mmi(ll a) {
    return pow(a,mod-2);
}
vector<ll> factorial;
ll findfac(ll a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(ll i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i)%mod);
    return factorial[a];
}
ll nCk(ll n, ll k){
    return ((findfac(n)*mmi(findfac(k))%mod)*mmi(findfac(n-k)))%mod;
}
ll nPk(ll n, ll k){
    return (findfac(n)*mmi(findfac(n-k)))%mod;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int u,v;
        for(int i=1;i<n;i++)
            cin>>u>>v;
        ll ans = 0;
        n--;
        for(int i=0;i<min(k,n+1);i++){
            ll nci = nCk(n,i), pki1 = nPk(k,i+1);
            ans += (nci*pki1)%mod;
            ans %= mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
