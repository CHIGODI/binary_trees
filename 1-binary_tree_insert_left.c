#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_insert_left - inserts a node as the left-child of
 *                           another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return:  a pointer to the created node, or NULL on failure or
 *          if parent is NULL
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (parent == NULL)
		return (NULL);

	left_node = malloc(sizeof(binary_tree_t));
	if (left_node == NULL)
		return (NULL);

	left_node->n = value;
	left_node->parent = parent;
	left_node->left = parent->left;

	if (parent->left != NULL)
		parent->left->parent = left_node;

	parent->left = left_node;
	left_node->right = NULL;

	return (left_node);
}
