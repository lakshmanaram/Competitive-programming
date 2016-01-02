#PLANEDIV codechef
t = input()
for T in range(t):
    n = input()
    m = {}
    for i in range(n):
        a,b,c = raw_input().split()
        a,b,c = float(a),float(b),float(c)
        if a == 0:
            if 'Inf' in m.keys():
                m['Inf'][c/b] = 1
            else:
                m['Inf'] = {}
                m['Inf'][c/b] = 1
        else:
            if b/a in m.keys():
                m[b/a][c/a] = 1
            else:
                m[b/a] = {}
                m[b/a][c/a] = 1
    maxv = 0
    for i in m.keys():
        if len(m[i].keys())>maxv:
            maxv = len(m[i].keys())
    print maxv
