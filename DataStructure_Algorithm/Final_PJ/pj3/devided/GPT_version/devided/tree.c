#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Initializes a Huffman tree with the given symbol and weight
void huffman_tree_init(HuffmanTree *tree, int symbol, int weight) {
  tree->num_nodes = 1;
  tree->root = 0;
  tree->nodes[0].weight = weight;
  tree->nodes[0].symbol = symbol;
  tree->nodes[0].parent = -1;
  tree->nodes[0].left = -1;
  tree->nodes[0].right = -1;
}

// Adds a new symbol to the Huffman tree with the given weight
void huffman_tree_add_symbol(HuffmanTree *tree, int symbol, int weight) {
  // Find the node with the smallest weight
  int min_weight_node = -1;
  for (int i = 0; i < tree->num_nodes; i++) {
    if (tree->nodes[i].weight < tree->nodes[min_weight_node].weight || min_weight_node == -1) {
      min_weight_node = i;
    }
  }

  // Create a new internal node with the sum of the weights of the two smallest nodes
  int new_node_index = tree->num_nodes++;
  tree->nodes[new_node_index].weight = tree->nodes[min_weight_node].weight + weight;
  tree->nodes[new_node_index].symbol = -1;
  tree->nodes[new_node_index].parent = -1;
  tree->nodes[new_node_index].left = min_weight_node;
  tree->nodes[new_node_index].right = tree->num_nodes;

  // Create a new leaf node for the new symbol
  tree->nodes[tree->num_nodes].weight = weight;
  tree->nodes[tree->num_nodes].symbol = symbol;
  tree->nodes[tree->num_nodes].parent = new_node_index;
  tree->nodes[tree->num_nodes].left = -1;
  tree->nodes[tree->num_nodes].right = -1;

  // Update the parent of the two smallest nodes to point to the new internal node
  tree->nodes[min_weight_node].parent = new_node_index;
  tree->nodes[tree->num_nodes].parent = new_node_index;

  // Update the root of the tree to point to the new internal node
  tree->root = new_node_index;
}

// Finds the node in the tree with the given symbol
int huffman_tree_find_node(const HuffmanTree *tree, int symbol) {
  // Traverse the tree to find the node with the given symbol
  int cur_node = tree->root;
  while (cur_node >= 0) {
    if (tree->nodes[cur_node].symbol == symbol) {
      return cur_node;
    }
    cur_node = (symbol < tree->nodes[cur_node].symbol) ? tree->nodes[cur_node].left : tree->nodes[cur_node].right;
  }
  return -1;
}

// Updates the weight of the node with the given symbol in the tree
void huffman_tree_update_weight(HuffmanTree *tree, int symbol, int weight) {
  // Find the node with the given symbol
  int node = huffman_tree_find_node(tree, symbol);
  if (node < 0) {
    return;
  }

  // Update the weight of the node
  tree->nodes[node].weight = weight;

  // Check if the parent needs to be updated
  while (tree->nodes[node].parent >= 0) {
    int parent = tree->nodes[node].parent;
    if (tree->nodes[parent].left == node || tree->nodes[parent].right == node) {
      // Update the weight of the parent
      tree->nodes[parent].weight = tree->nodes[tree->nodes[parent].left].weight + tree->nodes[tree->nodes[parent].right].weight;

      // Move up to the next node
      node = parent;
    } else {
      break;
    }
  }
}

