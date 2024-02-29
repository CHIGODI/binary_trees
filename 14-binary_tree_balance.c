#include "binary_trees.h"
/**
 * find_height - determine the height of a binary tree
 * @tree: pointer to root node
 * Return: height of the binary tree
 */
size_t find_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = find_height(tree->left);
	height_r = find_height(tree->right);

	return ((height_l > height_r ? height_l : height_r) + 1);
}

/**
 * binary_tree_balance - checks the distribution of nodes
 * between left and righ branches
 * @tree: pointer to the node of interest
 * Return: the balance (left nodes - right nodes)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (find_height(tree->left) - find_height(tree->right));
}
