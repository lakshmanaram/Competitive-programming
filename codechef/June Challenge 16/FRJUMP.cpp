#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
ll mod=1000000007;
using namespace std;
ll powd(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            x%=mod;
        }
        y = (y*y);
        y%=mod;
        b /= 2;
    }
    return x;
}
ll mmi(ll a) {
    return powd(a,mod-2);
}
int ffd(double x){
    return pow(10,x-floor(x));
}
vector<vll> getDivisors(long n, vll arr, vll &prod, vector<double> &log_val){
    vector<vll> divisors(n+1);
    divisors[0].push_back(-1);
    for(long i=1;i<=n;i++){
        ll ans=1;
        double log_tval=0;
        for(long j=i;j<=n;j+=i){
            divisors[j].push_back(i);
            ans *= arr[j];
            log_tval += log10(arr[j]);
            ans %= mod;
            if(ans<0) ans+=mod;
        }
        prod[i] = ans;
        log_val[i] = log_tval;
        // cout<<i<<" "<<prod[i]<<" "<<log_val[i]<<endl;
    }
    return divisors;
}
int main(){
    long n,q;
    cin>>n;
    vll arr(n);
    for(long i=0;i<n;i++)
        cin>>arr[i];
    if(n>10){
        vll prod(n+1);
        prod[n] = 1;
        vector<double> log_val(n+1);
        log_val[n] = 0;
        vector<vll> divisors = getDivisors(n-1,arr,prod,log_val);
        ll city1 = arr[0];
        cin>>q;
        while(q--){
            int ch;
            cin>>ch;
            long f;
            cin>>f;
            if(ch==1){
                ll val;
                cin>>val;
                f--;
                if(f==0)
                    city1 = val;
                else{
                    ll chval = mmi(arr[f]);
                    double chlog = log10(arr[f]), log_tval = log10(val);
                    for(long i=0;i<divisors[f].size();i++){
                        prod[divisors[f][i]] *= chval;
                        prod[divisors[f][i]] %= mod;
                        if(prod[divisors[f][i]]<0) prod[divisors[f][i]]+=mod;
                        prod[divisors[f][i]] *= val;
                        prod[divisors[f][i]] %= mod;
                        if(prod[divisors[f][i]]<0) prod[divisors[f][i]]+=mod;
                        log_val[divisors[f][i]] += log_tval - chlog;
                    }
                    arr[f] = val;
                }
            } else{
                ll ans = prod[f];
                ans *= city1;
                ans %= mod;
                if(ans<0) ans += mod;
                cout<<ffd(log_val[f]+log10(city1))<<" "<<ans%mod<<endl;
            }
        }
    } else {
        cin>>q;
        while(q--){
            int ch;
            cin>>ch;
            long f;
            cin>>f;
            if(ch==1){
                f--;
                ll val;
                cin>>val;
                arr[f] = val;
            } else {
                ll ans = 1;
                for(int i=0;i<n;i+=f){
                    ans *= arr[i];
                }
                ll t = ans;
                while(t/10)
                    t /= 10;
                cout<<t<<" "<<ans%mod<<endl;
            }
        }
    }
    return 0;
}
