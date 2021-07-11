#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member structure
*/
// 트리 
class TNode{
	public:
		TNode(TNode* parent=NULL,int no=0);
		
		TNode* parent;
		std::vector<TNode> child;
		
		void addChild(int no);
		void removeChild(int no);
		TNode* getChild();
		
		int number;
};
TNode::TNode(TNode* parent,int no){
	this->parent = (TNode*)malloc(sizeof(TNode));
	*this->parent = *parent;
	this->number = no; 
}
void TNode::addChild(int no){
	TNode buf(this, no);
	this->child.push_back(buf);
}
void TNode::removeChild(int no){
	
}
TNode* TNode::getChild(){
	int bsize = this->child.size();
	TNode* buf = new TNode[bsize];
	for(int i=0; i<bsize; i++){
		*(buf+i) = this->child[i];
	}
	return buf;
}