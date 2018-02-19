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
	string s;
	cin>>s;
	int direction = -1;
	long x = 0;
	long y = 0;
	long ans = 0;
	for(long i = 0; i<s.size();i++) {
		if(s[i] == 'U') {
			y++;
		} else x++;
		if(direction == -1) {
			if(x > y) direction = 1;
			else direction = 0;
		}
		if(x > y && direction == 0) {
			direction = 1;
			ans++;
		}
		if(x < y && direction == 1) {
			direction = 0;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}