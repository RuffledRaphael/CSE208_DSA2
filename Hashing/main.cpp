#include<bits/stdc++.h>
#include"hash.cpp"

using namespace std;

string randomWord(){
    int length = rand() % 6 + 5;
    string word;
    char randomChar;
    for (int i=0; i<length; ++i) {
        randomChar = 'a' + rand() % 26;
        word.push_back(randomChar);
    }
    return word;
}

int main(){
    // ifstream in;
    // in.open("in.txt");
    ofstream out;
    out.open("words.txt");
    srand(2005035);

    for(int i=0; i<10000; i++){
        out<<randomWord()<<"\n";
    }
    out.close();

    ifstream in;
    in.open("words.txt");

    string str;
    int N=5000;

    HashTable hashtable1(N, "SC",1);
    HashTable hashtable2(N, "SC",2);

    HashTable hashtable3(N, "DH",1);
    HashTable hashtable4(N, "DH",2);

    HashTable hashtable5(N, "CP",1);
    HashTable hashtable6(N, "CP",2);

    for(int i=0; i<4000;i++){
        in>>str;
       // cout<<str;
        hashtable1.Insert(str,i+1);
        hashtable2.Insert(str,i+1);

        hashtable3.Insert(str,i+1);
        hashtable4.Insert(str,i+1);

        hashtable5.Insert(str,i+1);
        hashtable6.Insert(str,i+1);

        //cout<<hashtable.hash1(str)<<endl;
    }

    cout<<hashtable1.findData("ribagi")<<endl;
    cout<<hashtable2.findData("ribagi")<<endl;

    cout<<hashtable3.findData("ribagi")<<endl;
    cout<<hashtable4.findData("ribagi")<<endl;

    cout<<hashtable5.findData("ribagi")<<endl;
    cout<<hashtable6.findData("ribagi")<<endl;
    
    return 0;

}