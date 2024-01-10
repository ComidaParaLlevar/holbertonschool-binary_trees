#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses in pre-order to apply function
 * @tree: pointer to root node
 * @func: function to apply to value
 * 
 * Return: nothing
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
