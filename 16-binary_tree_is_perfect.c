#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: A pointer to the root of the tree.
* Return: 1 if the binary tree is perfect, 0 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (!tree)
return (0);

if (binary_tree_is_full(tree) == 1 && binary_tree_balance(tree) == 0)
return (1);

return (0);
}

/**
* binary_tree_is_full - Checks if a binary tree is full.
* @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is full, 0 otherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
if (!tree)
return (0);

if (!tree->left && !tree->right)
return (1);

if (tree->left && tree->right)
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

return (0);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree.
* @tree: A pointer to the root node to calculate the balance factor.
* Return: The balance factor of the tree.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;

if (!tree)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (left_height - right_height);
}

/**
* binary_tree_height - Gets the height of a binary tree.
* @tree: The root node to draw height from for the tree.
* Return: The height of the tree, 0 on failure or NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_size = 0;
size_t right_size = 0;

if (!tree)
return (0);

left_size += 1 + binary_tree_height(tree->left);
right_size += 1 + binary_tree_height(tree->right);

if (left_size > right_size)
return (left_size);

return (right_size);
}

