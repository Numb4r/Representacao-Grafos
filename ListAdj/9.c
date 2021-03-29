#include<stdio.h>
#include<stdlib.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

struct TipoVertex{
	int value;
	Vertex prox;
};

struct graph{
	int V;
	int E;
	Vertex *adj;
};

//fila
struct TipoItem{
    int data;
	Item *prox;
};

struct TipoFila{
	Item *head;
	Item *tail;
	int size;
};

//// procs FILA

Fila* FFVazia(){
	Fila *f = (Fila*) malloc(sizeof(Fila));
	f->head = NULL;
	f->tail = NULL;
	return f;
}

void Queue(Fila *f, int vertex){
	Item *d = (Item *) malloc (sizeof(Item));
	d->data = vertex;
	d->prox = NULL;

	if(f->head == NULL){
		f->head = d;
		f->tail = d;
	}else{
		f->tail->prox = d;
		f->tail = d;
	}

	f->size ++;
}

Item* Dequeue(Fila *f){
	Item *aux;

	if(f->head == NULL)
		return NULL;

	aux = f->head;
	f->head = f->head->prox;
	f->size --;

	return aux;
}

//// fim procs FILA




Vertex VertexInitialize(int value){
	Vertex v = malloc (sizeof(Vertex));
	v->value = value;
	v->prox  = NULL;
	return v;
}

Graph GraphInitialize(int V){
	Graph G = malloc (sizeof(Graph));
	G->V = V;
	G->E = 0;
	G->adj = malloc(V * sizeof(Vertex));
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




int main(int argc, char const *argv[])
{

	int numberVertex,numberEdges;
	FILE *pf = fopen("../graph.txt","r");
    if(!pf) exit(-1);
	fscanf(pf,"%d,%d",&numberVertex,&numberEdges);
	Graph G = GraphInitialize(numberVertex);
	int v1,v2;
    while (!feof(pf))
    {   
        fscanf(pf,"%d,%d\n",&v1,&v2);
			GraphInsertEdge(G,G->adj[v1],G->adj[v2]);
        
    }
	fclose(pf);
	// Graph G = GraphInitialize(NUMBERVERTEX);
	
	// for (int i = 0; i < NUMBEREDGES; i++)
	// {
	// 	GraphInsertEdge(G,G->adj[vertex[i][0]],G->adj[vertex[i][1]]);
	// }
	//Modelo de Grafo do slide 9 / aula 11
	//S=0, W=1, R=2, V=3, T=4, X=5, U=6, Y=7
	// GraphInsertEdge(G, G->adj[0], G->adj[1]);
	// GraphInsertEdge(G, G->adj[0], G->adj[2]);
	// GraphInsertEdge(G, G->adj[1], G->adj[0]);
	// GraphInsertEdge(G, G->adj[1], G->adj[4]);
	// GraphInsertEdge(G, G->adj[1], G->adj[5]);
	// GraphInsertEdge(G, G->adj[2], G->adj[0]);
	// GraphInsertEdge(G, G->adj[2], G->adj[3]);
	// GraphInsertEdge(G, G->adj[3], G->adj[2]);
	// GraphInsertEdge(G, G->adj[4], G->adj[1]);
	// GraphInsertEdge(G, G->adj[4], G->adj[5]);
	// GraphInsertEdge(G, G->adj[4], G->adj[6]);
	// GraphInsertEdge(G, G->adj[5], G->adj[1]);
	// GraphInsertEdge(G, G->adj[5], G->adj[4]);
	// GraphInsertEdge(G, G->adj[5], G->adj[6]);
	// GraphInsertEdge(G, G->adj[5], G->adj[7]);
	// GraphInsertEdge(G, G->adj[6], G->adj[4]);
	// GraphInsertEdge(G, G->adj[6], G->adj[5]);
	// GraphInsertEdge(G, G->adj[6], G->adj[7]);
	// GraphInsertEdge(G, G->adj[7], G->adj[6]);
	// GraphInsertEdge(G, G->adj[7], G->adj[5]);

	ImprimeGraph(G);

	DFS(G);



	return 0;
}













