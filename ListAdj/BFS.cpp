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
	Fila *f = (Fila*) malloc(sizeof *f);
	f->head = NULL;
	f->tail = NULL;
	f->size=0;
	return f;
}

void Queue(Fila *f, int vertex){
	Item *d = (Item *) malloc (sizeof *d);
	d->data = vertex;
	d->prox = NULL;

	if(f->head == NULL){
		f->head = d;
		f->tail = d;
	}else{
		f->tail->prox = d;
		f->tail = d;
	}
	f->size++;
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


void BFS(Graph G, Vertex s){
	int cor[G->V]; //0 Branco, 1 Cinza, 2 Preto
	int d[G->V];
	int pi[G->V]; // -1 == NULL
	Fila *f = FFVazia();

	for(int i=0; i<G->V; i++)
		if(i != s->value){
			cor[i] = 0;
			d[i]   = -1; //infinito
			pi[i]  = -1; // ? não tem pai ainda
		}

	cor[s->value] = 1;
	d[s->value]   = 0;
	pi[s->value]  = -1;

	Queue(f, s->value);

	while (f->size > 0){
		Item *u = Dequeue(f);
		for(Vertex v = G->adj[u->data]; v != NULL; v=v->prox){
			if(cor[v->value] == 0){
				cor[v->value] = 1;
				d[v->value]   = d[u->data] + 1;
				pi[v->value]  = u->data;
				Queue(f, v->value);
			}
		}
		cor[u->data] = 2;
		printf("Vertex:%d\n", u->data);
	}
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
	// ImprimeGraph(G);

	BFS(G, G->adj[0]);
	DestroyGraph(G);
	return 0;
}













