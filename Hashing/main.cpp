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
    int N=20000;

    HashTable hashtable1(N, "SC",1);
    HashTable hashtable2(N, "SC",2);

    HashTable hashtable3(N, "DH",1);
    HashTable hashtable4(N, "DH",2);

    HashTable hashtable5(N, "CP",1);
    HashTable hashtable6(N, "CP",2);

    vector<string> wordslist;

    for(int i=0; i<10000;i++){
        in>>str;
        wordslist.push_back(str);

        // cout<<str;
        hashtable1.InsertData(str,i+1);
        hashtable2.InsertData(str,i+1);

        hashtable3.InsertData(str,i+1);
        hashtable4.InsertData(str,i+1);

        hashtable5.InsertData(str,i+1);
        hashtable6.InsertData(str,i+1);

        //cout<<hashtable.hash1(str)<<endl;
    }
    in.close();
    
    hashtable1.probeCount=0;
    hashtable2.probeCount=0;

    hashtable3.probeCount=0;
    hashtable4.probeCount=0;

    hashtable5.probeCount=0;
    hashtable6.probeCount=0;

    in.open("word.txt");
    

    double count=0;
    for(int i=0; count<1000; i++){
        i+=rand()%18;
        if(i>10000)
            break;

        //cout<<i<<" ";
        str= wordslist[i];
        count++;
        
        hashtable1.FindData(str);
        hashtable2.FindData(str);

        hashtable3.FindData(str);
        hashtable4.FindData(str);

        hashtable5.FindData(str);
        hashtable6.FindData(str);
    }

    cout<<"\nSearch Count: "<<count<<"\n\n";
    cout<<"Separate chaining hash 1 Collision Count: "<<hashtable1.collisionCount <<" average probe count : "<<hashtable1.probeCount/count<<"\n";
    cout<<"Separate chaining hash 2 Collision Count: "<<hashtable2.collisionCount <<" average probe count : "<<hashtable2.probeCount/count<<"\n\n";

    cout<<"Double Hashing hash 1 Collision Count: "<<hashtable3.collisionCount <<" average probe count : "<<hashtable3.probeCount/count<<"\n";
    cout<<"Double Hashing hash 2 Collision Count: "<<hashtable4.collisionCount <<" average probe count : "<<hashtable4.probeCount/count<<"\n\n";

    cout<<"Custom probing hash 1 Collision Count: "<<hashtable5.collisionCount <<" average probe count : "<<hashtable5.probeCount/count<<"\n";
    cout<<"Custom probing hash 2 Collision Count: "<<hashtable6.collisionCount <<" average probe count : "<<hashtable6.probeCount/count<<"\n\n";
    
    return 0;

}