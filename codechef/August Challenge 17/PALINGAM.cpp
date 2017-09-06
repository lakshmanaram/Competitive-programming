#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--) {
		string a, b;
		cin>>a>>b;
		vector<int> hasha(26,0), hashb(26,0);
		for(int i=0;i<a.size();i++)
			hasha[a[i]-'a']++;
		for(int i=0;i<b.size();i++)
			hashb[b[i]-'a']++;
		bool flag = true;
		for(int i=0;i<26;i++){
			if((hasha[i] > 0 && hashb[i] > 0) || (hasha[i] == 0 && hashb[i] == 0)) continue;
			else flag = false;
		}
		if(flag) cout<<"B\n";
		else {
			for(int i=0;i<26;i++)
				if(hasha[i] > 1 && hashb[i] == 0) flag = true;
			if(flag) cout<<"A\n";
			else {
				int bspecial = 0, aspecial = 0;
				for(int i=0;i<26;i++){
					if(hasha[i] == 0 && hashb[i] > 0) bspecial++;
					if(hashb[i] == 0 && hasha[i] > 0) aspecial++;
				}
				if(bspecial == 0) cout<<"A\n";
				else cout<<"B\n";
			}
		}
	}
	return 0;
}