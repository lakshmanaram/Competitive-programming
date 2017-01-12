import re
overall_possibilities = []
ans = []
def func(n):
	if n == len(overall_possibilities):
		return True
	else:
		if n == 0:
			x = overall_possibilities[n][:]
			for poss in x:
				ans[n] = poss
				if func(n+1):
					return True
				else:
					overall_possibilities[n].remove(poss)
		else:
			x = overall_possibilities[n][:]
			for poss in x:
				if not poss == ans[n-1]:
					ans[n] = poss
					if func(n+1):
						return True
					else:
						overall_possibilities[n].remove(poss)
		return False
t = input()
while t:
	n = input()
	names = raw_input().split()
	n = input()
	messages = []
	overall_possibilities = []
	ans = []
	for i in range(n):
		x = raw_input()
		messages.append(x)
		ans.append(' ')
	flag = True
	for message in messages:
		if message[0] == '?':
			poss = []
			for name in names:
				exp = r'[^0-9a-zA-Z]'+name+r'[^0-9a-zA-Z]'
				reg_exp = re.compile(exp)
				result = re.search(reg_exp,message)
				if not result and not message.endswith(name):
					poss.append(name)
		else:
			poss = [message[:message.find(':')]]
		if len(poss) == 0:
			flag = False
		overall_possibilities.append(poss)
	if not flag:
		print "Impossible"
	else:
		if func(0):
			for i in range(len(ans)):
				print ans[i]+messages[i][messages[i].find(":"):]
		else:
			print "Impossible"
	t -= 1