#include "binary_trees.h"
/**
 * binary_tree_sibling - find current node's sibling
 * @node: current node
 *
 * Return: sibling of current node or NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);
}
