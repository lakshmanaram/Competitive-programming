f1 = open('A-large.in','r')
f2 = open('output','w')
t = int(f1.readline())
for i in range(1,t+1):
    a = int(f1.readline())
    if a == 0:
        f2.write("Case #"+str(i)+": INSOMNIA\n")
    else:
        digithash = [0] * 10
        remaining_digits = 10
        no = 1
        while True:
            temp = no*a
            while temp != 0:
                if digithash[temp%10] == 0:
                    remaining_digits -= 1
                    digithash[temp%10] = 1
                temp = int(temp/10)
                #print temp, digithash, remaining_digits
                #x = input()
            if remaining_digits == 0:
                break
            no += 1
        f2.write("Case #"+str(i)+": "+str(no*a)+"\n")
f1.close()
f2.close()
