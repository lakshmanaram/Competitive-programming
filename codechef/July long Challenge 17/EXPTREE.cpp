#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull moda, modb;
ull pow(ull a, ull b, ull mod) {
ull x = 1, y = a;
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
ull mmi(ull a, ull mod) {
    return pow(a,mod-2, mod);
}
ull gcd(ull a, ull b){
	if(a == 0) return b;
	return gcd(b%a,a);
}

int main(){
	moda = 1000000007;
	modb = 1000000009;
	long t;
	cin>>t;
	while(t--){
		ull n;
		cin>>n;
		n--;
		ull num = n;
		ull den = 2*n-1;
		den <<= 1;
		ull g = gcd(num,den);
		if( g != 1){
			num /= g;
			den /= g;
		}
		ull num1 = n+1;
		g = gcd(num1,den);
		if( g != 1){
			num1 /= g;
			den /= g;
		}
		ull numa = ((num%moda)*(num1%moda))%moda;
		ull numb = ((num%modb)*(num1%modb))%modb;
		ull dena = den % moda;
		ull denb = den%modb;
		cout<<(numa*(mmi(dena,moda)))%moda<<" "<<(numb*(mmi(denb,modb)))%modb<<endl;
	}
    return 0;
}
