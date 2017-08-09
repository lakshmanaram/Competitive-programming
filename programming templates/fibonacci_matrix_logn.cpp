#include <bits/stdc++.h>
#define ll long long
#define matrix pair<pair<ll, ll>, pair<ll, ll> >
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
using namespace std;
matrix unit;
matrix multiply(matrix a, matrix b){
    matrix c;
    c.f.f = (a.f.f*b.f.f + a.f.s*b.s.f)%mod;
    c.f.s = (a.f.f*b.f.s + a.f.s*b.s.s)%mod;
    c.s.f = (a.s.f*b.f.f + a.s.s*b.s.f)%mod;
    c.s.s = (a.s.f*b.f.s + a.s.s*b.s.s)%mod;
    return c;
}

matrix fast_multiply(matrix a, long long n){
	if(n == 1)
		return a;
	matrix temp = fast_multiply(a,n/2);
	return (n&1)?multiply(multiply(temp, temp), unit):multiply(temp, temp);	
}

ll fibo( ll n ){
	if(n <= 1) return 1;
	matrix a = fast_multiply(unit, n);
	return a.first.first;
}

int main() {
	unit = mp(mp(1,1), mp(1,0));
	while(true){
		long long x;
		cout<<"Enter fibonacci index: ";
		cin>>x;
		cout<<fibo(x)<<endl;
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
