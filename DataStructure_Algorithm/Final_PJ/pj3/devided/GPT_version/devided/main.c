#include "huffman.h"
#include "tree.h"



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
