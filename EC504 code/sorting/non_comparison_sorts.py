# Counting and Radix Sort

n=10000 # number of values
k=10000000 # range

import random
import time

A =[random.choice(range(k)) for i in range(n)]

def counting_sort(A,k):
	n=len(A)
	C=[0]*k
	#
	#for val in A:
	#   C[val] += 1
	#
	for i in range(n):
		C[A[i]] +=1
	S=[]
	for j in range(k):
		S.extend([j]*C[j])
	return S

def insert_into(val,L):
	if not L:
		L.insert(0,val)
	else:
		for i in range(len(L)):
			if L[i]>val:
				L.insert(i,val)
				return
		L.insert(len(L),val)

def bucket_sort(A,k):
	buckets = n = len(A)
	# determine buckets
	bucket_width = k//n + 1

	#Make Buckets
	B=[]
	for i in range(n):
		B.append([])
    
	for i in range(n):
		b = A[i] // bucket_width
		insert_into(A[i],B[b])
    
	S=[]
	for bucket in B:
	    S.extend(bucket)
	return S

D={}
for method in [counting_sort,bucket_sort]:
  t1=time.time()
  C=method(A,k)
  t2=time.time()
  D[method]=t2-t1

print(D)
t1=time.time()
A.sort()
t2=time.time()
print(t2-t1)

