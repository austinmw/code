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

PossibleKeys=[x.strip() for x in open('wordlist.txt').readlines()]


#result = subprocess.run(['custom_bst',"8","4"],input=valstr,stdout=subprocess.PIPE,universal_newlines=True)
#print(result.stdout,end="")

TestValues=[ (1000,1,False), (10000,1,False), (25000,1,False), (50000,1,False), (75000,1,False) ,
    (100000,1,False) , (150000,1,False) , (len(PossibleKeys),1,False) ]

TestValues=[]
for kval in [10000,20000,30000,40000,50000,60000]:
  TestValues.append((50000,kval,False))
print(TestValues)


#TestValues=[ (10,10,True),(100,100,True),(1000,1000,True), (5000,5000,True)]

programs={'custom_bst':'-o','vector_find3':'-x','map_find3':'-s'}


programs={'calibrated_bst':'-x'}
TestValues=[(2**17-1,1,False)]

RunTimes={}

for program in programs:
	RunTimes[program]=[]
	for test in TestValues:
	  RunTimes[program].append(0)

NTrials=3

for ntimes in range(NTrials):
	for ii,(N,K,sortit) in enumerate(TestValues):
		Data = random.sample(range(len(PossibleKeys)),N)
		Keys = [PossibleKeys[i] for i in Data]
		T = [(Keys[i],str(Data[i])) for i in range(N)]
		if sortit:
		  T.sort()
		valstr = "\n".join([ k+" "+d for k,d in T])

		keystr = "\n".join(random.choice(Keys) for k in range(K) )

		valstr = valstr + keystr

		for program in programs:
			t1=time.time()
			result = subprocess.run([program,str(N),str(K)],input=valstr,stdout=subprocess.PIPE,universal_newlines=True)
			t2=time.time()
			RunTimes[program][ii] += t2 - t1

print(RunTimes)
quit()

from pylab import *

for prg in programs:
   plot([t[1] for t in TestValues],RunTimes[prg],programs[prg],markersize=10)

#for prg in programs:
#   plot([t[0] for t in TestValues],RunTimes[prg],programs[prg],markersize=10)

legend(programs)
show()