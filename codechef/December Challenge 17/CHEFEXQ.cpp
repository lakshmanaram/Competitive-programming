#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
class node{
public:
	long mod_to_be;
	map<long, long> m;
};
int main(){
	long n,q;
	scanf("%ld %ld",&n,&q);
	vector<long> arr(n);
	for(long i=0;i<n;i++){
		scanf("%ld",&arr[i]);
	}
	node temp;
	temp.mod_to_be = 0;
	long sq = sqrt(n);
	vector<node> y(ceil((double)n/sq)+2, temp);
	vector<long> x(n);
	x[0] = arr[0];
	y[0].m[arr[0]] = 1;
	for(long i=1;i<n;i++){
		x[i] = x[i-1]^arr[i];
		y[i/sq].m[x[i]]++;
	}
	while(q--){
		int ch;
		long i, k;
		scanf("%d %ld %ld",&ch, &i, &k);
		if(ch == 1){
			//update i to k
			i--;
			long yi = (i)/sq;
			long j = (yi+1)*sq;
			long val = arr[i]^k;
			y[yi].m.clear();
			for(long l = yi*sq; l < i; l++)
				y[yi].m[x[l]]++;
			for(long l=i;l<j && l < arr.size();l++){
				x[l] ^= val;
				y[yi].m[x[l]]++;
			}

			arr[i] = k;
			yi++;
			y[yi].mod_to_be ^= val;
			// for(long l=0;l<y.size();l++){
			// 	cout<<l<<" block"<<endl;
			// 	cout<<"mod_to_be = "<<y[l].mod_to_be<<endl;
			// 	cout<<"startval = "<<y[l].startval<<endl;
			// 	map<long, long>::iterator mit = y[l].m.begin();
			// 	while(mit != y[l].m.end()){
			// 		cout<<mit->first<<" -> "<<mit->second<<endl;
			// 		mit++;
			// 	}
			// 	cout<<endl<<endl;
			// }
		} else{
			// find till i for k
			long tempans = 0;
			long j = 0;
			for(;j<y.size() && (j+1)*sq < i;j++){
				k ^= y[j].mod_to_be;
				if(y[j].m.find(k) != y[j].m.end())
					tempans += y[j].m[k];
			}
			// cout<<"till the block ans = "<<tempans<<endl;
			if((j+1)*sq >= i) {
				k ^= y[j].mod_to_be;
				j = j*sq;
				while(j < i && j < arr.size()){
					if(x[j] == k) {
						tempans++;
						// cout<<"temp = "<<temp<<" j = "<<j<<" arr[j]="<<arr[j]<<" arr[j]^temp = "<<(arr[j]^temp)<<" k = "<<k<<endl;
					}
					j++;
				}
				// cout<<"in the block ans has become "<<tempans<<endl;
			}
			printf("%ld\n", tempans);
		}
	}
	return 0;
}