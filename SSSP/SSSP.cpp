#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<pair<int,int>> *adj;
    vector< pair<pair<int,int>, int> > edgeList;
    // map < pair<int,int>, int> cost;
    int *distance;
    int *prev;
    int totalVertex;
    int totalEdge;
    int *visited;

    string pathPrint(int s,int d);

public:
    Graph(int v, int e){
        totalVertex= v;
        totalEdge = e;
        visited= new int [totalVertex];
        distance= new int [totalVertex];
        prev = new int [totalVertex];
        adj = new vector<pair<int,int>> [totalVertex];
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

    string dijkstra(int s, int d);
    string bellmanFord(int s,int d);
};

string Graph::pathPrint(int s, int d)
{
    stack<int> path;
    string printable="";

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

    return printable;
}

void Graph::setEdge(int v1, int v2, int w)
{
    adj[v1].push_back({v2,w});
    //cost[{v1,v2}]=w;
    edgeList.push_back({{v1,v2},w});
}

void Graph::init()
{
    for (int i=0; i<totalVertex; i++){
        distance[i]=INT_MAX;
        prev[i]=-1;
        visited[i]=0;
    }
}

string Graph::dijkstra(int s, int d)
{
    string printable="Dijkstra Algorithm:\n";
    init();
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > vertexQ;

    distance[s]=0;
    vertexQ.push({distance[s], s});

    int u=s;
    while(!vertexQ.empty()){
        u= vertexQ.top().second;
        vertexQ.pop();

        if(visited[u]==1)
            continue;
        
        visited[u]=1;

        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if( distance[u]!=INT_MAX && distance[v] > (distance[u]+ abs(w)) ) {
                distance[v]= distance[u]+ abs(w);
                prev[v]=u;
                vertexQ.push({distance[v], v});
            }
        }
    }

    if(distance[d]==INT_MAX){
        printable+="INF\n";
        //cout<<printable;
        return printable;
    }

    printable+=to_string(distance[d])+"\n";
    printable+= pathPrint(s,d);
    //cout<<printable;

    return printable;
}

string Graph::bellmanFord(int s, int d)
{
    string printable="Bellman Ford Algorithm:\n";
    init();
    distance[s]=0;
    int u,v,w;

    for(int i=0; i<totalVertex-1;i++){
        for(int j=0; j<totalEdge; j++){
            u= edgeList[j].first.first;
            v= edgeList[j].first.second;
            w= edgeList[j].second;
            if( distance[u]!=INT_MAX && distance[v] > distance[u] + w ){
                distance[v]= distance[u]+w;
                prev[v]=u;
            }
        }
    }

    for(int j=0; j<totalEdge; j++){
        u= edgeList[j].first.first;
        v= edgeList[j].first.second;
        w= edgeList[j].second;

        if( distance[u]!=INT_MAX && distance[v] > distance[u] + w ){
            printable+="Negative weight cycle present\n\n";
            //cout<<printable;
            return printable;
        }
    }

    if(distance[d]==INT_MAX){
        printable+="INF\n";
        //cout<<printable;
        return printable;
    }
    printable+= to_string(distance[d])+"\n";
    printable+= pathPrint(s,d)+"\n\n";

    //cout<<printable;

    return printable;
}
