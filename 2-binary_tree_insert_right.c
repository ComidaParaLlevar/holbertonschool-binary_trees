#include "binary_trees.h"
/**
 * binary_tree_insert_right - Insert node at right child of a node
 * @parent: pointer to node to inser child node
 * @value: data value of node
 *
 * Return: Pointer to created node, NULL if failure
*/
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
