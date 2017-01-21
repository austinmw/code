from collections import Counter

Words=['test','dictionary','cat','act','tea','eat','ate']

D={}
D['ab']=5
D[5]='this'
#print(D)

Words=open('enable1.txt').read().splitlines()

# How many different anagrams are in this word list?

#print(len(Words))
# Which words are anagrams of each other?
# for word in Words:
# 	c_w=Counter(word)
# 	for otherword in Words:
# 		if word == otherword:
# 			continue
# 		c_o=Counter(otherword)
# 		if c_o==c_w:
# 			print(word,otherword)

def has_anagram(targetword,Words):
	"""does targetword have an anagram in Words?"""
	Anagrams={}
	for word in Words:
		# add word to Anagrams
		key=tuple(sorted(word))
		#print(key)
		if key in Anagrams:
			Anagrams[key].append(word)
		else:
			Anagrams[key]=[word]

	mykey=tuple(sorted(targetword))
	if mykey in Anagrams:
		for word in Anagrams[mykey]:
			if word != targetword:
				return True
	return False



def find_anagram_count(Words):
	Anagrams={}
	for word in Words:
		# add word to Anagrams
		key=tuple(sorted(word))
		#print(key)
		if key in Anagrams:
			Anagrams[key].append(word)
		else:
			Anagrams[key]=[word]

	total=0
	for key in Anagrams:
		if len(Anagrams[key])>1:
			total += 1
	return total

# What is the complexity of find_anagram_count(Words)

# What is the complexity of has_anagram?

print(has_anagram('dictionary',Words))

testword='abcdefghi'
import itertools,math
All=list(itertools.permutations(testword))
print(len(All),math.factorial(len(testword)))
print(has_anagram(testword,All))