#include <iostream>
#include <ctime>
#include <fstream>

struct HNode;

struct QueueHNode
{
	HNode *node;
	QueueHNode *next;

	QueueHNode(HNode *, QueueHNode *);
};

QueueHNode::QueueHNode(HNode *n = nullptr, QueueHNode *ne = nullptr)
{
	node = n;
	next = ne;
}

class HQueue
{
	public:
		Queue();
		HNode* getFirst();
		HNode* getLast();
		void enqueue(Node *);
		void dequeue();

	private:
		QueueHNode *first, *last;
};

HQueue::HQueue()
{
	first = last = nullptr;
}

void HQueue::enqueue(HNode *node)
{
	if (first == nullptr)
		first = last = new QueueHNode(node);
	else
	{
		last->next = new QueueHNode(node);
		last = last->next;
	}
}

void HQueue::dequeue()
{
	QueueHNode *tmp = first;
	first = first->next;
	delete tmp;
}

HNode* HQueue::getFirst()
{
	return first->node;
}

HNode *HQueue::getLast()
{
	return last->node;
}

struct HNode
{
    int value, level;
    HNode *left, *right;
    
    HNode(int, HNode *, HNode *);
};

HNode::HNode(int val, HNode *l = nullptr, HNode *r = nullptr)
{
    value = val;
    left = l;
    right = r;
}

class BHTree
{
	public:
		BHTree();
		int max(int, int);
		int getSize();
		bool checkBal();
		void clear();
		void remove(int);
		void insert(int);
		void rmEnd();
		void rmRoot();
		void rmMiddle(HNode *);
		void preOrder(std::ofstream&);
		void inOrder(std::ofstream&);
		void postOrder(std::ofstream&);
		void updateLevels();
		void search(std::ofstream&, int);
        	void heapifymin(int[], int, int);
       		void heapSort(int[], int);
     	        void printminheap(std::ofstream&, int arr[], int n);
		void heap_Sort(int arr[], int n);
   		void printMaxheap(std::ofstream&, int arr[], int n);
		void heapifymax(int arr[], int x, int i);
	private:
		int nodes;
		HNode *root, *end;
		
		int getHeight(HNode *);
		void clear(HNode *);
		void rmMiddle(HNode *, HNode *, HNode *, HQueue *);
		void rmEnd(HNode *, HNode *, HQueue *);
		void insert(int, HNode *, HQueue *);
		void rmRoot(HNode *, HNode *, HQueue *);
		void inOrder(std::ofstream&, HNode *);
		void preOrder(std::ofstream&, HNode *);
		void postOrder(std::ofstream&, HNode *);
		void updateLevels(int, int, int, HNode *, HQueue *);
		void search(std::ofstream&, int, HNode *);
};

BHTree::BHTree()
{
	nodes = 0;
	root = end = nullptr;
}

int BHTree::max(int a, int b)
{
	if (a <= b)
		return b;
	else
		return a;
}

int BHTree::getSize()
{
	return nodes;
}

bool BHTree::checkBal()
{
	if (getHeight(root->left) - getHeight(root->right) > 1 || getHeight(root->left) - getHeight(root->right) < -1)
		return false;
	else
		return true;
}

void BHTree::clear()
{
	clear(root);
}


void BHTree::remove(int val)
{
	if (val == root->value)
		rmRoot();
}

void BHTree::insert(int val)
{
	if (root == nullptr)
	{
		root = new HNode(val);
		root->level = 1;
	}
	else
	{
		HQueue *list = new HQueue;

		list->enqueue(root);
		insert(val, root, list);
		delete list;
	}

	updateLevels();
	nodes++;
}

void BHTree::rmEnd()
{
	HQueue *list = new HQueue;

	list->enqueue(root);
	rmEnd(root, root, list);
	updateLevels();
	delete list;
}

void BHTree::rmRoot()
{
	if (nodes > 1)
	{
		HQueue *list = new HQueue;

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

void BHTree::rmMiddle(Node *target)
{
	HQueue *list = new HQueue;

	list->enqueue(root);
	rmMiddle(root, root, target, list);
	updateLevels();
	delete list;
}

void BHTree::preOrder(std::ofstream& output)
{
	if (root != nullptr)
		preOrder(output, root);
}

void BHTree::inOrder(std::ofstream& output)
{
	if (root != nullptr)
		inOrder(output, root);
}

void BHTree::postOrder(std::ofstream& output)
{
	if (root != nullptr)
		postOrder(output, root);
}

void BHTree::updateLevels()
{
	HQueue *list = new HQueue;

	list->enqueue(root);
	updateLevels(1, 1, 1, root, list);
	delete list;
}

// private functions

int BHTree::getHeight(HNode *node)
{
	int height = 0;

	if (node != nullptr)
		height = max(getHeight(node->left), getHeight(node->right)) + 1;

	return height;
}

void BHTree::clear(HNode *node)
{
	while (node->left != nullptr)
		rmEnd();

	delete root;
	root = nullptr;
}

void BHTree::insert(int val, HNode *node, HQueue *list)
{
	if (node->left == nullptr)
	{
		node->left = new HNode(val);
		end = node->left;
	}
	else if (node->right == nullptr)
	{
		node->right = new HNode(val);
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

void BHTree::rmEnd(HNode *node, HNode *tmp, HQueue *list)
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
		HNode *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmEnd(list->getFirst(), tmp, list);
	}
}

void BHTree::rmRoot(HNode *node, HNode *tmp, HQueue *list)
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
		HNode *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmRoot(list->getFirst(), tmp, list);
	}
}

void BHTree::rmMiddle(HNode *node, HNode *tmp, HNode *target, HQueue *list)
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
		HNode *tmp = node->right;
		list->enqueue(node->left);
		list->enqueue(node->right);
		list->dequeue();
		rmMiddle(list->getFirst(), tmp, target, list);
	}
}

void BHTree::preOrder(std::ofstream& output, HNode *node)
{
	if (node != nullptr)
	{
		output << node->value << " ";
		preOrder(output, node->left);
		preOrder(output, node->right);
	}
}

void BHTree::inOrder(std::ofstream& output, HNode *node)
{
	if (node != nullptr)
	{
		inOrder(output, node->left);
		output << node->value << " ";
		inOrder(output, node->right);
	}
}

void BHTree::postOrder(std::ofstream& output, HNode *node)
{
	if (node != nullptr)
	{
		postOrder(output, node->left);
		postOrder(output, node->right);
		output << node->value << " ";
	}
}

void BHTree::updateLevels(int iteration, int multiple, int currLevel, HNode *node, HQueue *list)
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

void BHTree::search(std::ofstream& output, int value, HNode *node)
{
	if (node != nullptr)
	{
		search(output, value, node->left);
       		 search(output, value, node->right);

        if (value == node->value)
        	output << "Value found at level: " << node->level << std::endl;
	}
}


void BHTree::heapifymin(int arr[], int x, int i)
{
    int max = i; // Initialize max as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    
    // If left child is bigger than root
    if (l < x && arr[l] > arr[max])
        max = l;
    
    // If right child is bigger than biggest so far
    if (r < x && arr[r] > arr[max])
        max = r;
    
    // If max is not root
    if (max != i)
    {
        swap(arr[i], arr[max]);
        
        // Recursively heapify
        heapifymin(arr, x, max);
    }
}


void BHTree::heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifymin(arr, n, i);
    
    // extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // call heapify on the reduced heap
        heapifymin(arr, i, 0);
    }
}

//function to print array of size n
void BHTree::printminheap(std::ofstream& output, int arr[], int n)
{
    for (int i=0; i<n; ++i)
        output << arr[i] << " ";
        output << "\n";
}

void BHTree::heap_Sort(int arr[], int n)
{
	
 for (int i = n / 2 - 1; i >= 0; i--)
        
        heapifymax(arr, n, i);
    
    for (int i=n-1; i>=0; i--)
        
    {
        
       swap(arr[0], arr[i]);
        
       heapifymax(arr, i, 0);
        
    }

}
void BHTree::printMaxheap(std::ofstream& output, int arr[], int n)
{
	for (int i=0; i<n; ++i)
        
        output << arr[i] << " ";
    
        output << "\n";
}
		
void BHTree::heapifymax(int arr[], int x, int i)
{
int max = i;
    
    int l = 2*i + 1;
    
    int r = 2*i + 2;
    
    
    
    
    
    if (l < x && arr[l] < arr[max])
        
        max = l;
    
     if (r < x && arr[r] < arr[max])
        
        max = r;
    
     if (max != i)
        
    {
        
        swap(arr[i], arr[max]);
        
     	heapifymax(arr, x, max);
        
    }
    
}



