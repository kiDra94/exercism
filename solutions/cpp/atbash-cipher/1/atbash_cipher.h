#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include<string>
namespace atbash_cipher {

// TODO: add your solution here
std::string encoding(std::string text);
std::string c(std::string text);
std::string plain{"abcdefghijklmnopqrstuvwxyz"};
std::string cipher{"zyxwvutsrqponmlkjihgfedcba"};
}  // namespace atbash_cipher

#endif  // ATBASH_CIPHER_H
