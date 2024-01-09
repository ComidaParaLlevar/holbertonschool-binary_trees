#include "binary_trees.h"
/**
 * binary_tree_node - creates node for binary tree
 * @parent: ponter to parent of new node
 * @value: data value in new node
 * 
 * Return: Pointer to new node, NULL if failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /*Create space in memory for node*/
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /*Connect node to binary tree and add value*/
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}