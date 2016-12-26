#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	string puz;
	bool ans = true;
	for (int i=0;i<n;i++) {
		cin>>s;
		if(s.find('X')==string::npos)
			continue;
		string x = "";
		bool started = false;
		bool ended = false;
		for(int j=0;j<s.size();j++){
			if(s[j] == 'X' && ended){
				ans = false;
				break;
			}
			if(s[j] == 'X' && !started){
				started = true;
				x += 'X';
			} else if(s[j] == 'X' && started)
				x += 'X';
			else if(s[j] == '.' && started && !ended){
				ended = true;
			}
		}
		if(puz.size()!=0 && x.size()!=puz.size())
			ans = false;
		puz = x;
		if(!ans)
			break;
	}

	if(ans)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}