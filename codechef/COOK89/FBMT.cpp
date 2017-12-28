#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		string a, b;
		a = b = "lakshmanaram";
		long asc, bsc;
		asc = bsc = 0;
		while(n--){
			string s;
			cin>>s;
			if(a == s){
				asc++;
			} else if(b == s){
				bsc++;
			} else if(a == "lakshmanaram"){
				a = s;
				asc++;
			} else if(b == "lakshmanaram") {
				b = s;
				bsc++;
			}
		}
		if(asc > bsc){
			cout<<a<<endl;
		} else if(bsc > asc) {
			cout<<b<<endl;
		} else {
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}