#include<bits/stdc++.h>
using namespace std;


class hashNode{
public:
    string key;
    int value;
    hashNode* nextNode=NULL;
    bool isDeleted=false;
};

class HashTable{
private:
    int tableSize;
    hashNode** table1;
    hashNode** table2;
    string collisionMethod;
    int hashMethod;

public:
    HashTable(int size, string method, int hash){
        tableSize= getPrime(size);
        table1= new hashNode*[tableSize];
        table2= new hashNode*[tableSize];

        for(int i=0; i<tableSize; i++){
            table1[i]=NULL;
            table2[i]=NULL;
        }
        collisionMethod= method;
        hashMethod=hash;
    }
    int collisionCount=0;
    int probeCount=0;

    int hash1(string str){
        int hashValue=0;
        int L= str.length();
        int charVal;
        for(int i=0; i<L; i++){
            charVal= str.at(i)-'a'+1;
            hashValue+= charVal*((int)pow(31,i))% tableSize;
            hashValue%=tableSize;
        }

        hashValue%= tableSize;

        if(hashValue<0){
            hashValue+=tableSize;
        }

        return hashValue;
    }

    int hash2(string str){
        long long hashValue= 5381;
        int charVal;
        for(int i=0; i< str.size(); i++){
            charVal= str.at(i);
            hashValue= hashValue*33 + charVal;

        }
        hashValue%=tableSize;

        int hashFinal = hashValue;
        return hashFinal;
    }

    int auxHash(string key){
        int hashValue=0;
        for(int i=0; i<key.length(); i++){
            hashValue+= key[i];
        }
        return hashValue;
    }

    int findData(string key){
        if(collisionMethod=="SC"){
            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            int found = 0;
            int probe=1;
            hashNode* temp = table1[index1];

            while(temp!=NULL){
                if(temp->key!= key){
                    temp=temp->nextNode;
                    probe++;
                }else{
                    found=1;
                    break;
                }
            }

            if(found==1){
                probeCount+=probe;
                return temp->value;
            }else
                return -1;
        }

        else if(collisionMethod=="DH"){
            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            int found = 0;
            int probe=1;
            hashNode* temp = table1[index1];

            if(temp==NULL)
                return -1;
            else{
                if(temp->key!=key){
                    int auxVal= auxHash(key);
                    while(temp!=NULL){
                        if(temp->key==key){
                            found=1;
                            probeCount+=probe;
                            return temp->value;
                        }

                        index1 += auxVal+tableSize;
                        index1 %= tableSize;
                        probe++;
                        if(probe>tableSize)
                            return -2;
                        temp= table1[index1];
                    }
                }
                if(temp==NULL)
                    return -1;

                if(temp->key==key){
                    found=1;
                    probeCount+=probe;
                    return temp->value;
                }

                if(found==0)
                    return -1;
            }
        }

        else if(collisionMethod=="CP"){
            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            int primaryHash= index1; 
            int found = 0;
            int probe=1;
            hashNode* temp = table1[index1];

            if(temp==NULL)
                return -1;
            else{
                if(temp->key!=key){
                    int auxVal= auxHash(key);
                    while(temp!=NULL){
                        if(temp->key==key){
                            found=1;
                            probeCount+=probe;
                            return temp->value;
                        }
                        index1= primaryHash + 37*probe*auxVal + 29*probe*probe + tableSize ;
                        index1 %= tableSize;
                        probe++;
                        if(probe>tableSize)
                            return -2;
                        temp= table1[index1];
                    }
                }
                if(temp==NULL)
                    return -1;

                if(temp->key==key){
                    found=1;
                    probeCount+=probe;
                    return temp->value;
                }

                if(found==0)
                    return -1;
            }
        }

        return -2;
    }

    void Insert(string key, int value){
        if(findData(key)==-2)
            return;

        if(collisionMethod=="SC"){
            if(findData(key)!=-1)
                return;
    
            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            hashNode* temp1= table1[index1];

            if(temp1==NULL){
                hashNode* newNode= new hashNode(); 
                newNode->key = key;
                newNode->value = value;
                table1[index1]=newNode;
                return;
            }

            else {
                while(temp1->nextNode !=NULL){
                    temp1 = temp1->nextNode;
                }
                hashNode* newNode= new hashNode(); 
                newNode->key = key;
                newNode->value = value;
                temp1->nextNode = newNode; 
                collisionCount++;
                return;
            }
                
        }

        else if(collisionMethod=="DH"){
            if(findData(key)!=-1)
                return;

            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            hashNode* temp1= table1[index1];
            int collision=0;

            if(temp1==NULL){
                hashNode* newNode= new hashNode(); 
                newNode->key = key;
                newNode->value = value;
                table1[index1]=newNode;
                return;
            }

            else{
                int auxVal= auxHash(key);
                while(table1[index1]!=NULL){
                    collision++;
                    index1+= auxVal+tableSize;
                    index1%= tableSize;
                }
                
                if(table1[index1]==NULL){
                    hashNode* newNode= new hashNode(); 
                    newNode->key = key;
                    newNode->value = value;
                    table1[index1]=newNode;
                    collisionCount+=collision;
                    return;
                }
            }

        }

        else if(collisionMethod=="CP"){
            if(findData(key)!=-1)
                return;
            int index1;
            if(hashMethod==1)
                index1= hash1(key);
            else if(hashMethod==2)
                index1= hash2(key);

            int primaryHash= index1;
            hashNode* temp1= table1[index1];
            int collision=0;

            if(temp1==NULL){
                hashNode* newNode= new hashNode(); 
                newNode->key = key;
                newNode->value = value;
                table1[index1]=newNode;
                return;
            }

            else{
                int auxVal=auxHash(key);
                while(table1[index1]!=NULL){
                    collision++;
                    index1=(primaryHash + 37*collision*auxVal + 29*collision*collision + tableSize);
                    index1%=tableSize;
                }
                
                if(table1[index1]==NULL){
                    hashNode* newNode= new hashNode(); 
                    newNode->key = key;
                    newNode->value = value;
                    table1[index1]=newNode;
                    collisionCount+=collision;
                    return;
                }
            }
        }
    }


    int checkPrime(int n){
        if(n==1||n==0)
            return 0;
        for(int i=2; i<n/2; i++){
            if(n%i==0)
                return 0;
        }
        return 1;
    }

    int getPrime(int n){
        if(n%2==0)
            n++;
        while(!checkPrime(n))
            n += 2;

        return n;
    }
};


