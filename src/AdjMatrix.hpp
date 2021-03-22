#include <memory>
namespace AdjMatrix
{
    enum Color{
        WHITE,
        GREY,
        BLACK
    };
    class Graph
    {
        private:
            int numberVertex;
            int numberEdges;
            // int** matrix;
            std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
            void DFSVisit(int vertex,enum Color *color,int *tDiscovery,int *tCompletion,int *time) noexcept;
        public:
            void insertEdge(const int vertexOrigin, const int vertexDestination);
            void foo() const noexcept;
            void bar() const noexcept;
            void DFS() noexcept;
            Graph(const int numberVertex);
            // ~Graph(); Substituido por smartpointer
    };
    
} // namespace AdjMatrix

