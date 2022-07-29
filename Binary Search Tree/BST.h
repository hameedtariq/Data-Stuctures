#pragma once
#include<stdint.h>
#include<iostream>
#include<stack>
#include <queue>
using std::cout;

template<typename T>
struct BSTnode {
	T data;
	BSTnode<T>* left;
	BSTnode<T>* right;
};

template<typename T>
class BST
{	
private:
	BSTnode<T>* root;
	uint32_t size;
public:
	BST() : root(nullptr), size(0) {};
	void insert(T data);
	BSTnode<T>* generateNode(T data);
	void preOrderPrint();
	void postOrderPrint();
	void inOrderPrint();
	void levelOrderPrint();
};

#include "BST.h"

template<typename T>
inline void BST<T>::insert(T data)
{
	BSTnode<T>* node = generateNode(data);
	if (root == nullptr) {
		root = node;
	}
	else {
		BSTnode<T>* ptr = root;
		while (true) {
			if (data <= ptr->data) {
				if (ptr->left == nullptr) {
					ptr->left = node;
					break;
				}
				else {
					ptr = ptr->left;
				}
			}
			else {
				if (ptr->right == nullptr) {
					ptr->right = node;
					break;
				}
				else {
					ptr = ptr->right;
				}

			}
		}
	}
}

template<typename T>
inline BSTnode<T>* BST<T>::generateNode(T data)
{
	return new BSTnode<T>({ data,nullptr,nullptr });
}

template<typename T>
inline void BST<T>::preOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	traversal.push(root);

	while (!traversal.empty()) {
		BSTnode<T>* top = traversal.top();
		traversal.pop();
		cout << top->data<< ":";
		if(top->right)
			traversal.push(top->right);
		if(top->left)
			traversal.push(top->left);
	}
}

template<typename T>
inline void BST<T>::postOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	traversal.push(root);
	BSTnode<T>* top = traversal.top();
	while (!traversal.empty()) {
		if (traversal.top()->right == top) {
			top = traversal.top();
			cout << top->data << ":";
			traversal.pop();
			continue;
		}

		top = traversal.top();
		if (!top->left && !top->right) {
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		if (top->right) traversal.push(top->right);
		if (top->left) traversal.push(top->left);
		
		
	}
	
		
	
}

template<typename T>
inline void BST<T>::inOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	BSTnode<T>* top = root;

	while (top != nullptr || !traversal.empty()) {
		while (top) {
		traversal.push(top);
		top = top->left;
		}

		top = traversal.top();
		traversal.pop();
		cout << top->data << ":";

		top = top->right;
	}

}

template<typename T>
inline void BST<T>::levelOrderPrint()
{
	std::queue<BSTnode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		BSTnode<T>* front = q.front();
		q.pop();
		cout << front->data << ":";
		if (front->left) q.push(front->left);
		if (front->right) q.push(front->right);
	}
}

/*
		if (top->right)
		traversal.push(top->right);
	traversal.push(top);
	if (top->left) {
		traversal.push(top->left);
		top = top->left;
	}


if (traversal.top()->left == top || (traversal.top()->left && traversal.top()->left->right == top)) {
			top = traversal.top();
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		top = traversal.top();
		if (!top->left && !top->right) {
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		traversal.pop();
		if (top->right) {
			traversal.push(top->right);
		}
		traversal.push(top);
		if (top->left) {
			traversal.push(top->left);
		}*/