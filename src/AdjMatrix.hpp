#include <memory>
namespace AdjMatrix
{

    class Graph
    {
        private:
            int numberVertex;
            int numberEdges;
            // int** matrix;
            std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
            void DFSVisit() noexcept;
        public:
            void insertEdge(const int v1, const int v2);
            void foo() const noexcept;
            void bar() const noexcept;
            void DFS() noexcept;
            Graph(const int numberVertex);
            // ~Graph(); Substituido por smartpointer
    };
    
} // namespace AdjMatrix

