k,p = map(int, raw_input().split())
ans = 0
for i in range(1,k+1):
	ans += int(str(i)+str(i)[::-1])
ans %= p
print ans