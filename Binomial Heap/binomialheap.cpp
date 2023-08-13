#include<bits\stdc++.h>
using namespace std;

class HeapNode{
public:
    int key=0;
    HeapNode* nextRoot;
    HeapNode* prevRoot;
    HeapNode* sibling;
    HeapNode* leftChild;
    HeapNode* parent;
    int degree=0;

    HeapNode(int k){
        key=k;
        nextRoot=NULL;
        prevRoot=NULL;
        leftChild=NULL;
        sibling=NULL;
        parent=NULL;
        
        degree=0;
    }
};

class BinomialHeap{
private:
    HeapNode* head=NULL;
    int size=0;
    string printTree(HeapNode* Node);
    long long factorial(int n);
    long long levelcount(int degree, int level);

public:
    void unionHeap(vector<int> vect);
    HeapNode* mergeHeap(BinomialHeap* newheap);
    HeapNode* adjustHeap();
    void insertHeap(int k);
    string findMin();
    string extractMin();
    string printHeap();
    
};

HeapNode *BinomialHeap::mergeHeap(BinomialHeap *newheap)
{
    HeapNode* node1= head;
    HeapNode* node2= newheap->head;
    HeapNode* temp;
    HeapNode* end=node1;

    while(node1!=NULL && node2!=NULL){
        if(node1->degree <= node2->degree){
            node1=node1->nextRoot;
            if(node1!=NULL){
                end=node1;
            }
        }
        else{
            temp=node2;
            node2=node2->nextRoot;

            if(node1==head){
                head= temp;
            }
            temp->prevRoot=node1->prevRoot;
            if(node1->prevRoot!=NULL){
                node1->prevRoot->nextRoot=temp;
            }
            temp->nextRoot=node1;
            node1->prevRoot=temp;
        }
    }

    if(node2!=NULL){
        end->nextRoot=node2;
        node2->prevRoot=end;
    }

    head= adjustHeap();

    return head;
}
void BinomialHeap::unionHeap(vector<int> vect)
{
    BinomialHeap* newHeap= new BinomialHeap();
    int key1;
    int i=0;
    while(i<vect.size()){
        key1= vect[i];
        ////cout<<key1;
        newHeap->insertHeap(key1);
        i++;
    }

    size+= newHeap->size;
    ////cout<<"SIZE"<<size<<"\n";

    if(head==NULL)
        head=newHeap->head;
    else
        head= mergeHeap(newHeap);
    head->prevRoot=NULL;

    ////cout<<"UNIONDONE";
}



HeapNode *BinomialHeap::adjustHeap()
{   
    ////cout<<"adjusting...\n";
    ////cout<<"head="<<head->key<<"\n";
    if(head==NULL)
        return head;
    else if(head->nextRoot==NULL)
        return head;

    HeapNode* x= head;
    while(x!= NULL){
        ////cout<<"movingandAdjusting...\n";
        ////cout<<"head="<<head->key<<"\n";
        HeapNode* nx= x->nextRoot;
        HeapNode* sib_nx= NULL;
        if(nx!=NULL)
           sib_nx= nx->nextRoot;

        if(nx==NULL)
            return head;
        else if(x->degree < nx->degree){
            x=x->nextRoot;
            continue;
        }
        else if(sib_nx!= NULL && x->degree==nx->degree && nx->degree==sib_nx->degree){
            x=x->nextRoot;
            continue;
        }
        else if(x->degree==nx->degree){
            if(x->key < nx->key){
                x->nextRoot= nx->nextRoot;
                if(nx->nextRoot!=NULL)
                    nx->nextRoot->prevRoot= x;
                if(x->leftChild!=NULL){
                    nx->sibling= x->leftChild;
                    ////cout<<"\n\n\ndone "<<nx->key<<" "<<x->leftChild->key;
                }
                x->leftChild=nx;
                nx->parent=x;
                nx->nextRoot=NULL;
                nx->prevRoot=NULL;
                x->degree+=1;
            }

            else{
                if(x==head){
                    head=nx;
                }
                nx->prevRoot= x->prevRoot;
                if(x->prevRoot!=NULL){
                    x->prevRoot->nextRoot= nx;
                }
                if(nx->leftChild!=NULL){
                    x->sibling= nx->leftChild;
                    ////cout<<"\n\n\ndone "<<x->key<<" "<<nx->leftChild->key;
                }
                nx->leftChild=x;
                x->parent=nx;
                x->nextRoot=NULL;
                x->prevRoot=NULL;
                nx->degree+=1;

                x=nx;

            }
        }
    }
    
    return head;
}

void BinomialHeap::insertHeap(int k)
{
    ////cout<<"inserting\n";
    HeapNode* newNode = new HeapNode(k);
    if(size==0)
        head= newNode;

    else{
        newNode->nextRoot= head;
        head->prevRoot=newNode;
        head= newNode;
    }

    size++;

    head= adjustHeap();
}

string BinomialHeap::findMin()
{   
    if(head==NULL)
        return "\n";

    string printable="";

    int min=INT_MAX;
    HeapNode* temp= head;
    while(temp!= NULL){
        if(temp->key < min){
            min= temp->key;
        }
        temp= temp->nextRoot;
    }
    if(min!=INT_MAX)
        printable+="Find-Min returned "+ to_string(min);

    return printable;
}

string BinomialHeap::extractMin()
{
    if(head==NULL)
        return "\n";
    //cout<<"head "<<head->key;
        
    string printable="";

    int min=INT_MAX;
    HeapNode* temp= head;
    HeapNode* minNode;
    while(temp!= NULL){
        if(temp->key < min){
            min= temp->key;
            minNode= temp;
        }
        temp= temp->nextRoot;
        // if(temp==NULL)
        //     //cout<<"yes";
    }

    //cout<<minNode->key;
    if(minNode==head){
        head=minNode->nextRoot;

        if(head!=NULL)
            head->prevRoot=NULL;
        minNode->nextRoot=NULL;
        minNode->prevRoot=NULL;
    }
    ////cout<<"head "<<head->key;

    temp=head;
    while(temp!=NULL){
        if(temp==minNode){
            if(minNode==head){
                head=NULL;
                break;
            }
            minNode->prevRoot->nextRoot= minNode->nextRoot;
            if(minNode->nextRoot!=NULL){
                //cout<<"min Next found";
                minNode->nextRoot->prevRoot=minNode->prevRoot;
            }
            minNode->nextRoot=NULL;
            minNode->prevRoot=NULL;
        }
        temp=temp->nextRoot;
    }


    HeapNode* tempSib= minNode->leftChild;
    stack<HeapNode*> stck;

    while(tempSib!=NULL){
        //cout<<"lc found\n";
        stck.push(tempSib);
        tempSib= tempSib->sibling;
    }
    int newSize= stck.size();
    HeapNode* newHead= NULL;
    if(stck.size()>0)
        newHead=stck.top();
    newHead->prevRoot=NULL;
    stck.pop();
    temp= newHead;
    HeapNode* temp2;
    while(!stck.empty()){
        temp2=stck.top();
        temp->nextRoot=temp2;
        temp2->prevRoot=temp;
        temp=temp2;
        temp->nextRoot=NULL;
        stck.pop();
    }


    BinomialHeap* newHeap = new BinomialHeap();
    newHeap->head= newHead;
    //cout<<"newHeap head "<<newHeap->head->key<<"\n";
    newHeap->size= newSize;

    ////cout<<"head "<<head->key;

    if(head==NULL)
        head=newHead;
    else
        head= mergeHeap(newHeap);
    //cout<<"head "<<head->key;
    if(head!=NULL)
        head->prevRoot=NULL;

    size--;

    if(min!=INT_MAX)
        printable+="Extract-Min returned "+ to_string(min);
    
    //cout<<"head "<<head->key;

    return printable;
}

long long BinomialHeap::factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long long BinomialHeap::levelcount(int degree, int level)
{   
    if(degree>=level)
        return factorial(degree)/(factorial(level)*factorial(degree-level));
    else 
        return 1;
}

string BinomialHeap::printTree(HeapNode *Node)
{
    ////cout<<"callTreePrint...\n";
    string printable="";
    
    HeapNode* temp= Node;
    HeapNode* tempSib;
    queue<HeapNode*> Q;
    int count=0;
    int level=0;
    int degree= Node->degree;
    long long levelmax= levelcount(degree, level);

    Q.push(temp);

    while(!Q.empty()){
        if(count==0){
            printable+="Level "+ to_string(level)+" : ";
            levelmax= levelcount(degree, level);
        }
        temp= Q.front();
        Q.pop();
        printable+= to_string(temp->key)+" ";
        count++;
        if(count==levelmax){
            count=0;
            level++;
            if(level<degree)
                levelmax=levelcount(degree, level);
            printable+="\n";
        }

        tempSib= temp->leftChild;
        while(tempSib!=NULL){
            Q.push(tempSib);
            tempSib= tempSib->sibling;         
        }

    }

    return printable;

}


string BinomialHeap::printHeap()
{
    ////cout<<"callHeapPrint...\n";
    string printable="";
    HeapNode* root= head;
    //////cout<<root->key;
    printable+="Printing Binomial Heap...\n";
    while (root!= NULL){
        printable+="Binomial Tree, B"+to_string(root->degree)+"\n";
        printable+=printTree(root);
        root=root->nextRoot;
    }
    return printable;
}
