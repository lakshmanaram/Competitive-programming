#include <bits/stdc++.h>
using namespace std;
vector<long long> factorial;
long long mod;
vector<long long> modInverseArray;
long long mmi(long long n) {
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
long long findfac(long long a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(long long i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i)%mod);
    return factorial[a];
}
long long nCk(long long n, long long k){
    return (k>=0 && k<=n && n>=0)?((findfac(n)*mmi(findfac(k))%mod)*mmi(findfac(n-k))%mod):-1;
}

int main(){
    cout<<"Enter mod value: ";
    cin>>mod;
    while(true){
        cout<<"Enter n and k values: ";
        long long n,k;
        cin>>n>>k;
        cout<<"nCk is "<<nCk(n,k)<<endl;
    }
    return 0;
}
