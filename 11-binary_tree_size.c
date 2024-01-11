#include "binary_trees.h"

/**
* binary_tree_size - Measures the size of a node
* @tree: Pointer to the node to measures the height
* Return: How many nodes are in the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	size_t totalSize;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? binary_tree_size(tree->left) : 0;
	height_r = tree->right ? binary_tree_size(tree->right) : 0;
	totalSize = height_l + height_r;
	return (totalSize + 1);
}
