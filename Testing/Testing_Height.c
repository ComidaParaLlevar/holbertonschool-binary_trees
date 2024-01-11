#include "binary_trees.h"


int main()
{	
	binary_tree_t *root;
	size_t height;
	
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);
	
	height = binary_tree_height(root);
	printf("Height from %d: %lu\n", root->n, height);
	height = binary_tree_height(root->right);
	printf("Height from %d: %lu\n", root->right->n, height);
	height = binary_tree_height(root->left->right);
	printf("Height from %d: %lu\n", root->left->right->n, height);
	return (0);
//	root = binary_tree_node(NULL, 19);
//	root->left = binary_tree_node(root, 15);
//	root->right = binary_tree_node(root, 30);
//	binary_tree_insert_left(root->left, 40);
//	binary_tree_insert_right(root->left, 80);
//	binary_tree_insert_right(root->right, 90);
//	binary_tree_insert_right(root->right->right, 37);
//	binary_tree_insert_left(root->right->right, 48);
//	binary_tree_insert_left(root->right->right->left, 20);
//
//	printf("%zu", _height(root));
	
}

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

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;
	
	if (!tree)
		return;
	height = binary_tree_height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
		{
			s[i] = malloc(sizeof(**s) * 255);
			if (!s[i])
				return;
			memset(s[i], 32, 255);
		}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
		{
			for (j = 254; j > 1; --j)
				{
					if (s[i][j] != ' ')
						break;
					s[i][j] = '\0';
				}
			printf("%s\n", s[i]);
			free(s[i]);
		}
	free(s);
}

int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6] = "";
	int width, left, right, is_left, i;
	
	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
		{
			for (i = 0; i < width + right; i++)
				s[depth - 1][offset + left + width / 2 + i] = '-';
			s[depth - 1][offset + left + width / 2] = '.';
		}
	else if (depth && !is_left)
		{
			for (i = 0; i < left + width; i++)
				s[depth - 1][offset - width / 2 + i] = '-';
			s[depth - 1][offset + left + width / 2] = '.';
		}
	return (left + width + right);
}