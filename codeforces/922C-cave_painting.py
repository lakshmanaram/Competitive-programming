def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)
x = raw_input().split()
n = int(x[0])
k = int(x[1])
yes = "Yes"
no = "No"
if k == 1:
	print yes
else:
	if n < k-1:
		print no
	else:
		ans = 1
		step = 2
		i = 3
		while i <= k:
			ans += step*((i/gcd(step, i))-1)
			if ans > n:
				break
			step /= gcd(step, i)
			step *= i
			i += 1
		if (ans > n) or ((n-ans)%step != 0):
			print no
		else:
			print yes