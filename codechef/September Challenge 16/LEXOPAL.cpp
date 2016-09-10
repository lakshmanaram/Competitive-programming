#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int j = s.size()-1;
		bool pal = true;
		for(int i=0;i <= j;i++,j--){
			if(s[i] != s[j]){
				if(s[i] == '.') {
					s[i] = s[j];
				} else if(s[j] == '.'){
					s[j] = s[i];
				} else {
					pal = false;
					break;
				}
			} else if(s[i] == '.'){
				s[i] = s[j] = 'a';
			}
		}
		if(pal)
			cout<<s<<endl;
		else
			cout<<-1<<endl;

	}
	return 0;
}