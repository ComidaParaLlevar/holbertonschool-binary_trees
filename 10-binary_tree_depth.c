#include "binary_trees.h"


/**
* binary_tree_depth - Measures the depth of a node
* @tree: Pointer to the node to measures the height
* Return: how far away the node is from the parent
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}
