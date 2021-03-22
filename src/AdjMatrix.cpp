#include "AdjMatrix.hpp"
#include <cstdio>



void AdjMatrix::Graph::insertEdge(const int v1,const int v2){
    if(v1 >= this->numberVertex || v2 >= this->numberVertex )
        throw "ERROR: Out of index";
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
    if(v1==v2) matrix[v1][v2] = 2; //Fazer de forma mais inteligente
    this->numberEdges+=1;
}
void AdjMatrix::Graph::foo()const noexcept{
    for (int i = 0; i < this->numberVertex; i++)
    {
        printf("[%d] ->",i);
        for (int j = 0; j < this->numberVertex; j++)
        {            
            if(this->matrix[i][j]== 1 || this->matrix[i][j] == 2) 
                printf("%d ->",j);
        }
        printf("\n");
    }
    
}
void AdjMatrix::Graph::bar()const noexcept{
    printf("/ ");
    for (size_t i = 0; i < this->numberVertex; i++)
        printf("%d ",i);
    printf("\n");
    for (size_t i = 0; i < this->numberVertex; i++)
    {
        printf("%d ",i);
        // for (size_t i = 0; i < count; i++)
        
        for (size_t j = 0; j < numberVertex; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

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

// Substituido por smartpointer
// AdjMatrix::Graph::Graph(const int numberVertex){
//     this->matrix = new int*[numberVertex];
//     for (int i = 0; i < numberVertex; i++)
//     {
//         this->matrix[i] = new int[numberVertex];
//     }
// }
