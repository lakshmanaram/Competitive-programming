s = "What are you doing at the end of the world? Are you busy? Will you save us?"
f1 = 'What are you doing while sending "'
f2 = '"? Are you busy? Will you send "'
f3 = '"?'
lf1 = len(f1)
lf2 = len(f2)
lf3 = len(f3)
m = 10**20
def count(n):
	if n >= 60:
		return m
	temp = 1<<n
	return temp*75+(temp-1)*68
def func(n,k):
	if count(n) < k:
		return '.',1,0
	if n == 0:
		return s[k-1],1,0
	if lf1 >= k:
		return f1[k-1],1,0
	c = count(n-1)
	k -= lf1
	if c >= k:
		return n-1,k,1
	k -= c
	if lf2 >= k:
		return f2[k-1],1,0
	k -= lf2
	if c >= k:
		return n-1,k,1
	k -= c
	if lf3 >= k:
		return f3[k-1],1,0
q = input()
ans = ""
while q:
	n,k = map(int,raw_input().split())
	a,b,c = func(n,k)
	while c == 1:
		a,b,c = func(a,b)
	ans += a
	q -= 1
print ans