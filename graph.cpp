/*! \file graph.cpp
*   \brief Graph implementations a map include vertices and ajecency edges list.\n
*          Using a priority_queue to store edges, and a vector to stored vertices
*          which reading from a text file.
*
*/

#include <iostream> // C++ I/O routines
#include <queue>    // The STL list class
#include <fstream>  //std::ifstream
#include <istream>  //std::seekg
#include "graph.h"


//Set vertices into a vector data structure
void Graph::setV(int v)
{
    Vectax.push_back(v);
}

//Set edges into a priority_queue data stucture
void Graph::addEdge(int u, int v, int w)
{
	edges.push({w, {u, v}});
}


// Function to find MST using Kruskal's minimun spanning tree algorithm
void Graph::kruskalMST()
{
    // Initialize result of weight
    int mst_wt = 0; 
    // Create disjoint sets
    DisjointSets ds(Vectax);
    // The total vertices
    int total = edges.size();

    if(!edges.empty()){
	cout << "Edges         Cost" <<endl;
	cout << "===================" <<endl;
	for (int i = 0; i<total; i++)
	{
	    pair<int, iPair> x = edges.top();
	    edges.pop();
            int u = x.second.first;
            int v = x.second.second;
	    int w = x.first;
  
            int set_u = ds.find(u);
            int set_v = ds.find(v);
  
            // Check if the selected edge is creating
            // a cycle or not (Cycle is created if u
            // and v belong to same set)
            if (set_u != set_v)
            {
		// Current edge will be in the MST
		// so print it
		cout << u << " - " << v << "         "<<w<<endl;
  
		// Update MST weight
		mst_wt += w;
  
		// Merge two sets
		ds.merge(set_u, set_v);
            }
	}
	cout << "===================" <<endl;  
	cout << "Total Cost:   " << mst_wt << endl<<endl;
    }
}

/*!
*   \fn Constructor
*   \brief itialize disjoint vertices set
*   \param vector<int> -  vertices
*/
DisjointSets::DisjointSets(vector<int> &vic)
{
    //Find out the maximun number in vertax vector
    //then create a two array - parent, rank
    //It declares a pointer to a dynamic array of type interger.
    int MAX = 0;
    for(vector<int>::iterator it = vic.begin(); it != vic.end(); ++it) {
	MAX = (*it>MAX) ? *it: MAX;
    }
	
    this->v = MAX+1;
    //It declares a pointer to a dynamic array of type interger.
    parent = new int[MAX+1]; 
    rnk = new int[MAX+1];  
	
    for (int i = 0; i <= v; i++)
    {   //Initially, all vertices have rank 0
        rnk[i] = 0;
  
        //every element is parent of itself
        parent[i] = i;
    }
}

int DisjointSets::find(int u)
{
/* Make the parent of the nodes in the path
   from u--> parent[u] point to parent[u] */
    return (u == parent[u] ? parent[u] : (parent[u] = find(parent[u])) );
}


void DisjointSets::merge(int x, int y)
{
    x = find(x), y = find(y);
  
    /* Make tree with smaller height
       a subtree of the other tree  */
    if (rnk[x] > rnk[y])
        parent[y] = x;

    else // If rnk[x] <= rnk[y]
        parent[x] = y;
	  
 
    if (rnk[x] == rnk[y])
        rnk[y]++;
}

