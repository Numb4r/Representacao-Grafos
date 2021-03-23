#pragma once
#include<memory>
namespace AdjMatrix
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
            std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
            void DFSVisit(int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time) noexcept;
        public:
            void insertEdge(const int vertexOrigin, const int vertexDestination);
            void foo() const noexcept;
            void bar() const noexcept;
            void DFS() noexcept;
            void BFS(const int vertex = 0) noexcept;
            Graph(const int numberVertex);
            // ~Graph(); Substituido por smartpointer
    };
    
} // namespace AdjMatrix

