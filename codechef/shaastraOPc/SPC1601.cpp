#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
int main() {
	int t;
	t = 1;
	while(t--) {
		ll m, n, k;
	cin >> n >> m >> k;
	string instr;
	cin >> instr;
 
	string vert = "", horiz = "";
	for(int i = 0; i < instr.size(); i++) {
		if(instr[i] == 'U' || instr[i] == 'D') vert += instr[i];
		else horiz += instr[i];
	}
 
	ll vertpos[100];
	for(int z = 0; z < m; z++) {
		ll x = z;
		for(int i = 0; i < vert.size(); i++) {
			if(vert[i] == 'U') x -= (x <= 0 ? 0 : 1);
			else               x += (x >= m-1 ? 0 : 1);
		}
		vertpos[z] = min(x-0,m-x-1);
	}
 
 
	ll horizpos[100];
	for(int z = 0; z < n; z++) {
		ll x = z;
		for(int j = 0; j < horiz.size(); j++) {
			if(horiz[j] == 'L') x -= (x <= 0 ? 0 : 1);
			else                x += (x >= n-1 ? 0 : 1);
		}
		horizpos[z] = min(x-0,n-x-1);
	}
 
	int minu = m-1, maxu = 0, minl = n-1, maxl = 0;
	for(int i = 0; i < m; i++) {
		if(vertpos[i] < minu) minu = vertpos[i];
		if(vertpos[i] > maxu) maxu = vertpos[i];
	}
 
	for(int i = 0; i < n; i++) {
		if(horizpos[i] < minl) minl = horizpos[i];
		if(horizpos[i] > maxl) maxl = horizpos[i];
	}
 
	//cout << find(vertpos, vertpos+n, maxu)-vertpos << " " << maxu << " " << find(horizpos, horizpos+n, maxl)-horizpos << " " <<  maxl << endl;
	cout << maxu + maxl << endl;
	}
	return 0;
}