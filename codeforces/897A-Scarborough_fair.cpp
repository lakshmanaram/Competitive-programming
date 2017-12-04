#include <bits/stdc++.h>
using namespace std;
string s;
void func(int l, int r, char c, char d){
	for(int i=l;i<r;i++){
		if(s[i] == c) s[i] = d;
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	cin>>s;
	while(q--){
		int l,r;
		char c,d;
		cin>>l>>r>>c>>d;
		func(l-1,r,c,d);
	}
	cout<<s<<endl;
	return 0;
}