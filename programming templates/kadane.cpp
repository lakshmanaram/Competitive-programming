#include <bits/stdc++.h>
using namespace std;
long long max_sum_subarray(vector<long long> arr){
	long long ans = 0, current_max = 0;
	for(long i=0;i<arr.size();i++) {
		current_max += arr[i];
		if(current_max > ans)
			ans = current_max;
		if(current_max < 0)
			current_max = 0;
	}
	return ans;
}
int main() {
	vector<long long> arr;
	arr.push_back(-2);
	arr.push_back(-3);
	arr.push_back(4);
	arr.push_back(-1);
	arr.push_back(-2);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(-3);
	cout <<"Max sum of a contiguous sub array is "<<max_sum_subarray(arr);
	return 0;
}