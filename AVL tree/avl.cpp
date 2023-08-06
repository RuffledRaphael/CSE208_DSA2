#include<bits\stdc++.h>
using namespace std;

class BstNode{
public:
    int data;
    BstNode* leftChild;
    BstNode* rightChild;
    int nodeHeight;

    int isLeft;

    BstNode(){
        leftChild=NULL;
        rightChild=NULL;
        isLeft=2;
        nodeHeight=1;
    }

    int isLeaf(){
        if(leftChild==NULL && rightChild==NULL)
            return 1;
        else
            return 0; 
    }
};

class AVLtree{

private:
    BstNode* root;
    int currentSize;

    friend ostream& operator<<(ostream& out, AVLtree &ob);
    string print(BstNode* parent);
    // string preOrder(BstNode* parent);
    // string postOrder(BstNode* parent);
    string inOrder(BstNode* parent);

    BstNode* Insert(BstNode* node, int obj);
    BstNode* Delete(BstNode* node, int obj);
    string Find(BstNode* node, int obj);

    BstNode* balanceRotate(BstNode* node, int bf);

public:
    AVLtree(){
        currentSize=0;
        root=NULL;
    }

    string Traversal();

    BstNode* rightRotation(BstNode* A);
    BstNode* leftRotation(BstNode* A);

    void insertNode(int obj);
    int deleteNode(int obj);
    string findNode(int obj);

    int height(BstNode *node){
        if(!node)
            return 0;
        return node->nodeHeight;
    }

    int getBalanceFactor(BstNode *node){
        if(!node)
            return 0;
        return height(node->leftChild) - height(node->rightChild);
    }

    BstNode* leftMostMinValue(BstNode* node){
        BstNode* curr = node;

        while (curr->leftChild != NULL)
            curr=curr->leftChild;

        return curr;
    }

};

string AVLtree::print(BstNode* parent){   
    string printable;
    
    printable= (parent->isLeaf()==1)? to_string(parent->data) :( to_string(parent->data) +  "(" + ((parent->leftChild!=NULL) ? (print(parent->leftChild) + "," ) : ",") + "" + ((parent->rightChild!=NULL) ? (print(parent->rightChild) + ")" ) : ")")) ;

    return printable;
}

inline string AVLtree::inOrder(BstNode *parent)
{
    string printable = ((parent->leftChild== NULL) ? "" : (inOrder(parent->leftChild) + " ") ) + to_string(parent->data) + ( (parent->rightChild== NULL)? "" : (" "+ inOrder(parent->rightChild)) );
    return printable;
}

// string AVLtree::preOrder(BstNode *parent){
//     string printable = to_string(parent->data) + ((parent->leftChild== NULL) ? "" : (" "+ preOrder(parent->leftChild)) ) +( (parent->rightChild== NULL)? "" : (" "+preOrder(parent->rightChild)) );
//     return printable;
// }

// string AVLtree::postOrder(BstNode *parent){   
//     string printable = ((parent->leftChild== NULL) ? "" : (postOrder(parent->leftChild) + " ") ) + ( (parent->rightChild== NULL)? "" : (postOrder(parent->rightChild)+ " ") ) + to_string(parent->data);
//     return printable;
// }

string AVLtree::Traversal()
{
    if(currentSize==0)
        return "\n";

    //string printable="Invalid Input";
    // if(command=="Pre"){
    //     printable= preOrder(root);
    // }
    // else if(command=="Post"){
    //     printable= postOrder(root);
    // }
    //else if(command=="In"){
    
    string printable=inOrder(root);
    return printable;
}

ostream& operator<<(ostream& stream, AVLtree &ob){
    stream << ob.print(ob.root);
    return stream;
}

BstNode *AVLtree::rightRotation(BstNode *A){
    BstNode* B = A->leftChild;
    BstNode* Br= B->rightChild;
    //cout<<"rotateR ";

    B->rightChild= A;
    A->leftChild = Br;

    A->nodeHeight= 1+ max(height(A->leftChild),height(A->rightChild)) ;
    B->nodeHeight= 1+ max(height(B->leftChild),height(B->rightChild)) ;

    return B;
}

BstNode *AVLtree::leftRotation(BstNode *A){
    BstNode* B = A->rightChild;
    BstNode* Bl= B->leftChild;
    //cout<<"rotateL ";

    B->leftChild=A;
    A->rightChild=Bl;

    A->nodeHeight= 1+ max(height(A->leftChild),height( A->rightChild));
    B->nodeHeight= 1+ max(height(B->leftChild),height( B->rightChild));

    return B;
}


BstNode* AVLtree::balanceRotate(BstNode *node, int bf)
{
    int balanceFactor=bf;

    if(balanceFactor>1 && getBalanceFactor(node->leftChild)>=0)
		return rightRotation(node);

	else if (balanceFactor>1 && getBalanceFactor(node->leftChild)<0){
		node->leftChild = leftRotation(node->leftChild);
		return rightRotation(node);
	}

	else if (balanceFactor<-1 && getBalanceFactor(node->rightChild)<=0)
		return leftRotation(node);

	else if (balanceFactor<-1 && getBalanceFactor(node->rightChild)>0){
		node->rightChild= rightRotation(node->rightChild);
		return leftRotation(node);
	}

    return node;
}

void AVLtree::insertNode(int obj){
    root= Insert(root, obj);
}

int AVLtree::deleteNode(int obj){
    if(currentSize==0)
        return -1;
    if(Find(root, obj)=="found"){
        root= Delete(root, obj);
        currentSize--;
        if(currentSize==0)
            return -1;
        return 1;
    }
    else if(Find(root, obj)=="not found")
        return 1;

    return 1;
}

string AVLtree::findNode(int obj){
    return Find(root, obj) ;
}


BstNode* AVLtree::Insert(BstNode* node, int obj){
    if( currentSize==0 ){
        BstNode* temp = new BstNode();
        root=temp;
        root->data=obj;
        root->isLeft=-1;
        currentSize++;

        return root;
    }

    else if( obj < node->data && !node->leftChild ){
        BstNode* temp = new BstNode();
        node->leftChild=temp;
        node->leftChild->data=obj;
        node->leftChild->isLeft=1;
        currentSize++;
    }

    else if( obj > node->data && !node->rightChild ){
        BstNode* temp = new BstNode();
        node->rightChild=temp;
        node->rightChild->data=obj;
        node->rightChild->isLeft=0;
        currentSize++;
    }

    else if( obj < node->data && node->leftChild ){
        node->leftChild= Insert(node->leftChild, obj);
    }

    else if(obj > node->data && node->rightChild ){
        node->rightChild = Insert(node->rightChild,obj);
    }

    int leftHeight = height(node->leftChild);
    int rightHeight =height(node->rightChild);

    node->nodeHeight = 1 + max(height(node->leftChild), height(node->rightChild));

    int balanceFactor= getBalanceFactor(node);
    node= balanceRotate(node,balanceFactor);

    return node;
}

string AVLtree::Find(BstNode* node, int obj){
    if(currentSize==0)
        return "not found";
    if(obj < node->data && node->leftChild==NULL){
        return "not found";
    }
    else if(obj > node->data && node->rightChild==NULL){
        return "not found";
    }
    else if(obj < node->data && node->leftChild!=NULL){
        return Find(node->leftChild,obj);
    }
    else if(obj > node->data && node->rightChild!=NULL){
        return Find(node->rightChild,obj);
    }
    else if(node->data==obj){
        return "found";
    }
    return "not found";
}


BstNode* AVLtree::Delete(BstNode* node, int obj){
	if (node==NULL)
		return node;

	if(obj==node->data){
        if(node->isLeaf()==1){
            BstNode *temp= node;
            node= NULL;
        }
        else if(node->leftChild == NULL){
            BstNode *temp= node->rightChild;
            *node= *temp;
        }
        else if(node->rightChild == NULL){
            BstNode *temp= node->leftChild;
            *node= *temp;
        }
		else{
			BstNode *temp = leftMostMinValue(node->rightChild);
			node->data = temp->data;
			node->rightChild = Delete(node->rightChild,temp->data);
		}
	}

    else if(obj < node->data)
		node->leftChild =Delete(node->leftChild,obj);

	else if(obj > node->data)
		node->rightChild = Delete(node->rightChild,obj);


	if (node==NULL)
		return node;

	node->nodeHeight = 1 + max(height(node->leftChild),height(node->rightChild));
	int balanceFactor = getBalanceFactor(node);

	node= balanceRotate(node,balanceFactor);

	return node;
}

