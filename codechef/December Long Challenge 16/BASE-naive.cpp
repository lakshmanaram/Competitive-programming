#include <bits/stdc++.h>
using namespace std;
int main(){
	ofstream outfile;
	outfile.open("bnaive.txt");
	for(long long n=0;n<=1000;n++){
		if(n == 1)
			outfile<<"INFINITY\n";
		else if(n == 2)
			outfile<<1<<endl;
		else if(n == 0)
			outfile<<0<<endl;
		else {
			long long ans = 2;
			for(long long i=3;i<n;i++){
				long long temp = i;
				long j=1;
				long long cl = pow(temp,j);
				while(cl <= n){
					if(n >= cl && n < 2*cl){
						ans++;
						break;
					} 
					j++;
					cl = pow(temp,j);
				}
			}
			outfile<<ans<<endl;
		}
	}
	outfile.close();
	return 0;
}