#include<bits/stdc++.h>
#include"MaxFlow.cpp"
using namespace std;

string INPUT_FILE="input.txt";
string OUTPUT_FILE1="output.txt";
int main(){

    ifstream in;
    in.open(INPUT_FILE);
    ofstream out;
    out.open(OUTPUT_FILE1);

    int V,E;
    in>>V;
    in>>E;
    //cout<<V<<E;
    
    Graph graph(V,E);
   
    for(int i=0; i<E; i++){
        int F,S,W;
        in>>F;
        in>>S;
        in>>W;
        //cout<<F<<S<<W;
        graph.setEdge(F,S,W);
    }

    int s,d;
    in>>s>>d;
    //cout<<s<<d;

    cout<<"\n"<<graph.maxFlow(s,d)<<"\n";
    // out<<graph.dijkstra(s,d);
    

    in.close();
    out.close();

    return 0;
}