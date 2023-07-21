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

    int V;
    in>>V;

    //cout<<V<<E;
    string name[V+1];
    int win[V+1];
    int lost[V+1];
    int left[V+1];
    int matrix[V+1][V+1];

    for(int i=1; i<=V; i++){
        in>>name[i]>>win[i]>>lost[i]>>left[i];
        for(int j=1; j<=V; j++){
            in>>matrix[i][j];
        }
    }

    int V2= V*(V-1)/2 +2;

    int p=V-1;
    int pC2=p*(p-1)/2;

    for(int k=1; k<V+1; k++){
        Graph graph(V2);
        int count=0;
        int  sum=0;
    
        for(int i=1; i< V+1; i++){
            for(int j=i+1; j<V+1; j++){
                if(i==k || j==k)
                    continue;
                //cout<<"matdress"<<i<<" "<<j<<" "<<matrix[i][j]<<"\n";
                graph.setEdge(0, V+1+count, matrix[i][j]);
                //cout<<"matdress"<<i<<" "<<j<<" "<<matrix[i][j]<<"\n";
                sum+=matrix[i][j];
                graph.setEdge(V+1+count, i , INT_MAX);
                graph.setEdge(V+1+count, j , INT_MAX);
                count++;
            }
            graph.setEdge(i, k, win[k]+left[k]-win[i]);
        }

        int maxFlow= graph.maxFlow(0,k);
        cout<<maxFlow<<" "<<sum<<"\n";
    
    }


    //cout<<"\n"<<graph.maxFlow(s,d)<<"\n";
    // out<<graph.dijkstra(s,d);
    

    in.close();
    out.close();

    return 0;
}