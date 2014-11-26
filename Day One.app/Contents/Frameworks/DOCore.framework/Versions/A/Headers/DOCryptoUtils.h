//
//  DOCryptoUtils.h
//  DayOne
//
//  Created by Ben Dolman on 3/22/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

// An implementation of the OpenSSL equivalent using only CommonCrypto
int PKCS5_PBKDF2_HMAC_SHA1(const char *pass, int passlen,
						   const unsigned char *salt, int saltlen, int iter,
						   int keylen, unsigned char *out);