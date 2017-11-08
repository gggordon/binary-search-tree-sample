#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "TreeNode.h"


class BinarySearchTree {
private:
  TreeNode* root;

public:
  BinarySearchTree() {
    root = NULL;
  }

  TreeNode* getRoot() {
    return root;
  }

  bool isEmpty() {
    return root == NULL;
  }

  bool isFull() {
    TreeNode* n = new TreeNode(999);
    if (n != NULL) {
      delete n;
      return false;
    } else {
      return true;
    }
  }

  bool remove(int value) {

    if (root == NULL)

      return false;

    else {

      if (root->getData() == value) {

        TreeNode tempSubRoot(0);

        tempSubRoot.setLeft(root);

        TreeNode* removedNode = root->remove(value, &tempSubRoot);

        root = tempSubRoot.getLeft();

        if (removedNode != NULL) {

          delete removedNode;

          return true;

        } else

          return false;

      } else {

        TreeNode* removedNode = root->remove(value, NULL);

        if (removedNode != NULL) {

          delete removedNode;

          return true;

        } else

          return false;

      }

    }

  }


  bool search(int num) {
    if (!isFull()) {

      if (isEmpty()) {
        return false;
      } else {
        TreeNode * temp = root;
        while (temp != NULL) {
          if (num == temp->getData()) {
            return true;
          }
          if (num > temp->getData() ) {
            if (temp->getRight() == NULL) {
              return false;
            } else {
              temp = temp->getRight();
            }
          } else {
            if (temp->getLeft() == NULL) {
              return false;
            } else {
              temp = temp->getLeft();
            }
          }
        }
      }
    }
  }

  void insert(int num) {
    if (!isFull()) { //check if list is full
      //create new tree node
      TreeNode * n = new TreeNode(num);
      if (isEmpty()) { //check if list is empty
        root = n; //let new node be root
      } else { // if list is not emty
        //get temporary iterator for tree
        TreeNode * temp = root;
        while (temp != NULL) { //while(true)
          //check if number is greater
          //   than/equal to number at
          // current tree  node
          if (num >= temp->getData() ) {
            //if number is greater
            // check if right sub tree is empty
            if (temp->getRight() == NULL) {
              //since right sub tree is empty
              //insert node on right
              temp->setRight(n);
              //break outside of loop
              break;
            } else {
              //if right sub tree is not empty
              //traverse to right element
              temp = temp->getRight();
            }
          } else {
            //since mumber is less than number at curernt
            //elemt, check if left sub tree is empty
            if (temp->getLeft() == NULL) {
              //since left sub tree is empty
              //insert node on left
              temp->setLeft(n);
              //break outside of loop
              break;
            } else {
              //if left sub tree is not empty
              //traverse to left
              temp = temp->getLeft();
            }
          }
        }
      }
    }
  }

  void display() {
    if (isEmpty()) {
      cout << "Tree is empty" << endl;
    } else {
      displayInOrder(root);
    }
  }

  void displayInOrder(TreeNode* subTreeRoot) {
    if (subTreeRoot == NULL) {
      return;
    }
    displayInOrder(subTreeRoot->getLeft());

    subTreeRoot->display();

    displayInOrder(subTreeRoot->getRight());

  }

  void displayPostOrder(TreeNode* subTreeRoot) {
    if (subTreeRoot == NULL) {
      return;
    }
    displayPostOrder(subTreeRoot->getLeft());

    displayPostOrder(subTreeRoot->getRight());

    subTreeRoot->display();

  }

  void deleteInOrder(TreeNode* subTreeRoot) {
    if (subTreeRoot == NULL) {
      return;
    }
    TreeNode*tempLeft = subTreeRoot->getLeft();
    TreeNode*tempRight = subTreeRoot->getRight();

    deleteInOrder(tempLeft);
    delete subTreeRoot;
    deleteInOrder(tempRight);
  }

  void deletePostOrder(TreeNode* subTreeRoot) {
    if (subTreeRoot == NULL) {
      return;
    }
    TreeNode*tempLeft = subTreeRoot->getLeft();
    TreeNode*tempRight = subTreeRoot->getRight();

    deletePostOrder(tempLeft);
    deletePostOrder(tempRight);
    //subTreeRoot = null;
    delete subTreeRoot;
  }

  void destroy() {
    deletePostOrder(root);
    root = NULL;
  }

  ~BinarySearchTree() {
    deletePostOrder(root);
  }
};
#endif