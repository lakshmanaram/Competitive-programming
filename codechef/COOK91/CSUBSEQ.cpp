#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
string clean(string &s){
	int c, h, e, f;
	string ans = "";
	c = h = e = f = 0;
	for(long i=0;i<s.size();i++){
		if(s[i] == 'c') c++;
		else if (s[i] == 'h') {
			if(c == 0) continue;
			h++;
		}
		else if (s[i] == 'e') {
			if(h == 0) continue;
			e++;
		}
		else {
			if(e == 0) continue;
			f++;
		}
		ans += s[i];
	}
	s = ans;
	ans = "";
	reverse(all(s));
	c = h = e = f = 0;
	for(long i=0;i<s.size();i++){
		if(s[i] == 'f') f++;
		else if (s[i] == 'e') {
			if(f == 0) continue;
			e++;
		}
		else if (s[i] == 'h') {
			if(e == 0) continue;
			h++;
		}
		else {
			if(h == 0) continue;
			c++;
		}
		ans += s[i];
	}
	reverse(all(ans));
	return ans;
}
// int find_all(ans) {

// }
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n,k;
		cin>>n>>k;
		string s;
		// cin>>s;
		s = "ffhffhffcfechchccccfhhhfhhhhhhehhhehhhhheeeeefeeeeeeheeheeeeffcfffffffffffhffffchffeffcefefhhfcehfe";
		s = clean(s);	
		cout<<s;
	}
	return 0;
}