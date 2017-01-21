# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 11:04:13 2016

@author: engineer
"""

import os
import subprocess
import time
import random
files=os.listdir()

def makenumbersfile(V,fn):
	f=open(fn,'w')
	for x in V:
		print(x,file=f)
	f.close()


#print(files)
# Test Bubble Sort
Nvalues=[1,10,100]+list(range(1000,40000,5000))
programs={'merge_sort':'-o','bubble_sort':'-x','stdlib_sort':'-s'}
programs={'merge_sort':'-o','stdlib_sort':'-s','sort':'-x'}

filename='numbers.txt'

RunTimes={}

for program in programs:
 RunTimes[program]=[]
 for N in Nvalues:
  Nums=list(range(N))
  Nums=Nums[::-1]
  makenumbersfile(Nums,filename)

  t1=time.time()
  if program=='sort':
  	  subprocess.call(['sort','-n',filename])
  else:
	  subprocess.call([program,filename])
  t2=time.time()
  RunTimes[program].append(t2-t1)

print(RunTimes)
 # use check_output to test correctness

#SortedByProgram=[int(x) for x in a.decode().split('\n')[:-1]]

#print(SortedByProgram)

#Nums.sort()
#if Nums == SortedByProgram:
#    print('sort was correct')
#else:
#    print('bad sort')
#print(Nums)
#print(SortedByProgram)

from pylab import *
for prg in programs:
  plot(Nvalues,RunTimes[prg],programs[prg],markersize=10)

legend(programs)
show()