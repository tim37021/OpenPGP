/*
encrypt.h
Function to encrypt data with a PGP public key

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto at gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __PGPENCRYPT__
#define __PGPENCRYPT__

#include <stdexcept>
#include <string>
#include <vector>

#include "Compress/Compress.h"
#include "Hashes/Hashes.h"
#include "PKA/PKAs.h"
#include "cfb.h"
#include "mpi.h"
#include "PGPKey.h"
#include "PGPMessage.h"
#include "PKCS1.h"
#include "revoke.h"

// used internally
Tag6::Ptr find_encrypting_key(const PGP & k);

PKA::Values pka_encrypt(const uint8_t pka,
                        const PGPMPI & data,
                        const PKA::Values & pub);

PKA::Values pka_encrypt(const uint8_t pka,
                        const std::string & data,
                        const PKA::Values & pub);

Packet::Ptr encrypt_data(const std::string & session_key,
                         const std::string & data,
                         const std::string & filename = "",
                         const uint8_t sym_alg = Sym::ID::AES256,
                         const uint8_t comp = Compression::Algorithm::ZIP,
                         const bool mdc = true,
                         const PGPSecretKey::Ptr & signer = nullptr,
                         const std::string & sig_passphrase = "");

// Encrypt data
// Default:
//      Symmetric Key Algorithm: AES256
//      Compression Algorithm: ZLIB
//      Use Modification Detection Packet: true
PGPMessage encrypt_pka(const PGPPublicKey & pub,
                       const std::string & data,
                       const std::string & filename = "",
                       const uint8_t sym_alg = Sym::ID::AES256,
                       const uint8_t comp = Compression::Algorithm::ZLIB,
                       const bool mdc = true,
                       const PGPSecretKey::Ptr & signer = nullptr,
                       const std::string & sig_passphrase = "");

PGPMessage encrypt_sym(const std::string & passphrase,
                       const std::string & data,
                       const std::string & filename = "",
                       const uint8_t sym_alg = Sym::ID::AES256,
                       const uint8_t comp = Compression::Algorithm::ZLIB,
                       const bool mdc = true,
                       const PGPSecretKey::Ptr & signer = nullptr,
                       const std::string & sig_passphrase = "");

#endif
