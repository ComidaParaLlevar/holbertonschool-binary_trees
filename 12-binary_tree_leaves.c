#include "binary_trees.h"

/**
* binary_tree_leaves - Counts how many leaves are in a tree
* @tree: Pointer to the node to measures the height
* Return: How many leaves are in the tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_l = 0;
	size_t leaves_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	leaves_l = tree->left ? binary_tree_leaves(tree->left) : 0;
	leaves_r = tree->right ? binary_tree_leaves(tree->right) : 0;

	return (leaves_r + leaves_l);
}
