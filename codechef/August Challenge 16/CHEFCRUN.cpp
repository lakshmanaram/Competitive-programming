#include <bits/stdc++.h>
using namespace std;
/*
vector <long long> group(vector<long long> arr){
	vector<long long> tarr;
	bool sign;
	if(arr.size()!=0){
		long long val = arr[0];
		if(val >= 0)
			sign = true;
		else
			sign = false;
		for(long i=1;i<arr.size();i++){
			if(arr[i]==0)
				continue;
			else if(arr[i]>0){
				if(sign)
					val += arr[i];
				else{
					tarr.push_back(val);
					// cout<<val<<" ";
					val = arr[i];
					sign = true;
				}
			} else {
				if(sign){
					tarr.push_back(val);
					// cout<<val<<" ";
					val = arr[i];
					sign = false;
				} else {
					val += arr[i];
				}
			}
		}
		tarr.push_back(val);
		// cout<<val<<" "<<endl;
	}
	return tarr;
}
vector<long long> eliminate(vector<long long> arr){
	vector<long long> newarr;
	newarr.push_back(arr[0]);
	long i;
	for(i=1;i<arr.size()-1;i++){
		if(arr[i]<0){
			if(abs(arr[i])<arr[i-1] && abs(arr[i])<arr[i+1]){
				newarr.push_back(arr[i]+arr[i+1]);
				i++;
			} else {
				newarr.push_back(arr[i]);
			}
		} else {
			newarr.push_back(arr[i]);
		}
	}
	if(i == arr.size()-1)
		newarr.push_back(arr[i]);
	return newarr;
}
long long utilfunc(vector<long long> arr){
	vector<long long> tarr = group(arr);
	
	long present_size, new_size = tarr.size();
	do{
		present_size = new_size;
		tarr = eliminate(tarr);
		tarr = group(tarr);
		new_size = tarr.size();
	} while(new_size != present_size);
	
	long long ans = 0;
	if(tarr.size()!=0) {
		long index = distance(tarr.begin(),max_element(tarr.begin(),tarr.end()));
		if(tarr[index] <= 0){
			ans += 2*accumulate(tarr.begin(),tarr.end(),0);
		} else {
			vector<bool> abool(tarr.size(),true);
			abool[index] = false;
			long long tempans = 0;
			long pos = index;
			for(long i = index+1; i<tarr.size();i++){
				tempans += tarr[i];
				if(tempans > 0){
					tempans = 0;
					pos = i;
				}
			}
			for(long i = pos+1; i<tarr.size();i++)
				ans += tarr[i]+tarr[i];
			tempans = 0;
			pos = index;
			for(long i = index-1; i>=0;i--){
				tempans += tarr[i];
				if(tempans > 0){
					tempans = 0;
					pos = i;
				}
			}
			for(long i = pos-1; i>=0;i--)
				ans += tarr[i]*2;
		}
	}
	
	vector<long long> fd,bd;
	for(long i=0;i<tarr.size();i++){
		if(i==0)
			fd.push_back(tarr[i]);
		else
			fd.push_back(tarr[i]+fd[fd.size()-1]);
	}
	reverse(tarr.begin(),tarr.end());
	for(long i=0;i<tarr.size();i++){
		if(i==0)
			bd.push_back(tarr[i]);
		else
			bd.push_back(tarr[i]+bd[bd.size()-1]);
	}
	reverse(bd.begin(),bd.end());
	long long minval = 0;
	for(long i=distance(bd.begin(),min_element(bd.begin(), bd.end()));i<tarr.size()-1;i++){
		if(i!=0){
			long long val1, val2;
			vector<long long>::iterator it = min_element(fd.begin(),fd.begin()+i-1);
			if(it!= fd.begin()+i)
				val1 = *it;
			else
				val1 = 0;
			it = min_element(bd.begin()+i, bd.end());
			if(it!= bd.end()+i)
				val2 = *it;
			else
				val2 = 0;
			long long tempmin = val1+val2;
			if(tempmin<minval)
				minval = tempmin;
		}
	}
	if(minval > *min_element(fd.begin(),fd.end()))
		minval = *min_element(fd.begin(),fd.end());
	if(minval > *min_element(bd.begin(),bd.end()))
		minval = *min_element(bd.begin(),bd.end());
	if(ans > 2*minval)
		ans = 2*minval;

	return ans;
}
*/
// long long utilfunc(vector<long long> arr){
// 	vector<long long> fd,bd;
// 	for(long i=0;i<arr.size();i++){
// 		if(i==0)
// 			fd.push_back(arr[i]);
// 		else
// 			fd.push_back(arr[i]+fd[fd.size()-1]);
// 	}
// 	reverse(arr.begin(),arr.end());
// 	for(long i=0;i<arr.size();i++){
// 		if(i==0)
// 			bd.push_back(arr[i]);
// 		else
// 			bd.push_back(arr[i]+bd[bd.size()-1]);
// 	}
// 	reverse(bd.begin(),bd.end());
// 	long long minval = 0;
// 	for(long i=1;i<arr.size()-1;i++){
// 		long long val1 = *min_element(fd.begin(),fd.begin()+i), val2 = *min_element(bd.begin()+i+1, bd.end());
// 		long long tempmin = min(min(val1+val2,val1),val2);
// 		if(tempmin<minval)
// 			minval = tempmin;
// 	}
// 	if(minval > *min_element(fd.begin(),fd.end()))
// 		minval = *min_element(fd.begin(),fd.end());
// 	if(minval > *min_element(bd.begin(),bd.end()))
// 		minval = *min_element(bd.begin(),bd.end());
// 	return 2*minval;
// }
long long kadane_max_sum_subarray(vector<long long> arr){
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
long long utilfunc(vector<long long> arr) {
	long long maxval = kadane_max_sum_subarray(arr);
	return 2*(accumulate(arr.begin(),arr.end(),0) - maxval);
}
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long long> arr(n);
		vector<long long> betw, away;
		for(long i=0;i<n;i++)
			cin>>arr[i];
		long l,r;
		cin>>l>>r;
		l--;
		r--;
		for(long i=l; i!=r; i = (i+1)%n){
			betw.push_back(arr[i]);
		}
		for(long i=r; i!=l; i = (i+1)%n){
			away.push_back(arr[i]);
		}
		reverse(away.begin(), away.end());
		long long ans = accumulate(betw.begin(),betw.end(),0)+utilfunc(away);
		long long tans = accumulate(away.begin(),away.end(),0)+utilfunc(betw);
		
		if(ans > tans)
			ans = tans;
		cout<<ans<<endl;
	}
	return 0;
}