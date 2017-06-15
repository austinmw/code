# AUTHOR1: Austin Welch austinmw@bu.edu

# not sure if I get more credit for incorrect but on time or 
# correct but late?

import sys

def main():
	s = str(sys.argv[1])
	x = int(sys.argv[2])
	Analyze(s, x)	

def Analyze(s, x):
	l = [s[i:i+x] for i in range(len(s)-1)]
	print(max(l, key=lambda m:s.count(m)))
	
main()