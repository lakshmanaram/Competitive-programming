#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll mod = 1E9 + 7;
int main(){
	vll temp(1000005, 0);
	vector<vll> ans(3, temp);
	ans[0][1] = 1;
	ans[1][1] = 1;
	for(long i=2;i<ans[0].size();i++){
		ans[0][i] = (ans[0][i-1] + ans[1][i-1] + ans[2][i-1])%mod;
		ans[1][i] = ans[0][i-1];
		ans[2][i] = ans[1][i-1];
	}
	ll x,m;
	S(m);
	while(m--){
		ll x;
		S(x);
		printf("%lld\n", ans[0][x+1]);
	}
	return 0;
}