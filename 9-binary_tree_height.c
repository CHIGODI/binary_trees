#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	right = binary_tree_height(tree->right);
	left = binary_tree_height(tree->left);

	return ((right > left ? right : left) + 1);
}
