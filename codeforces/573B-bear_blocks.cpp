#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	long long h[t+1];
	long long left[t+1],right[t+1];
	long long i=1,j;
	for(i=1;i<=t;i++){
		cin>>h[i];
	}
	long long maxval;
	left[1] = 1;
	left[1] = min(h[1],left[1]);	
	for(i=2;i<=t;i++){		
		left[i] = min(left[i-1]+1,h[i]);
	}
	right[t] = 1;
	right[t] = min(h[t],right[t]);
	for(i=t-1;i>0;i--)
		right[i] = min(right[i+1]+1,h[i]);
	for(i=1;i<=t;i++){
		long long k = min(left[i],right[i]);
		if(i==1)
			maxval = k;
		else
			maxval = max(maxval,k);
	}
	// for(i=1;i<=t;i++){
	// 	long long k=i, temp_k;
	// 	k = min(k,t-i+1);
	// 	k = min(k,h[i]);
	// 	for(j=1;i-j>0;j++){
	// 		temp_k=h[i-j]+j;
	// 		if(k>temp_k){
	// 			k = temp_k;
	// 		}
	// 	}
	// 	for(j=1;i+j<=t;j++){
	// 		temp_k=h[i+j]+j;
	// 		if(k>temp_k){
	// 			k = temp_k;
	// 		}
	// 	}
	// 	if(i==1)
	// 		max = k;
	// 	else if(max<k)
	// 		max = k;
	// }
	cout<<maxval;
	return 0;
}
