#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
ll mod=1000000007;
using namespace std;
ll pow(ll a, ll b) {
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
    return pow(a,mod-2);
}
int main(){
    long n,q;
    cin>>n;
    vll arr(n);
    for(long i=0;i<n;i++)
        cin>>arr[i];
    vll prod(101,0);
    long prodind = min((long)1000,n-1);
    for(long r = 1;r<=prodind;r++){
        ll ans = 1;
        for(long i=0;i<n;i+=r){
            ans *= arr[i];
            ans %= mod;
            if(ans<0) ans+=mod;
        }
        prod[r] = ans;
    }
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
            ll chval = mmi(arr[f]);
            for(long i=1;i<=min(prodind,f);i++){
                if(f==0 || f%i==0){
                    // cout<<"gonna do mmi on "<<prod[i]<<" with "<<arr[f]<<" chval = "<<chval;
                    prod[i] *= chval;
                    prod[i] %= mod;
                        // cout<<" result "<<prod[i]<<endl;
                    if(prod[i]<0) prod[i]+=mod;
                    prod[i] *= val;
                    prod[i] %= mod;
                    if(prod[i]<0) prod[i]+=mod;
                }
            }
            arr[f] = val;
        } else{
            ll ans = 1;
            if(f<=prodind)
                ans=prod[f];
            else{
                for(long i=0;i<n;i+=f){
                    ans *= arr[i];
                    ans %= mod;
                    if(ans<0) ans+=mod;
                }
            }
            ll val = ans;
            while(val/10){
                val /= 10;
            }
            cout<<val<<" "<<ans<<endl;

        }
        // for(int i=1;i<=prodind;i++)
        //     cout<<prod[i]<<" ";
        // cout<<endl;
    }
    return 0;
}
