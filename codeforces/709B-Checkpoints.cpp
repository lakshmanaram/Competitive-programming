#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	long long s;
	cin>>s;
	vector<long long> checkpoints;
	for(long i=0; i<n; i++) {
		long long x;
		cin>>x;
		if(x==s){
			n--;
			i--;
		} else {
			checkpoints.push_back(x);
		}
	}
	sort(checkpoints.begin(),checkpoints.end());

	if(n<=1)
		cout<<0<<endl;
	else {
		// find position
		bool twopos = false;
		long pos;
		if(s <= checkpoints[0])
			pos = 0;
		else if(s >= checkpoints[n-1])
			pos = n-1;
		else {
			for(long i=0;i<n-1;i++) {
				if(s >= checkpoints[i] && s <= checkpoints[i+1]) {
					pos = i;
					twopos = true;
					break;
				}
			}
		}
		vector<long long> answers;
		if(!twopos) {
			answers.push_back(abs(checkpoints[n-2]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[0]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[n-1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
		} else {
			answers.push_back(abs(checkpoints[n-2]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[0]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[n-1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
			pos++;
			answers.push_back(abs(checkpoints[n-2]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[0]-checkpoints[pos])+abs(checkpoints[n-2]-checkpoints[0])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[n-1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
			answers.push_back(abs(checkpoints[1]-checkpoints[pos])+abs(checkpoints[n-1]-checkpoints[1])+abs(s - checkpoints[pos]));
		}
		cout<<*min_element(answers.begin(),answers.end())<<endl;

	}
	return 0;
}