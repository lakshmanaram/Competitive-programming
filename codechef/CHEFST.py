import math
t = input()
for i in range(t):
    a,b,m = raw_input().split()
    a,b,m = int(a),int(b),int(m)
    m = m*(m+1)/2
    if b<a:
        a,b = b,a
    if m<a:
        print a+b-2*m
    else:
        print b-a
