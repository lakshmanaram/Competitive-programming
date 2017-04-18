#include <bits/stdc++.h>
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long long n;
		cin>>n;
		if(n == 1)
			cout<<"INFINITY\n";
		else if(n == 2)
			cout<<1<<endl;
		else if(n == 0)
			cout<<0<<endl;
		else if(n == 3)
			cout<<2<<endl;
		else if(n == 4)
			cout<<3<<endl;
		else {
			double left = log10((double)n/2), right = log10(n);
			long long ans = 0;
			long i=1;
			long long cl = floor(pow(10,left/i)), cr = floor(pow(10,right/i));
			if(pow(cl+1,i) <= ((double)n)/2)
				cl++;
			if(pow(cr+1,i) <= n)
				cr++;
			while(cr != 2) {
				// cout<<cl<<" "<<cr<<endl;
				ans += cr-cl;
				i++;
				cl = floor(pow(10,left/i));
				cr = floor(pow(10,right/i));
				if(pow(cl+1,i) <= ((double)n)/2)
					cl++;
				if(pow(cr+1,i) <= n)
					cr++;
			}
			cout<<ans+1<<endl;
		}
	}
	return 0;
}