# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

#define	NUM 100

typedef struct {
	int vex;
	int gno;
} TVex;

typedef struct {
	int vh, vt;
	int cost;
	int flag;
} TEdge;

typedef struct {
	TVex *pv;
	TEdge *pe;
	int nv, ne;
} TGraph, *PGraph;

PGraph read_file(char * fname);

int graph_vex_id(TGraph *G, int vex);

void kruskal_mst(TGraph *G);

void show_result(TGraph *G);

int main(int argc, char *argv[])
{
	char *fname = "graph.txt";

	PGraph G = read_file(fname);

	kruskal_mst(G);

	show_result(G);
	
	return 0;
}

int graph_vex_id(TGraph *G, int vex)
{
	int i;
	for (i = 0; i < G->nv; ++i) {
		if (G->pv[i].vex == vex)
			return i;
	}
	G->pv[G->nv].vex = vex;
	G->pv[G->nv].gno = vex;
	return G->nv++;
}

PGraph read_file(char * fname)
{
	int vh, vt;
	FILE * pFile = NULL;
	PGraph G = (PGraph)malloc(sizeof(TGraph));

	G->nv = G->ne = 0;
	G->pv = (TVex*)malloc(sizeof(TVex) * NUM);
	G->pe = (TEdge*)malloc(sizeof(TEdge) * NUM);
	
	pFile = fopen(fname, "r");
	if(!pFile)	{
		printf("打开文件失败!\n");
		exit(0);
	}
	
	while(!feof(pFile))	{
		fscanf(pFile, "%d\t%d\t%d\n", &vh, &vt, &G->pe[G->ne].cost);
		G->pe[G->ne].vh = graph_vex_id(G, vh);
		G->pe[G->ne].vt = graph_vex_id(G, vt);
		G->pe[G->ne].flag = 0;
		G->ne++;
	}
	
	fclose(pFile);
	return G;
}

void kruskal_mst(TGraph *G) {
	int i, min, idx, m, n, g, count = 1;
	while (count < G->nv) {
		min = INT_MAX;
		for (i = 0; i < G->ne; ++i) {
			if (G->pe[i].cost < min && G->pe[i].flag == 0) {
				min = G->pe[i].cost;
				idx = i;
			}
		}
		m = G->pe[idx].vh;
		n = G->pe[idx].vt;
		if (G->pv[m].gno != G->pv[n].gno) {
			G->pe[idx].flag = 1;
			count++;
			g = G->pv[n].gno;
			for (i = 1; i <= G->nv; ++i) {
				if (G->pv[i].gno == g)
					G->pv[i].gno = G->pv[m].gno;
			}
		}
		else
			G->pe[idx].flag = -1;
	}
}

void show_result(PGraph G)
{
	printf("最小生成树的边为：\n");
	int i;
	for (i = 0; i < G->ne; ++i) {
		if (G->pe[i].flag == 1) {
			printf("%d\t%d\t%d\n", G->pv[G->pe[i].vh].vex, G->pv[G->pe[i].vt].vex, G->pe[i].cost);
		}
	}
}