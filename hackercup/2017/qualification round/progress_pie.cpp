#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("input.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        double p;
        infile>>p;
        double x,y;
        infile>>x>>y;
        bool flag = true;
        if( p!=0 && ((x-50)*(x-50)+(y-50)*(y-50) <= 50*50) )
            if (atan2(x-50,y-50)-atan2(0,50) <= p*22/350)
                flag = false;
        outfile<<"Case #"<<tk<<": ";
        if(flag)
            outfile<<"white";
        else
            outfile<<"black";
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
