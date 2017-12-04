s = "What are you doing at the end of the world? Are you busy? Will you save us?"
f1 = 'What are you doing while sending "'
f2 = '"? Are you busy? Will you send "'
f3 = '"?'
lf1 = len(f1)
lf2 = len(f2)
lf3 = len(f3)
def count(n):
	temp = 1<<n
	return temp*75+(temp-1)*68
def func(n,k):
	if count(n) < k:
		return '.'
	if n == 0:
		return s[k-1]
	if lf1 >= k:
		return f1[k-1]
	c = count(n-1)
	k -= lf1
	if c >= k:
		return func(n-1,k)
	k -= c
	if lf2 >= k:
		return f2[k-1]
	k -= lf2
	if c >= k:
		return func(n-1,k)
	k -= c
	if lf3 >= k:
		return f3[k-1]
q = input()
ans = ""
while q:
	n,k = map(int,raw_input().split())
	ans += func(n,k)
	q -= 1
print ans