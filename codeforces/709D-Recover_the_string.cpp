#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a00, a01,a10,a11;
	cin>>a00>>a01>>a10>>a11;
	long long zeros = 2*a00, ones = 2*a11;
	if(zeros != 0)
		zeros = sqrt(zeros) +1;
	if(ones != 0)
		ones = sqrt(ones) +1;
	if(zeros*(zeros-1)!=2*a00 || ones*(ones-1)!=2*a11 || a01+a10 != zeros*ones)
		cout<<"Impossible"<<endl;
	else if (zeros ==0 && ones ==0 && a01 == 0 && a10 ==0)
		cout<<0<<endl;
	else {
		string ans;
		if(a00 == 0){
			for(long long i=0;i<ones;i++)
				ans += '1';
		} else if(a11 == 0){
			for(long long i=0;i<zeros;i++)
				ans += '0';
		} else if(a10 == 0) {
			for(long long i=0;i<zeros;i++)
				ans += '0';
			for(long long i=0;i<ones;i++)
				ans += '1';
		} else if(a01 == 0) {
			for(long long i=0;i<ones;i++)
				ans += '1';
			for(long long i=0;i<zeros;i++)
				ans += '0';
		} else{
			bool yes = false;
			long long noz,noo;
			long long prod = a01;
			for(long long i=1; i<= sqrt(prod); i++){
				if(prod%i == 0) {
					long long j = prod/i;
					if(i <= zeros && j <= ones) {
						noz = i;
						noo = j;
						yes = true;
						break;
					} else if(i <= ones && j <= zeros) {
						noz = j;
						noo = i;
						yes = true;
						break;
					}
				}
			}
			if(yes){
				ones -= noo;
				zeros -= noz;
				for(long long i=0;i<ones;i++)
					ans += '1';
				for(long long i=0;i<noz;i++)
					ans += '0';
				for(long long i=0;i<noo;i++)
					ans += '1';
				for(long long i=0;i<zeros;i++)
					ans += '0';
			} else {
				prod = a10;
				for(long long i=1; i<= sqrt(prod); i++){
					if(prod%i == 0) {
						long long j = prod/i;
						if(i <= zeros && j <= ones) {
							noz = i;
							noo = j;
							break;
						} else if(i <= ones && j <= zeros) {
							noz = j;
							noo = i;
							break;
						}
					}
				}
				zeros -= noz;
				ones -= noo;
				for(long long i=0;i<zeros;i++)
					ans += '0';
				for(long long i=0;i<noo;i++)
					ans += '1';
				for(long long i=0;i<noz;i++)
					ans += '0';
				for(long long i=0;i<ones;i++)
					ans += '1';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}