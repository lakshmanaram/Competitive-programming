#include <bits/stdc++.h>
using namespace std;
# define ll long long
long long mod = 1000000007;
vector<long long> modInverseArray;
long long mmi(long long n) {
	if(modInverseArray.size() > n)
        return modInverseArray[n];
	if(modInverseArray.size() == 0){
        modInverseArray.push_back(0);
        modInverseArray.push_back(1);
    }
	for(long long i = modInverseArray.size(); i <= n; i++)
		modInverseArray.push_back((-(mod/i) * modInverseArray[mod % i]) % mod + mod);
    return modInverseArray[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,tempn=0;
        cin>>n>>k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0)
                tempn++;
        }
        if(tempn==0){
            long long ans,i, cur;
            if(k%2==0){
                ans = 1;
                i = 2;
            }
            else{
                ans = n;
                i = 3;
            }
            cur = ans;
            while(i<=k && i<=n){
                cur *= (n-i+2);
                cur %= mod;
                cur *= (n-i+1);
                cur %= mod;
                cur *= mmi(i);
                cur %= mod;
                cur *= mmi(i-1);
                cur %= mod;
                ans += cur;
                ans %= mod;
                i+=2;
            }
            cout<<ans<<endl;
        }else {
            n -= tempn;
            long long ans,i, cur;
            ans = 1;
            i = 1;
            cur = ans;
            while(i<=k && i<=n){
                cur *= (n-i+1);
                cur %= mod;
                cur *= mmi(i);
                cur %= mod;
                ans += cur;
                ans %= mod;
                i++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
