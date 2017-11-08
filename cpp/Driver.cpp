 #include "BinarySearchTree.h"

void isNumInBinarySearchTree(BinarySearchTree* tree, int num);

int main(){

	BinarySearchTree * myBinarySearchTree 
	        = new BinarySearchTree();
	myBinarySearchTree->insert(5);
	myBinarySearchTree->insert(12);
	myBinarySearchTree->insert(0);
	myBinarySearchTree->insert(38);
	myBinarySearchTree->insert(9);
	myBinarySearchTree->display();
	
    isNumInBinarySearchTree(myBinarySearchTree,5);
    isNumInBinarySearchTree(myBinarySearchTree,200);
    isNumInBinarySearchTree(myBinarySearchTree,38);
    isNumInBinarySearchTree(myBinarySearchTree,1);

    myBinarySearchTree->remove(38);
    myBinarySearchTree->display();
    myBinarySearchTree->remove(5);
    myBinarySearchTree->display();

    myBinarySearchTree->destroy();
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