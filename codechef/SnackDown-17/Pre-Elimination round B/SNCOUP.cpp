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
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		long ans = 0;
		long sides = 0; 
		for(long i=0;i<n;i++) {
			if(a[i] == '*' || b[i] == '*') {
				sides++;
				if(a[i] == '*' && b[i] == '*')
					ans = 1;
			}
		}
		long ac , bc;
		ac = bc = 0;
		long temp = 0;
		for(long i=0;i<n;i++) {
			if(a[i] == '*' && ac == 1) {
				ac = bc = 0;
				temp++;
			}
			if(b[i] == '*' && bc == 1) {
				ac = bc = 0;
				temp++;
			}
			if(a[i] == '*') ac++;
			if(b[i] == '*') bc++;
		}
		if(ans == 0) {
			// middle is not necessary
			ans = max((long) 0, min(sides-1,temp+1));
		} else {
			ans += temp;
		}
		cout<<ans<<endl;
	}
  	return 0;
}