#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define s(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define F(i,n) for(typeof(n) i=0;i<n;i++)
#define R(i,n) for(typeof(n) i=n-1;i>=0;i--)
int main(){
	long n;
	cin>>n;
	long long l,r;
	cin>>l>>r;
	vll arr(n,false);
	F(i,n) cin>>arr[i];
	sort(all(arr));
	vpll a;
	F(i,n-1) {
		if(arr[i+1]+arr[i]-1 >= arr[i+1]-arr[i]+1)
			a.pb(mp(arr[i+1]-arr[i]+1,arr[i+1]+arr[i]-1));
	}
	sort(all(a));
	ll ans = 0;
	F(i,s(a)) {
		if(l > a[i].second) {
			continue;
		} else if(l <= a[i].second && a[i].second < r) {
			ans += a[i].second - max(l,a[i].first) +1;
			l = a[i].second + 1;
		} else if(a[i].first > r)
			break;
		else if(a[i].second >= r) {
			ans += r - max(l,a[i].first) +1;
			l = r + 1;
			break;
		}
	}
	cout<<ans<<endl;
  	return 0;
}