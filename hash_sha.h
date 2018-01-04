#ifndef _HASH_SHA_H_
#define _HASH_SHA_H_
#include <crypto++/cryptlib.h>
#include <crypto++/sha.h>
#include <crypto++/hex.h>
#include <iostream>

using namespace std;

string SHA256(string);
string calculate_sha(string);

#endif
