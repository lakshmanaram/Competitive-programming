#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	ll w, g, n;
	S(w);
	S(g);
	S(n);
	vector<string> words(w);
	for(long i=0;i<w;i++) {
		cin>>words[i];
	}
	vector<long> mval(w);
	for(long i=0;i<w;i++)
		cin>>mval[i];
	map<string, long> m;
	vector<long> groups(g);
	for(long i=0; i<g; i++) {
		long j;
		cin>>j;
		bool first = true;
		while(j--) {
			long k;
			cin>>k;
			k--;
			if(first) {
				groups[i] = mval[k];
			}
			first = false;
			m[words[k]] = i;
			groups[i] = min(groups[i], mval[k]);
		}
	}
	ll ans = 0;
	for(long i=0; i< n;i++) {
		string s;
		cin>>s;
		ans += groups[m[s]];
	}
	cout<<ans<<endl;
	return 0;
}