#include<bits\stdc++.h>
#include"binomialheap.cpp"
using namespace std;

string INPUT_FILE="in.txt";
string OUTPUT_FILE="out.txt";

int main(){
    ifstream in;
    in.open(INPUT_FILE);
    ofstream out;
    out.open(OUTPUT_FILE);

    BinomialHeap heap;

    char command;
    int argument;
    string retstr="";
    vector<int> vect;


    while(in>>command){

        switch (command){
            case 'I':
                in>>argument;
                heap.insertHeap(argument);
                break;
            case 'P':
                retstr=heap.printHeap()+"\n";
                out<<retstr;
                break;
            case 'F':
                retstr=heap.findMin()+" \n";
                out<<retstr;
                break;
            case 'E':
                retstr=heap.extractMin()+" \n";
                out<<retstr;
                break;
            case 'U':
                retstr="";
                getline(in,retstr);
                istringstream iss(retstr);
                while(iss>> argument){
                    //cout<<argument;
                    vect.push_back(argument);
                }
                heap.unionHeap(vect);
                break;
            
        }
    }


    in.close();
    out.close();
    return 0;
}