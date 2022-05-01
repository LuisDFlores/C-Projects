#ifndef BT_H
#define BT_H

#include <fstream>
#include <iostream>

struct Node;

struct QueueNode
{
	Node *node;
	QueueNode *next;

	QueueNode(Node *, QueueNode *);
};

QueueNode::QueueNode(Node *n = nullptr, QueueNode *ne = nullptr)
{
	node = n;
	next = ne;
}

class Queue
{
	public:
		Queue();
		Node* getFirst();
		Node* getLast();
		void enqueue(Node *);
		void dequeue();

	private:
		QueueNode *first, *last;
};

Queue::Queue()
{
	first = last = nullptr;
}

void Queue::enqueue(Node *node)
{
	if (first == nullptr)
		first = last = new QueueNode(node);
	else
	{
		last->next = new QueueNode(node);
		last = last->next;
	}
}

void Queue::dequeue()
{
	QueueNode *tmp = first;
	first = first->next;
	delete tmp;
}

Node* Queue::getFirst()
{
	return first->node;
}

Node *Queue::getLast()
{
	return last->node;
}

struct Node
{
    int value, level;
    Node *left, *right;
    
    Node(int, Node *, Node *);
};

Node::Node(int val, Node *l = nullptr, Node *r = nullptr)
{
    value = val;
    left = l;
    right = r;
}

class BTree
{
	public:
		BTree();
		int max(int, int);
		int getSize();
		bool checkBal();
		void clear();
		void remove(int);
		void insert(int);
		void rmEnd();
		void rmRoot();
		void rmMiddle(Node *);
		void preOrder(std::ofstream&);
		void inOrder(std::ofstream&);
		void postOrder(std::ofstream&);
		void updateLevels();
		void search(std::ofstream&, int);

	private:
		int nodes;
		Node *root, *end;

		int getHeight(Node *);
		void clear(Node *);
		void rmMiddle(Node *, Node *, Node *, Queue *);
		void rmEnd(Node *, Node *, Queue *);
		void insert(int, Node *, Queue *);
		void rmRoot(Node *, Node *, Queue *);
		void inOrder(std::ofstream&, Node *);
		void preOrder(std::ofstream&, Node *);
		void postOrder(std::ofstream&, Node *);
		void updateLevels(int, int, int, Node *, Queue *);
		void search(std::ofstream&, int, Node *);
};

BTree::BTree()
{
	nodes = 0;
	root = end = nullptr;
}

int BTree::max(int a, int b)
{
	if (a <= b)
		return b;
	else
		return a;
}

int BTree::getSize()
{
	return nodes;
}

bool BTree::checkBal()
{
	if (getHeight(root->left) - getHeight(root->right) > 1 || getHeight(root->left) - getHeight(root->right) < -1)
		return false;
	else
		return true;
}

void BTree::clear()
{
	clear(root);
}


void BTree::remove(int val)
{
	if (val == root->value)
		rmRoot();
}

void BTree::insert(int val)
{
	if (root == nullptr)
	{
		root = new Node(val);
		root->level = 1;
	}
	else
	{
		Queue *list = new Queue;

		list->enqueue(root);
		insert(val, root, list);
		delete list;
	}

	updateLevels();
	nodes++;
}

void BTree::rmEnd()
{
	Queue *list = new Queue;

	list->enqueue(root);
	rmEnd(root, root, list);
	updateLevels();
	delete list;
}

void BTree::rmRoot()
{
	if (nodes > 1)
	{
		Queue *list = new Queue;

		list->enqueue(root);
		rmRoot(root, root, list);
		updateLevels();
	}
	else
	{
		delete root;
		root = nullptr;
	}

	nodes--;
}


void BTree::rmMiddle(Node *target)
{
	Queue *list = new Queue;

	list->enqueue(root);
	rmMiddle(root, root, target, list);
	updateLevels();
	delete list;
}


void BTree::preOrder(std::ofstream& output)
{
	if (root != nullptr)
		preOrder(output, root);
}

void BTree::inOrder(std::ofstream& output)
{
	if (root != nullptr)
		inOrder(output, root);
}

void BTree::postOrder(std::ofstream& output)
{
	if (root != nullptr)
		postOrder(output, root);
}

void BTree::updateLevels()
{
	Queue *list = new Queue;

	list->enqueue(root);
	updateLevels(1, 1, 1, root, list);
	delete list;
}

void BTree::search(std::ofstream& output, int value)
{
	if (root != nullptr)
		search(output, value, root);
}


// private functions

int BTree::getHeight(Node *node)
{
	int height = 0;

	if (node != nullptr)
		height = max(getHeight(node->left), getHeight(node->right)) + 1;

	return height;
}

void BTree::clear(Node *node)
{
	while (node->left != nullptr)
		rmEnd();

	delete root;
	root = nullptr;
}

void BTree::insert(int val, Node *node, Queue *list)
{
	if (node->left == nullptr)
	{
		node->left = new Node(val);
		end = node->left;
	}
	else if (node->right == nullptr)
	{
		node->right = new Node(val);
		end = node->right;
	}
	else
	{
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		insert(val, list->getFirst(), list);
	}
}

void BTree::rmEnd(Node *node, Node *tmp, Queue *list)
{
	if (node->left == end)
	{
		delete node->left;
		node->left = nullptr;
		end = tmp;
	}
	else if (node->right == end)
	{
		delete node->right;
		node->right = nullptr;
		end = node->left;
	}
	else
	{
		Node *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmEnd(list->getFirst(), tmp, list);
	}
}

void BTree::rmRoot(Node *node, Node *tmp, Queue *list)
{
	if (node->left == end)
	{
		root->value = node->left->value;
		delete node->left;
		node->left = nullptr;
		end = tmp;
	}
	else if (node->right == end)
	{
		root->value = node->right->value;
		delete node->right;
		node->right = nullptr;
		end = node->left;
	}
	else
	{
		Node *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmRoot(list->getFirst(), tmp, list);
	}
}

void BTree::rmMiddle(Node *node, Node *tmp, Node *target, Queue *list)
{
	if (node->left == end)
	{
		target->value = node->left->value;
		delete node->left;
		node->left = nullptr;
		end = tmp;
	}
	else if (node->right == end)
	{
		target->value = node->right->value;
		delete node->right;
		node->right = nullptr;
		end = node->left;
	}
	else
	{
		Node *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmMiddle(list->getFirst(), tmp, target, list);
	}
}

void BTree::preOrder(std::ofstream& output, Node *node)
{
	if (node != nullptr)
	{
		output << node->value << " ";
		preOrder(output, node->left);
		preOrder(output, node->right);
	}
}

void BTree::inOrder(std::ofstream& output, Node *node)
{
	if (node != nullptr)
	{
		inOrder(output, node->left);
		output << node->value << " ";
		inOrder(output, node->right);
	}
}

void BTree::postOrder(std::ofstream& output, Node *node)
{
	if (node != nullptr)
	{
		postOrder(output, node->left);
		postOrder(output, node->right);
		output << node->value << " ";
	}
}

void BTree::updateLevels(int iteration, int multiple, int currLevel, Node *node, Queue *list)
{
	if (iteration == multiple)
	{
		multiple *= 2;
		iteration = 0;
		currLevel++;
	}

	if (node->left != nullptr)
		node->left->level = currLevel;

	if (node->right != nullptr)
	{
		node->right->level = currLevel;
		iteration += 2;

		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		updateLevels(iteration, multiple, currLevel, list->getFirst(), list);
	}
}

void BTree::search(std::ofstream& output, int value, Node *node)
{
	if (node != nullptr)
	{
		search(output, value, node->left);
        search(output, value, node->right);

        if (value == node->value)
        	output << "Value found at level: " << node->level << std::endl;
	}
}

#endif