#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define INF 32767

char airports[SIZE][20] = {
    "DEL", "MUM", "BLR", "CHN", "HYD",
    "KOL", "AMD", "PUN", "GOA", "CHD"
};

int graph[SIZE][SIZE] = {
    {0,1400,2150,2180,0,1300,780,0,0,240},
    {1400,0,980,1030,0,0,520,150,0,0},
    {2150,980,0,350,630,0,0,0,0,0},
    {2180,1030,350,0,630,1600,0,0,1140,0},
    {0,0,630,630,0,0,0,0,0,0},
    {1300,0,0,1600,0,0,0,0,0,0},
    {780,520,0,0,0,0,0,0,0,900},
    {0,150,0,0,0,0,0,0,360,0},
    {0,0,0,1140,0,0,0,360,0,0},
    {240,0,0,0,0,0,900,0,0,0}
};

int distArr[SIZE], parentArr[SIZE], visited[SIZE];

void pressAnyKey() {
    printf("\nPress any key to return to menu...");
    getchar();  
    getchar();  
}

void init_single_source(int n, int s) {
    int  v;
    for (v = 0; v < n; v++) {
        distArr[v] = INF;
        parentArr[v] = -1;
        visited[v] = 0;
    }
    distArr[s] = 0;
}

void relax(int u, int v) {
    if (graph[u][v] != 0 && distArr[u] != INF) {
        int newDist = distArr[u] + graph[u][v];
        if (distArr[v] > newDist) {
            distArr[v] = newDist;
            parentArr[v] = u;
        }
    }
}

int extract_min(int n) {
    int i;
    int min = INF, idx = -1;
    for (i = 0; i < n; i++) {
        if (!visited[i] && distArr[i] < min) {
            min = distArr[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int n, int s) {
    int i,v;
    init_single_source(n, s);
    for (i = 0; i < n; i++) {
        int u = extract_min(n);
        if (u == -1) break;
        visited[u] = 1;
	for (v = 0; v < n; v++) {
            relax(u, v);
        }
    }
}

void printPath(int dest) {
    if (parentArr[dest] == -1) return;
    printPath(parentArr[dest]);
    printf(" -> %s", airports[dest]);
}

void showAirports() {
    int i;
    printf("\nAvailable Airports:\n");
    for (i = 0; i < SIZE; i++) {
	printf("%d. %s\n", i + 1, airports[i]);
    }
}

void showAdjMatrix() {
    int i,j;
    printf("\nFlight Network (Distance in km):\n\n");

    printf("%7s","");
    for (i = 0; i < SIZE; i++) {
	printf("%7s", airports[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
	printf("%7s", airports[i]);
	for (j = 0; j < SIZE; j++) {
	    if (graph[i][j] == 0)
		printf("%7s", "-");
	    else
		printf("%7d", graph[i][j]);
	}
	printf("\n");
    }

}

void findShortestRoute(int s, int d) {
    dijkstra(SIZE, s);

    if (distArr[d] == INF) {
	printf("\nNo path exists between %s and %s.\n", airports[s], airports[d]);
        return;
    }

    printf("\nShortest path from %s to %s (Distance: %d km):\n",
           airports[s], airports[d], distArr[d]);

    printf("%s", airports[s]);
    printPath(d);
    printf("\n");
}

int main() {
    int choice, s, d;
    // clrscr();
    while (1) {
	printf("\n==============================\n");
	printf("  FLIGHT NETWORK SIMULATION\n");
	printf("==============================\n");
	printf("1. Show all airports\n");
	printf("2. Show flight network (Adjacency Matrix)\n");
	printf("3. Find shortest route between airports\n");
	printf("4. Exit\n");
	printf("5. Clear Screen\n");
	printf("------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		showAirports();
		pressAnyKey();
		break;

	    case 2:
		showAdjMatrix();
		break;

	    case 3:
		showAirports();
		printf("\nEnter Source Airport Number: ");
		scanf("%d", &s);
		printf("Enter Destination Airport Number: ");
		scanf("%d", &d);
		s--; d--;
		if (s < 0 || s >= SIZE || d < 0 || d >= SIZE) {
		    printf("Invalid airport number!\n");
		} else {
		    findShortestRoute(s, d);
		}
		pressAnyKey();
		break;

	    case 4:
		printf("Exiting program.\n");
		return 0;
	    case 5:
		// clrscr();
		break;
	    default:
		printf("Invalid choice! Try again.\n");
		pressAnyKey();
		break;
	}
    }
    // getch();
    return 0;
}
