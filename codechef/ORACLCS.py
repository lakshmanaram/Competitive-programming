#ORACLCS codechef
def finda(s):
    a = 0
    for i in s:
        if i == 'a':
            a += 1
    return a
def findb(s):
    b = 0
    for i in s:
        if i == 'b':
            b += 1
    return b
t = input()
for T in range(t):
    n = input()
    rem = ""
    for N in range(n):
        s = raw_input()
        if N==0:
            a = finda(s)
            b = findb(s)
        else:
            if a > finda(s):
                a = finda(s)
            if b > findb(s):
                b = findb(s)
    if a > b:
        a,b = b,a
    print a
            
