#include <stdio.h>
#include <time.h>

#define MAX_VERTEX 10000
#define MAX_EDGE 50000000

typedef struct _line{
	int first;
	int last;
	int weight;
}Line;

Line heap[MAX_EDGE];
Line element;

int Vertex_Num,Edge_Num,i;
int Heap_Num=0,Kruskal=0,Total_Weight=0;
int parent, child;
int Root[MAX_VERTEX];

void Insert_heap(Line item, int *n) {
  i = ++(*n);
  while((i != 1) && (item.weight < heap[i/2].weight)) {
    heap[i] = heap[i/2];
    i /= 2;
  }
  heap[i] = item;
}

Line Delete_heap(int *n) {
  Line item, temp;
  item = heap[1];
  temp = heap[(*n)--];
  parent = 1;
  child = 2;

  while(child <= *n) {
    if((child < *n) && (heap[child].weight > heap[child+1].weight)) child++;
    if(temp.weight <= heap[child].weight) break;
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }

  heap[parent] = temp;
  return item;
}

int Find(int a){
  for( ; Root[a] >= 0; a = Root[a])
    ;
  return a;
}

void Union(int a, int b){
  int temp = Root[a] + Root[b];
  if(Root[a] > Root[b]){
    Root[a] = b;
    Root[b] = temp;
  } 
  else{
    Root[b] = a;
    Root[a] = temp;
  }
}

int main(int argc, char * argv[]){
	clock_t start = clock();

	if (argc != 2){
    printf("usage: ./fp1 input_filename\n");
    return 0;
  }

	FILE * input = fopen(argv[1], "r");
	if(!input){
		printf("The input file does not exist.\n");
		return 0;
	}

	FILE * result = fopen("fp1_result.txt","w");

	fscanf(input,"%d", &Vertex_Num);
	fscanf(input,"%d", &Edge_Num);

	for(i=0;i<Edge_Num;i++){
		fscanf(input,"%d %d %d",&element.first,&element.last,&element.weight);
		Insert_heap(element,&Heap_Num);
	}

	for(i=0;i<Vertex_Num;i++)
		Root[i]=-1; 

	while(Kruskal < Vertex_Num-1){
		if(!Heap_Num) break;
		element = Delete_heap(&Heap_Num);

		if((Find(element.first) == -1) || (Find(element.first) != Find(element.last))){
			Kruskal++;
			Total_Weight+=element.weight;
			Union(Find(element.first), Find(element.last));
      fprintf(result, "%d %d %d\n", element.first, element.last, element.weight);
		}
	}

	fprintf(result, "%d\n",Total_Weight);
  if(Kruskal < Vertex_Num-1) fprintf(result, "DISCONNECTED\n");
	else fprintf(result, "CONNECTED\n");

	clock_t end = clock();
	printf("output written to fp1_result.txt.\nrunning time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	fclose(input);
	fclose(result);
	return 0;
}
