#Wasim Khan		wasimk95@bu.edu
#Austin Welch	austinmw@bu.edu
#Dave Ferullo   dferullo@bu.edu

#My own test function with that only handles integers
def TEST(x,y):
	if(x<y):
		return "nut is too small"
	elif(x>y):
		return "nut is too big"
	else:
		return "nut fits perfectly"

def nuts_and_bolts(nuts,bolts):
	n = len(nuts)
	#size n
	Result_nuts = [0 for x in range(n)]
	Result_bolts = [0 for x in range(n)]
	count = [0 for x in range(n)]
	#size n*n
	temp = [[0 for x in range(n)] for x in range(n)]

	#Determine which bolt fits a certain nut
	#Assign 1 if nut is too small
	#Assign 3 if nut is too big
	for i in range(n):
		for j in range(n):
			size = TEST(nuts[i],bolts[j])
			if size == "nut is too small":
				temp[i][j] = 1
			elif size == "nut fits perfectly":
				temp[i][j] = 2
			elif size == "nut is too big":
				temp[i][j] = 3
		#print temp[i]

	#Count the number of bolts that are smaller
	#If no bolts are smaller, you know it is the smallest nut
	for i in range(n):
		for j in range(n):
			if temp[i][j] == 3:
				count[i] = count[i]+1

	#Place correct combination of nut and bolt into the count[i] position of the array
	#The sorted nuts and bolts arrays will be returned in the end
	for i in range(n):
		for j in range(n):
			if TEST(nuts[i],bolts[j]) == "nut fits perfectly":
				Result_nuts[count[i]] = nuts[i]
				Result_bolts[count[i]] = bolts[j]
	return Result_nuts,Result_bolts


#array1 = [6,5,2,4,1]
#array2 = [1,6,2,5,4]
#print (nuts_and_bolts(array1,array2))
