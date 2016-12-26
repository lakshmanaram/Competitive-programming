#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int k;
		cin>>k;
		string s;
		cin>>s;
		bool flag = true;
		if(s.size() == 1){
			if(s[0] == '?')
				cout<<"0"<<endl;
			else if(s[0] < '0'+k)
				cout<<s<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
		if(k == 2) {
			if(s.size()%2 != 0){
				cout<<"NO"<<endl;
				continue;
			}
			string temp1 = "0",temp2 = "1";
			for(int i=1;i<s.size();i++) {
				temp1 += temp2[i-1];
				temp2 += temp1[i-1];
			}
			for(int i=0;i<s.size();i++)
				if(s[i] != temp1[i] && s[i]!='?')
					flag = false;
			if(flag)
				cout<<temp1<<endl;
			else {
				flag = true;
				for(int i=0;i<s.size();i++)
					if(s[i] != temp2[i] && s[i]!='?')
						flag = false;
				if(flag)
					cout<<temp2<<endl;
				else
					cout<<"NO"<<endl;
			}
		} else {
			for(int i=0;i<s.size() && flag;i++){
				int l = i-1;
				int r = i+1;
				if(l == -1) l += s.size();
				if(r == s.size()) r -= s.size();
				if(s[i] == '?'){
					char paint = '0';
					bool colored = false;
					while(!colored && paint < k+'0') {
						if(s[l]!=paint && s[r]!=paint) {
							s[i] = paint;
							colored = true;
						}
						paint++;
					}
					if(!colored)
						flag = false;
				} else {
					if(s[l]==s[i] || s[r]==s[i] || s[i] >= '0'+k){
						flag = false;
					}
				}
			}
			if(flag)
				cout<<s<<endl;
			else
				cout<<"NO"<<endl;
		}
	}	
	return 0;
}