#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
	string s;
	cin>>s;
	vector<int> options(s.size());
	for(long i=0;i<s.size();i++){
		options[i] = (int)'Z'-(int)s[i];
		// cout<<options[i]<<" ";
	}
	// cout<<endl;
	long long multip = 1;
	long long precomp = 0;
	long long mmi26 = 576923081;
	for(long i=1;i<s.size();i++){
		precomp += multip*options[i];
		multip *= 26;
		multip %= mod;
		if(multip < 0) multip += mod;
		precomp %= mod;
		if(precomp < 0) precomp += mod;
	}
	// cout<<"precomp = "<<precomp<<endl;
	long long ans = 0;
	for(long i=0;i<s.size()-1;i++){
	
		precomp++;
		precomp %= mod;
		if(precomp < 0) precomp += mod;
		long long temp = options[i];
		temp *= precomp;
		temp %= mod;
		if(temp < 0) temp += mod;
		// cout<<"precomp1 = "<<precomp<<endl;
		ans += temp;
		ans %= mod;
		if(ans < 0) ans += mod;
		
		precomp--;
		precomp %= mod;
		if(precomp < 0) precomp += mod;
		// cout<<"precomp2 = "<<precomp<<endl;
		precomp -= options[i+1];
		precomp %= mod;
		if(precomp < 0) precomp += mod;
		// cout<<"precomp3 = "<<precomp<<endl;
		precomp *= mmi26;
		// cout<<"mmi26 = "<<mmi26<<endl;
		// cout<<"precomp dunno = "<<precomp<<endl;

		precomp %= mod;
		if(precomp < 0) precomp += mod;
		// cout<<"precomp4 = "<<precomp<<endl;
	}
	ans += options[options.size()-1];
	ans %= mod;
	if(ans < 0) ans += mod;	
	cout<<ans<<endl;
}