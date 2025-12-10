#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define NODE 7
#define INF 37267

/* Colors */
#define COL_WHITE 15
#define COL_BLUE 1
#define COL_GREEN 2
#define COL_YELLOW 14
#define COL_RED 4
#define COL_BLACK 0

/* Airports */
char airports[NODE][8] = {"DEL","BOM","BLR","HYD","MAA","CCU","AMD"};

/* Edge list with comments */
long edges[16][3] = {
    {0,1,1400},  // DEL–BOM
    {0,2,2150},  // DEL–BLR
    {0,4,2150},  // DEL–MAA
    {0,6,940},   // DEL–AMD

    {1,2,840},   // BOM–BLR
    {1,3,1150},  // BOM–HYD
    {1,4,1040},  // BOM–MAA

    {2,3,570},   // BLR–HYD
    {2,5,1750},  // BLR–CCU
    {2,6,1730},  // BLR–AMD

    {3,4,630},   // HYD–MAA
    {3,5,1450},  // HYD–CCU
    {3,6,1550},  // HYD–AMD

    {4,5,1650},  // MAA–CCU
    {5,6,1800}   // CCU–AMD
};
int edgeCount = 16;

int GX[NODE], GY[NODE];
int SCR_W=639, SCR_H=479;

/* ---- Helper ---- */
void topText(const char *s){
    setfillstyle(SOLID_FILL, COL_BLACK);
    bar(0,0,SCR_W,40);
    setcolor(COL_WHITE);
    outtextxy(10,10,s);
}

void drawNodefill(int i, int color){
    setcolor(COL_WHITE);
    setfillstyle(SOLID_FILL, color);
    fillellipse(GX[i], GY[i], 20, 20);
    outtextxy(GX[i]-10, GY[i]-7, airports[i]);
}

void drawEdgeIndex(int idx, int color){
    int u = edges[idx][0];
    int v = edges[idx][1];
    long w = edges[idx][2];
    int mx = (GX[u]+GX[v])/2;
    int my = (GY[u]+GY[v])/2;
    char buf[16];

    setcolor(color);
    line(GX[u], GY[u], GX[v], GY[v]);
    sprintf(buf, "%ld", w);
    outtextxy(mx+4, my-6, buf);
}

/* ---- Fixed legend (removed +200 that pushed it off screen) ---- */
void drawLegendBox(){
    int boxW = 390;
    int boxH = 130;
    int lineH = 27;

    int x = SCR_W - boxW - 20;  // FIXED: now it fits on screen
    int y = SCR_H - boxH - 8;

    setfillstyle(SOLID_FILL, COL_BLACK);
    bar(x-2, y-2, x+boxW+2, y+boxH+2);
    setcolor(COL_WHITE);
    rectangle(x-2, y-2, x+boxW+2, y+boxH+2);

    outtextxy(x+9, y+5, "LEGEND");

    setfillstyle(SOLID_FILL, COL_YELLOW); bar(x+10, y+40, x+34, y+64);
    outtextxy(x+45, y+40, "Source Node");

    setfillstyle(SOLID_FILL, COL_GREEN); bar(x+10, y+40+lineH, x+34, y+64+lineH);
    outtextxy(x+45, y+40+lineH, "Relaxed / Path Node");

    setfillstyle(SOLID_FILL, COL_RED); bar(x+10, y+40+2*lineH, x+34, y+64+2*lineH);
    outtextxy(x+45, y+40+2*lineH, "Destination Node");

    setfillstyle(SOLID_FILL, COL_BLUE); bar(x+10, y+40+3*lineH, x+34, y+64+3*lineH);
    outtextxy(x+45, y+40+3*lineH, "Normal Node");

    outtextxy(x+210, y+20, "Edges:");
    setcolor(COL_WHITE); line(x+210, y+60, x+220, y+60); outtextxy(x+225, y+52, "Unvisited");
    setcolor(COL_RED);   line(x+210, y+90, x+220, y+90); outtextxy(x+225, y+82, "Considering");
    setcolor(COL_GREEN); line(x+210, y+120, x+220, y+120); outtextxy(x+225, y+112, "Shortest Path");
}

void drawGraph(int highlightEdge, int pathMask[], int nodeSpecial, int src, int dest){
    int i;
    cleardevice();
    topText("Airports Graph (Dijkstra Visualization)");

    for(i=0;i<edgeCount;i++){
        if(pathMask != NULL && pathMask[i]) drawEdgeIndex(i, COL_GREEN);
        else if(i == highlightEdge) drawEdgeIndex(i, COL_RED);
        else drawEdgeIndex(i, COL_WHITE);
    }

    for(i=0;i<NODE;i++){
        if(i == src) drawNodefill(i, COL_YELLOW);
        else if(i == dest) drawNodefill(i, COL_RED);
        else if(i == nodeSpecial) drawNodefill(i, COL_GREEN);
        else drawNodefill(i, COL_BLUE);
    }

    drawLegendBox();
}

void setupNodes(){
    GX[0]=120; GY[0]=100;
    GX[1]=320; GY[1]=80;
    GX[2]=220; GY[2]=200;
    GX[3]=420; GY[3]=200;
    GX[4]=520; GY[4]=120;
    GX[5]=560; GY[5]=320;
    GX[6]=160; GY[6]=320;
}

void showAirportsScreen(){
    int i;
    cleardevice();
    topText("Airport List");
    for(i=0;i<NODE;i++){
        char buf[40];
        sprintf(buf,"%d -> %s", i, airports[i]);
        outtextxy(80, 80 + i*30, buf);
    }
    outtextxy(80, 80 + NODE*30 + 10, "Press any key...");
    getch();
}

/* adjacency matrix */
void buildAdj(long adj[NODE][NODE]){
    int i,j;
    for(i=0;i<NODE;i++)
        for(j=0;j<NODE;j++)
            adj[i][j]=0;

    for(i=0;i<edgeCount;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        long w = edges[i][2];

        adj[u][v] = w;
        adj[v][u] = w;
    }
}

/* ----------- DIJKSTRA VISUALIZATION ------------- */
void dijkstra_vis(int src, int dest){
    int i,j,u;
    long adj[NODE][NODE];
    long dist[NODE];
    int visited[NODE];
    int parent[NODE];
    int pathMask[16];
    char buf[100];
    int k;

    int route[NODE], rc=0, cur=dest;
    char routeStr[256]; routeStr[0]='\0';

    buildAdj(adj);

    for(i=0;i<NODE;i++){
	dist[i]=INF;
	visited[i]=0;
	parent[i]=-1;
    }
    for(i=0;i<edgeCount;i++) pathMask[i]=0;

    dist[src]=0;

    for(i=0;i<NODE;i++){
	long best = INF;
	u=-1;

	for(j=0;j<NODE;j++)
	    if(!visited[j] && dist[j] < best){
		best = dist[j];
		u=j;
	    }

	if(u==-1) break;

	visited[u]=1;

	drawGraph(-1, pathMask, u, src, dest);
	if(dist[u] >= INF) sprintf(buf,"Visiting %s, dist=INF", airports[u]);
	else sprintf(buf,"Visiting %s, dist=%ld", airports[u], dist[u]);
	outtextxy(10,SCR_H-110,buf);
	delay(250);

	/* print full status list */
	for(k=0;k<NODE;k++){
            char s2[120];
            if(dist[k] >= INF)
                sprintf(s2,"%s : dist = INF  parent = %s",
                        airports[k],
                        parent[k]==-1?"NONE":airports[parent[k]]);
            else
                sprintf(s2,"%s : dist = %ld  parent = %s",
                        airports[k], dist[k],
                        parent[k]==-1?"NONE":airports[parent[k]]);
            outtextxy(10, SCR_H-150 - k*15, s2);
        }

        for(j=0;j<edgeCount;j++){
            int a = edges[j][0];
            int b = edges[j][1];
            long w = edges[j][2];
            int neighbor=-1;

            if(a==u && !visited[b]) neighbor=b;
            else if(b==u && !visited[a]) neighbor=a;
            if(neighbor==-1) continue;

            drawGraph(j, pathMask, neighbor, src, dest);
            if(dist[neighbor] >= INF)
                sprintf(buf,"Considering %s-%s, w=%ld, cur dist=INF",
                        airports[u], airports[neighbor], w);
            else
                sprintf(buf,"Considering %s-%s, w=%ld, cur dist=%ld",
                        airports[u], airports[neighbor], w, dist[neighbor]);
            outtextxy(10,SCR_H-110,buf);
            delay(300);

            if(dist[u] + w < dist[neighbor] && dist[u] < INF){
                dist[neighbor] = dist[u] + w;
                parent[neighbor] = u;

                drawGraph(j, pathMask, neighbor, src, dest);
                sprintf(buf,"Updated %s -> dist=%ld",
                        airports[neighbor], dist[neighbor]);
                outtextxy(10,SCR_H-110,buf);
                delay(300);
            }
        }
    }

    /* reconstruct shortest path */
    while(cur!=-1){
        route[rc++]=cur;
        cur=parent[cur];
    }

    for(i=rc-1;i>0;i--){
        int n1=route[i];
        int n2=route[i-1];
        for(j=0;j<edgeCount;j++){
            if( (edges[j][0]==n1 && edges[j][1]==n2) ||
                (edges[j][1]==n1 && edges[j][0]==n2) ){
                pathMask[j]=1;
            }
        }
    }

    drawGraph(-1, pathMask, -1, src, dest);

    strcat(routeStr, airports[route[rc-1]]);
    for(i=rc-2;i>=0;i--){
        strcat(routeStr, " -> ");
        strcat(routeStr, airports[route[i]]);
    }

    sprintf(buf,"Shortest path: %s", routeStr);
    outtextxy(10,SCR_H-110,buf);

    if(dist[dest] >= INF)
        sprintf(buf,"Total distance: INF");
    else
        sprintf(buf,"Total distance: %ld km", dist[dest]);

    outtextxy(10,SCR_H-90,buf);
    outtextxy(10,SCR_H-70,"Press any key...");
    getch();
}

/* -------- MAIN -------- */
int main(){
    int gd=DETECT, gm, ch, src, dest;
    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

    SCR_W=getmaxx(); 
    SCR_H=getmaxy();
    setupNodes();

    while(1){
        clrscr();
        cleardevice();
        topText("Dijkstra Visualization - Menu");
        setcolor(COL_WHITE);

        outtextxy(100,100,"1. Show Airports");
        outtextxy(100,140,"2. Show Graph");
        outtextxy(100,180,"3. Dijkstra Shortest Path");
        outtextxy(100,220,"4. Exit");

        ch=getch();

        if(ch=='1'){
            showAirportsScreen();
        }
        else if(ch=='2'){
            int mask[16];
            for(src=0;src<edgeCount;src++) mask[src]=0;
            drawGraph(-1, mask, -1, -1, -1);
            outtextxy(10,SCR_H-110,"Press any key...");
            getch();
        }
        else if(ch=='3'){
            showAirportsScreen();
            while(1){
                printf("\nEnter Source index (0-%d): ",NODE-1);
                if(scanf("%d",&src)==1 && src>=0 && src<NODE) break;
                printf("Invalid!\n");
            }
            while(1){
                printf("Enter Destination index (0-%d): ",NODE-1);
                if(scanf("%d",&dest)==1 && dest>=0 && dest<NODE) break;
                printf("Invalid!\n");
            }
            dijkstra_vis(src,dest);
        }
        else if(ch=='4'){
            break;
        }
    }

    closegraph();
    return 0;
}