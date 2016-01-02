n = 1
m = {}
for i in range(40):
    t = n
    while t!=0:
        if str(t) in m.keys():
            print n
        else:
            m[str(t)] = n
        t /= 10
    n *= 2
