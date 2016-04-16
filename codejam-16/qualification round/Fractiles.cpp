#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream inp;
	ofstream op;
	inp.open("D-small-attempt0.in");
	op.open("D-small.out");
	int t;
	inp>>t;
	for(int i=1;i<=t;i++){
		int k,c,s;
		inp>>k>>c>>s;
		op<<"Case #"<<i<<": ";
		for(int j=1;j<=s;j++)
			op<<j<<" ";
		op<<endl;
	}
	inp.close();
	op.close();
	return 0;
}
