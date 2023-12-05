#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree after rotation
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);
	tmp = tree->left;
	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->left->right;
	if (tmp->right)
		tmp->right->parent = tree;
	tmp->right = tree;
	return (tree->parent);
}
