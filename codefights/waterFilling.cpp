double wF(std::vector<std::vector<double>> b, double v) {
    using namespace std;
    vector<double> a = b[0];
    double ans = 0;
    for(int i=1;i<b.size();i++){
        if(v > max(a[1],b[i][1])){
            ans += (v -  max(a[1],b[i][1]))*(b[i][0] - a[0]);
            ans +=  (b[i][0] - a[0]) * (max(a[1],b[i][1]) - min(a[1],b[i][1]))/2;
        }
        else if(v > min(a[1],b[i][1]) )
            ans +=  (v - min(a[1],b[i][1]))*(b[i][0] - a[0])/(max(a[1],b[i][1]) - min(a[1],b[i][1])) * (v - min(a[1],b[i][1]))/2;
        a = b[i];
    }
    return ans;
}
double waterFilling(std::vector<std::vector<double>> b, double v) {
    double left = 0, right = 100000.0,mid;
    for(int i=0;i<100;i++){
        mid = (left + right)/2;
    std::cout<<mid<<std::endl;
        if(left == right){
            left = left - 0.1;
            right = right +0.1;
        }
        else if(wF(b,mid)<v)
            left = mid;
        else if(wF(b,mid)>v)
            right = mid;
        else
            return mid;
    }
    return mid;
}