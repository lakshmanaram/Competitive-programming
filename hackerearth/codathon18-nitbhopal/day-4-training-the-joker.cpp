#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
    set<pair<ll, long> > sq, cb;
    ll val = 0;
    for(long i=0;val < 1E18 + 10;i++){
        val += pow(i, 2);
        sq.insert(mp(val, i));
    }
    val = 0;
    for(long i=0;val < 1E18 + 10;i++){
        val += pow(i, 3);
        cb.insert(mp(val, i));
    }
	ll q;
	S(q);
	while(q--){
		ll n;
		int k;
		S(n);
		cin>>k;
		ll x = 1, val;
		set<pair<ll, long> >::iterator y;
		switch(k) {
			case 1:
			x = ceil(sqrt(n*2));
			val = (x+1)*(x)/2;
			while(val > n){
				x--;
				val = (x+1)*(x)/2;
			}
			break;
			case 2:
			y = sq.lower_bound(mp(x+1, -1));
			if(y == sq.begin()) 
			    x = 0;
			else {
			    y--;
			    x = y->second;
			}
			break;
			case 3:
			y = cb.lower_bound(mp(x+1, -1));
			if(y == cb.begin()) 
			    x = 0;
			else {
			    y--;
			    x = y->second;
			}
		}
		printf("%lld\n", x);
	}
	return 0;
}