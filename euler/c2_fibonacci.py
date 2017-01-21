
f = 0
s = 1
i = 0
n = 0
while (i < 4000000):
	i = f + s
	print("i: ", i)
	f = s
	s = i
	if (i % 2 == 0):
		n += i
		
		
print(n) 


# prints sum of even fib up to 4mil