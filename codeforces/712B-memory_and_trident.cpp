#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	long u,d,l,r;
	u = d = l = r = 0;
	for(long i=0;i<s.size();i++){
		if(s[i] == 'U')
			u++;
		else if(s[i] == 'D')
			d++;
		else if(s[i] == 'R')
			r++;
		else
			l++;
	}
	long diffy = abs(u-d), diffx = abs(l-r);
	if((diffx+diffy)%2 == 0)
		cout<<(diffx+diffy)/2;
	else
		cout<<-1;
	
	return 0;
}