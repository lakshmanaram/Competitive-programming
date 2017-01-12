#include <bits/stdc++.h>
using namespace std;
struct chance{
    int dice;
    int times;
    long a;
};
struct chance parse(string s) {
    chance c;
    c.times = c.dice = c.a = 0;
    int i=0;
    while(i<s.size() && s[i]>='0' && s[i] <= '9'){
        c.times *= 10;
        c.times += s[i]-'0';
        i++;
    }
    i++;
    while(i<s.size() && s[i]>='0' && s[i] <= '9'){
        c.dice *= 10;
        c.dice += s[i]-'0';
        i++;
    }
    char sign = '+';
    if(i<s.size())
        sign = s[i];
    i++;
    while(i<s.size() && s[i]>='0' && s[i] <= '9'){
        c.a *= 10;
        c.a += s[i]-'0';
        i++;
    }
    if(sign == '-')
        c.a = -c.a;
    return c;
}
vector<vector<double> > get_probs(int dice) {
    vector<vector<double> > ans(21);
    double prob = 1.0/(double)dice;
    vector<double> temp(1,0);
    for(int i=0;i<dice;i++)
        temp.push_back(prob);
    ans[1] = temp;
    for(int i=2;i<21;i++) {
        vector<double> arr(i*dice+1,0);
        for(int j=1;j<=dice;j++){
            for(long k=1;k<ans[i-1].size();k++){
                arr[j+k] += ans[i-1][k]*temp[j];
            }
        }
        ans[i] = arr;
    }
    return ans;
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    map<int,vector<vector<double> > > probs;
    infile.open("input.txt");
    outfile.open("output.txt");
    infile>>t;
    probs[4] = get_probs(4);
    probs[6] = get_probs(6);
    probs[8] = get_probs(8);
    probs[10] = get_probs(10);
    probs[12] = get_probs(12);
    probs[20] = get_probs(20);
    int c= 0;
    for(long long tk=1;tk<=t;tk++){
        long h;
        int s;
        infile>>h>>s;
        vector<chance> arr(s);
        double ans = 0;
        for(int i=0;i<arr.size();i++){
            string x;
            infile>>x;
            arr[i] = parse(x);
        }
        int pos = 0;
        for(int i=0; i<arr.size();i++){
            double prob = 0;
            int dice_outcome = arr[i].times*arr[i].dice;
            long maxval = dice_outcome + arr[i].a;
            while(maxval >= h && dice_outcome > 0){
                prob += probs[arr[i].dice][arr[i].times][dice_outcome];
                dice_outcome--;
                maxval--;
            }
            if(prob >= ans){
                ans = prob;
                pos = i;
            }
        }
        double prob = 0;
        outfile<<arr[pos].times<<" times "<<arr[pos].dice<<" dice ";
        int dice_outcome = arr[pos].times*arr[pos].dice;
        long maxval = dice_outcome + arr[pos].a;
        while(maxval >= h && dice_outcome > 0){
            outfile<<dice_outcome<<" with prob = "<<probs[arr[pos].dice][arr[pos].times][dice_outcome]<<",";
            prob += probs[arr[pos].dice][arr[pos].times][dice_outcome];
            dice_outcome--;
            maxval--;
        }
        if(ans > 0.999999)
        	c++;
        outfile<<"Case #"<<tk<<": "<<std::fixed<<std::setprecision(6)<<ans<<" "<<pos<<endl;
    }
    cout<<c<<endl;
    infile.close();
    outfile.close();
    return 0;
}