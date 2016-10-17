#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long powd(long ans) {
	if(ans == 1)
		return 2;
	long long temp = powd(ans/2)%mod;
	if(ans % 2 == 0){
		return (temp*temp)%mod;
	} else {
		return (((temp*temp)%mod)*2)%mod;
	}
}
bool func(string &a, string &b) {
	bool noa, nob, nta, ntb;
	noa = false;
	nob = false;
	nta = false;
	ntb = false;
	if(a[a.size()-2] == '2' || b[b.size()-2] == '2')
		return false;
	for(long i=0;i<a.size();i++) {
		if(a[i] == '2' && b[i] == '2') {
			if(noa || nob){
				// cout<<"both 2"<<endl;
				return false;
			}
			else if(nta && ntb) {
				nta = ntb = false;
				noa = nob = true;
			} else if(nta) {
				nta = false;
				ntb = noa = true;
			} else if(ntb) {
				ntb = false;
				nta = nob = true;
			} else {
				nta = ntb = true;
			}
		} else if ( a[i] == '1' && b[i] == '1') {
			if(nta || ntb){
				// cout<<i<<" both 1"<<endl;
				return false;
			}
			else if(noa && nob) {
				noa = nob = false;
			} else if(noa) {
				noa = false;
			} else if(nob) {
				nob = false;
			}
		} else {
			if((noa && nob) || (nta && ntb)){
				return false;
			}
			else if(!noa && !nob && !nta && !ntb) {
				nta = true;
				a[i] = '2';
				b[i] = '1';
			} else {
				if(noa) {
					a[i] = '1';
					b[i] = '2';
					if(ntb){
						ntb = false;
						nob = true;
					} else {
						ntb = true;
					}
					noa = false;
				} else if(nta) {
					a[i] = '2';
					b[i] = '1';
					if(nob){
						nob = false;
					}
					nta = false;
					noa = true;
				} else if(nob) {
					b[i] = '1';
					a[i] = '2';
					nob = false;
					nta = true;
				} else if(ntb) {
					b[i] = '2';
					a[i] = '1';
					ntb = false;
					nob = true;
				}
			}
		}
	}
	return true;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		string a,b;
		cin>>a>>b;
		string tempa = a, tempb = b;
		if(a.size() <= 3) {
			bool flag = true;
			for(int i=0;i<a.size()-1;i++)
				if(a[i] == '2' || b[i] == '2')
					flag = false;
			if(flag) {
				long long x = pow(2,a.size());
				cout<<x<<endl;
			} else {
				cout<<0<<endl;
			}
			continue;
		}
		if(!func(a,b)){
			cout<<0<<endl;
			continue;
		}
		long ans = 0;
		bool ns = false;
		for(long i=0; i<a.size()-1;i++){
			if(ns) {
				if(a[i] == b[i]) {
					if(a[i] == '1'){
						ns = false;
						ans++;
					}
					ans++;
				}
			}
			else if(a[i] == b[i])
				ans++;
			else
				ns = true;
 
		}
		ans++;
		// cout<<ans<<" ";
		cout<<powd(ans)<<endl;
	}
	return 0;
}