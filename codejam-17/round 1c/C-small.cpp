#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-small-1-attempt0.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long n,k;
        infile>>n>>k;
        double u;
        vector<double> arr(n);
        infile>>u;
        for(long i=0;i<n;i++)
            infile>>arr[i];
        sort(arr.begin(),arr.end());
        while(u > 0) {
            double initial = arr[0];
            double final;
            double no = 1;
            if(initial == 1.0000)
                break;
            final = initial;
            for(int i=1; i< n;i++) {
                if(arr[i] == initial)
                    no++;
                else {
                    final = arr[i];
                    break;
                }
            }
            if(no == n) final = 1.0;
            double required = final-initial;
            required *= no;
            if(required <= u){
                for(int i=0;i<no;i++) arr[i] = final;
                u -= required;
            } else {
                double val = u;
                val /= (double)no;
                for(int i=0;i<no;i++) arr[i] += val;
                break;
            }
        }
        double prod = 1.0;
        for(long i=0;i<n;i++) {
            prod *= arr[i];
        }
        outfile<<"Case #"<<tk<<": "<<std::fixed<<setprecision(9)<<prod<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
