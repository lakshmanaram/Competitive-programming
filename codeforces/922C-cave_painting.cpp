#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main(){
	ll n, k;
	cin>>n>>k;
	if(k == 1){
		cout<<"Yes"<<endl;
	} else {
		if(n <= k) cout<<"No"<<endl;
		else {
			ll ans = 1;
			ll step = 2;
			ll i = 3;
			bool flag = true;
			while(i <= k)  {
				cout<<ans<<endl;
				ans += step*(i/gcd(step, i)-1);
				if(!flag) break;
				step /= gcd(step, i);
				step *= i;
				i++;
			}

			if(flag) {
				if(ans > n || (n-ans)%step != 0)
					cout<<"No"<<endl;
				else
					cout<<"Yes"<<endl;
			}
			else cout<<"No"<<endl;
		}
	}
	return 0;
}