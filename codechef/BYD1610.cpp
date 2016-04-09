#include <bits/stdc++.h>
using namespace std;
long long modular_pow(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int modInverse(int a, int m) {
    return modular_pow(a,m-2,m);
}
long long mod = 1000000007;
int main(){
    int n;
    cin>>n;
    long a[n];
    long long sum = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        sum += a[i];
        sum %= mod;
    }
    long long t;
    cin>>t;
    int q;
    cin>>q;
    long long val = modular_pow(n-1,t,mod);
    if(t%2==0)
        val --;
    else
        val++;
    val *= modInverse(n,mod);
    val %= mod;
    val *= sum;
    val %= mod;
    while(q--){
        long s;
        cin>>s;
        if(t%2 == 0)
            cout<<(val + a[s-1])%mod<<endl;
        else
            cout<<(val - a[s-1])%mod<<endl;
    }
    return 0;
}
