#ifndef AVL_H
#define AVL_H

#include <fstream>
#include <iostream>

struct AVLNode
{
	int key;
	AVLNode *left, *right;

	AVLNode(int);
};

AVLNode::AVLNode(int k)
{
	key = k;
	left = right = nullptr;
}

class AVLTree
{
	public:
		AVLTree();
		int max(int, int);
		int size();
		// int search(int);
		bool getBal();
		void rmRoot();
		void clear();
		void insert(int);
		void remove(int);
		void preOrder(std::ofstream&);
		void inOrder(std::ofstream&);
		void postOrder(std::ofstream&);

	private:
		int nodes;
		AVLNode *root;

		// int search(int, int, AVLNode *);
		int bFactor(AVLNode *);
		int getHeight(AVLNode *);
		void rmRoot(AVLNode *);
		void clear(AVLNode *);
		void preOrder(std::ofstream&, AVLNode *);
		void inOrder(std::ofstream&, AVLNode *);
		void postOrder(std::ofstream&, AVLNode *);
		AVLNode *insert(int, AVLNode *&);
		AVLNode *remove(int, AVLNode *&);
		AVLNode *RRCase(AVLNode *);
		AVLNode *LLCase(AVLNode *);
		AVLNode *RLCase(AVLNode *);
		AVLNode *LRCase(AVLNode *);
		AVLNode *balance(AVLNode *);
		AVLNode *locateMax(AVLNode *);
		AVLNode *locateMin(AVLNode *);
};

AVLTree::AVLTree()
{
	nodes = 0;
	root = nullptr;
}

int AVLTree::max(int a, int b)
{
	if (a <= b)
		return b;
	else
		return a;
}

int AVLTree::size()
{
	return nodes;
}

/*
int AVLTree::search(int value)
{
	if (root != nullptr)
		search(value, 1, root);
	else
		return 0;
}
*/

bool AVLTree::getBal()
{
	std::cout << bFactor(root);
	if (bFactor(root) > 1 || bFactor(root) < -1)
		return false;
	else 
		return true;
}

void AVLTree::rmRoot()
{
	rmRoot(root);
}

void AVLTree::clear()
{
	clear(root);
}

void AVLTree::insert(int key)
{
	if (root != nullptr)
		insert(key, root);
	else
		root = new AVLNode(key);

	nodes++;
}

void AVLTree::remove(int key)
{
	if (root != nullptr)
	{
		remove(key, root);
		nodes--;
	}
}

void AVLTree::preOrder(std::ofstream& output)
{
	if (root != nullptr)
		preOrder(output, root);
}

void AVLTree::inOrder(std::ofstream& output)
{
	if (root != nullptr)
		inOrder(output, root);
}

void AVLTree::postOrder(std::ofstream& output)
{
	if (root != nullptr)
		postOrder(output, root);
}

// private functions

/*
int AVLTree::search(int value, int lvl, AVLNode *node)
{
	if (node == nullptr)
		return 0;
	else
		if (value < node->key)
			search(value, ++lvl, node->left);
		else if (value > node->key)
			search(value, ++lvl, node->right);
		else
			return lvl;
}
*/

int AVLTree::bFactor(AVLNode *node)
{
	int bal = getHeight(node->left) - getHeight(node->right);

	return bal;
}

int AVLTree::getHeight(AVLNode *node)
{
	int height = 0;

	if (node != nullptr)
		height = max(getHeight(node->left), getHeight(node->right)) + 1;

	return height;
}

void AVLTree::rmRoot(AVLNode *node)
{
	remove(node->key, node);
}

void AVLTree::clear(AVLNode *node)
{
	/*
	int max = locateMax(root)->key;
	int min = locateMin(root)->key;

	for (int i = min; i <= max + 1; i++)
		remove(i);
	*/

	/*
	for (int i = 1; i <= nodes; i++)
	{
		preOrder();
		std::cout << std::endl;
		remove(root->key, root);
	}
	*/
}

void AVLTree::preOrder(std::ofstream& output, AVLNode *node)
{
	if (node != nullptr)
	{
		output << node->key << " ";
		preOrder(output, node->left);
		preOrder(output, node->right);
	}
}

void AVLTree::inOrder(std::ofstream& output, AVLNode *node)
{
	if (node != nullptr)
	{
		inOrder(output, node->left);
		output << node->key << " ";
		inOrder(output, node->right);
	} 
}

void AVLTree::postOrder(std::ofstream& output, AVLNode *node)
{
	if (node != nullptr)
	{
		postOrder(output, node->left);
		postOrder(output, node->right);
		output << node->key << " ";
	}
}

AVLNode *AVLTree::insert(int key, AVLNode *&node)
{
	if (node == nullptr)
		return node = new AVLNode(key);

	if (key < node->key)
	{
		node->left = insert(key, node->left);
		node = balance(node);
	}

	if (key > node->key)
	{
		node->right = insert(key, node->right);
		node = balance(node);
	}

	return node;
}

AVLNode *AVLTree::remove(int key, AVLNode *&node)
{
	if (node->key == key)
		if (node->left == nullptr && node->right == nullptr)
		{
			node = nullptr;
			delete node;
			return nullptr;
		}
		else if (node->right == nullptr && node->left->left == nullptr && node->left->right == nullptr)
		{
			node->key = node->left->key;
			node->left = remove(node->key, node->left);
			return node;
		}
		else if (node->left == nullptr && node->right->left == nullptr && node->right->right == nullptr)
		{
			node->key = node->right->key;
			node->right = remove(node->key, node->right);

			return node;
		}
		else if (node->right == nullptr)
		{
			AVLNode *tmp = locateMax(node->left);

			node->key = tmp->key;
			node->left = remove(node->key, node->left);
			return node;
		}
		else
		{
			AVLNode *tmp = locateMin(node->right);

			node->key = tmp->key;
			node->right = remove(node->key, node->right);
			return node;
		}

	if (key < node->key)
	{
		node->left = remove(key, node->left);
		node = balance(node);
	}

	if (key > node->key)
	{
		node->right = remove(key, node->right);
		node = balance(node);
	}

	return node;
}

AVLNode *AVLTree::RRCase(AVLNode *node)
{
	AVLNode *tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;

	return tmp;
}

AVLNode *AVLTree::LLCase(AVLNode *node)
{

	AVLNode *tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;

	return tmp;
}

AVLNode *AVLTree::RLCase(AVLNode *node)
{
	node->right = LLCase(node->right);

	return RRCase(node);
}

AVLNode *AVLTree::LRCase(AVLNode *node)
{
	node->left = RRCase(node->left);

	return LLCase(node);
}

AVLNode *AVLTree::balance(AVLNode *node)
{
	int bal = bFactor(node);

	if (bal > 1)
	{
		if (bFactor(node->left) > 0)
			node = LLCase(node);
		else
			node = LRCase(node);
	}

	if (bal < -1)
	{
		if (bFactor(node->right) > 0)
			node = RLCase(node);
		else
			node = RRCase(node);
	}

	return node;
}

AVLNode *AVLTree::locateMax(AVLNode *node)
{
	AVLNode *tmp = node;

	while (tmp->right != nullptr)
		tmp = tmp->right;

	return tmp;
}


AVLNode *AVLTree::locateMin(AVLNode *node)
{
	AVLNode *tmp = node;

	while (tmp->left != nullptr)
		tmp = tmp->left;

	return tmp;
}

#endif
