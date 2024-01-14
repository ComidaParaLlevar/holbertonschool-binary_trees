#include "binary_trees.h"

/**
* binary_tree_height - Measures the height to the left
* @tree: Pointer to the root node of the tree to measure the height
* Return: Height of the tree. If tree is NULL, return 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}


/**
* is_perfect_recursive - Helper function to check if tree is perfect
* @tree: Pointer to the root node of the tree
* @d: Depth of the tree
* @level: Current level in the tree
*
* Return: 1 if tree is perfect, 0 otherwise
*/
int is_perfect_recursive(const binary_tree_t *tree, size_t d, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, d, level + 1) &&
	is_perfect_recursive(tree->right, d, level + 1));
}


/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if tree is perfect, 0 otherwise. If tree is NULL, return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);

	d = binary_tree_height(tree);

	return (is_perfect_recursive(tree, d, 0));
}
