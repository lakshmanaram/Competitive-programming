#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F(i,n) for(long i=0;i<n;i++)
#define pll pair<ll, ll>
#define vpll vector<pll>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,k,m;
		cin>>n>>k>>m;
		ll sl = (n-k)/2+1, el = (n+k)/2;
		vpll row, col;
		F(i,m) {
			ll x,y,a,b;
			cin>>x>>y>>a>>b;
			if(x == a) {
				if(x >= sl && x <= el) {
					// affects row
					row.pb(mp(x,x));
				} else {
					col.pb(mp(min(y,b),max(y,b)));
					// x affects col
				}
			} else {
				if(y >= sl && y <= el) {
					col.pb(mp(y,y));
					// affects col
				} else {
					row.pb(mp(min(x,a),max(x,a)));
					// y affects row
				}
			}
		}
		sort(row.begin(),row.end());
		sort(col.begin(),col.end());
		long long ans = 0, end = sl, maxval = 0;
		F(i,row.size()) {
			if(end > el) break;
			if(row[i].first <= end) {
				maxval = max(maxval,row[i].second);
			} else {
				if(maxval+1 > end) {
					end = maxval+1;
					i--;
					ans++;
				}
				else break;
			}
		}
		if(maxval+1 > end) {
			end = maxval+1;
			ans++;
		}
		if(end <= el) {
			cout<<-1<<endl;
		} else {
			end = sl, maxval = 0;
			F(i,col.size()) {
				if(end > el) break;
				if(col[i].first <= end) {
					maxval = max(maxval,col[i].second);
				} else {
					if(maxval+1 > end) {
						i--;
						end = maxval+1;
						ans++;
					}
					else break;
				}
			}
			if(maxval+1 > end) {
				end = maxval+1;
				ans++;
			}
			if(end <= el) {
				cout<<-1<<endl;
			} else {
				cout<<ans<<endl;
			}
		}
	}
	return 0;
} 
