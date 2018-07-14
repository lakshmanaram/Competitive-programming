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
    infile.open("interception.txt");
    outfile.open("output.txt");
	long t;
    infile>>t;
	for (long t1 = 1; t1 <= t; t1++) {
		long n;
		infile >> n;
		long long x;
		for (long i = 0; i <= n; i++) {
			infile >> x;
		}
		outfile << "Case #" << t1 << ":";
		if (n&1)
			outfile << " 1\n0.0\n";
		else
			outfile << " 0\n";
	}
	infile.close();
	outfile.close();
	return 0;
}