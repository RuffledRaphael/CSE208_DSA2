#include<bits/stdc++.h>
#include"MST.cpp"
using namespace std;

string INPUT_FILE="input.txt";
string OUTPUT_FILE1="prim.txt";
string OUTPUT_FILE2="kruskal.txt";

int main(){

    ifstream in;
    in.open(INPUT_FILE);
    ofstream out1,out2;
    out1.open(OUTPUT_FILE1);
    out2.open(OUTPUT_FILE2);

    int V,E;
    in>>V;
    in>>E;

    //cout<<V<<" "<<E;
    Graph graph(V,E);
   
    for(int i=0; i<E; i++){
        //cout<<"step3";
        int F,S,W;
        in>>F;
        in>>S;
        in>>W;
        //cout<<K<<" "<<P;
        graph.setEdge(F,S,W);        
        //cout<<"step";
    }
    //cout<<"on";
    out1<<graph.prim(0);
    out2<<graph.kruskal();

    in.close();
    out1.close();
    return 0;
}