file = open('fighting_the_zombies.txt','wb')
file.write("50\n")
for i in range(0,50):
	file.write("50 10000000\n")
	for j in range(0,50):
		file.write(str(i)+" "+str(j)+"\n")