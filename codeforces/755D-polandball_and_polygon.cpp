#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main() {
    ll n,k;
    cin>>n>>k;
    ll start = 0;
    long long i = 1, inc = 1;
    if(k!=n-1){
        if( k > n/2)
            k = n-k;
        do {
            start += k;
            if(start > n) {
                inc ++;
                i += inc;
                inc++;
            } else i += inc;
            cout<<i<<" ";
            start %= n;
        } while(start!=0);
    } else {
        for(i=0;i<n;i++)
            cout<<"1 ";
    }
 	return 0;
}