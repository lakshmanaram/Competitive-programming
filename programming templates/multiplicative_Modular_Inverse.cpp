#include <bits/stdc++.h>
using namespace std;
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
