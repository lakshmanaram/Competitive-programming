#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%ld", &a)
using namespace std;
int main(){
	map<string, string> ma;
	long n, m;
	S(n);
	S(m);
	while(n--){
		string s, t;
		cin>>s>>t;
		ma[t+";"] = s;
	}
	while(m--) {
		string s, t;
		cin>>s>>t;
		cout<<s<<" "<<t<<" #"<<ma[t]<<endl;
	}
	return 0;
}