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
	long t;
	cin>>t;
	while(t--) {
		long o,p;
		cin>>o>>p;
		vector<int> arr(o*p);
		F(i,o*p) cin>>arr[i];
		vll ones(o,0), prev;
		bool flag = false;
		F(i,o) {
			F(j,p) if(arr[i*p+j] == 1) ones[i]++; 
		}
		ll ans = 0;
		F(j,o) if(ones[j] > p/2) ans++;
		if(ans > o/2)
			flag = true;
		F(i,p-1) {
			ans = 0;
			F(j,o) {
				long change = i+j*p;
				if(arr[change] == 1){
					ones[j] -= 1;
					ones[(j-1+o)%o] += 1;
				}
			}
			F(j,o) if(ones[j] > p/2) ans++;
			if(ans > o/2){
				flag = true;
				break;
			}
		}
		if(flag) cout<<1<<endl;
		else cout<<0<<endl;
	}
  	return 0;
}