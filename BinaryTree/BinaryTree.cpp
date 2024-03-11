// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
	int data;
	Node *left;
	Node *right;
	Node *root;
};

class BinaryTree {
private:
	Node *root;
	int size;

	void insert(Node* new_node, Node* node) {
		if (new_node->data < node->data) {
			if (!node->left) {
				node->left = new_node;
				new_node->root = node;
			}
			else {
				insert(new_node, node->left);
			}
		}
		else if (new_node->data > node->data) {
			if (!node->right) {
				node->right = new_node;
				new_node->root = node;
			}
			else {
				insert(new_node, node->right);
			}
		}
	}

	struct Node* remove(Node* node, int data) {
		if (node == NULL) return node;

		if (data < node->data) {
			node->left = remove(node->left, data);
		}
		else if (data > node->data) {
			node->right = remove(node->right, data);
		}
		else {
			if (node->left == NULL) {
				Node* temp = node->right;
				node = NULL;
				return temp;
			}
			else if (node->right == NULL) {
				Node* temp = node->left;
				node = NULL;
				return temp;
			}
			Node* temp = min(node->right);
			node->data = temp->data;
			node->right = remove(node->right, temp->data);
		}
		return node;
	}

	struct Node* min(Node* node) {
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}

	bool isEmpty() {
		return root == NULL;
	}

	struct Node* search(int data, struct Node* node) {
		if (!node || data == node->data) {
			return node;
		}
		else if (data < node->data) {
			return search(data, node->left);
		}
		else {
			return search(data, node->right);
		}
	}

	#pragma region Navegações
		void emOrdem(Node* node) {
			if (node == NULL) return;

			emOrdem(node->left);
			std::cout << node->data << std::endl;
			emOrdem(node->right);
		}

		void preOrdem(Node* node) {
			if (node == NULL) return;

			std::cout << node->data << std::endl;
			preOrdem(node->left);
			preOrdem(node->right);
		}

		void posOrdem(Node* node) {
			if (node == NULL) return;

			posOrdem(node->left);
			posOrdem(node->right);
			std::cout << node->data << std::endl;
		}
	#pragma endregion

public:
	void Insert(int data) {
		Node* node = new struct Node;
		node->data = data;
		node->left = node->right = node->root = NULL;
		if (isEmpty()) {
			root = node;
		} else {
			insert(node, root);
		}
		size++;
	}

	struct Node* getRoot() {
		if (root != NULL) return root;
	}
	
	void Remove(int data) {
		remove(root, data);
	}

	void PreOrdem() {
		preOrdem(root);
	}

	void EmOrdem() {
		emOrdem(root);
	}

	void PosOrdem() {
		posOrdem(root);
	}
};



int main() {
	BinaryTree* tree = new BinaryTree();
	tree->Insert(10); // Raiz
	tree->Insert(7);
	tree->Insert(20);
	tree->Insert(15);
	tree->Insert(6);

	std::cout << "EM ORDEM" << std::endl;
	tree->EmOrdem();
	std::cout << std::endl;
	std::cout << "PRE ORDEM" << std::endl;
	tree->PreOrdem();
	std::cout << std::endl;
	std::cout << "POS ORDEM" << std::endl;
	tree->PosOrdem();
	std::cout << std::endl;

	tree->Remove(7);
	std::cout << "7 foi Removido" << std::endl;
	std::cout << std::endl;

	std::cout << "EM ORDEM (novo)" << std::endl;
	tree->EmOrdem();
	std::cout << std::endl;

	tree->Insert(30);
	tree->Insert(8);
	std::cout << "30 e 8 foram inseridos" << std::endl;
	std::cout << std::endl;

	std::cout << "PRE ORDEM (novo^2)" << std::endl;
	tree->PreOrdem();

	delete tree;

	return EXIT_SUCCESS;
}
