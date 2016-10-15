#include <bits/stdc++.h>
using namespace std;
long long n,m,val;
long long ans;
void enumerate_subsequences (vector<pair<pair<int, int>, int> > arr, int i, vector<pair<pair<int, int>, int> > so_far) {
	if(i == arr.size()){
		if(so_far.size() == 0)
			return;
		long long price = 0;
		long long x = 0, y = 0;
		for(long j=0;j<so_far.size();j++){
			price += so_far[j].second;
			x += so_far[j].first.first;
			y += so_far[j].first.second;
		}
		// cout<<x<<" "<<y<<" "<<price<<endl;
		if(price <= m) {
			if(x <= val && val <= y) {
				if(ans == -1 || ans > price)
					ans = price;
			}
		}
	} else {
		enumerate_subsequences(arr,i+1,so_far);
		so_far.push_back(arr[i]);
		enumerate_subsequences(arr,i+1,so_far);
	}
}
int main() {
	ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("D-small-attempt0.in");
    outfile.open("D-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        infile>>n>>m>>val;
        ans = -1;
        vector<pair<pair<int, int>, int> > bands(n), emptybands;
		for(long i=0;i<n;i++) {
			infile>>bands[i].first.first>>bands[i].first.second>>bands[i].second;
			// cout<<bands[i].first.first<<" "<<bands[i].first.second<<" "<<bands[i].second<<"<-==="<<endl;
		}
		enumerate_subsequences(bands,0,emptybands);
        outfile<<"Case #"<<tk<<":";
        if(ans == -1)
        	outfile<<" IMPOSSIBLE";
        else 
        	outfile<<" "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}