#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member structure
*/
// 완전 이진 트리
class BSTNode{
	public:
		BSTNode(BSTNode* parent=NULL, int no=-1);
		
		int number;
		BSTNode* parent;
		BSTNode* leftChild;
		BSTNode* rightChild;
		
		bool addChild(int no);
		bool removeChild(int no);
		int getSize();
		BSTNode* getChild();
		
		int getDeps();
		
		void preorder();
		void inorder();
		void postorder();
};
BSTNode::BSTNode(BSTNode* parent, int no){
	this->number = no;
	if(parent != NULL){
		this->parent = (BSTNode*)malloc(sizeof(BSTNode));
		*this->parent = *parent;
	}
	leftChild = NULL;
	rightChild = NULL;
}
bool BSTNode::addChild(int no){
	// BST 라면 NULL 확인하고 left에는 작은수/right는 큰수 
	if(this->number == -1){
		// 노드에 엘리멘트가 없으면 삽입.
		this->number = no; 
			cout<<"입력 "<<no<<endl;
		return true;
	}
	if(no < this->number){
		cout<<"왼쪽운행< ";
		if(leftChild == NULL){
			this->leftChild = (BSTNode*)malloc(sizeof(BSTNode));
			leftChild = new BSTNode(this);
		}
		return this->leftChild->addChild(no);
	}
	if(no > this->number){
		cout<<"오른쪽운행> ";
		if(rightChild == NULL){
			this->rightChild = (BSTNode*)malloc(sizeof(BSTNode));
			rightChild = new BSTNode(this);
		}
		return this->rightChild->addChild(no);
	}
	//같은수라서 삽입 불가능일때는
	return false; 
}
bool BSTNode::removeChild(int no){
	// 해당 노드가 삭제될때 처리
	if(this->number == no){
		this->~BSTNode();	// 소멸자 처리 
		return true; 
	}
	if(this->number > no)
		if(leftChild != NULL) return leftChild->removeChild(no);
	if(this->number < no)
		if(rightChild != NULL) return rightChild->removeChild(no);
	// 모든 입력된 노드에 업어서 삭제 못했으면  
	return false;
}
int BSTNode::getSize(){
	return (leftChild != NULL ? 1 : 0) + (rightChild != NULL ? 1 : 0);
}
BSTNode* BSTNode::getChild(){
	int cnt = (leftChild != NULL ? 1 : 0) + (rightChild != NULL ? 1 : 0);
	BSTNode* buf = new BSTNode[cnt];
	if(cnt == 2){
		*(buf+0) = *leftChild;
		*(buf+1) = *rightChild;
	}else if(cnt == 1){
		*(buf+0) = *leftChild;
	}
	return buf;
}

int BSTNode::getDeps(){
	if(leftChild != NULL) return leftChild->getDeps()+1;
	if(rightChild != NULL) return rightChild->getDeps()+1;
	
	return 1;
}

void BSTNode::preorder(){
	printf("%d ", this->number);
	if(this->leftChild != NULL) leftChild->preorder();
	if(this->rightChild != NULL) rightChild->preorder();
}
void BSTNode::inorder(){
	if(this->leftChild != NULL) leftChild->inorder();
	printf("%d ", this->number);
	if(this->rightChild != NULL) rightChild->inorder();
}
void BSTNode::postorder(){
	if(this->leftChild != NULL) leftChild->postorder();
	if(this->rightChild != NULL) rightChild->postorder();
	printf("%d ", this->number);
}
