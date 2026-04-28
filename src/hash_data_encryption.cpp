#include <sodium.h>
#include <string>
#include <cstdlib>
#include <iostream>

int hashEncyptData(std::string& data)
{
    // Initialize libsodium - required once per process to set up 
    // CPU-specific optimizations and seed the random number generator.
    if ( sodium_init() < 0 )
    {
        std::cerr << "ERROR : LIBSODIUM FAILED TO INITIALIZE.\n";
        return EXIT_FAILURE;
    }

    // Fixed-size buffer for the Argon2id hash string output.
    // crypto_pwhash_STRBYTES ensures enough space for the salt and parameters.
    char hashedPassword[crypto_pwhash_STRBYTES];

    // Compute the hash using Argon2id.
    // OPSLIMIT_INTERACTIVE and MEMLIMIT_INTERACTIVE are used for 
    // a balance of high security and acceptable latency for users.
    if ( crypto_pwhash_str(
        hashedPassword,
        data.c_str(),
        data.length(),
        crypto_pwhash_OPSLIMIT_INTERACTIVE,
        crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0 )
    {
        std::cerr << "Out of memory or error hashing password." << std::endl;
        return EXIT_FAILURE;
    }

    // Clear the sensitive plaintext from the string object.
    data = "";

    // Reconstruct the 'data' string by appending the characters 
    // from the hashed C-string buffer.
    for ( char ch : hashedPassword )
    {
        data += ch;
    }

    return EXIT_SUCCESS;
}