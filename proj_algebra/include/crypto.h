/*
 * File： crypto.cpp
 * ----------------------------------------------------
 * This file serves as a cryptography library, designed for handling RSA encryption, signing and
 * verification, as well as Base64 encoding and decoding.
 */

#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <assert.h>

namespace crypto
{

    /* Function: createPrivateRSA
     * ----------------------------------------------------
     * Creates an RSA private key from a given string.
     *
     * Parameters:
     *   key - A string representation of the RSA private key.
     *
     * Returns:
     *   A pointer to an RSA structure representing the private key.
     */
    RSA *createPrivateRSA(std::string key);

    /* Function: createPublicRSA
     * ----------------------------------------------------
     * Creates an RSA public key from a given string.
     *
     * Parameters:
     *   key - A string representation of the RSA public key.
     *
     * Returns:
     *   A pointer to an RSA structure representing the public key.
     */
    RSA *createPublicRSA(std::string key);

    /* Function: RSASign
     * ----------------------------------------------------
     * Signs a message using RSA private key.
     *
     * Parameters:
     *   rsa - RSA private key.
     *   Msg - The message to be signed.
     *   MsgLen - The length of the message.
     *   EncMsg - Pointer to store the encrypted message.
     *   MsgLenEnc - Pointer to store the length of the encrypted message.
     *
     * Returns:
     *   True if signing is successful, false otherwise.
     */
    bool crypto::RSASign(RSA *rsa,
                     const unsigned char *Msg,
                     size_t MsgLen,
                     unsigned char **EncMsg,
                     size_t *MsgLenEnc)

    /* Function: RSAVerifySignature
     * ----------------------------------------------------
     * Verifies a signature against a message using RSA public key.
     *
     * Parameters:
     *   rsa - RSA public key.
     *   MsgHash - The hashed message.
     *   MsgHashLen - Length of the hashed message.
     *   Msg - The original message.
     *   MsgLen - Length of the original message.
     *   Authentic - Pointer to store the result of verification.
     *
     * Returns:
     *   True if verification is successful, false otherwise.
     */
    bool crypto::RSAVerifySignature(RSA *rsa,
                                unsigned char *MsgHash,
                                size_t MsgHashLen,
                                const char *Msg,
                                size_t MsgLen,
                                bool *Authentic)

    /* Function: Base64Encode
     * ----------------------------------------------------
     * Encodes binary data into a Base64 string.
     *
     * Parameters:
     *   buffer - Binary data to be encoded.
     *   length - Length of the binary data.
     *   base64Text - Pointer to store the encoded Base64 string.
     */
    void crypto::Base64Encode(const unsigned char *buffer,
                          size_t length,
                          char **base64Text)

    /* Function: calcDecodeLength
     * ----------------------------------------------------
     * Calculates the length of a Base64 decoded string.
     *
     * Parameters:
     *   b64input - Base64 encoded string.
     *
     * Returns:
     *   The length of the decoded string.
     */
    size_t calcDecodeLength(const char *b64input);

    /* Function: Base64Decode
     * ----------------------------------------------------
     * Decodes a Base64 encoded string into binary data.
     *
     * Parameters:
     *   b64message - Base64 encoded string.
     *   buffer - Pointer to store the decoded binary data.
     *   length - Pointer to store the length of the decoded data.
     */
    void Base64Decode(const char *b64message, unsigned char **buffer, size_t *length);

    /* Function: signMessage
     * ----------------------------------------------------
     * Signs a plaintext message using a private key.
     *
     * Parameters:
     *   privateKey - The RSA private key as a string.
     *   plainText - The plaintext message to sign.
     *
     * Returns:
     *   The signed message as a Base64 encoded string.
     */
    std::string signMessage(std::string privateKey, std::string plainText);

    /* Function: verifySignature
     * ----------------------------------------------------
     * Verifies a signed message using a public key.
     *
     * Parameters:
     *   publicKey - The RSA public key as a string.
     *   plainText - The original plaintext message.
     *   signatureBase64 - The Base64 encoded signature to verify.
     *
     * Returns:
     *   True if the signature is valid, false otherwise.
     */
    bool verifySignature(std::string publicKey, std::string plainText, std::string signatureBase64);

    /* Function: keyFromRSA
     * ----------------------------------------------------
     * Extracts a key as a string from an RSA structure.
     *
     * Parameters:
     *   rsa - The RSA structure.
     *   isPrivate - True if the key is private, false for public key.
     *
     * Returns:
     *   The key as a string.
     */
    const char *keyFromRSA(RSA *rsa, bool isPrivate);

    /* Function: generate_key
     * ----------------------------------------------------
     * Generates a pair of RSA public and private keys.
     *
     * Parameters:
     *   public_key - String to store the generated public key.
     *   private_key - String to store the generated private key.
     */
    void generate_key(std::string &public_key, std::string &private_key);

    /* Function: sha256
     * ----------------------------------------------------
     * Computes the SHA256 hash of a string.
     *
     * Parameters:
     *   s - The string to hash.
     *
     * Returns:
     *   The SHA256 hash as a hexadecimal string.
     */
    std::string sha256(std::string s);

}
#endif // CRYPTO_H