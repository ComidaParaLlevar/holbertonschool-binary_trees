#include "binary_trees.h"
/**
 * binary_tree_inorder - traverses in in-order to apply function
 * @tree: pointer to root node
 * @func: function to apply to value
 *
 * Return: nothing
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_preorder(tree->left, func);
	func(tree->n);
	binary_tree_preorder(tree->right, func);
}
