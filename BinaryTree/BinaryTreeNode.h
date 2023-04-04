/*

				|		|
				|  val	|
				|		|
				   /\
				  /  \
				 /    \
		TreeNode*		TreeNode*
*/


class TreeNode {

	int value;
	TreeNode* leftChildPtr;
	TreeNode* rightChildPtr;
	//TreeNode* next;

public:
	TreeNode() :value(0), leftChildPtr(nullptr), rightChildPtr(nullptr) {}
	TreeNode(int v) :value(v), leftChildPtr(nullptr), rightChildPtr(nullptr) {}
	//TreeNode* temp = new TreeNode(10, root, nullptr);
	TreeNode(int v, TreeNode* l, TreeNode* r) :value(0), leftChildPtr(l), rightChildPtr(r) {}

	TreeNode* getLeftNode();
	TreeNode* getRightNode();

	void setLeftNode(TreeNode*);
	void setRightNode(TreeNode*);

	int getNodeValue();
	

	void setNodeValue(int);
	

	
};


TreeNode* TreeNode::getLeftNode() {
	return leftChildPtr;
}

TreeNode* TreeNode::getRightNode() {
	return rightChildPtr;
}


void TreeNode::setLeftNode(TreeNode* l) {
	leftChildPtr = l;
}

void TreeNode::setRightNode(TreeNode* r) {
	rightChildPtr = r;
}


int TreeNode::getNodeValue() {
	return value;
}




void TreeNode::setNodeValue(int i) {
	value = i;
}



