#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream inp;
	ofstream op;
	inp.open("B-large.in");
	op.open("B-large.out");
	int t;
	inp>>t;
	for(int i=1;i<=t;i++){
		string a;
		inp>>a;
		int count = 0;
		char last = '+';
		for(int j=a.size()-1;j>=0;j--){
			if(a[j] != last){
				last = a[j];
				count++;
			}
		}
		op<<"Case #"<<i<<": "<<count<<endl;
	}
	inp.close();
	op.close();
	return 0;
}
