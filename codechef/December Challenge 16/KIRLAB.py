def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b,a%b)
t = input()
while t:
	n = input()
	x = raw_input().split()
	arr = []
	for i in x:
		arr.append(int(i))
	mat = [1]
	mv = 0
	for a in arr:
		cur = mv
		while cur != -1:
			temp = gcd(mat[cur],a)
			if temp != 1:
				mat[cur] /= temp
				break
			cur -= 1
		cur += 1
		if mv < cur:
			mv = cur
			mat.append(a)
		else:
			mat[cur] *= a
	print(mv+1)
	t -= 1