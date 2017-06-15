#AUTHOR Brandon Phan bphan@bu.edu
#AUTHOR Austin Welch austinmw@bu.edu
#AUTHOR Omar Janoudi ojanoudi@bu.edu

import networkx as nx
import operator

G = nx.DiGraph()

code = []
name = []
longitude = []
latitude = []
airports = {}
rows = 0
with open("airport_info.txt") as f:
	content = f.readlines()
	rows = len(content)
	for i in range(0, rows-1):
		columns = content[i].split(",")
		airports[columns[0]] = columns[1]
		G.add_node(columns[0],pos=(float(columns[2]),float(columns[3].replace("\n",""))))


with open("flying_times.txt") as x:
	content = x.readlines()
	rows = len(content)
	for i in range(0,rows-1):
		columns = content[i].split(",")
		G.add_edge(columns[0],columns[1],weight=float(columns[2].replace("\n","")))
		
paths = nx.single_source_dijkstra_path_length(G, 'BOS')
path_length = nx.single_source_dijkstra_path(G, 'BOS')
delayls = []
for key, val in path_length.items():
	delayls.append([key, paths[val[-1]] + (len(val)-2)*4])
sorteds = sorted(paths.items(), key=operator.itemgetter(1))
sorted_delays = sorted(delayls, key=operator.itemgetter(1))
path = nx.dijkstra_path(G, 'BOS', sorteds[-1][0])
filtered = nx.single_source_dijkstra_path_length(G, 'BOS', cutoff=1.56)
print "1A. Reachable in 1.56 : %d airports" % len(filtered)
print "1B. The 5 closest are: "
print "{} {}".format(airports[sorteds[1][0]],sorteds[1][1])
print "{} {}".format(airports[sorteds[2][0]],sorteds[2][1])
print "{} {}".format(airports[sorteds[3][0]],sorteds[3][1])
print "{} {}".format(airports[sorteds[4][0]],sorteds[4][1])
print "{} {}".format(airports[sorteds[5][0]],sorteds[5][1])
print "2A. The most remote airport is {}".format(airports[sorteds[-1][0]])
print "2B. The travel time is {} and the path is ".format(sorteds[-1][1])
print "{}".format(path[0])
for k in range (len(path)-1):
	print "-> {}".format(path[k+1])
discon = G.number_of_nodes() - len(paths)
print "3. Unreachable from Boston: {} airports".format(discon)

results = []
nodes = nx.shortest_path_length(G,"BOS") # nodes
times =  nx.shortest_path_length(G,"BOS",weight='weight')
for key in nodes:
	numnodes = (nodes[key] - 1)*4
	totalweight = times[key]
	dict = {
		key: numnodes + totalweight
	}
	results.append(dict)
				
rr= []
for i in range(0,len(results)-1):
	for key in results[i]:
		if results[i][key] > 43:
			rr = results[i]
print "5A. The furthest airport is: {}".format(rr)

count = 0
for i in range(0,len(results)-1):
	for key in results[i]:
		if results[i][key] <= 10:
			count = count + 1
print "5B. The number of flights under 10 hours with delays is: {}".format(count) 