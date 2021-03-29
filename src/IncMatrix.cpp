#include "IncMatrix.hpp"
#include <cstdio>
#include <queue>
using namespace IncMatrix;

void Graph::insertEdge(const int vertexOrigin,const int vertexDestination){
    if (lastEdge == numberEdges || vertexDestination >= numberVertex || vertexOrigin >= numberVertex )
        throw "ERROR: Out of index";
    matrix[vertexOrigin][lastEdge] = 1;
    matrix[vertexDestination][lastEdge] = -1;
    lastEdge++;
}


void Graph::foo()const noexcept{
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
void Graph::bar()const noexcept{
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
void Graph::DFS() noexcept{
    Graph::Color color[this->numberVertex];
    int tDiscovery[this->numberVertex];
    int tCompletion[this->numberVertex];
    int time{};
    for (int i = 0; i < this->numberVertex; i++)
        color[i] = WHITE;
    for (int i = 0; i < this->numberVertex; i++)
        if(color[i]==WHITE)
            DFSVisit(i,color,tDiscovery,tCompletion,&time);
}


void Graph::DFSVisit(const int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time){
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





void Graph::BFS(const int vertex) noexcept{
    Graph::Color color[this->numberVertex];
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

Graph::Graph(const char* fileName){
    FILE *pf = fopen(fileName,"r");
    if(!pf) return ;
    fscanf(pf,"%d,%d",&numberVertex,&numberEdges);
    
    matrix = std::make_unique< std::unique_ptr<int[]>[] >(numberVertex);
    for (int i = 0; i < numberVertex; i++)
    {
        matrix[i] = std::make_unique<int[]>(numberEdges);
        for (int j = 0; j < numberEdges; j++)
            matrix[i][j] = 0;
    }
    int v1,v2;
    while (!feof(pf))
    {   
        fscanf(pf,"%d,%d\n",&v1,&v2);
        this->insertEdge(v1,v2);
    }
}
Graph::Graph(const int nVertex,const int nEdges):
    numberVertex{nVertex},numberEdges{nEdges},
    matrix{std::make_unique< std::unique_ptr<int[]>[] >(nVertex)}{
    for (int i = 0; i < nVertex; i++)
    {
        matrix[i] = std::make_unique<int[]>(nEdges);
        for (int j = 0; j < nEdges; j++)
            matrix[i][j] = 0;
    }
}