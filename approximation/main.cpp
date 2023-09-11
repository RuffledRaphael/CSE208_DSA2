#include<bits/stdc++.h>
#include"graph.cpp"
using namespace std;

Graph* Create_Random_Graph(int V){

    Graph* randomGraph= new Graph(V);
    int random1 = 50 + rand()%50;

    for(int i=0; i<V; i++)
        for(int j=i+1; j<V; j++){
            int random2 = 0.75*random1 + rand()%random1;
            randomGraph->setEdge(i,j, random2);
        }

    return randomGraph;
}

int main(){
    srand(time(0));

    int T;
    cout<< "Enter Testcase no.: ";
    cin>>T;

    vector<double> exact;
    vector<double> approximate;

    for(int i=0; i<T;i++){
        Graph* graph = Create_Random_Graph(20);

        exact.push_back(graph->exactDP());
        // cout<<exact[i]<<" ";

        approximate.push_back(graph->approxPrim());
        // cout<<approximate[i]<<"\n";

        cout<<"Testcase "<<i+1<<" ratio: "<< approximate[i]/exact[i]<<"\n";
    }


    return 0;
}

 