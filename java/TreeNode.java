public class TreeNode {
	private int data;
	private TreeNode left;
	private TreeNode right;

	public TreeNode(){
		data = 0;
		left = null;
		right = null;
	}

	public TreeNode(int data){
		this.data = data;
		left = null;
		right = null;
	}

	public int getData(){
		return data;
	}

	public TreeNode getLeft(){
		return left;
	}

	public TreeNode getRight(){
		return right;
	}

	public void setData(int data){
		this.data = data;
	}

	public void setLeft(TreeNode left){
		this.left = left;
	}

	public void setRight(TreeNode right){
		this.right = right;
	}

	public String toString(){
        return "TreeNode[data=" +
                data +
                ",leftIsNull=" +
                (left == null ? "T" : "F") +
                ",rightIsNull=" +
                (right == null ? "T" : "F") +
                "]";
	}

	public void display(){
		System.out.println(toString());
	}

	public int minValue(){
		if(left == null){
			return data;
		}else{
			return left.minValue();
		}
	}

	TreeNode remove(int value, TreeNode parent) {

        if (value < this.data) {

            if (left != null)

                return left.remove(value, this);

            else

                return null;

        } else if (value > this.data) {

            if (right != null)

                return right.remove(value, this);

            else

                return null;

        } else {

            if (left != null && right != null) {

                this.data = right.minValue();

                return right.remove(this.data, this);

            } else if (parent.left == this) {

                parent.left = (left != null) ? left : right;

                return this;

            } else if (parent.right == this) {

                parent.right = (left != null) ? left : right;

                return this;

            } else {
            	return null;
            }

        }

    }


}