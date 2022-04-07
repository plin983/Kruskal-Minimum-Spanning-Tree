# Kruskal-Minimum-Spanning-Tree
This project is implementation of Kruskal’s algorithm for finding a minimum cost spanning tree.<br>
A Class hold map data which reading from a text file line by line then stored in a  priority_queue for edges with cost. 
An vector hold the vertex. One vertex could connect to multiple vertices, which means one vertex can have several edges.<br>
The other Class execute the find and merge function. <br><br>

Time complicity: V is vertices number, E is edge number
Look up every edge is O(E). For each edge go through find function is O(logV).
Therefore, overall time complicity is O(ElogV).

