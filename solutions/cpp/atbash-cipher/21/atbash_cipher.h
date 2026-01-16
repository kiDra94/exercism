#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include<string>
namespace atbash_cipher {

std::string encode(std::string text);
std::string decode(std::string text);
std::string atbash_logic(std::string text, bool is_encode);

}  // namespace atbash_cipher

#endif  // ATBASH_CIPHER_H
