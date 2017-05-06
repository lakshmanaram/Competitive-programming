#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-small-attempt0.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long n,q;
        infile>>n>>q;
        vector<long long> dist(n), speed(n);
        for(long i=0;i<n;i++) {
            infile>>dist[i]>>speed[i];
        }
        vector<long long> temp(n,0);
        vector<vector<long long> > arr(n,temp);

        for(long i=0;i<n;i++) {
            for(long j=0;j<n;j++) {
                infile>>arr[i][j];
            }
        }

        while(q--) {
            long u,v;
            infile>>u>>v;
            u--;
            v--;
            vector<vector<double> > tarr(n);
            tarr[0].push_back((double)0);
            for(long i=0;i<n-1;i++) {
                long long distance = arr[i][i+1];
                long j=i+1;
            if(tarr[i].size() == 0)
                cout<<"Something went wrong "<<i<<endl;
                double x = *min_element(tarr[i].begin(),tarr[i].end());
                while(distance <= dist[i] && j < n) {
                    double d = distance;
                    d /= speed[i];
                    tarr[j].push_back(d+x);
                    distance += arr[j][j+1];
                    j++;
                }
            }
            if(tarr[n-1].size() == 0)
                cout<<"Something went wrong"<<endl;
            outfile<<"Case #"<<tk<<": "<<std::fixed<<setprecision(8)<<*min_element(tarr[n-1].begin(),tarr[n-1].end())<<endl;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
