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
    infile.open("tourist.txt");
    outfile.open("output.txt");
	long t;
    infile>>t;
	for (long t1 = 1; t1 <= t; t1++) {
		long n, k;
		ll v;
		infile >> n >> k >> v;
		vector<string> arr(n);
		for (long i = 0; i < n; i++) {
			infile >> arr[i];
		}
		v--;
		v %= n;
		ll overall_count = k*(v);
		vector<pair<long, string> > ans_vec;
		ll start = overall_count % n;
		while(k--) {
			ans_vec.pb(mp(start, arr[start]));
			start++;
			start %= n;
		}
		sort(all(ans_vec));
		outfile << "Case #" << t1 << ":";
		for (long i = 0; i < ans_vec.size(); i++) {
			outfile << " " << ans_vec[i].second;
		}
		outfile << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}