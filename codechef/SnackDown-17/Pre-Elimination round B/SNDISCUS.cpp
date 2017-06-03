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
		long n;
		cin>>n;
		vector<pair<pll,pll> > vals;
		while(n--) {
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(b > d) swap(b,d);
			if(a > c) swap(a,c);
			vals.pb(mp(mp(a-1,b-1),mp(c-1,d-1)));
		}
		vll temp(50,0);
		vvll ans(50,temp);
		long ansval = 0;
		for(long i=0;i<50;i++) {
			for(long j=0;j<50;j++) {
				for(long k=0;k<vals.size();k++) {
					long temp = 0;
					if(vals[k].first.first <= i && i <= vals[k].second.first)
						temp += 0;
					else 
						temp += min(abs(i-vals[k].first.first),abs(i-vals[k].second.first));
					if(vals[k].first.second <= j && j <= vals[k].second.second)
						temp += 0;
					else 
						temp += min(abs(j-vals[k].first.second),abs(j-vals[k].second.second));
					if(k == 0) ans[i][j] = temp;
					else ans[i][j] = max(ans[i][j],temp);
				}
			}
			if(i==0) ansval = *min_element(ans[i].begin(),ans[i].end());
			else ansval = min(ansval,*min_element(ans[i].begin(),ans[i].end()));
		}
		cout<<ansval<<endl;
	}
  	return 0;
}