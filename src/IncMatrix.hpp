#pragma once
#include <memory>
namespace IncMatrix
{
    class Graph
    {
    private:
        enum Color{
            WHITE,
            GREY,
            BLACK
        };
        int numberVertex;
        int numberEdges;
        int lastEdge{-1};
        std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
        void DFSVisit(const int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time);
    public:
        void insertEdge(const int vertexOrigin,const int vertexDestination);
        void foo() const noexcept;
        void bar() const noexcept;
        void DFS() noexcept;
        void BFS(const int vertex = 0) noexcept;
        Graph(const int nVertex,const int nEdges);
        
    };
    
    
    
} // namespace IncMatrix
