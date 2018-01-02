#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	string s;
	cin>>s;
	ll ans = 0;
	string k = "aeiou13579";
	for(long i=0;i<s.size();i++){
		for(long j=0;j<k.size();j++){
			if(s[i] == k[j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}