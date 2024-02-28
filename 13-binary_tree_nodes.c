#include "binary_trees.h"
/**
 * binary_tree_nodes - a function that counts the nodes with at least 1
 *                    child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: count
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_subtree = 0, right_subtree = 0;

	if (tree == NULL)
		return (0);

	left_subtree = binary_tree_nodes(tree->left);
	right_subtree = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (left_subtree + right_subtree + 1);

	return (left_subtree + right_subtree);
}
