#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	bool flag = false;
	int start;
	for(int i=0;i<s.size();i++)	
		if(s[i]=='G')
			start = i;
	int x = start;
	while(x >= 0){
		if(flag)
			break;
		if(s[x] == '#')
			break;
		if(s[x] == 'T')
			flag = true;
		x -= k;
	}
	x = start;
	while(x < s.size()){
		if(flag)
			break;
		if(s[x] == '#')
			break;
		if(s[x] == 'T')
			flag = true;
		x += k;
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
