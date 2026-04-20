#ifndef HASH_DATA_ENCRYPTION_H
#define HASH_DATA_ENCRYPTION_H

#include <sodium.h>
#include <string>
#include <vector>

/**
 * @brief Hashes input data using the Argon2id algorithm.
 * This function utilizes libsodium to generate a secure, one-way hash.
 * Argon2id is the modern standard for password hashing, providing
 * resistance against GPU-based attacks and side-channel leakage.
 * 
 * @param data Reference to the plaintext string. It will be overwritten
 * with the resulting hash string on success.
 * @return int EXIT_SUCCESS (0) on success, or EXIT_FAILURE on error.
 */
int hashEncyptData(std::string& data);

#endif