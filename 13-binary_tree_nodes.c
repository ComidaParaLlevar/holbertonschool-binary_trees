#include "binary_trees.h"

/**
* binary_tree_nodes - Counts how many nodes have childs
* @tree: Pointer to the node to measures the height
* Return: the number of parents
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t leaves_l = 0;
	size_t leaves_r = 0;
	
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		leaves_l = binary_tree_nodes(tree->left);
		leaves_r = binary_tree_nodes(tree->right);
		return (1 + leaves_l + leaves_r);
	}
	return (0);
}
