#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	long capb = 0;
	vector<long> hash(26,0);
	for(long i=0;i<s.size();i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			hash[s[i]-'a']++;
		else if(s[i] == 'B')
			capb++;
	}
	capb = min(capb,hash[0]/2);
	capb = min(capb,hash['u'-'a']/2);
	capb = min(capb,hash[1]);
	capb = min(capb,hash['l'-'a']);
	capb = min(capb,hash['s'-'a']);
	capb = min(capb,hash['r'-'a']);
	cout<<capb<<endl;
	return 0;
}
