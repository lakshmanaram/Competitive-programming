//binary string modulo m value as long
long binmod(string a, long m){
	long ans = 0, i = 0;
	while(i<a.size()){
		cout<<ans<<endl;
		ans *= 2;
		ans %= m;
		ans += int(a[i++]) - int('0');
	}
	return ans%m;
}
