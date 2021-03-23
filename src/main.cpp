#include "AdjMatrix.hpp"
#include <cstdio>
int main(int argc, char const *argv[])
{
	
    
    AdjMatrix::Graph pGraph(10);
    pGraph.insertEdge(0,2);
	pGraph.insertEdge(0,1);
	pGraph.insertEdge(1,0);
	pGraph.insertEdge(1,4);
	pGraph.insertEdge(1,5);
	pGraph.insertEdge(2,0);
	pGraph.insertEdge(2,3);
	pGraph.insertEdge(3,2);
	pGraph.insertEdge(4,1);
	pGraph.insertEdge(4,5);
	pGraph.insertEdge(4,6);
	pGraph.insertEdge(5,1);
	pGraph.insertEdge(5,4);
	pGraph.insertEdge(5,6);
	pGraph.insertEdge(5,7);
	pGraph.insertEdge(6,4);
	pGraph.insertEdge(6,5);
	pGraph.insertEdge(6,7);
	pGraph.insertEdge(7,6);
	pGraph.insertEdge(7,5);
    pGraph.foo();
    pGraph.BFS();
	pGraph.DFS();
    return 0;
}
