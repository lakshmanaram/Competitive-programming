#include <bits/stdc++.h>
using namespace std;
int main(){
	string init;
	bool running = false;
	bool changes = false;
	cin>>init;
	for(long i=0;i<init.size();i++){
		if(running) {
			if(init[i] == 'a')
				break;
			else{
				init[i]--;
				changes = true;
			}
		} else {
			if(init[i] == 'a')
				continue;
			running = true;
			i--;
		}
	}
	if(!changes)
		init[init.size()-1] = 'z';
	cout<<init<<endl;

	return 0;
}