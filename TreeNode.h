#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <string>

using namespace std;

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
public:

    TreeNode() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }


    TreeNode(int data, TreeNode* left,
             TreeNode * right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    int getData() {
        return data;
    }

    void setData(int num) {
        data = num;
    }

    TreeNode* getLeft() {
        return left;
    }

    void setLeft(TreeNode * left) {
        this->left = left;
    }

    TreeNode * getRight() {
        return right;
    }

    void setRight(TreeNode* right) {
        this->right = right;
    }



    void display() {
        cout << "TreeNode[data="
             << data
             << ",leftIsNull="
             << (left == NULL ? "T" : "F")
             << ",rightIsNull="
             << (right == NULL ? "T" : "F")
             << "]"
             << endl;
    }

    TreeNode* remove(int value, TreeNode *parent) {

        if (value < this->data) {

            if (left != NULL)

                return left->remove(value, this);

            else

                return NULL;

        } else if (value > this->data) {

            if (right != NULL)

                return right->remove(value, this);

            else

                return NULL;

        } else {

            if (left != NULL && right != NULL) {

                this->data = right->minValue();

                return right->remove(this->data, this);

            } else if (parent->left == this) {

                parent->left = (left != NULL) ? left : right;

                return this;

            } else if (parent->right == this) {

                parent->right = (left != NULL) ? left : right;

                return this;

            }

        }

    }



    int minValue() {

        if (left == NULL)

            return data;

        else

            return left->minValue();

    }

    ~TreeNode() {
        cout << "Deleting : ";
        display();
    }

};

#endif