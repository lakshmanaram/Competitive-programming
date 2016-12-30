#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		map<long,bool> hash;
		for(long i=0;i<n;i++){
			long x;
			cin>>x;
			if(hash.find(x) != hash.end())
				hash[x] = false;
			else
				hash[x] = true;
		}
		for(map<long,bool>::iterator it = hash.begin();it!=hash.end();it++){
			if(it->second)
				cout<<it->first<<endl;
		}


	}
	return 0;
}