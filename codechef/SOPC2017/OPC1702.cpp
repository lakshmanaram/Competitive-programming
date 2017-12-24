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
		long b, s;
		cin>>s>>b;
		double p;
		cin>>p;
		double strength = b;
		strength /= 2;
		long days = 0;
		cout<<log2((double)(b - s)/(double)(strength - s));
		double res = floor((double)log2((double)(b - s)/(double)(strength - s))/(double)log2(1-p));
		cout << res << endl;
	}
	return 0;
} 