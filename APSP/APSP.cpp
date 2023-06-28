#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int** matrix;
    int totalVertex;
    int totalEdge;

    void multiplicate(int** C, int** A, int** B);
    string printer(int** mat);

public:
    Graph(int v, int e){
        totalVertex= v;
        totalEdge = e;

        matrix = new int*[totalVertex+1];
        for(int i=0; i<totalVertex+1; i++)
            matrix[i] = new int[totalVertex+1];
        
        for(int i=1; i<totalVertex+1; i++)
            for(int j=1; j<totalVertex+1; j++)
                matrix[i][j]= (i==j)? 0 : INT_MAX;
    }

    ~Graph(){
        for(int i=0; i<totalVertex+1; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void setEdge(int v1, int v2, int w);
    void init();

    string floydWarshal();
    string matrixMultiplication();

};

void Graph::setEdge(int v1, int v2, int w){
    matrix[v1][v2] = w;
}

void Graph::init(){
    for (int i=0; i<totalVertex; i++){
    
    }
}

string Graph::printer(int** mat){
    string printable="";
    for(int i=1;i<totalVertex+1; i++){
        for(int j=1; j<totalVertex+1;j++){
            if(mat[i][j]==INT_MAX)
                printable+= "INF ";
            else
                printable+= to_string(mat[i][j])+" ";
        }
        printable+="\n";
    }
    printable+="\n";
    //cout<<printable;

    return printable;
}

string Graph::floydWarshal()
{
    string printable="Floyd-Warshal Algorithm:\n";

    for(int k=1; k<totalVertex+1; k++)
        for(int i=1; i<totalVertex+1; i++)
            for(int j=1; j<totalVertex+1;j++){
                if( (matrix[i][j] > matrix[i][k] + matrix[k][j]) && matrix[i][k]!= INT_MAX && matrix[k][j]!=INT_MAX)
                    matrix[i][j]= matrix[i][k] + matrix[k][j];
            }

    printable+= printer(matrix);
    cout<<printable;

    return printable;
}

void Graph::multiplicate(int **C, int **A, int **B){
    int min;
    for(int i=1; i<totalVertex+1; i++)
        for(int j=1; j<totalVertex+1; j++){
            min=C[i][j];
            for(int k=1; k<totalVertex+1; k++){
                if(min> A[i][k]+B[k][j] && A[i][k]!=INT_MAX && B[k][j]!= INT_MAX)
                    min= A[i][k]+ B[k][j];
            }
            C[i][j]=min;
        }

    for(int i=1; i<totalVertex+1; i++)
        for(int j=1; j<totalVertex+1; j++)
            A[i][j]=C[i][j];
}


string Graph::matrixMultiplication(){   
    string printable="Matrix Multiplication:\n";

    int** matAns;
    int** matD;

    matAns = new int*[totalVertex+1];
    matD = new int*[totalVertex+1];
    for(int i=0; i<totalVertex+1; i++){
        matAns[i] = new int[totalVertex+1];
        matD[i] = new int[totalVertex+1];
    }
    for(int i=1; i<totalVertex+1; i++)
        for(int j=1; j<totalVertex+1; j++){
            matAns[i][j]= (i==j)? 0 : INT_MAX;
            matD[i][j]= matAns[i][j];
        }
    
    for(int i=0; i<totalVertex-1;i++)
        multiplicate(matAns, matD, matrix);


    printable+= printer(matAns);
    cout<<printable;

    for(int i=0; i<totalVertex+1; i++){
        delete[] matAns[i];
        delete[] matD[i];
    }
    delete[] matAns;
    delete[] matD;

    return printable;
}