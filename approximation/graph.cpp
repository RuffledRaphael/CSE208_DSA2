#include<bits/stdc++.h>
using namespace std;


class Graph{

public:
    vector<int> *adj;
    map < pair<int,int>, double> weight;
    double *key;
    int *parent;
    int totalVertex;
    int totalEdge;
    int *visited;
    bool* dfsVISIT;


    Graph(int v){
        totalVertex= v;
        visited= new int [totalVertex];
        key= new double [totalVertex];
        parent = new int [totalVertex];
        adj = new vector<int> [totalVertex];
        dfsVISIT = new bool[totalVertex]; 
        init();
    }

    ~Graph(){
        delete[] visited;
        delete[] key;
        delete[] parent;
        delete[] adj;
    }

    void setEdge(int v1, int v2, double w);
    void init();

    void prim(int root);
    int exactDP();
    int approxPrim();
    void dfs(int current);
    
    vector<int> tour;
};

void Graph::init()
{
    for (int i=0; i<totalVertex; i++){
        key[i]=1.7e300;
        parent[i]=-1;
        visited[i]=0;
        dfsVISIT[i]=false;
    }
}

void Graph::setEdge(int v1, int v2, double w)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
    weight[{v1,v2}]=w;
    weight[{v2,v1}]=w;
}

void Graph::prim(int root)
{
    double cost=0;
    priority_queue< pair<double,int> , vector<pair<double,int>> , greater<pair<double,int>> > vertexQ;
    init();
    int u;
    double d; 
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

    // printable+="Total weight = "+to_string(cost)+"\n";
    // printable+="Root node "+to_string(root)+"\n";
    // for(int i=0; i<totalVertex; i++){
    //     if(i==root)
    //         continue;
    //     else
    //         printable+= to_string(parent[i])+ " "+ to_string(i)+"\n";
    // }
    //cout<<"\n"<<printable;

    return;
}

int Graph::exactDP()
{
    int sizeT=1<<totalVertex;

    int** table;
    table = new int*[sizeT];
    for(int i=0; i< sizeT; i++){
        table[i]= new int[totalVertex];
        for(int j=0; j<totalVertex;j++)
            table[i][j]= INT_MAX;
    }

    table[1][0]= 0;

    for (int maskSet = 1; maskSet < sizeT; maskSet++ ){
        for (int last = 0; last < totalVertex; last++){
            if(((maskSet>>last)&1)==0)
                continue;
            
            int prev = maskSet - (1<<last);

            for(int v = 0; v<totalVertex ;v++){
                if(((prev>>v)&1)==0)
                    continue;
                
                table[maskSet][last]= __min( (table[prev][v] + weight[{v,last}]) , table[maskSet][last]);
            }
        }
    }


    int minimum = INT_MAX;

    for(int i=1; i <totalVertex ;i++){
        minimum = __min(minimum , (table[sizeT-1][i]+ weight[{i,0}]) );
    }

    return minimum;
}

void Graph::dfs(int current)
{
    dfsVISIT[current] = true;
    tour.push_back(current);
    for (int neighbor : adj[current]) {
        if (!dfsVISIT[neighbor]) {
            dfs(neighbor);
        }
    }
}


int Graph::approxPrim()
{
    prim(0);

    Graph MST(totalVertex);

    for(int i=1; i<totalVertex ;i++){
        MST.setEdge(i , parent[i], weight[{i,parent[i]}]);
    }

    MST.dfs(0);

    int cost = 0;
    for (int i = 0; i < totalVertex - 1; i++) {
        cost+= weight[{MST.tour[i],MST.tour[i+1]}];
    }

    cost += weight[{MST.tour[totalVertex - 1], MST.tour[0]}];

    return cost;
}
