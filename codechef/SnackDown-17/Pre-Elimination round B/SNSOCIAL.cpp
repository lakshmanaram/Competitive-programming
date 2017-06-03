#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n,m;
		cin>>n>>m;
		vll temp(m);
		vvll arr(n,temp);
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>arr[i][j];
			}
		}
		ll maxval = 0;
		vpll maxvals;
		queue<pll> q;
		for(int i=0;i<n;i++) {
			for(int j=0; j<m;j++) {
				if(arr[i][j] > maxval) {
					maxval = arr[i][j];
					maxvals.clear();
					maxvals.pb(mp(i,j));
				} else if(arr[i][j] == maxval) {
					maxvals.pb(mp(i,j));
				}
			}
		}
		vll tem(m,n+m);
		vvll ans(n,tem);
		for(long i=0;i<maxvals.size();i++) {
			q.push(maxvals[i]);
			ans[maxvals[i].first][maxvals[i].second] = 0;
		}
		while(q.size()!=0) {
			pll xr = q.front();
			q.pop();
			long x,y;
			x = xr.first;
			y = xr.second;
			for(long i=max((long)0,x-1);i<min(n,x+2);i++) {
				for(long j=max((long)0,y-1);j<min(m,y+2);j++) {
					if(ans[i][j] > ans[x][y] + 1) {
						ans[i][j] = ans[x][y]+1;
						q.push(mp(i,j));
					}
				}
			}
		}
		long aval = 0;
		for(long i=0;i<n;i++) {
			for(long j=0;j<m;j++) {
				aval = max(aval,ans[i][j]);
			}
		}
		cout<<aval<<endl;
	}
  	return 0;
}