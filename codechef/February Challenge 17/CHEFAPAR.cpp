#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<bool> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
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
		vll arr(n,false);
		bool flag = false;
		ll ans = n, temp = n;
		F(i,n) {
			int a;
			cin>>a;
			if(a) {
				arr[i] = true;
				ans--;
			} else {
				flag = true;
			}
			if(!flag) {
				temp--;
			}
		}
		cout<<temp*100+ans*1000<<endl;
  	}
  	return 0;
}