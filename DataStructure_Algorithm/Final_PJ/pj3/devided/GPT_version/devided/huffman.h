#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "tree.h"

// Structure for storing the Huffman code for a symbol
typedef struct HuffmanCode {
  int code;
  int len;
} HuffmanCode;

// Generates the Huffman codes for each symbol in the tree
void huffman_tree_generate_codes(const HuffmanTree *tree, HuffmanCode codes[]);

// Encodes the given message using the Huffman codes
void huffman_encode(const HuffmanCode codes[], const unsigned char *message, int len, unsigned char *encoded_message);

// Decodes the given encoded message using the Huffman codes
void huffman_decode(const HuffmanTree *tree, const unsigned char *encoded_message, int len, unsigned char *decoded_message);

#endif
