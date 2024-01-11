#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	
	if (tree == NULL)
		return (0);
	
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l + height_r + 1);
}
