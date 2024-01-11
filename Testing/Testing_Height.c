#include "binary_trees.h"

static size_t _height(const binary_tree_t *tree);

int main()
{
	binary_tree_t *root;
	
	root = binary_tree_node(NULL, 19);
	root->left = binary_tree_node(root, 15);
	root->right = binary_tree_node(root, 30);
	binary_tree_insert_left(root->left, 40);
	binary_tree_insert_right(root->left, 80);
	binary_tree_insert_right(root->right, 90);
	binary_tree_insert_right(root->right->right, 37);
	binary_tree_insert_left(root->right->right, 48);
	binary_tree_insert_left(root->right->right->left, 20);

	printf("%zu", _height(root));
	
}

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	
	/*Create space in memory for node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	
	/*Connect node to binary tree and add value*/
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return (new_node);
}

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node = NULL;
	
	if (parent == NULL)
		return (NULL);
	
	/* make space in memory for left node*/
	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);
	
	right_node->n = value;
	right_node->parent = parent;
	right_node->left = NULL;
	right_node->right = NULL;
	
	if (parent->right != NULL)
		{
			right_node->right = parent->right;
			parent->right->parent = right_node;
		}
	
	parent->right = right_node;
	return (right_node);
}

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node = NULL;
	
	if (parent == NULL)
		return (NULL);
	
	/* make space in memory for left node*/
	left_node = malloc(sizeof(binary_tree_t));
	if (left_node == NULL)
		return (NULL);
	
	left_node->n = value;
	left_node->parent = parent;
	left_node->left = NULL;
	left_node->right = NULL;
	
	if (parent->left != NULL)
		{
			left_node->left = parent->left;
			parent->left->parent = left_node;
		}
	
	parent->left = left_node;
	return (left_node);
}

static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	
	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}