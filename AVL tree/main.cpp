#include<bits\stdc++.h>
#include<chrono>
#include"avl.cpp"
using namespace std;

string INPUT_FILE="in.txt";
string OUTPUT_FILE="out_avl.txt";
string OUTPUT_FILE2="report_avl.txt";

int main(){
    ifstream in;
    in.open(INPUT_FILE);
    ofstream out;
    out.open(OUTPUT_FILE);
    ofstream out2;
    out2.open(OUTPUT_FILE2);

    AVLtree BinaryTree;
    auto start_time_ = std::chrono::high_resolution_clock::now();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_).count();

    char command;
    int argument;
    int returnVal;
    string retstr;
    double timeInsert=0;
    double timeFind=0;
    double timeDelete=0;
    double timeTrav=0;


    while(in>>command){

        switch (command){
            case 'I':
                in>>argument;
                start_time_ = std::chrono::high_resolution_clock::now();
                BinaryTree.insertNode(argument);
                end_time = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_).count();
                timeInsert+= duration;
                out<<BinaryTree<<"\n";
                break;
            case 'F':
                in>>argument;
                start_time_ = std::chrono::high_resolution_clock::now();
                retstr=BinaryTree.findNode(argument)+"\n";
                end_time = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_).count();
                timeFind+= duration;
                out<<retstr;
                break;
            case 'D':
                in>>argument;
                start_time_ = std::chrono::high_resolution_clock::now();
                returnVal=BinaryTree.deleteNode(argument);
                end_time = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_).count();
                timeDelete+= duration;
                if(returnVal==1)
                    out<<BinaryTree<<"\n";
                else if(returnVal==-1)
                    out<<"\n";
                break;
            case 'T':
                start_time_ = std::chrono::high_resolution_clock::now();
                retstr=BinaryTree.Traversal()+" \n";
                end_time = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_).count();
                timeTrav+= duration;

                out<<retstr;
                break;
        }
    }
    
    string output= "operation time(ms)\ninsert "+ to_string(timeInsert/1000000)+"\ndelete ";
    output+=to_string(timeDelete/1000000)+"\nsearch "+to_string(timeFind/1000000)+ "\ntrav   "+to_string(timeTrav/1000000);
    output+="\ntotal  "+to_string((timeInsert+timeDelete+timeFind+timeTrav)/1000000);

    out2<<output;

    in.close();
    out.close();
    out2.close();
    return 0;
}