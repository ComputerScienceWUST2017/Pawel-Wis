#include<iostream>
#include<string>
#include <sstream>

#include <queue>

using namespace std;

#define INFINITY 10000000

enum Color{
    white, grey, black
};

struct Graph{
    int numVertices;
    double** matrix;
};

void fillLineWithInf(Graph &g,int row,int length){
    for(int i=0;i<length;++i){
        g.matrix[row][i]=INFINITY;
    }
}

void fillDiagonalWithZeros(Graph &g, int n){
    for(int i=0;i<n;++i){
        g.matrix[i][i]=0;
    }
}

void loadGraph(Graph &g, int n, int m){
    g.numVertices=n;
    g.matrix = new double*[n];
    for(int i=0;i<n;++i){
        g.matrix[i] = new double[n];
        fillLineWithInf(g,i,n);
    }

    fillDiagonalWithZeros(g,n);

    int starting,ending;
    double weight;
    for(int i=0;i<m;++i){
        cin>> starting;
        cin>> ending;
        cin>> weight;
        g.matrix[starting][ending]=weight;
    }
}

void insertEdge(Graph &g, int u, int v, double weight){
    g.matrix[u][v]=weight;
}

bool findEdge(Graph &g, int u, int v, double &weight){
    if(g.matrix[u][v]==0 || g.matrix[u][v] ==INFINITY){
        return false;
    }
    weight = g.matrix[u][v];
    return true;
}

void showAsMatrix(Graph &g){
    for(int i=0;i<g.numVertices;++i){
        for(int j=0;j<g.numVertices;++j){
            if(g.matrix[i][j]<INFINITY){
                cout<<g.matrix[i][j];
            }
            else{
                cout<<"-";
            }
            cout << (j+1 == g.numVertices ? ",\n": ",");
        }
    }
}

void showAsArrayOfLists(Graph &g) {

    for(int i=0;i<g.numVertices;++i){
        cout<<i<<':';
        for(int j=0;j<g.numVertices;++j){
            if(g.matrix[i][j]<INFINITY && g.matrix[i][j]!=0){
                cout<<j<<'('<<g.matrix[i][j]<<"),";
            }
            if(j+1 == g.numVertices) cout<<endl;
        }
    }
}

void printPath(Graph &g,int s, int v,int *&parent){
    if(s==v){
        cout<<s<<',';
    }
    else if(parent[v]==-1){
        cout<<" no path from "<<s<<" to "<<v<<',';
    }
    else{
        printPath(g,s,parent[v],parent);
        cout<<v<<',';
    }
}

void BFS(Graph &g, int s){
    Color *colorArr = new Color[g.numVertices];
    int *distance = new int[g.numVertices];
    int *parent = new int[g.numVertices];
    int v;
    for(int i=0;i<g.numVertices;++i){
        colorArr[i] = white;
        distance[i] = INFINITY;
        parent[i] = -1;
    }
    colorArr[s] = grey;
    distance[s] = 0;
    cout<<s<<','<<flush;
    queue<int> Queue;
    Queue.push(s);
    while(!Queue.empty()){
        int u = Queue.front();
        Queue.pop();
        v=0;
        for(;v<g.numVertices && (g.matrix[u][v]==0 || g.matrix[u][v]>=INFINITY);++v);
        while(v<g.numVertices){
            if(colorArr[v]==white){
                cout<<v<<','<<flush;
                colorArr[v]=grey;
                distance[v]=distance[u]+1;
                parent[v]=u;
                Queue.push(v);
            }
            ++v;
            for(;v<g.numVertices && (g.matrix[u][v]==0 || g.matrix[u][v]>=INFINITY);++v);
        }
        colorArr[u]=black;
    }
    cout<<endl;
}

void DFSVisit(Graph &g,int u,int*&t,int*&f,int&time,Color*&colorArr,int*&parent){
    colorArr[u] = grey;
    t[u]=++time;
    int v;
    for(v = 0;v<g.numVertices && (g.matrix[u][v]==0 || g.matrix[u][v]>=INFINITY);++v);
    while(v<g.numVertices){
        if(colorArr[v]==white){
            cout<<v<<','<<flush;
            parent[v] = u;
            DFSVisit(g,v,t,f,time,colorArr,parent);
        }
        colorArr[u] = black;
        f[u]=++time;
        ++v;
        for(;v<g.numVertices && (g.matrix[u][v]==0 || g.matrix[u][v]>=INFINITY);++v);
    }
}

void DFS(Graph &g, int s){
    Color *colorArr = new Color[g.numVertices];
    int *distance = new int[g.numVertices];
    int *parent = new int[g.numVertices];
    int *t = new int[g.numVertices];
    int *f = new int[g.numVertices];
    for(int i=0;i<g.numVertices;++i){
        colorArr[i] = white;
        parent[i] = -1;
    }

    int time = 0;
    cout<<s<<','<<flush;

    DFSVisit(g,s,t,f,time,colorArr,parent);
    for(int u=0; u<g.numVertices;++u){
        if (colorArr[u] == white){
            DFSVisit(g,u,t,f,time,colorArr,parent);
        }
    }
    cout<<endl;
}


int minInArr(double* &dist,int range,bool*&visited){
    double min = INFINITY;
    int indexMin = 0;
    for(int i=1;i<range;++i){
        if(min>dist[i] && !visited[i]){
            min = dist[i];
            indexMin = i;
        }
    }
    return indexMin;
}

struct ordList{
    int value;
    ordList* next;
};

void ordListInsert(ordList *&set, int value){

    if(set == NULL){
        set = new ordList;
        set->next=NULL;
        set->value=value;
        return;
    }

    if(value<set->value){
        ordList *newEL = new ordList;
        newEL->value = value;
        newEL->next = set;
        set = newEL;
        return;
    }

    ordList *prev = set;
    ordList *temp = set;
    while(temp !=NULL && value>temp->value){
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL && value == temp->value){
        return;
    }

    ordList * newEl = new ordList;
    newEl->value=value;
    newEl->next=temp;
    prev->next=newEl;
}

void ordListRemove(ordList *&set, int value){
    if(set == NULL) return;

    ordList* temp = set;
    if(value == set->value){
        set = set->next;
        delete temp;
        return;
    }

    ordList* prev = set;
    while(temp!=NULL && value!=temp->value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next=temp->next;
    delete temp;
}

double *SSSP(Graph &g, int s){
    ordList* V = NULL;
    double *distance = new double[g.numVertices];

    for(int i=0;i<g.numVertices;++i){
            distance[i] = g.matrix[s][i]<INFINITY ? g.matrix[s][i] : INFINITY;
        ordListInsert(V, i);
    }
    ordListRemove(V, s);

    while(V != NULL) {
        double min = INFINITY;
        int u;
        for (ordList *v = V; v != NULL; v = v->next) {
            if (min > distance[v->value]) {
                min = distance[v->value];
                u = v->value;
            }
        }

        ordListRemove(V, u);

        for (ordList* v = V; v != NULL; v = v->next) {
            if (g.matrix[u][v->value] != 0 && g.matrix[u][v->value]<INFINITY && (distance[v->value] > distance[u] + g.matrix[u][v->value])) {
                distance[v->value] = distance[u] + g.matrix[u][v->value];
            }
        }
    }
    return distance;
}

void printSSSP(Graph &g, double *&dist){
    for(int i = 0;i<g.numVertices;++i){
        cout<<i<<'('<<dist[i]<<")"<<endl;
    }
}

    bool isCommand(const string command,const char *mnemonic){
    return command==mnemonic;
}


int main(){
    string line;
    string command;
    Graph *graph;
    int currentT=0;
    int value;
    cout << "START" << endl;
    while(true){
        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;
        if(line=="" || command[0]=='#')
        {
            // ignore empty line and comment
            continue;
        }

        // copy line on output with exclamation mark
        cout << "!" << line << endl;;

        // change to uppercase
        command[0]=toupper(command[0]);
        command[1]=toupper(command[1]);

        // zero-argument command
        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
        }
        // zero-argument command
        if(isCommand(command,"SM")) //
        {
            showAsMatrix(graph[currentT]);
            continue;
        }


        if(isCommand(command,"SA")) //
        {
            showAsArrayOfLists(graph[currentT]);
            continue;
        }

        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"LG")) //
        {
            int m;
            stream >> m;
            loadGraph(graph[currentT], value, m);
            continue;
        }

        if(isCommand(command,"SS")) //
        {
            double* dist = SSSP(graph[currentT], value);
            printSSSP(graph[currentT], dist);
            continue;
        }

        if(isCommand(command,"BF"))
        {
            BFS(graph[currentT], value);
            continue;
        }

        if(isCommand(command,"DF"))
        {
            DFS(graph[currentT], value);
            continue;
        }

        if(isCommand(command,"IE")) //
        {
            int v;
            double w;
            stream >> v >> w;
            insertEdge(graph[currentT],value,v,w);
            continue;
        }

        if(isCommand(command,"FE")) //
        {
            int v;
            stream >> v;
            double w;
            bool ret=findEdge(graph[currentT],value,v,w);

            if(ret)
                cout << w << endl;
            else
                cout << "false" << endl;
            continue;
        }

        if(isCommand(command,"CH"))
        {
            currentT=value;
            continue;
        }

        if(isCommand(command,"GO")) //
        {
            graph=new Graph[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
        return 1;
    }
}
