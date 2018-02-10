import random 
print 100
t = 100
while t:
	n = random.randint(5, 200)
	print n
	for i in range(0, n):
		print random.randint(1, 4), random.randint(1, 1000000)
	t -= 1