#include <bits/stdc++.h>
using namespace std;
long long bsearch8(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,8) + pow(m,7) + pow(m,6) + pow(m,5) + pow(m,4) + pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}

long long bsearch7(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,7) + pow(m,6) + pow(m,5) + pow(m,4) + pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
long long bsearch6(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,6) + pow(m,5) + pow(m,4) + pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
long long bsearch5(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,5) + pow(m,4) + pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
long long bsearch4(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,4) + pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
long long bsearch3(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,3) + pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
long long bsearch2(long long l, long long r, long long val) {
    while(l < r) {
        long long m = floor((l+r)/2);
        long long ans = pow(m,2) +m +1 ;
        if(ans < val)
            l = m+1;
        else if(ans == val)
            return m;
        else
            r = m-1;
    }
    return -1;
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    set<long long> temp;
    vector<set<long long> > vals(101,temp);
    // cout<<"start"<<endl;
    for(long long i=2;i<101;i++) {
        for(long long j=i;j<1000000000000000001; j *= i){
            vals[i].insert(j);
        }
    }
    // cout<<"end"<<endl;
    infile.open("B-large.in");
    outfile.open("B-output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long n;
        infile>>n;
        long long b = 2;
        while(b < 101) {
            if(vals[b].find(1+(b-1)*n)!=vals[b].end())
                break;
            b++;
        }
        if(b == 101){
            long long val = bsearch8(100,177,n);
            if(val == -1){
                val = bsearch7(100,372,n);
                if(val == -1){
                    val = bsearch6(100,1000,n);
                    if(val == -1){
                        val = bsearch5(100,3981,n);
                        if(val == -1){
                            val = bsearch4(100,31622,n);
                            if(val == -1){
                                val = bsearch3(100,1000000,n);
                                // /cout<<"here"<<endl;
                                if(val == -1){
                                    val = bsearch2(100,1000000000,n);

                                    if(val == -1){
                                        val = n-1;
                                    }   
                                }   
                            }   
                        }   
                    }   
                }
            }
            b = val;
        }
        // outfile<<n<<endl;
        // if(b < 0)
        //     b = n-1;
        outfile<<"Case #"<<tk<<": "<<b;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
