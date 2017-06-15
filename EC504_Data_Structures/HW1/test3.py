import sys

def main():
	str = sys.argv[1]
	size = int(sys.argv[2])
	analyze(str, size)

def analyze(str, size):
 
	l = [str[i:i+size] for i in range(len(str)-1)]


	max(l, key=str.count)


main()
