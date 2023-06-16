#include<bits/stdc++.h>
#include"SSSP.cpp"
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
    
    Graph graph(V,E);
   
    for(int i=0; i<E; i++){
        int F,S,W;
        in>>F;
        in>>S;
        in>>W;
        graph.setEdge(F,S,W);        
    }

    int s,d;
    in>>s>>d;
    //cout<<s<<d;
    out<<graph.bellmanFord(s,d);
    out<<graph.dijkstra(s,d);

    in.close();
    out.close();

    return 0;
}