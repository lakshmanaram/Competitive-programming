#include <bits/stdc++.h>
using namespace std;
int main() {
	long n;
	cin>>n;
	map<long, long> h;
	set<long> sh;
	for(long i=0;i<n;i++){
		long x;
		cin>>x;
		h[x]++;
		sh.insert(x);
	}
	long t = 0;
	long ppl_remaining = 0;
	long total_ppl = 0;
	for(set<long>::iterator it = sh.begin();it != sh.end(); it++) {
		// cout<<*it<<" ";
		if(it != sh.begin() && *it > total_ppl && ppl_remaining >= 0)
			break;
		total_ppl += h[*it];
		t = max(*it,total_ppl);
		if(sh.begin() == it)
			ppl_remaining = - *it + h[*it];
		else 
			ppl_remaining = total_ppl - *it;
		// cout<<t<< " " << ppl_remaining<<endl;
	}
	cout<<t<<endl;

	return 0;
}
/*
10
3 3 4 4 4 6 7 8 9 10
*/