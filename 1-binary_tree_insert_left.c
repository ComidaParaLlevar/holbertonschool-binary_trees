#include "binary_trees.h"
/**
 * binary_tree_insert_left - Insert node at left child of a node
 * @parent: pointer to node to inser child node
 * @value: data value of node
 *
 * Return: Pointer to created node, NULL if failure
*/
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
