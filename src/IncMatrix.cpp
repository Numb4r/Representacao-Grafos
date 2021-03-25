#include "IncMatrix.hpp"
#include <cstdio>
#include <queue>


void IncMatrix::Graph::insertEdge(const int vertexOrigin,const int vertexDestination){
    if ((lastEdge+1) == numberEdges || vertexDestination >= numberVertex || vertexOrigin >= numberVertex )
        throw "ERROR: Out of index";
    ++lastEdge;
    matrix[vertexOrigin][lastEdge] = 1;
    matrix[vertexDestination][lastEdge] = -1;
}


void IncMatrix::Graph::foo()const noexcept{
    for (int i = 0; i < this->numberVertex; i++)
    {
        printf("[%d] -> ",i);    
        for (int j = 0; j < this->numberEdges; j++)
        {            
            if(this->matrix[i][j]== 1) {
                for (int k = 0; k < numberVertex; k++)
                {
                    if (this->matrix[k][j] == 1 && k != i) // Arrumar isso
                        printf("%d -> ",k);
                }
            }
        }
        printf("\n");
    }
    
}
void IncMatrix::Graph::bar()const noexcept{
    printf("/  ");
    for (int i = 0; i < this->numberEdges; i++)
        printf("e%d ",i);
    printf("\n");
    for (int i = 0; i < this->numberVertex; i++)
    {
        printf("%d  ",i);
        for (int j = 0; j < numberEdges; j++)
        {
            printf("%d   ",matrix[i][j]);
        }
        printf("\n");
    }
}
void IncMatrix::Graph::DFS() noexcept{
    IncMatrix::Graph::Color color[this->numberVertex];
    int tDiscovery[this->numberVertex];
    int tCompletion[this->numberVertex];
    int time{};
    for (int i = 0; i < this->numberVertex; i++)
        color[i] = WHITE;
    for (int i = 0; i < this->numberVertex; i++)
        if(color[i]==WHITE)
            DFSVisit(i,color,tDiscovery,tCompletion,&time);
}


void IncMatrix::Graph::DFSVisit(const int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time){
    color[vertex]       =   GREY;
    *time              +=   1;
    tDiscovery[vertex]  =   *time;
    for (int i = 0; i < numberEdges; i++)
    {
        if (matrix[vertex][i] == 1)
        {
            for (int j = 0; j < numberVertex; j++)
            {
                if (matrix[j][i] == -1 && color[j] == WHITE)
                {
                    DFSVisit(j,color,tDiscovery,tCompletion,time);
                }
                
            }
            
        }
    }
    color[vertex] = BLACK;
    *time += 1;
    tCompletion[vertex] = *time;
    printf("Vertex:%d D:%d, F:%d \n", vertex, tDiscovery[vertex], tCompletion[vertex]);
}





void IncMatrix::Graph::BFS(const int vertex) noexcept{
    IncMatrix::Graph::Color color[this->numberVertex];
    int tDiscovery[this->numberVertex];
    int pi[this->numberVertex];
    std::queue<int> queue;
    for (int i = 0; i < this->numberVertex; i++)
    {
        if(i != vertex){
            color[i] = WHITE;
            tDiscovery[i] = -1;
            pi[i] = -1;
        }
    }
    color[vertex]       = GREY;
    tDiscovery[vertex]  = 0;
    pi[vertex]          = -1;
    queue.push(vertex);
    while (queue.size() > 0)
    {
        int vertexHolder = queue.front();
        queue.pop();
        for (int i = 0; i < numberEdges; i++)
        {
            if (matrix[vertexHolder][i] == 1)
            {
                for (int destV = 0; destV < numberVertex; destV++)
                {
                    if (matrix[destV][i] == -1 && color[destV] == WHITE)
                    {
                        color[destV] = GREY;
                        tDiscovery[destV] = tDiscovery[vertexHolder] + 1;
                        pi[destV] = vertexHolder;
                        queue.push(destV);
                    }
                    
                }
            }
            
        }
        color[vertexHolder] = BLACK;
        printf("Vertex:%d\n",vertexHolder);
        
    }
    

}

IncMatrix::Graph::Graph(const int nVertex,const int nEdges):
    numberVertex{nVertex},numberEdges{nEdges},
    matrix{std::make_unique< std::unique_ptr<int[]>[] >(nVertex)}{
    for (int i = 0; i < nVertex; i++)
    {
        matrix[i] = std::make_unique<int[]>(nEdges);
        for (int j = 0; j < nEdges; j++)
            matrix[i][j] = 0;
    }
}