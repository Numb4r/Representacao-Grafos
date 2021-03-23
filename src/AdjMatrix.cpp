#include "AdjMatrix.hpp"
#include <cstdio>
#include <queue>



void AdjMatrix::Graph::insertEdge(const int vertexOrigin, const int vertexDestination){
    if(vertexOrigin >= this->numberVertex || vertexDestination >= this->numberVertex )
        throw "ERROR: Out of index";
    matrix[vertexOrigin][vertexDestination] = (vertexOrigin == vertexDestination ? 2 : 1 );
    
    this->numberEdges+=1;
}
void AdjMatrix::Graph::foo()const noexcept{
    for (int i = 0; i < this->numberVertex; i++)
    {
        printf("[%d] -> ",i);
        for (int j = 0; j < this->numberVertex; j++)
        {            
            if(this->matrix[i][j]== 1 || this->matrix[i][j] == 2) 
                printf("%d -> ",j);
        }
        printf("\n");
    }
    
}
void AdjMatrix::Graph::bar()const noexcept{
    printf("/ ");
    for (int i = 0; i < this->numberVertex; i++)
        printf("%d ",i);
    printf("\n");
    for (int i = 0; i < this->numberVertex; i++)
    {
        printf("%d ",i);
        // for (size_t i = 0; i < count; i++)
        
        for (int j = 0; j < numberVertex; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

/*=================================================================================*/
/*                              DFS                                                */
/*=================================================================================*/
void AdjMatrix::Graph::DFS()noexcept{
    AdjMatrix::Graph::Color color[this->numberVertex];
    int tDiscovery[this->numberVertex];
    int tCompletion[this->numberVertex];
    int time{};
    for (int i = 0; i < this->numberVertex; i++)
        color[i] = WHITE;
    for (int i = 0; i < this->numberVertex; i++)
        if(color[i] == WHITE)
            DFSVisit(i,color,tDiscovery,tCompletion,&time);
}
void AdjMatrix::Graph::DFSVisit(int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time) noexcept{
    color[vertex]       = GREY;
    *time              += 1;
    tDiscovery[vertex]  = *time;
    for (int i = 0; i < this->numberVertex; i++)
        if(matrix[vertex][i] == 1 & color[i] == WHITE)
            DFSVisit(i,color,tDiscovery,tCompletion,time);
    

    color[vertex]       = BLACK;
    *time              += 1;
    tCompletion[vertex] = *time;
    printf("Vertex:%d D:%d, F:%d \n", vertex, tDiscovery[vertex], tCompletion[vertex]);
}
/*=================================================================================*/
/*                              DFS                                                */
/*=================================================================================*/



/*=================================================================================*/
/*                              BFS                                                */
/*=================================================================================*/


void AdjMatrix::Graph::BFS(const int vertex) noexcept{
    AdjMatrix::Graph::Color color[this->numberVertex];
    int tDiscovery[this->numberVertex];
    int pi[this->numberVertex];
    std::queue<int> queue; 
    for (int i = 0; i < this->numberVertex; i++)
    {
        if(i != vertex){
            color[i] = WHITE;
            tDiscovery[i] = -1; //infinito
            pi[i] = -1; // ? nao tem pai ainda
        }
    }
    color[vertex] = GREY;
    tDiscovery[vertex] = 0;
    pi[vertex] = -1;

    queue.push(vertex);

    while (queue.size() > 0)
    {
        int VertexHolder = queue.front();
        queue.pop();

        for (int i = 0; i < this->numberVertex; i++)
        {
            if (this->matrix[VertexHolder][i] == 1 && color[i] == WHITE)
            {
                color[i] = GREY;
                tDiscovery[i] = tDiscovery[VertexHolder] + 1;
                pi[i] = VertexHolder;
                queue.push(i);
            }
            
        }
        color[VertexHolder] = BLACK;
		printf("Vertex:%d\n", VertexHolder);
        
        
    }
    
    
}
/*=================================================================================*/
/*                              BFS                                                */
/*=================================================================================*/



//Using smart pointer
//https://stackoverflow.com/questions/41378590/declare-bi-directional-matrix-using-smart-pointers-in-c

AdjMatrix::Graph::Graph(const int numberVertex):
    numberVertex{numberVertex},numberEdges{0},
    matrix{std::make_unique< std::unique_ptr<int[]>[] >(numberVertex)}{
    for ( int i = 0; i < numberVertex; ++i)
       {
         matrix[i] = std::make_unique< int[] >(numberVertex);
         for (int j = 0; j < numberVertex; ++j)
            matrix[i][j] = 0;
       }    
}

