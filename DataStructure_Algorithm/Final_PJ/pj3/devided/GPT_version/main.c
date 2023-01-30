#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Structure for storing the Huffman code for a symbol
typedef struct HuffmanCode {
  int code;
  int len;
} HuffmanCode;

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

// Generates the Huffman codes for each symbol in the tree
void huffman_tree_generate_codes(const HuffmanTree *tree, HuffmanCode codes[]) {
  int stack[MAX_TREE_NODES];
  int top = -1;

  // Start at the root of the tree and traverse to the leaves
  int cur_node = tree->root;
  while (cur_node >= 0) {
    // If the current node is a leaf, store the code for the symbol
    if (tree->nodes[cur_node].symbol >= 0) {
      codes[tree->nodes[cur_node].symbol].code = 0;
      codes[tree->nodes[cur_node].symbol].len = top + 1;
      for (int i = 0; i <= top; i++) {
        codes[tree->nodes[cur_node].symbol].code = (codes[tree->nodes[cur_node].symbol].code << 1) | stack[i];
      }
    }

    // Push the direction to the left child onto the stack and move to the left child
    stack[++top] = 0;
    cur_node = tree->nodes[cur_node].left;

    // If the current node has no left child, pop a direction from the stack and move to the right child
    while (cur_node < 0 && top >= 0) {
      cur_node = tree->nodes[tree->nodes[cur_node].parent].right;
      --top;
    }
  }
}

// Encodes the given message using the Huffman codes
void huffman_encode(const HuffmanCode codes[], const unsigned char *message, int len, unsigned char *encoded_message) {
  int encoded_len = 0;
  for (int i = 0; i < len; i++) {
    int symbol = message[i];
    for (int j = 0; j < codes[symbol].len; j++) {
      encoded_message[encoded_len++] = (codes[symbol].code >> (codes[symbol].len - j - 1)) & 1;
    }
  }
}

// Decodes the given encoded message using the Huffman codes
void huffman_decode(const HuffmanTree *tree, const unsigned char *encoded_message, int len, unsigned char *decoded_message) {
  int decoded_len = 0;
  int cur_node = tree->root;
  for (int i = 0; i < len; i++) {
    // Move to the left child if the next bit is 0, or the right child if it is 1
    cur_node = (encoded_message[i] == 0) ? tree->nodes[cur_node].left : tree->nodes[cur_node].right;

    // If the current node is a leaf, store the symbol and move back to the root of the tree
    if (tree->nodes[cur_node].symbol >= 0) {
      decoded_message[decoded_len++] = tree->nodes[cur_node].symbol;
      cur_node = tree->root;
    }
  }
}

int main(int argc, char **argv) {
  // Initialize the Huffman tree with the symbol 'A' and weight 1
  HuffmanTree tree;
  huffman_tree_init(&tree, 'A', 1);

  // Add the other symbols to the tree with their respective weights
  huffman_tree_add_symbol(&tree, 'B', 2);
  huffman_tree_add_symbol(&tree, 'C', 3);
  huffman_tree_add_symbol(&tree, 'D', 4);
  huffman_tree_add_symbol(&tree, 'E', 5);
  huffman_tree_add_symbol(&tree, 'F', 6);

  // Generate the Huffman codes for each symbol
  HuffmanCode codes[256];
  huffman_tree_generate_codes(&tree, codes);

  // Encode the message "ACBFEDCBA" using the Huffman codes
  unsigned char message[] = {'A', 'C', 'B', 'F', 'E', 'D', 'C', 'B', 'A'};
  unsigned char encoded_message[256];
  huffman_encode(codes, message, 9, encoded_message);

  // Decode the encoded message using the Huffman tree
  unsigned char decoded_message[256];
  huffman_decode(&tree, encoded_message, 18, decoded_message);

  // Print the original message and the decoded message to check that they are the same
  printf("Original message: %s\n", message);
  printf("Decoded message: %s\n", decoded_message);

  return 0;
}


