#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long l,r;
        infile>>l>>r;
        long long mv = min(l,r);
        mv = mv*(mv+1)/2;
        outfile<<"Case #"<<tk<<": "<<mv;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
