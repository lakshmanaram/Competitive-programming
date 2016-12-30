t = input()
while t:
	n = input()
	arr = map(int,raw_input().rstrip().split())
	ans = []
	for i in arr:
		if i in ans:
			ans.remove(i)
		else:
			ans.append(i)
	print ans[0]
	t -= 1