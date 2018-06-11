#include<iostream>
#include<string>
#include <sstream>
#include <queue>
using namespace std;
#define INFINITY 10000000

struct Vertex{
    int vertexNum;
    double edgeWeight;
    Vertex* next;
};

enum Color{
    white, grey, black
};

struct Graph{
    int numberVer;
    Vertex** list;
};

void pushToList(Vertex** &list,int start, int end, double weight){
    Vertex* newV = new Vertex;
    if(list[start]==NULL){
        newV->next=NULL;
        newV->edgeWeight=weight;
        newV->vertexNum=end;
        list[start]=newV;
        return;
    }

    if(end<list[start]->vertexNum){
        newV->next=list[start];
        newV->edgeWeight=weight;
        newV->vertexNum=end;
        list[start]=newV;
        return;
    }

    Vertex* temp = list[start];
    Vertex* prev = NULL;

    while(temp!=NULL && temp->vertexNum<end){
        prev = temp;
        temp=temp->next;
    }

    if(temp!=NULL && temp->vertexNum==end){
        temp->edgeWeight=weight;
        return;
    }

    if(prev!=NULL) prev->next=newV;
    newV->vertexNum = end;
    newV->next=temp;
    newV->edgeWeight=weight;
}

void loadGraph(Graph &g, int n, int m){
    g.numberVer=n;
    g.list= new Vertex*[n];
    for(int i=0;i<n;++i) {
        g.list[i] = NULL;
    }

    int starting,ending;
    double weight;
    for(int i=0;i<m;++i){
        cin>> starting;
        cin>> ending;
        cin>> weight;
        pushToList(g.list,starting,ending,weight);
    }
}

void showAsArrayOfLists(Graph &g){
    for(int i=0;i<g.numberVer;++i){
        cout<<i<<':';
        if(g.list[i] != NULL){
            Vertex* temp = g.list[i];
            while(temp != NULL){
                cout<<temp->vertexNum<<'('<<temp->edgeWeight<<"),";
                temp=temp->next;
            }
        }
        cout<<endl;
    }
}

void insertEdge(Graph &g, int u, int v, double weight){
    pushToList(g.list,u,v,weight);
}

bool findEdge(Graph &g, int u, int v, double &weight){
    Vertex* temp = g.list[u];
    while(temp!=NULL){
        if (u==v){
            weight = 0;
            return true;
        }
        if(temp->vertexNum == v){
            weight = temp->edgeWeight;
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void showAsMatrix(Graph &g){
    double weight;
    for(int i=0;i<g.numberVer;++i){
        for(int j=0;j<g.numberVer;++j){
            if(i==j){
                cout<<"0";
            }
            else if(findEdge(g, i, j, weight)){
                cout<<weight;
            }
            else{
                cout<<"-";
            }
            cout << (j+1 == g.numberVer ? ",\n": ",");
        }
    }
}


void printPath(Graph &g,int s, int v,int*&parent){
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
    Color *colorArr = new Color[g.numberVer];
    int *distance = new int[g.numberVer];
    int *parent = new int[g.numberVer];
    int v;
    for(int i=0;i<g.numberVer;++i){
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
        Vertex *temp = g.list[u];
        while(temp!=NULL){
            v=temp->vertexNum;
            if(colorArr[v]==white){
                cout<<v<<','<<flush;
                colorArr[v]=grey;
                distance[v]=distance[u]+1;
                parent[v]=u;
                Queue.push(v);
            }
            temp = temp->next;
        }
        colorArr[u]=black;
    }
    cout<<endl;
}

void DFSVisit(Graph &g,int u,int*&t,int*&f,int&time,Color*&colorArr,int*&parent){
    colorArr[u] = grey;
    t[u]=++time;
    Vertex *temp = g.list[u];
    while(temp!=NULL){
        int v = temp->vertexNum;
        if(colorArr[v]==white){
            cout<<v<<','<<flush;
            parent[v] = u;
            DFSVisit(g,v,t,f,time,colorArr,parent);
        }
        colorArr[u] = black;
        f[u]=++time;
        temp = temp->next;
    }
}

void DFS(Graph &g, int s){
    Color *colorArr = new Color[g.numberVer];
    int *distance = new int[g.numberVer];
    int *parent = new int[g.numberVer];
    int *t = new int[g.numberVer];
    int *f = new int[g.numberVer];
    for(int i=0;i<g.numberVer;++i){
        colorArr[i] = white;
        parent[i] = -1;
    }

    int time = 0;
    cout<<s<<','<<flush;

    DFSVisit(g,s,t,f,time,colorArr,parent);
    for(int u=0; u<g.numberVer;++u){
        if (colorArr[u] == white){
            DFSVisit(g,u,t,f,time,colorArr,parent);
        }
    }
    cout<<endl;
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
        if(isCommand(command,"SM"))
        {
            showAsMatrix(graph[currentT]);
            continue;
        }

        if(isCommand(command,"SA"))
        {
            showAsArrayOfLists(graph[currentT]);
            continue;
        }
        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"LG"))
        {
            int m;
            stream >> m;
            loadGraph(graph[currentT], value, m);
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

        if(isCommand(command,"IE"))
        {
            int v;
            double w;
            stream >> v >> w;
            insertEdge(graph[currentT], value, v, w);
            continue;
        }

        if(isCommand(command,"FE"))
        {
            int v;
            stream >> v;
            double w;
            bool ret= findEdge(graph[currentT], value, v, w);

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

        if(isCommand(command,"GO"))
        {
            graph=new Graph[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
        return 1;
    }
}