#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if the tree is perfect
* @tree: Pointer to the node to measures the height
* Return: 1 or 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int expectedDepth = binary_tree_depth(tree);
	bool check = isPerfect(tree, expectedDepth);

	return (check);
}

/**
* find_depth_left - Measures the depth of a node
* @tree: Pointer to the node to measures the height
* Return: how far away the node is from the parent
*/
int find_depth_left(const binary_tree_t *tree)
{
	return !tree ? 0 : 1 + find_depth_left(tree->left);
}


/**
* isPerfect - checks if it is perfect
* @tree: Pointer to the node to measures the height
* @Depth: the depth of the node
* Return: how far away the node is from the parent
*/
bool isPerfect(const binary_tree_t *tree, int Depth)
{
	bool check;

	if (tree == NULL)
		return (0);

	if (!tree->left != !tree->right)
		return (false);
	check = Depth >= 0 &&
	isPerfect(tree->left, Depth - 1l) &&
	isPerfect(tree->right, Depth - 1);
	return (check);
}
