#include <bits/stdc++.h>
using namespace std;
long long ans;
vector<long long> factorial;
long long findfac(long long a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(long long i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i));
    return factorial[a];
}
void recurse(int a, int b, int m, int n){
    if(m+n == 0) {
        ans ++;
        return;
    }
    if(a==0){
        recurse(a+1,b,m-1,n);
    } else {
        if((m==0 && n!=0) || (a > b+1 && n!=0)){
            recurse(a,b+1,m,n-1);
        }
        if(m!=0) {
            recurse(a+1,b,m-1,n);
        }
    }
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-small-attempt0.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int m,n;
        infile>>m>>n;
        ans = 0;
        double fac = findfac(m+n);
        recurse(0,0,m,n);
        double x = ans;
        x *= findfac(m);
        x *= findfac(n);
        x /= fac;
        outfile<<"Case #"<<tk<<": "<<x;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
