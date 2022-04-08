/*!
*   \mainpage Kruskal Minmum Spanning Tree
*    1. Use a priority_queue of edges which consist of all the edges in the graph and 
*       each item of a priority_queue will contain 3 parameters: \n source, destination 
*       and the cost of an edge between the source and destination.\n 
*             \t priority_queue<pair<int, pair<int, int> > > edges \n
*       The first element corresponds to the cost of a edge while the second element is
*       itself a pair, and it contains two vertices of edge.\n
*    2. Use the "Union Find Algorithm" to check if it the current edge forms a cycle
*       if yes discard it, else include it (merge).
*    3. The time complicity:\n
*       Look up every edge is O(E), for each edge go through find function is O(logV).\n
*       Therefore, the total time complicity is O(ElogV).
*
*   \author    Pei Hua Lin
*
*   \file kruskal.cpp
*   \brief Implement a map include vertices and ajecency edges list.\n
*          Using a priority_queue to store edges, and a vector to stored vertices
*          which reading from a text file.
*
*/
#include <iostream> // C++ I/O routines
#include <queue>    // The STL queue class
#include <vector>
#include <fstream>  //std::ifstream
#include <istream>  //std::seekg
#include <sstream>
#include <limits> // for std::numeric_limits
#include <chrono> // analysis
#include "graph.h"

using namespace std;

/*!
*   \brief Open data file
*
*   The openFile function checks to see if the file the user specified
*   at runtime can be found.\n If no filename was passed during runtime, 
*   the user is prompted to provide one and that file is searched out.\n
*   If the file is found, the program continues, else the program exits
*   with code '1'.
*
*   \param &inf input file stream
*   \param fileName File to be searched for.
*   \return A boolean value to specifiy if the file was found.
*/
bool openFile(ifstream &inf, string fileName);

/*!
*   \brief Read data file into a graph.
*
*   The readfile function read data from a text file line by line.
*   
*   \param &inf input file stream.
*   \param &g  Graph.
*   \return A boolean is read successful.
*/
bool readFile(ifstream &inf, Graph &g);


// main fuction run command line
int main(int argc,char *argv[])
{
    ifstream inf;
    string fileName = "";
    Graph g;  
    
    //fileName get from command line
    // Or prompt for user type in
    if (argc > 1) { fileName = argv[1]; }
    else {
	cout << "Map file to Read >  ";
        cin>> fileName;
    }
    //If file doesn't exist, the exit status of '1'
    if(!openFile(inf, fileName) ){
	cout << "Input File not found" << endl;
	exit(1); 
    }

    if (readFile(inf, g)) { 
	//run system's clock
	auto begin = std::chrono::high_resolution_clock::now() ;
	//find out kruskal MST
	g.kruskalMST(); 
	
	auto end =std::chrono::high_resolution_clock::now() ; //auto is time datatype
	auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin) ;
	std::cout << "It took me " << ticks.count() << " microseconds.\n" ;

    }

    inf.close();
    exit(0);
}

// open a file
bool openFile(ifstream &inf, string fileName)
{
    if (fileName =="") {
	cout << "File to Read > ";
	cin>>fileName;
    }
    
    inf.open(fileName.c_str());
    if (!inf) 	      // File not found
	return(0);
    else 
	return(1);
}

//read from file
bool readFile(ifstream &inf, Graph& g)
{   string line;
    int v, d, c;
    iPair p;

    // read file line by line
    while (getline(inf, line)){
	//split string
	istringstream ss(line);
	ss >> v;
	//add to vector vertax
	g.setV(v);
	//add to priority_queue edges
	while(ss >> d >> c){
	    g.addEdge(v, d, c);
	}
    }

    inf.clear();
    inf.seekg(0, inf.beg);
    return true;
}
