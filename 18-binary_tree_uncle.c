#include "binary_trees.h"
/**
 * binary_tree_uncle - find current node's sibling
 * @node: current node
 *
 * Return: uncle of current node or NULL
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent)
		return (NULL);

	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);
	else
		return (node->parent->parent->right);
}
