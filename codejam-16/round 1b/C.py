import copy
now = 0
def give_ans(words,ans,fused,sused,first,second):
    nr = True
    while nr:
        nr = False
        temp_words = list(words)
        for w in words:
            if (w.split()[0] in fused) and (w.split()[1] in sused):
                temp_words.remove(w)
                first[w.split()[0]] -= 1
                second[w.split()[1]] -= 1
                nr = True
            elif ((first[w.split()[0]] == 1) and (w.split()[0] not in fused)) or ((w.split()[1] not in sused) and (second[w.split()[1]] == 1)):
                ans.append(w)
                fused.append(w.split()[0])
                sused.append(w.split()[1])
                temp_words.remove(w)
                nr = True
        words = list(temp_words)
    if len(words) == 0:
        return now - len(ans)
    res = 0
    for w in words:
        twords = list(words)
        tans = list(ans)
        tfused = list(fused)
        tsused = list(sused)
        tfirst = copy.copy(first)
        tsecond = copy.copy(second)
        tans.append(w)
        tfused.append(w.split()[0])
        tsused.append(w.split()[1])
        twords.remove(w)
        val = give_ans(list(twords),list(tans),list(tfused),list(tsused),copy.copy(tfirst),copy.copy(tsecond))
        if val > res:
            res = val
    return res
f1 = open('C-small-attempt0.in','r')
f2 = open('output3','w')
t = int(f1.readline())
for i in range(1,t+1):
    a = int(f1.readline())
    now = a
    words = []
    ans = []
    fused = []
    sused = []
    first = {}
    second = {}
    while(a):
        x = f1.readline()
        words.append(x)
        x = x.split()
        if x[0] in first.keys():
            first[x[0]] += 1
        else:
            first[x[0]] = 1
        if x[1] in second.keys():
            second[x[1]] += 1
        else:
            second[x[1]] = 1
        a -= 1
    result = give_ans(list(words),list(ans),list(fused),list(sused),copy.copy(first),copy.copy(second))
    f2.write("Case #"+str(i)+": "+str(result)+"\n")
f1.close()
f2.close()
