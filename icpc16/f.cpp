#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m,d,D;
		cin>>n>>m>>d>>D;
		if(m < n*d || m > n*D)
			cout<<-1<<endl;
		else {
			for(int i=0;i<d;i++) {
				for(int j=0;j<n;j++) {
					printf("%d %d\n",j+1,((j+i)%n)+1);
				}
			}
			m -= n*d;
			int i=d,j=0;
			while(m--) {
				printf("%d %d\n",j+1,((j+i)%n)+1);
				j++;
				if(j==n){
					i++;
					j = 0;
				}
			}
		}
	}
	return 0;
}
