#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
vector<string> arr;
ll si, sj, ei, ej;
string movement;
bool possible(long i, long j){
	if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size() || arr[i][j] == '#')
		return false;
	return true;
}
bool check(string a){
	long i = si, j = sj;
	for(long k=0;k<movement.size();k++){
		if(a[movement[k]-'0'] == 'U') i++;
		else if(a[movement[k]-'0'] == 'D') i--;
		else if(a[movement[k]-'0'] == 'R') j++;
		else if(a[movement[k]-'0'] == 'L') j--;
		if(!possible(i, j)) return false;
		if(i == ei && j == ej) return true;
	}
	return false;
}
int main(){
	ll n,m;
	cin>>n>>m;
	arr.resize(n);
	for(long i=0;i<n;i++) cin>>arr[i];
	for(long i=0;i<n;i++){
		for(long j=0;j<m;j++){
			if(arr[i][j] == 'S'){
				si = i;
				sj = j;
			}
			if(arr[i][j] == 'E'){
				ei = i;
				ej = j;
			}
		}
	}
	cin>>movement;
	string possibilities[24] = {"LRDU", "LRUD", "LUDR", "LURD", "LDUR", "LDRU", "RLDU", "RLUD", "RUDL", "RULD", "RDUL", "RDLU", "DRLU", "DRUL", "DULR", "DURL", "DLUR", "DLRU", "URDL", "URLD", "ULDR", "ULRD", "UDLR", "UDRL"};
	ll ans = 0;
	for(long i=0;i<24;i++){
		if(check(possibilities[i])) 
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}