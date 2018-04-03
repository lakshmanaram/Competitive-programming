#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<ll> arr;
set<ll> arr_all;
void markMultiples(ll a, ll n) {
    ll i = 2, num;
    while ( (num = i*a) <= n ) {
        arr[num] = a;
        ++i;
    }
}
void remMultiples(ll a, ll n) {
    ll i = 1, num;
    while ( (num = i*a) <= n ) {
        auto it = arr_all.find(num);
        if(it != arr_all.end())
            arr_all.erase(it);
        ++i;
    }
}
void SieveOfEratosthenes(ll n)
{
    arr.resize(n, 1);
    for (ll i=2; i<n; ++i)
        if (arr[i] == 1) {
            markMultiples(i, n);
        }
}
void rem_fac(ll x, ll n) {
    while(arr[x] != 1) {
        ll val = arr[x];
        if (arr_all.find(val) != arr_all.end()) {
            // cout<<"remove on "<<x<<" "<<arr[x]<<endl;
            remMultiples(val, n);
        }
        x /= arr[x];
    }
    ll val = x;
    if (arr_all.find(val) != arr_all.end()) {
        remMultiples(val, n);
    }
}

int main() {
    ll mv = 2000000;
    SieveOfEratosthenes(mv);
    for(ll i = 2; i < mv; i++) {
        arr_all.insert(i);
    }
    long n;
    scanf("%ld", &n);
    bool break_loop = false;
    for(long i=0;i<n;i++) {
        if(break_loop) {
            ll ans = *arr_all.begin();
            printf("%lld ", ans);
            rem_fac(ans, mv);    
        } else {
            ll x;
            scanf("%lld", &x);
            ll ans = *arr_all.lower_bound(x);
            if (ans != x) {
                break_loop = true;
            }
            printf("%lld ", ans);
            rem_fac(ans, mv);    
        }

        // it = arr_all.begin();
        // for(long j=0; j< 15; j++) {
        //     cout<<*it<<" ";
        //     it++;
        // } 
        // cout<<endl;
        // cout<<endl;
    }
    return 0;
}

