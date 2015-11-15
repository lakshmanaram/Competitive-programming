vis = [0]
val = [0.0]
preval = [0.0]
nxt = [0]
ans = 0.0
def dfs(a,v):
	global ans, val, preval, nxt, vis
	try:
		if vis[a] == 1:
			vis[a] = 2
			ans+=v/preval[a]
			return
		elif vis[a] == 2:
			return
		vis[a] = 1
		preval[a] = v
		dfs(nxt[a],val[a]*v)
		vis[a] = 2
		return
	except Exception, e:
		while(1):
	
n = input()
i=1
while i<=n :
	x=raw_input().split()
	w = int(x[0])
	p = float(x[1])
	val.append(p/100)
	nxt.append(w)
	preval.append(1)
	vis.append(0)
	i+=1
i=1
while i<=n:
	if vis[i] == 0:
		dfs(i,1.0)
	i+=1
print("%.2f" % ans)