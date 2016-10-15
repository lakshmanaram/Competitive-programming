#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > memorization;
string st;
long long count_substrings(int i, int j) {
	if(memorization[i][j]!=-1)
		return memorization[i][j];
	if(i==j){
		memorization[i][j] = 1;
		return 1;
	}
	if(i > j)
		return 0; // should never occur ideally
	memorization[i][j] = count_substrings(i+1,j) + count_substrings(i,j-1);
	if(st[i] == st[j])
		memorization[i][j] ++;
	else 
		memorization[i][j] -= count_substrings(i+1,j-1);
	return memorization[i][j];
}
long long no_palindromic_subsequences(string s) {
	st = s;
	memorization.clear();
	vector<long long> temp(s.size(),-1);
	memorization.resize(s.size(),temp);
	for(int i=0; i<s.size();i++){
		for(int j=i;j<s.size();j++) {
			memorization[i][j] = count_substrings(i,j);
			// cout<<memorization[i][j]<<" ";
		}
		// cout<<endl;
	}
	return memorization[0][s.size()-1];
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		string a;
		cin>>a;
		cout<<no_palindromic_subsequences(a)<<endl;
	}
	return 0;
}