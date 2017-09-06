#include <bits/stdc++.h>
using namespace std;
double nCk (double n, int k){
	double ans = 1.0;
	for(int i=1;i<=k;i++){
		ans *= n--;
		ans /= i;
		if(i != 1) ans /= 365.0;
	}
	return ans;
}
int main(){
	int arr[] = {0,1,23, 88, 187, 313, 460, 623, 798, 985, 1181, 1385, 1596, 1813, 2035, 2263, 2494, 2730, 2970, 3213, 3459};
	for(int i=0;i<=20;i++) cout<<arr[i]<<" ";
}