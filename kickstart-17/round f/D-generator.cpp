#include <bits/stdc++.h>
using namespace std;
int main(){
    int t = 100;
    ofstream outfile;
    outfile.open("D-small-attempt0.in");
    outfile<<t<<endl;
    for(int tk=1;tk<=t;tk++){
        long e = 10, n = 1000;
        outfile<<e<<" "<<n<<endl;
        for(long i=0;i<n;i++)
            outfile<<rand()%1000001<<" ";
        outfile<<endl;
    }
    outfile.close();
    return 0;
}
