#include <stdio.h>
#include "huffman.h"

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
    // Move to the left child if thecurrent bit is 0, or to the right child if the current bit is 1
    cur_node = (encoded_message[i] == 0) ? tree->nodes[cur_node].left : tree->nodes[cur_node].right;

    // If the current node is a leaf, add the symbol to the decoded message and go back to the root
    if (tree->nodes[cur_node].symbol >= 0) {
      decoded_message[decoded_len++] = tree->nodes[cur_node].symbol;
      cur_node = tree->root;
    }
  }
}

