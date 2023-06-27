#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int** matrix;
    int totalVertex;
    int totalEdge;

public:
    Graph(int v, int e){
        totalVertex= v;
        totalEdge = e;

        matrix = new int*[totalVertex+1];
        for(int i=0; i<totalVertex+1; i++)
            matrix[i] = new int[totalVertex+1];
        
        for(int i=1; i<totalVertex+1; i++)
            for(int j=1; j<totalVertex+1; j++){
                matrix[i][j]= (i==j)? 0 : INT_MAX;
            }
    }

    ~Graph(){
        for(int i=0; i<totalVertex+1; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void setEdge(int v1, int v2, int w);
    void init();

    string floydWarshal();

};

void Graph::setEdge(int v1, int v2, int w){
    matrix[v1][v2]=w;
}

void Graph::init(){
    for (int i=0; i<totalVertex; i++){
    
    }
}

string Graph::floydWarshal(){   
    string printable="Floyd-Warshal Algorithm:\n";

    for(int k=1; k<totalVertex+1; k++)
        for(int i=1; i<totalVertex+1; i++)
            for(int j=1; j<totalVertex+1;j++){
                if( (matrix[i][j] > matrix[i][k] + matrix[k][j]) && matrix[i][k]!= INT_MAX && matrix[k][j]!=INT_MAX)
                    matrix[i][j]= matrix[i][k] + matrix[k][j];
            }

    for(int i=1;i<totalVertex+1; i++){
        for(int j=1; j<totalVertex+1;j++){
            if(matrix[i][j]==INT_MAX)
                printable+= "INF ";
            else
                printable+= to_string(matrix[i][j])+" ";
        }
        printable+="\n";
    }
    
    cout<<printable;

    return printable;
}
