#include<bits/stdc++.h>
using namespace std;


class Graph{
private:
    vector<int> *adj;
    map < pair<int,int>, int> weight;
    priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> >edgeQ;
    int *key;
    int *parent;
    int totalVertex;
    int totalEdge;
    int *visited;

    int find(int x);
    void unionSet(int x, int y);
    bool isDisjoint(int x, int y);
public:
    Graph(int v, int e){
        totalVertex= v;
        totalEdge = e;
        visited= new int [totalVertex];
        key= new int [totalVertex];
        parent = new int [totalVertex];
        adj = new vector<int> [totalVertex];
        init();
    }

    ~Graph(){
        delete[] visited;
        delete[] key;
        delete[] parent;
        delete[] adj;
    }

    void setEdge(int v1, int v2, int w);
    //int getV(){return totalVertex;};
    void init();


    string prim(int root);
    string kruskal();

};

int Graph::find(int x)
{
    if( parent[x]!=-1)
        return find(parent[x]);
    else 
        return x;
}

void Graph::unionSet(int x, int y)
{   
    if(isDisjoint(x,y))
        parent[find(y)]= find(x);
        return;

    return;
}

bool Graph::isDisjoint(int x, int y)
{   
    if(find(x)==find(y))
        return false;
    else 
        return true;
}

void Graph::setEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
    weight[{v1,v2}]=w;
    weight[{v2,v1}]=w;

    edgeQ.push({w,{v1,v2}});
}

void Graph::init()
{
    for (int i=0; i<totalVertex; i++){
        key[i]=2147483645;
        parent[i]=-1;
        visited[i]=0;
    }
}

string Graph::prim(int root)
{
    string printable="Prim's algorithm:\n";
    int cost=0;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > vertexQ;
    init();
    int u,d; 
    key[root]=0;

    vertexQ.push({key[root], root});

    while(!vertexQ.empty()){
        u= vertexQ.top().second;
        d= vertexQ.top().first;
        vertexQ.pop();
        if (visited[u]==1)
            continue;
        cost+= d;
        visited[u]=1;

        for( auto v: adj[u] ){
            if (visited[v]==1)
                continue;

            if( weight[{u,v}] < key[v] ){
                key[v]= weight[{u,v}];
                vertexQ.push({key[v], v});
                parent[v]=u;
            }
        }
    }

    printable+="Total weight = "+to_string(cost)+"\n";
    printable+="Root node "+to_string(root)+"\n";
    for(int i=0; i<totalVertex; i++){
        if(i==root)
            continue;
        else
            printable+= to_string(parent[i])+ " "+ to_string(i)+"\n";
    }
    cout<<"\n"<<printable;

    return printable;
}

string Graph::kruskal()
{   
    string printable="";
    int cost=0;
    
    init();
    int x,y,t;
    while(!edgeQ.empty()){
        x= edgeQ.top().second.first;
        y= edgeQ.top().second.second;
        t= edgeQ.top().first;
        edgeQ.pop();
        if(!isDisjoint(x,y))
            continue;
        cost+= t;
        printable+= to_string(x)+" "+to_string(y)+"\n";
        unionSet(x,y);
    }

    printable= "Kruskal's algorithm:\nTotal weight = "+ to_string(cost)+"\n"+ printable+"\n";
    cout<<"\n"<<printable;
    
    return printable;
}
