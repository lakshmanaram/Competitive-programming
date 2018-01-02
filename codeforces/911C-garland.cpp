#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	bool flag = false;
	ll a, b, c;
	cin>>a>>b>>c;
	if(a == 1 || b == 1 || c == 1) flag = true;
	else {
		vector<int> arr;
		arr.pb(a);
		arr.pb(b);
		arr.pb(c);
		sort(arr.begin(), arr.end());
		if(arr[1] == 2) flag = true;
		else {
			if(b == 3 && c == 3 && a == 3) flag = true;
			if(arr[0] == 2 && arr[1] == 4 && arr[2] == 4) flag = true;
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}