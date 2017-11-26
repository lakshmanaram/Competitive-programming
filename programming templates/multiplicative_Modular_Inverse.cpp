#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b) {
    long long x = 1, y = a;
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
long long mmi_logm_complex(long long a) {
    return pow(a,mod-2);
}
vector<long long> modInverseArray;
long long mmi(long long n, long long mod) {
	if(modInverseArray.size() > n)
        return modInverseArray[n];
    // If Empty
	if(modInverseArray.size() == 0){
        // Value for 0 ignored and 1 is 1
        modInverseArray.push_back(0);
        modInverseArray.push_back(1);
    }
	for(long long i = modInverseArray.size(); i <= n; i++)
		modInverseArray.push_back((-(mod/i) * modInverseArray[mod % i]) % mod + mod);
    return modInverseArray[n];
}
/* This function return the gcd of a and b followed by
    the pair x and y of equation ax + by = gcd(a,b)*/
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
// ll modInverse(ll a, ll m) {
//     return (extendedEuclid(a,m).second.first + m) % m;
// }
int main(){
    cout<<"Enter mod value: ";
    long long mod;
    cin>>mod;
    while(true){
        cout<<"Enter value to find it's modInverse: ";
        long long x;
        cin>>x;
        cout<<"Modular Multiplicative Inverse of "<<x<<" is "<<mmi(x,mod)<<endl;
    }
    return 0;
}
