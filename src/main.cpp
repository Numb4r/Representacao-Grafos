#include "AdjMatrix.hpp"
#include "IncMatrix.hpp"

int main(int argc, char const *argv[])
{
    // IncMatrix::Graph pGraph("graph.txt");
    AdjMatrix::Graph pGraph("graph.txt");	
    pGraph.foo();
    pGraph.bar();
    pGraph.BFS();
	pGraph.DFS();
    return 0;
}
