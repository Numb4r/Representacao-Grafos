#include<stdio.h>
#include<stdlib.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;
typedef struct TipoItem Item;

struct TipoVertex{
	int value;
	Vertex prox;
};

struct graph{
	int V;
	int E;
	Vertex *adj;
};

Vertex VertexInitialize(int value){
	Vertex v = (Vertex)malloc (sizeof * v);
	v->value = value;
	v->prox  = NULL;
	return v;
}

Graph GraphInitialize(int V){
	Graph G = (Graph)malloc (sizeof * G);
	G->V = V;
	G->E = 0;
	G->adj = (Vertex*)malloc(V * sizeof * G->adj);
	for(int v=0; v<V; v++)
		G->adj[v] = VertexInitialize(v);
	return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2){
	Vertex v = G->adj[v1->value];
	
	while(v->prox != NULL){
		if (v->value == v2->value)
			return;
		v = v->prox;
	}

	v->prox = VertexInitialize(v2->value);
	G->E ++;
}

void ImprimeGraph(Graph G){
	Vertex aux;

	for(int v=0; v<G->V; v++){
		aux = G->adj[v];
		while(aux != NULL){
			printf(" %d -> ", aux->value);
			aux = aux->prox;
		}
		printf("\n");
	}
}


void DFS_VISIT(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo){
	cor[v->value]  = 1;
	*tempo        += 1;
	d[v->value]    = *tempo;

	for(Vertex u = G->adj[v->value]; u != NULL; u=u->prox)
		if(cor[u->value] == 0)
			DFS_VISIT(G, u, cor, d, f, tempo);


	cor[v->value] = 2;
	*tempo += 1;
	f[v->value] = *tempo;
	printf("Vertex:%d D:%d, F:%d \n", v->value, d[v->value], f[v->value]);
}

void DFS(Graph G){
	int cor[G->V]; // Branco 0, Cinza 1, Preto 2
	int d[G->V];   // Tempo de descoberta
	int f[G->V];   // Tempo de finalização
	int tempo = 0;

	for(int v=0; v<G->V; v++)
		cor[v] = 0;

	for(int v=0; v<G->V; v++)
		if(cor[v] == 0)
			DFS_VISIT(G, G->adj[v], cor, d, f, &tempo);
}



void DestroyGraph(Graph G){
	for (int i = 0; i < G->V; i++){
		Vertex atual = G->adj[i];
		while (atual != NULL)
		{
			Vertex prox = atual->prox;
			free(atual);
			atual->prox = NULL;
			atual = prox;
			prox = (atual == NULL ? NULL : atual->prox);
		}
		G->adj[i] = NULL;
	}
	
	free(G->adj);
	G->adj = NULL;
	free(G);
	G = NULL;
		
}
int main(int argc, char const *argv[])
{

	int numberVertex,numberEdges;
	FILE *pf = fopen("../graph.txt","r");
    if(!pf) exit(-1);
	fscanf(pf,"%d %d\n",&numberVertex,&numberEdges);
	Graph G = GraphInitialize(numberVertex);
	int v1,v2;
    while (!feof(pf))
    {   
          fscanf(pf,"%d %d\n",&v1,&v2);
		GraphInsertEdge(G,G->adj[v1],G->adj[v2]);
        
    }
	fclose(pf);
	
	ImprimeGraph(G);
	DFS(G);

	DestroyGraph(G);
	return 0;
}













