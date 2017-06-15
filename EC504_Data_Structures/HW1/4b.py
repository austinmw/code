import sys
from collections import OrderedDict

def main():
	inputstring = sys.argv[1]
	length = int(sys.argv[2])
	analyze(inputstring, length)

def analyze(inputstring, length):
	d = OrderedDict()
	for i in range(0, len(inputstring) - length + 1):    
		substring = inputstring[i:i+length]
		if substring in d:
			d[substring] += 1
		else:
			d[substring] = 1
	maxlength = max(d.values())
	for k,v in d.items():
		if v == maxlength:
			print(k)
			break

main()