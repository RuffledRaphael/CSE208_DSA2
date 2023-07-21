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

    //out<<V<<E;
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
        Graph graph(V2,V);
        int count=0;
        int  sum=0;
        int rem=-1;

        for(int i=1; i< V+1; i++){
            if(win[k]+left[k]-win[i]<0){
                rem=i;
                break;
            }
            for(int j=i+1; j<V+1; j++){
                if(i==k || j==k)
                    continue;
                //out<<"matdress"<<i<<" "<<j<<" "<<matrix[i][j]<<"\n";
                graph.setEdge(0, V+1+count, matrix[i][j]);
                //out<<"matdress"<<i<<" "<<j<<" "<<matrix[i][j]<<"\n";
                sum+=matrix[i][j];
                graph.setEdge(V+1+count, i , INT_MAX);
                graph.setEdge(V+1+count, j , INT_MAX);
                count++;
            }

            graph.setEdge(i, k, win[k]+left[k]-win[i]);
        }

        if(rem!=-1){
            out<< name[k]<<" is elliminated.\n";
            out<< "They can win at most "<<to_string(win[k])<<" + "<<to_string(left[k])<<" = "<<to_string(win[k]+left[k])<<" games.\n";
            out<< name[rem]<<" has own a total of "<<to_string(win[rem])<<" games.";
            out<< "They play each other 0 times.\nSo on average, each of the teams in this group wins "<< to_string(win[rem])<<"/1 = "<<win[rem]<<" games.\n\n";
            continue;
        }

        
        int maxFlow= graph.maxFlow(0,k);

        if(maxFlow < sum){
            out<< name[k]<<" is elliminated.\n";
            out<< "They can win at most "<<to_string(win[k])<<" + "<<to_string(left[k])<<" = "<<to_string(win[k]+left[k])<<" games.\n";
            graph.getMinCut(k);
            int size= graph.minCut.size();
            //out<<size;
            int totalwin=0;
            int leftMatch=0;

            for(int i=0; i<size;i++){
                int n= graph.minCut[i];
                out<<name[n];
                //out<< name[n];
                if(size-i>2)
                    out<<", ";
                else if( size-i==2)
                    out<< " and ";

                totalwin+=win[n];
            }
             for(int i=0; i<size; i++)
                for(int j=i+1; j<size; j++){
                    int l= graph.minCut[i];
                    int m= graph.minCut[j];
                    leftMatch+= matrix[l][m];

                }
            out<< " have a total of "<<to_string(totalwin)<<" games.\n";
            out<<"They play each other ";

           

            out<<to_string(leftMatch)<<" times.\n";
            double probable=totalwin+leftMatch;
            out<<"So on average, each of the teams in this group wins "<<to_string(totalwin+leftMatch)<<"/"<<to_string(size)<<" = "<<to_string(probable/size)<<" games.\n\n";
        }

        //out<<maxFlow<<" "<<sum<<"\n";
    
    }


    //out<<"\n"<<graph.maxFlow(s,d)<<"\n";
    // out<<graph.dijkstra(s,d);
    

    in.close();
    out.close();

    return 0;
}