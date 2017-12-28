#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		ll v1, v2, v3, v4;
		v1 = v2 = v3 = v4 = 0;
		for(long i=0;i<n;i++){
			ll x;
			scanf("%lld", &x);
			switch(x%4){
				case 0:
				v4++;
				break;
				case 1:
				v1++;
				break;
				case 2:
				v2++;
				break;
				case 3:
				v3++;
				break;
			}
		}
		if((v1 + v3)&1)
			printf("-1\n");
		else {
			ll value = abs(v1 - v3);
			value /= 2;
			if((value + v2)&1)
				printf("-1\n");
			else {
				ll ans = min(v1, v3)+abs(v3 - v1)/2;
				v2 += abs(v3 - v1)/2;
				ans += v2/2;
				cout<<ans<<endl;
			}
		}

	}
	return 0;
}