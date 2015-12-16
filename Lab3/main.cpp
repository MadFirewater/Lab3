#include<iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <iomanip>

using namespace std;
struct Node{
	int value;
	Node *left;
	Node *right;
};
Node *root;
int depth=0 ;
void InsertTree(Node **aNode, int data){//процедура вставки елемента в дерево
	if (!(*aNode)){
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else{
	if (data < (*aNode)->value) InsertTree(&(*aNode)->left,data);
	else InsertTree(&(*aNode)->right, data);
	}
	return;}

void createTree(Node **aNode,int N){//процедура створення дерева
     srand(time(0));
    for(int i=0;i<N;i++){
        int data=rand()%100-50;
        InsertTree(aNode,data);
    }

}
void printTree(Node *aNode){
	if (aNode){
		printTree(aNode->left);
		cout<<aNode->value<<" ";
		printTree(aNode->right);
	}
	return;}

void calculateDepth(Node *aNode,int d){
     if (aNode){
        calculateDepth(aNode->left,d+1);
        calculateDepth(aNode->right,d+1);

     }
     if (d>depth) depth=d;
     return ;
}


int main()
{   createTree(&root,10);
    printTree(root);
    calculateDepth(root,0);
    cout<<endl<<depth;

    return 0;
}
