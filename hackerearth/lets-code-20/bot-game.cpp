#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		ll n, m, x, y;
		S(n);
		S(m);
		S(x);
		S(y);
		ll ans = min(x-1, y-1);
		ans = min(ans, min(n-x, m-y));
		ans--;
		if(ans >= 4)
			printf("Shivam\n");
		else 
			printf("Mavis\n");
	}
	return 0;
}