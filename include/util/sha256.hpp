#include "sha2.hpp"
#include <sha3.hpp>

inline std::string sha256(std::string text) {
    return digestpp::sha256().absorb(text).hexdigest();
}