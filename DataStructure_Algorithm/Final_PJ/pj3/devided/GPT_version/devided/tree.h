#ifndef TREE_H
#define TREE_H

#define MAX_TREE_NODES 511

// Structure for a tree node in the Huffman tree
typedef struct TreeNode {
  int weight;
  int symbol;
  int parent;
  int left;
  int right;
} TreeNode;

// Structure for the Huffman tree
typedef struct HuffmanTree {
  TreeNode nodes[MAX_TREE_NODES];
  int num_nodes;
  int root;
} HuffmanTree;

// Initializes a Huffman tree with the given symbol and weight
void huffman_tree_init(HuffmanTree *tree, int symbol, int weight);

// Adds a new symbol to the Huffman tree with the given weight
void huffman_tree_add_symbol(HuffmanTree *tree, int symbol, int weight);

// Finds the node in the tree with the given symbol
int huffman_tree_find_node(const HuffmanTree *tree, int symbol);

// Updates the weight of the node with the given symbol in the tree
void huffman_tree_update_weight(HuffmanTree *tree, int symbol, int weight);

#endif
