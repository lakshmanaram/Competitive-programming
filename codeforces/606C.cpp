//606 C
#include<bits/stdc++.h>
using namespace std;
long insertion_sort1 (vector<long> a){
	 	long j, temp;
		long ans = 0;
	for (long i = 0; i < a.size(); i++){
		j = i;
		if(j > 0 && a[j] < a[j-1]){
			ans++;
		    temp = a[j];
		    a[j] = a[j-1];
		    a[j-1] = temp;
		}
	}
	return ans;
}
long insertion_sort2 (vector<long> a){
	 	long j, temp;
		long ans = 0;
	for (long i = a.size()-1; i>=0; i--){
		j = i;
		if(j <a.size()-1 && a[j] > a[j+1]){
			ans++;
		    temp = a[j];
		    a[j] = a[j+1];
		    a[j+1] = temp;
		}
	}
	return ans;
}
int main(){
	long n;
	cin>>n;
	vector<long> a;
	while(n--){
		long q;
		cin>>q;
		a.push_back(q);
	}
	if(insertion_sort1(a)<insertion_sort2(a))
		cout<<insertion_sort1(a);
	else
		cout<<insertion_sort2(a);
	return 0;
}
