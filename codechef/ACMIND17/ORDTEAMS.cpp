#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
bool func(vector<int> a, vector<int> b, vector<int> c) {
	for(int i=0;i<3;i++){
		if(a[i] > b[i] || b[i] > c[i]) return false;
	}
	if(a == b || b == c || a == c) return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> a,b,c;
		for(int i=0;i<3;i++){
			int x;
			cin>>x;
			a.pb(x);
		}
		for(int i=0;i<3;i++){
			int x;
			cin>>x;
			b.pb(x);
		}
		for(int i=0;i<3;i++){
			int x;
			cin>>x;
			c.pb(x);
		}
		if(func(a,b,c) || func(a,c,b) || func(b,a,c) || func(b,c,a) || func(c,a,b) || func(c,b,a))
			cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}