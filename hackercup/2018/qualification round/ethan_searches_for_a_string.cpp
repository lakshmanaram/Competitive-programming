#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	ifstream infile;
    ofstream outfile;
    infile.open("ethan_searches_for_a_string.txt");
    outfile.open("output.txt");
	long t;
    infile>>t;
	for (long t1 = 1; t1 <= t; t1++) {
		string s;
		infile >> s;
		bool ans_found = false;
		string ans;
		long i = 0;
		for (long j = 1; j < s.size();j++) {
			if (s[i] == s[j]) {
				bool changes = false;
				for (long k = i, l = j; k < j && l < s.size(); k++, l++) {
					if(s[k] != s[l]) {
						changes = true;
					}
				}
				if (changes) {
					ans = s.substr(0,j) + s;
					ans_found = true;
				}
			}
			if (ans_found) break;
		}
		outfile << "Case #" << t1 << ":";
		if(ans_found)
			outfile << " " << ans;
		else
			outfile << " Impossible";
		outfile << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}