#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to root node of tree to delete
 *
 * Return: Nothing!
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/** post-order traversal **/
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
