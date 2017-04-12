#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-small-attempt0.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long x;
        string s;
        infile>>s>>x;
        long long ans = 0;
        for(long i=0;i<s.size();i++) {
        	if(s[i] == '+')
        		continue;
        	if(i+x > s.size()) {
        		ans = -1;
        		break;
        	}
        	for(long j=i;j<i+x;j++){
        		if( s[j] == '-')
        			s[j] = '+';
        		else
        			s[j] = '-';
        	}
        	ans++;
        }

        if(ans == -1)
        	outfile<<"Case #"<<tk<<": IMPOSSIBLE";
        else
        	outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
