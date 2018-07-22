#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	string s;
	cin >> s;
	string ans = "";
	string ones = "";
	for (long i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			ones += s[i];
		else ans += s[i];
	}
	long i = 0;
	while(i < ans.size()) {
		if(ans[i] == '2')
			break;
		i++;
	}
	cout << ans.substr(0, i) + ones + ans.substr(i) << endl; 
	return 0;
}