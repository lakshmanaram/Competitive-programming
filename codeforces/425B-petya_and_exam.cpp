#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	vector<bool> harr(26, false);
	for(int i=0;i<a.size();i++){
		harr[a[i]-'a'] = true;
	}	
	string arr;
	cin>>arr;
	bool iscomplex = false;
	for(long i=0;i<arr.size();i++){
		if(arr[i] == '*'){
			iscomplex = true;
			break;
		}
	}
	long q;
	cin>>q;
	string yes="YES";
	string no = "NO";
	if(iscomplex){
		while(q--) {
			string s;
			cin>>s;
			bool ans = true;
			if(arr.size() > s.size()+1)
				ans = false;
			else {
				long j = s.size()-1;
				long k=0;
				for(;k<arr.size();k++){
					if(arr[k] == '*')
						break;
					else if(arr[k] == '?'){
						if(!harr[s[k]-'a']){
							ans = false;
							break;
						}
					}
					else if(arr[k] != s[k]){
						ans = false;
						break;
					}
				}
				long i = 1;
				for(;j>=k;j--){
					if(s.size()-j >= arr.size()-k){
						if(harr[s[j]-'a']){
							ans = false;
							break;
						}
					} else {
						if(arr[arr.size()-i] == '?'){
							if(!harr[s[s.size()-i]-'a']){
								ans = false;
								break;
							}
						}
						else if(s[s.size()-i] != arr[arr.size()-i]){
							ans = false;
							break;
						}
					}
					i++;
				}
			}
			cout<<((ans)?yes:no)<<endl;
		}
	} else {
		while(q--) {
			string s;
			cin>>s;
			bool ans = true;
			long i = 0, j = s.size()-1;
			long k=0;
			for(;k<arr.size();k++){
				if(arr[k] == '?'){
					if(!harr[s[k]-'a']){
						ans = false;
						break;
					}
				}
				else if(arr[k] != s[k]){
					ans = false;
					break;
				}
			}
			if(arr.size()!=s.size())
				ans = false;
			cout<<((ans)?yes:no)<<endl;
		}
	}
	return 0;
}