 #include "BinarySearchTree.h"

void isNumInBinarySearchTree(BinarySearchTree* tree, int num);

int main(){

	BinarySearchTree * myBinarySearchTree 
	        = new BinarySearchTree();
	myBinarySearchTree->insert(5);
	myBinarySearchTree->insert(12);
	myBinarySearchTree->insert(0)
	myBinarySearchTree->insert(38);
	myBinarySearchTree->insert(9);
	myBinarySearchTree->display();
	myBinarySearchTree->destroy();
    isNumInBinarySearchTree(myBinarySearchTree,5);
    isNumInBinarySearchTree(myBinarySearchTree,200);
    isNumInBinarySearchTree(myBinarySearchTree,1000);
    isNumInBinarySearchTree(myBinarySearchTree,1);
	delete myBinarySearchTree;
	return 0;
}

void isNumInBinarySearchTree(BinarySearchTree* tree, int num){
	if(tree->search(num)){
		cout << "Found "<< num <<" in tree";
	}else{
		cout << "Did not find "<< num <<" in tree";
	}
	cout << endl;
}