#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n,m;
		cin>>n>>m;
		vector<long long> minsal(n);
		for(long i=0;i<n;i++)
			cin>>minsal[i];
		vector<long long> sal(m);
		vector<long> vacancy(m);
		for(long i=0;i<m;i++)
			cin>>sal[i]>>vacancy[i];
		vector<string> arr(n);
		long no_placed = 0;
		long long total_sal = 0;
		vector<bool> companies(m,true);
		long remaining = m;
		for(long i=0;i<n;i++){
			cin>>arr[i];
			long ans = -1;
			long sal_now = minsal[i];
			for(int j=0;j<m;j++){
				if(arr[i][j] == '1' && sal_now <= sal[j] && vacancy[j] > 0){
					ans = j;
					sal_now = sal[j];
				}
			}
			if(ans != -1) {
				no_placed++;
				total_sal += sal[ans];
				vacancy[ans]--;
				if(companies[ans]) {
					companies[ans] = false;
					remaining--;
				}
			}
		}
		cout<<no_placed<<" "<<total_sal<<" "<<remaining<<endl;
	}
	return 0;
}