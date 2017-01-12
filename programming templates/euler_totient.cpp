// Program to find the euler totient of a number
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll n) {
    ll result = n;
    vector<bool> seive(sqrt(n)+1,true);
    for (ll p=2; p*p<=n; ++p) {
        if (seive[p]) {
            if (n % p == 0){
                result -= result/p;
                while (n%p == 0)
                    n /= p;
            }
            for (ll j = 2*p; j*j < n; j+= p) {
                seive[j] = false;
            }
        }
    }
    if (n > 1)
        result -= result/n;
    return (int)result;
}
int main() {
    long long n;
    // cin>>n;
    for(n=1;n<11;n++)
    cout<<phi(n)<<endl;
    return 0;
}
