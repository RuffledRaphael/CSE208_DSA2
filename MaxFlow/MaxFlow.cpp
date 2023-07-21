#include<bits/stdc++.h>
using namespace std;

class edge{
public:
    int v;
    int currFlow;
    int capacity;

    edge(int to,int flow, int cap){
        v=to;
        currFlow=flow;
        capacity=cap;
        ////cout<<v<<currFlow<<capacity;
    }
};

class Graph{
private:
    vector<edge> *flowGraph;
    vector<pair<int,int>> *residualRemaining;
    int totalVertex;
    int totalEdge;
    int N;
    int *visited;
    pair<int,int> *prev;

public:
    Graph(int v, int n,int e=0){
        totalVertex= v;
        totalEdge = e;
        N=n;
        flowGraph= new vector<edge> [totalVertex];
        residualRemaining= new vector<pair<int,int>> [totalVertex];
        visited= new int [totalVertex];
        prev= new pair<int,int> [totalVertex];
        //init();
    }

    ~Graph(){
        delete[] visited;
        delete[] prev;
        delete[] flowGraph;
        delete[] residualRemaining;
    }
    
    vector<int> minCut;

    void setEdge(int v1, int v2, int f);
    void init();
    void makeResidual();
    int BFS(int src,int dst);

    void getMinCut(int k,int src);
    int maxFlow(int src,int dst);

};


void Graph::setEdge(int v1, int v2, int f)
{   
    if(f==0)
        return;
    edge edge1(v2,0,f);
    flowGraph[v1].push_back(edge1);
    ////cout<<v1<<v2<<f;
}

void Graph::init()
{
    for(int i=0; i<totalVertex;i++){
        visited[i]=0;
        prev[i]={-1,-1};
    }
}

void Graph::makeResidual()
{   
    for(int i=0; i<totalVertex;i++){
        residualRemaining[i].clear();
    }

    int v2;
    int flow;
    int capacity;
    int leftCapacity;
    for(int i=0; i<totalVertex;i++){
        for(auto e : flowGraph[i]){
            v2= e.v;
            flow=e.currFlow;
            capacity=e.capacity;

            leftCapacity = capacity-flow;
            //cout<<" le"<<leftCapacity<<" ";
            
            if(leftCapacity>0)
                residualRemaining[i].push_back({v2, leftCapacity});

            if(flow>0)
                residualRemaining[v2].push_back({i, flow});
        }
    }
}

void Graph::getMinCut(int k,int src=0)
{
    makeResidual();

    int temp;
    int next;
    int flow;
    
    init();

    queue<int> q;
    q.push(src);

    while(q.size()>0){
        temp=q.front(); 
        visited[temp]=1;
        if(temp < N+1 && temp!= src){
            minCut.push_back(temp);
            //cout<<temp<<"pushed ";
        }
        q.pop();

        for(pair<int,int> e : residualRemaining[temp]){
            next=e.first;
            flow=e.second;

            if(visited[next]==0){
                prev[next]={temp,flow};
                q.push(next);
            }
        }
    }

}

int Graph::maxFlow(int src, int dst)
{
    int bottleneckSum=0;
    int bottleneck=0;

    while(true){
        makeResidual();
        bottleneck= BFS(src,dst);
        if(bottleneck==-1)
            break;
        //cout<<"bot"<<bottleneck<<" ";
        bottleneckSum+= bottleneck;
    }

    return bottleneckSum;
}

int Graph::BFS(int src, int dst)
{
    int temp;
    int next;
    int flow;
    
    init();

    queue<int> q;
    q.push(src);

    while(q.size()>0){
        temp=q.front(); 
        visited[temp]=1;
        q.pop();

        for(pair<int,int> e : residualRemaining[temp]){
            next=e.first;
            flow=e.second;

            if(visited[next]==0){
                prev[next]={temp,flow};
                if(next==dst){
                    visited[dst]=1;
                    break;
                }
                q.push(next);
            }
        }
    }
    
    if(visited[dst]==0){
        //cout<<"unreachable";
        return -1;
    }

    int min=INT_MAX;
    
    int parent=-1;
    int child=dst;
    int pathSize=1;

    // for(int i=0; i<totalVertex;i++){
    //     //cout<< prev[i].first<<prev[i].second<<" ";
    // }

    while(child!=src){
        parent= prev[child].first;
        flow= prev[child].second;
        //cout<<"f"<<flow;
        min= (min > flow) ? flow : min;
        child= parent;
        pathSize++;
    }

    if(pathSize==1)
        return -1;
    //cout<<"p"<<pathSize;

    if(min==INT_MAX){
        cout<<" min inf ";
        return 0;
    }

    child=dst;

    for(int i=0; i<pathSize-1; i++){
        ////cout<<child;
        parent=prev[child].first;
        flow=prev[child].second;
        int found =0;
        int pos=0;

        for(auto e: flowGraph[parent]){
            if(e.v==child){
                //cout<<"currF"<<e.currFlow;
                flowGraph[parent][pos].currFlow+=min;
                //cout<<flowGraph[parent][pos].currFlow;
                found=1;
            }
            pos++;
        }

        if(found==0){
            int pos1=0;
            for(auto e: flowGraph[child]){
                if(e.v==parent){
                    //cout<<"currF"<<e.currFlow;
                    flowGraph[child][pos1].currFlow-=min;
                    //cout<<flowGraph[parent][pos].currFlow;
                    found=1;
                }
                pos1++;
            }
        }
        child = parent;
    }
    
    // for(int i=0; i<totalVertex; i++)
    // for(auto e: flowGraph[i]){
    //     //cout<<"\n"<<i<<e.v<<e.currFlow;
    // }
    
    return min;
}

