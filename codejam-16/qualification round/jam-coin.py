def check_valid(s):
    for base in range(2,11):
        i = 15
        val = 0
        while i>=0:
            if s[i] == '1':
                val += base**(15-i)
            i-=1
        print val
f1 = open('combinations','r')
for i in range(1,16385):
    a = str(f1.readline())
    s = "1" + a[:-1] + "1"
    #print s
    count = 0
    
    #if check_valid(s):
    #    count += 1
print count
    #f2.write("Case #"+str(i)+": "+str(no*a)+"\n")
f1.close()
