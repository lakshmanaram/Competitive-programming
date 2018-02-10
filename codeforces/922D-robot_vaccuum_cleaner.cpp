#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<string> sa(n);
	vector<pair<long, pair<long, long> > > p;
	long ovs, ovh;
	ovs = ovh = 0;
	for(long i=0;i<n;i++) {
		// cout<<"out here\n";
		cin>>sa[i];
		long s = 0;
		long h = 0;
		for(long j=0;j<sa[i].size();j++){
			if(sa[i][j] == 's') s++;
			else h++;
		}
		ovs += s;
		ovh += h;
		p.pb(mp(min(h, s), mp(-max(h, s), i)));
	}
	sort(p.begin(), p.end());
	string front = "", back = "";
	for(long i=0;i<p.size();i++){
		// cout<<p[i].first<<" "<<p[i].second.first<<" "<<sa[p[i].second.second]<<endl;
		long s = 0, h = 0;
		for(long j=0;j<sa[p[i].second.second].size();j++){
			if(sa[p[i].second.second][j] == 's') s++;
			else h++;
		}
		// cout<<s<<" "<<h<<endl;
		if(s >= h){
			front += sa[p[i].second.second];
		} else {
			reverse(all(sa[p[i].second.second]));
			back += sa[p[i].second.second];
		}
		// cout<<front<<" "<<back<<endl;
	}
	reverse(all(back));
	front += back;
	ll ans = 0;
	for(long i=0;i<front.size();i++){
		if(front[i] == 's') ans += ovh;
		else ovh--;
	}
	cout<<ans<<endl;
	return 0;
}