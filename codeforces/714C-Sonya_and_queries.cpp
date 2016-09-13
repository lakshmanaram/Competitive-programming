#include <bits/stdc++.h>
using namespace std;
int main(){
	long t;
	cin>>t;
	map<string,long> ans;
	long long q;
	string qs;
	char ch;
	while(t--){
		cin>>ch;
		if(ch == '+') {
			cin>>q;
			qs = "";
			while(q){
				if(q%2 == 0)
					qs += '0';
				else
					qs += '1';
				q /= 10;
			}
			reverse(qs.begin(),qs.end());
			// while(qs.size()<=18){
				ans[qs]++;
				// qs = '0'+qs;
			// }
		} else if(ch == '-') {
			cin>>q;
			qs = "";
			while(q){
				if(q%2 == 0)
					qs += '0';
				else
					qs += '1';
				q /= 10;
			}
			reverse(qs.begin(),qs.end());
			// while(qs.size()<=18){
				ans[qs]--;
				// cout<<"->"<<ans[qs]<<endl; 
				// qs = '0'+qs;
			// }
		} else {
			cin>>qs;
			long long aval = 0;
			while(qs.size()!=1 && qs[0] == '0'){
				qs = qs.substr(1);
			}
			while(qs.size()<=18){
				if(ans.find(qs)!=ans.end())
					aval += ans[qs];
				qs = '0'+qs;
			}
			cout<<aval<<endl;
		}
	}
	return 0;
}