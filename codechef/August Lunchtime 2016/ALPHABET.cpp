#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,x;
	cin>> a;
	vector<bool> hash(26,false);
	for(int i=0;i<a.size();i++) {
		hash[a[i]-'a'] = true;
	}
	long n;
	cin>>n;
	while(n--) {
		cin>>x;
		bool answer = true;
		for(long i=0;i<x.size();i++){
			if(!hash[x[i]-'a']){
				answer = false;
				break;
			}
		}
		if(answer)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}