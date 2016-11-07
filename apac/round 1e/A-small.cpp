#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-large.in");
    outfile.open("A-output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        string b;
        infile>>b;
        long long l,r;
        infile>>l>>r;
        l--;
        r--;
        long nobl, nobr, tno;
        nobl = nobr = tno = 0;
        long nl = l%b.size(), nr = r%b.size();
        for(long i=0;i<b.size();i++) {
            if(b[i] == 'B'){
                if(i<nl)
                    nobl++;
                if(i<=nr)
                    nobr++;
                tno++;
            }
        }
        long long ans = 0;
        long long high = (r)/b.size(), low = (l)/b.size();
        if(high == low){
            ans = nobr-nobl;
        } else {
            ans = tno-nobl + nobr + (high-low-1)*tno;
        }
        outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
