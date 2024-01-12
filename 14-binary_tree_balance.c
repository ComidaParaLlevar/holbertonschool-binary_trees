#include "binary_trees.h"

/**
* binary_tree_balance - checks if it is balanced
* @tree: Pointer to the node to measures the height
* Return: how balanced it is.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t leaves_l = 0;
	size_t leaves_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->right != NULL)
	{
		leaves_l = binary_tree_balance(tree->left);
		leaves_r = binary_tree_balance(tree->right);
		return (-leaves_r + leaves_l);
	}
	if (tree->left == NULL && tree->right != NULL)
	{
		leaves_r = -1 + binary_tree_balance(tree->right);
		return (leaves_r);
	}
	if (tree->left != NULL && tree->right == NULL)
	{
		leaves_l = 1 + binary_tree_balance(tree->left);
		return (leaves_l);
	}

	return (0);
}
