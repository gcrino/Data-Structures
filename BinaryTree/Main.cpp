#include "BinaryTreeNode.h"
#include <iostream>

int main() {
	
	TreeNode* root = new TreeNode(1);
	root->setLeftNode(new TreeNode(2));
	root->setRightNode(new TreeNode(3));


	std::cout << root->getLeftNode()->getNodeValue();
	std::cout << root->getRightNode()->getNodeValue();
}