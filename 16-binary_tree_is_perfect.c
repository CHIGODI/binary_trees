#include "binary_trees.h"
/**
 * find_height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Height, NULL otherwise
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
 * find_size - Calculates the size of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Size, If tree is NULL, returns 0.
 */
size_t find_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + find_size(tree->left) + find_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height, max_size;

	if (tree == NULL)
		return (0);

	size = find_size(tree);
	height = find_height(tree);

	/** a perfect binary tree max_size = 2^(h+1)-1*/
	max_size = (1 << height) - 1;
	return (size == max_size);
}
