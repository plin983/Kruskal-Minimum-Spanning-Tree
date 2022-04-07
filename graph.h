/*!  \file graph.h
*    \brief Graph include vertices and ajecency edges with cost.\n
*           Complement Kruskal's minimun spanning tree algorithm.
*/
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream> // C++ I/O routines
#include <queue>    // The STL list class
#include <fstream>  //std::ifstream
#include <istream>  //std::seekg
#include <vector>

using namespace std;

/*!  \brief Creating shortcut for an integer pair.
*           Represent path cost.
*/
typedef  pair<int, int> iPair;

/*!
*    \class Graph
*    \brief Definition of a container for a graph.\n
*           The Garph class holds a number of vertices and adjacency edges,
*           all edges hold cost.\n
*           Member fuctions set vertices and edges, and retrieve these data
*           to find out kruskal's minimun spanning tree. 
*/
class Graph {
public: 

/*!
*   \brief add a vertax into a vector
*   \param int v - the vertax
*/
    void setV(int v);

/*!
*   \brief add an edge into priority_queue
*   \param int w - the weight of the edge
*   \param int u - the start of vertax of the edge
*   \param int v - the end of vertax of the edge
*/
    void addEdge(int u, int v, int w);
    
/*!
*   \brief Implement Kruskal MST algarithm. Check edges one by one, if their
*          parents are different then merge it, and add to the MST result.
*   \param int w - the weight of the edge
*   \param int u - the start of vertax of the edge
*   \param int v - the end of vertax of the edge
*/	
    void kruskalMST();
    
private:
/*!
*   \brief The number of total vertices
*/
    int V;
/*!
*   \brief Vector is container of all vertices
*/
    vector<int> Vectax;
/*!
*   \brief Priority_Queue is container of all containing adjacency edges.
*          Sort all the edges in decreasing order.
*/
    priority_queue<pair<int, iPair>, vector<pair<int, iPair>>, greater<pair<int, iPair>> > edges;
    
} ;

/*!
*   \class  DisjointSets
*   \brief  A disjont vertices' set. \n
*           Member fuction find their parent vertax.\n
*           If parent vertices are different then join(merge) it, other, discard.
*/
class DisjointSets {
public: 
/*!
*   \brief Constructor. Initialize disjoint vertices set
*   \param vector<int> -  vertices
*/
    DisjointSets(vector<int> & v);

/*!
*   \brief Find out a vertax's parent
*   \param int -  vertax number
*/
    int find(int u);
    
/*!
*   \brief merge two tree
*   \param int x - the first subtree vertax
*   \param int y - the second subtree vertax
*/
    void merge(int x, int y);

private:
/*!
*   \brief It declares a pointer point to a dynamic array of type interger.
*          A pointer represent parent to figure out if it forms a cycle.
*          And a pointer represent rank to figure out the smaller height
*          would be a subtree while merging.
*/
    int *parent, *rnk;
    
/*!
*   \brief Total vertices in a graph.
*/   
    int v;
};

#endif