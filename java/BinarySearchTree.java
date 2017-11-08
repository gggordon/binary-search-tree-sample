public class BinarySearchTree {
	private TreeNode root;

	public BinarySearchTree() {
		root = null;
	}

	public TreeNode   getRoot() {
		return root;
	}

	public boolean isEmpty() {
		return root == null;
	}

	public boolean isFull() {
		TreeNode   n = new TreeNode(999);
		if (n != null) {
			n= null;
			return false;
		} else {
			return true;
		}
	}

	public boolean remove(int value) {

		if (root == null)

			return false;

		else {

			if (root.getData() == value) {

				TreeNode tempSubRoot = new TreeNode(0);

				tempSubRoot.setLeft(root);

				TreeNode   removedNode = root.remove(value,  tempSubRoot);

				root = tempSubRoot.getLeft();

				if (removedNode != null) {

					removedNode = null;

					return true;

				} else

					return false;

			} else {

				TreeNode   removedNode = root.remove(value, null);

				if (removedNode != null) {

					removedNode = null;

					return true;

				} else

					return false;

			}

		}

	}


	public boolean search(int num) {
		if (!isFull()) {

			if (isEmpty()) {
				return false;
			} else {
				TreeNode   temp = root;
				while (temp != null) {
					if (num == temp.getData()) {
						return true;
					}
					if (num > temp.getData() ) {
						if (temp.getRight() == null) {
							return false;
						} else {
							temp = temp.getRight();
						}
					} else {
						if (temp.getLeft() == null) {
							return false;
						} else {
							temp = temp.getLeft();
						}
					}
				}
			}
		}
		return false;
	}

	public void insert(int num) {
		if (!isFull()) { //check if list is full
			//create new tree node
			TreeNode   n = new TreeNode(num);
			if (isEmpty()) { //check if list is empty
				root = n; //let new node be root
			} else { // if list is not emty
				//get temporary iterator for tree
				TreeNode   temp = root;
				while (temp != null) { //while(true)
					//check if number is greater
					//   than/equal to number at
					// current tree  node
					if (num >= temp.getData() ) {
						//if number is greater
						// check if right sub tree is empty
						if (temp.getRight() == null) {
							//since right sub tree is empty
							//insert node on right
							temp.setRight(n);
							//break outside of loop
							break;
						} else {
							//if right sub tree is not empty
							//traverse to right element
							temp = temp.getRight();
						}
					} else {
						//since mumber is less than number at curernt
						//elemt, check if left sub tree is empty
						if (temp.getLeft() == null) {
							//since left sub tree is empty
							//insert node on left
							temp.setLeft(n);
							//break outside of loop
							break;
						} else {
							//if left sub tree is not empty
							//traverse to left
							temp = temp.getLeft();
						}
					}
				}
			}
		}
	}

	public void display() {
		if (isEmpty()) {
			System.out.println("Tree is empty.");
		} else {
			displayInOrder(root);
		}
	}

	public void displayInOrder(TreeNode   subTreeRoot) {
		if (subTreeRoot == null) {
			return;
		}
		displayInOrder(subTreeRoot.getLeft());

		subTreeRoot.display();

		displayInOrder(subTreeRoot.getRight());

	}

	public void displayPostOrder(TreeNode   subTreeRoot) {
		if (subTreeRoot == null) {
			return;
		}
		displayPostOrder(subTreeRoot.getLeft());

		displayPostOrder(subTreeRoot.getRight());

		subTreeRoot.display();

	}

	public void deleteInOrder(TreeNode   subTreeRoot) {
		if (subTreeRoot == null) {
			return;
		}
		TreeNode   tempLeft = subTreeRoot.getLeft();
		TreeNode   tempRight = subTreeRoot.getRight();

		deleteInOrder(tempLeft);
		subTreeRoot = null;
		deleteInOrder(tempRight);
	}

	public void deletePostOrder(TreeNode   subTreeRoot) {
		if (subTreeRoot == null) {
			return;
		}
		TreeNode   tempLeft = subTreeRoot.getLeft();
		TreeNode   tempRight = subTreeRoot.getRight();

		deletePostOrder(tempLeft);
		deletePostOrder(tempRight);
		//subTreeRoot = null;
		subTreeRoot = null;
	}

	public void destroy() {
		deletePostOrder(root);
		root = null;
	}
}