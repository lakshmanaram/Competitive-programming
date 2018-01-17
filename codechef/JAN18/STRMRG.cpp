#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%ld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n, m;
		S(n);
		S(m);
		string a, b;
		cin>>a>>b;
		string x, y;
		x = y = "";
		for (long i=0; i < a.size();i++){
			if(i == 0 || a[i] != a[i-1])
				x += a[i];
		}
		for (long i=0; i < b.size();i++){
			if(i == 0 || b[i] != b[i-1])
				y += b[i];
		}
		vector<int> temp(x.size() + 1, x.size());
		vector<vector<int> > arr(y.size(), temp);
		for(long i=0;i<y.size();i++){
			if(i != 0)
				arr[i][0] = arr[i-1][0]+1;
			else 
				arr[i][0]++;
			for(long j=1;j<arr[0].size();j++) {
				if(x[j-1] == y[i]){
					if(i == 0)
						arr[i][j] = min(arr[i][j-1], arr[i][j]);
					else 
						arr[i][j] = arr[i-1][j-1];
				} else {
					if(i == 0)
						arr[i][j] = min(arr[i][j-1], 1 + arr[i][j]);
					else 
						arr[i][j] = min(arr[i][j-1], 1 + arr[i-1][j]);
 				}
			}
		}
		printf("%d\n", *min_element(arr[y.size()-1].begin(), arr[y.size()-1].end()));
	}
	return 0;
}