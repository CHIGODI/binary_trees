#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_balance -  a function that measures the balance
 *                        factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: balance factor
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0, balance_factor;

	if (tree && tree->left)
		height_l = 1 + binary_tree_balance(tree->left);

	if (tree && tree->right)
		height_r = 1 + binary_tree_balance(tree->right);

	balance_factor = height_l - height_r;

	return (balance_factor);
}
