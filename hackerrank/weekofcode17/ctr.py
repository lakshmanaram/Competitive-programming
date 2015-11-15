x = raw_input().split()
n = int(x[0])
h = int(x[1])
dh = int(x[2])
dw = int(x[3])
lis = []
init = []
my = 0
miny = 10000001
for j in range(n):
	x = raw_input().split()
	y = int(x[0])
	if miny>y:
		miny=y
		my=1
	elif miny==y:
		my+=1
	z = int(x[2])
	x = int(x[1])
	temp = [y,x,z]
	init.append(temp)
init.sort()
flag = 0
for j in init:
	y = j[0]
	x = j[1]
	z = j[2]
	flag1=0
#	print x,y,z
	minx = x - dw
	if minx<0:
		minx = 0
	maxx = x + dw
	if maxx>100000:
		maxx = 100000
	if flag<my:
		lis.append([minx,maxx,z,y])			#first time appending as such
		flag+=1
	else:
		# first deletion of values which cannot contribute to future development
		#then placing the new value within
		for i in lis:
			if y-dh > 0:
				if i[3]<(y-dh):
					lis.remove(i)
		val = 0
		for i in lis:
			if x<i[0] :
				break;
			if (x>=i[0]) & (x<=i[1]) & (y!=i[3]):
				temp = z + i[2]
				if flag1==0:
					flag1 = 1
					val = temp
				elif temp>val:
					val = temp
        if flag1==1:
        	fflag=0
        	for i in lis:
        		if minx<i[0] :
        			fflag = 1
        			break
        	if fflag==1:
        		lis.insert(lis.index(i)-1,[minx,maxx,val,y])
        	else:
        		lis.append([minx,maxx,val,y])
        	print lis
y = h
flag2 = 0
val = 0
for i in lis:
	if flag2 == 0:
		val = i[2]
		flag2 = 1
	else:
		if i[2] > val : 
			val = i[2]
print val