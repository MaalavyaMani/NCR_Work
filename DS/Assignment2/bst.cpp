#include<iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class BST
{
	struct node *start;
public:
	BST();
	node* insert(int, node *);
	void delete_ele(int);
	void inorder();
	void preorder();
	void postorder();
	int findmax(node *);
	int findmin(node *);
	int height(node *);
	int noofleafnodes(node *);
	int noofnonleafnodes(node *);
	void printinorder(node *);
	void printpreorder(node *);
	void printpostorder(node *);
	~BST();
};
BST::BST()
{
	start = NULL;
	
}
int BST::noofleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(noofleafnodes(curr->left) + noofleafnodes(curr->right));
}
int BST::noofnonleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(noofnonleafnodes(curr->left) + noofnonleafnodes(curr->right)+1);
}
int BST::findmin(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
			curr = curr->left;
		return(curr->data);
	}
	else
		return -1;
}
int BST::findmax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return(curr->data);
	}
	else
		return -1;
}
int BST::height(struct node *curr)
{
	if (curr == NULL)
		return -1;
	else
		return(max(height(curr->left), height(curr->right)) + 1);
}
void BST::printinorder(struct node *curr)
{
	if (curr != NULL)
	{
		printinorder(curr->left);
		cout << curr->data;
		printinorder(curr->right);
	}
}
void BST::printpreorder(struct node *curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		printpreorder(curr->left);
		printpreorder(curr->right);
	}

}
void BST::printpostorder(struct node *curr)
{
	if (curr != NULL)
	{
		printpostorder(curr->left);
		printpostorder(curr->right);
		cout << curr->data;
	}
}
void BST::inorder()
{
	if (start != NULL)
		printinorder(start);
}
void BST::preorder()
{
	if (start != NULL)
		printpreorder(start);
}
void BST::postorder()
{
	if (start != NULL)
		printpostorder(start);
}