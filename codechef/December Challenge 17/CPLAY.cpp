#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	while(1){
		char x[23];
		for(int i=0;i<23;i++) x[i] = '1';
		scanf("%s", &x);
		if(strlen(x) == 23) break;
		int a = 0, b = 0;
		int rema = 5, remb = 5;
		int ans = 0;
		bool flag = true;
		for(int i=0;i<20;i++){
			ans = i+1;
			if(x[i] == '1'){
				if(i%2 == 0) a++;
				else b++;
			}
			if(i < 10){
				if(i%2 == 0) rema--;
				else remb--;
				if((a > b+remb) || (b > a+rema))
					break;
			} else {
				if((i&1) && (a != b)) break;
			}
		}
		if(a == b){
			printf("TIE\n");
		} else {
			if(a > b) printf("TEAM-A %d\n",ans);
			else printf("TEAM-B %d\n",ans);
		}
		
	}
	return 0;
}