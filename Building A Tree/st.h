#ifndef st_h
#define st_h

#include <iostream>

struct TreeNode
{
    int value, level;
    TreeNode *left, *right;
    
    TreeNode(int, int, TreeNode *, TreeNode *);
};

TreeNode::TreeNode(int val, int lvl, TreeNode *l = nullptr, TreeNode *r = nullptr)
{
    value = val;
    level = lvl;
    left = l;
    right = r;
}

class STree
{
public:
    
    
    STree();
    ~STree();
    int getNodes();
    int getLevels();
    void insert(int);
    void search(int);
    void preOrder(std::ofstream&);
    void inOrder(std::ofstream&);
    void postOrder(std::ofstream&);
    bool isBalanced();
    
    
private:
    
    int nodes, levels, divisor;
    
    TreeNode *root, *end;
    
    TreeNode *insert(int, TreeNode *);
    void searchSTree(int, TreeNode *);
    void clearSTree(TreeNode *);
    void preOrder(std::ofstream&, TreeNode *);
    void inOrder(std::ofstream&, TreeNode *);
    void postOrder(std::ofstream&, TreeNode *);
    bool isBalanced(TreeNode *);
    int subTreeHeight(TreeNode *);
    
    
};

STree::STree()
{
    nodes = 0;
    root = nullptr;
}

STree::~STree()
{
    clearSTree(root);
}

int STree::getNodes()
{
    return nodes;
}

int STree::getLevels()
{
    return levels;
}

void STree::insert(int num)
{
    if (root != nullptr)
        insert(num, root);
    else
        root = new TreeNode(num,levels);
}

void STree::search(int num)
{
    if (root == nullptr)
        std::cout << "Empty tree. Nothing to search.";
    else
        searchSTree(num, root);
}
void STree::preOrder(std::ofstream& output)
{
    if (root != nullptr)
        preOrder(output, root);
}

void STree::inOrder(std::ofstream& output)
{
    if (root != nullptr)
        inOrder(output, root);
   
}

void STree::postOrder(std::ofstream& output)
{
    if (root != nullptr)
        postOrder(output, root);
}

bool STree::isBalanced()
{
    if(nodes == 0)
        return true;
    else
        
        return isBalanced(root);
}


// private functions

void STree::clearSTree(TreeNode *node)

{
    
    if(node != NULL)
    {
        clearSTree(node->left);
        clearSTree(node->right);
        delete node;
        nodes--;
    }
    
    
}

void STree::searchSTree(int value , TreeNode *node)
{
    if (node != nullptr)
    {
        searchSTree(value, node->left);
        searchSTree(value, node->right);
        
        if (value == node->value)
            std::cout << "Value found at level: " << node->level << std::endl;
    }
}


int STree::subTreeHeight(TreeNode *node)
{
    if (node->left != nullptr)
    {
        subTreeHeight(node->left);
        
    }
    
    if (node->right == nullptr)
    {
        
        subTreeHeight(node->right);
        
    }
    
    if (node->left == nullptr && node->right == nullptr)
    {
        std::cout << node->level;
    }
    
    return node->level;
}


TreeNode *STree::insert(int num, TreeNode *node)
{
    if (node == nullptr)
    {
        levels = divisor = 1;
        return node = new TreeNode(num,levels);
    }
    
    if (num < node->value)
        
        node->left = insert(num,node->left);
    
    if (num > node->value)
        
        node->right = insert(num, node->right);
    
    
    
    if(((nodes + 1.0) / divisor) == 2.0)
    {
        levels++;
        divisor = nodes + 1;
    }
    
    nodes++;
    return node;
    
}

//void STree::rmRoot(, TreeNode *)
//{

//}

//void STree::rmNTL(, TreeNode *)
//{

//}
//void STree::rmTL(, TreeNode *)
//{

//}

void STree::preOrder(std::ofstream& output, TreeNode *node)
{
	if (node != nullptr)
	{
		output << node->value << " ";
		preOrder(output, node->left);
		preOrder(output, node->right);
	}
}

void STree::inOrder(std::ofstream& output, TreeNode *node)
{
	if (node != nullptr)
	{
		inOrder(output, node->left);
		output << node->value << " ";
		inOrder(output, node->right);
	}
}

void STree::postOrder(std::ofstream& output, TreeNode *node)
{
	if (node != nullptr)
	{
		postOrder(output, node->left);
		postOrder(output, node->right);
		output << node->value << " ";
	}
}

bool STree::isBalanced(TreeNode *node)
{
    if (subTreeHeight(node->left) > subTreeHeight(node->right) + 2)
        
        return false;
    
    else
        
        return true;
    
}

#endif
