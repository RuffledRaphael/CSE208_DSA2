#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<int> *adj;
    map < pair<int,int>, int> cost;
    //priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> >edgeQ;
    int *distance;
    int *prev;
    int totalVertex;
    int totalEdge;
    int *visited;

public:
    Graph(int v, int e){
        totalVertex= v;
        totalEdge = e;
        visited= new int [totalVertex];
        distance= new int [totalVertex];
        prev = new int [totalVertex];
        adj = new vector<int> [totalVertex];
        init();
    }

    ~Graph(){
        delete[] visited;
        delete[] distance;
        delete[] prev;
        delete[] adj;
    }

    void setEdge(int v1, int v2, int w);
    void init();

    string djikstra(int s, int d);
    //string bellmanFord(int s,int d);
};


void Graph::setEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    cost[{v1,v2}]=w;

    //edgeQ.push({w,{v1,v2}});
}

void Graph::init()
{
    for (int i=0; i<totalVertex; i++){
        distance[i]=2147483645;
        prev[i]=-1;
        visited[i]=0;
    }
}

string Graph::djikstra(int s, int d)
{
    string printable="Dijkstra Algorithm:\n";
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > vertexQ;
    stack<int> path;

    distance[s]=0;
    vertexQ.push({distance[s], s});

    int u=s;
    while(u!=d){
        u= vertexQ.top().second;
        vertexQ.pop();

        if(visited[u]==1)
            continue;
        
        visited[u]=1;

        for(int x : adj[u]){
            if(visited[x]==0 && ( distance[x] > (distance[u]+ abs(cost[{u,x}])) ) ){
                distance[x]= distance[u]+ abs(cost[{u,x}]);
                prev[x]=u;
                vertexQ.push({distance[x], x});
            }
        }
    }

    printable+=to_string(distance[d])+"\n";

    path.push(d);
    int x=d;
    while(x!=s){
        path.push(prev[x]);
        x=prev[x];
    }
    int t=path.size();
    for(int i=0; i< t; i++){
        printable+=to_string(path.top());
        path.pop();
        if(path.size()!=0)
            printable+=" -> ";
    }

    cout<<printable;

    return printable;
}
