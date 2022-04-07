# Kruskal-Minimum-Spanning-Tree
This project is implementation of Kruskal’s algorithm for finding a minimum cost spanning tree.
A Class hold map data which reading from a text file line by line then stored in a  priority_queue for edges with cost. 
An vector hold the vertex. One vertex could connect to multiple vertices, which means one vertex can have several edges.
The other Class execute the find and merge function.

1. Project files include: kruskal.cpp, graph.cpp, graph.h <br>
   Program can be run indepently by either running command line or cin:<br>
   
   <tab>./kruskal (file to read),  for example:   ./skruskal graph1.txt 


2. Input map file format would like this way<br>
   (vertex#)(edge)(weight):<br>

   <tab><img width="113" alt="image" src="https://user-images.githubusercontent.com/103209001/162260713-ce8acd97-1d1f-4095-8928-0198c9c3a4a2.png">

  *If input file contains duplicate data then the minimum cost will be considered,  ex: 0 1 2 1 3,
   then cost=2 will be considered.
  *This program considers undirective map, derective map will be treat as undirection.


3. Output will be as below<br>
   <tab><img width="241" alt="image" src="https://user-images.githubusercontent.com/103209001/162260507-870c0bbd-481c-4d54-85c9-2951f19a00a1.png">


4. Time complicity: V is vertices number, E is edge number
Look up every edge is O(E). For each edge go through find function is O(logV).
Therefore, overall time complicity is O(ElogV).

