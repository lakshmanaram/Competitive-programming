#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-large-practice.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long long n,k;
        infile>>n>>k;
        set<long long> s;
        s.insert(n);
        map<long long, long long> c;
        c[n] = 1;
        long long done = 0, x1, x2; 
        long long x;
        while(true) {
            set<long long>::iterator it = s.end();
            it--;
            x = *it;
            s.erase(it);
            x1 = x / 2;
            x2 = x-1-x1;
            done += c[x];
            if( done >= k )
                break;
            s.insert(x1);
            s.insert(x2);
            if(c.count(x1) == 0)
                c[x1] = 0;
            if(c.count(x2) == 0)
                c[x2] = 0;
            c[x1] += c[x];
            c[x2] += c[x];
            c[x] = 0;
        }
        outfile<<"Case #"<<tk<<": "<<x1<<" "<<x2<<endl;
        if(tk == 63) cout<<x;
    }
    infile.close();
    outfile.close();
    return 0;
}
