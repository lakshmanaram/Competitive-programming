#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){ 

	long t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int count = 0;
		char prev = '1';
		for(long i=0;i<s.size();i++) {
			if(prev != s[i]) {
				count++;
				prev = s[i];
			}
		}
		cout<<count/2<<endl;
	}
	return 0;
}