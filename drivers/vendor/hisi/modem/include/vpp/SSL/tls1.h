/* ssl/tls1.h */
/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  All rights reserved.
 
  This package is an SSL implementation written
  by Eric Young (eay@cryptsoft.com).
  The implementation was written so as to conform with Netscapes SSL.
  
  This library is free for commercial and non-commercial use as long as
  the following conditions are aheared to.  The following conditions
  apply to all code found in this distribution, be it the RC4, RSA,
  lhash, DES, etc., code; not just the SSL code.  The SSL documentation
  included with this distribution is covered by the same copyright terms
  except that the holder is Tim Hudson (tjh@cryptsoft.com).
  
  Copyright remains Eric Young's, and as such any Copyright notices in
  the code are not to be removed.
  If this package is used in a product, Eric Young should be given attribution
  as the author of the parts of the library used.
  This can be in the form of a textual message at program startup or
  in documentation (online or textual) provided with the package.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
  3. All advertising materials mentioning features or use of this software
     must display the following acknowledgement:
     "This product includes cryptographic software written by
      Eric Young (eay@cryptsoft.com)"
     The word 'cryptographic' can be left out if the rouines from the library
     being used are not cryptographic related :-).
  4. If you include any Windows specific code (or a derivative thereof) from 
     the apps directory (application code) you must include an acknowledgement:
     "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
  
  THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.
  
  The licence and distribution terms for any publically available version or
  derivative of this code cannot be changed.  i.e. this code cannot simply be
  copied and put under another distribution licence
  [including the GNU Public Licence.]
 */
/* ====================================================================
  Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 
  Portions of the attached software ("Contribution") are developed by 
  SUN MICROSYSTEMS, INC., and are contributed to the OpenSSL project.
 
  The Contribution is licensed pursuant to the OpenSSL open source
  license provided above.
 
  ECC cipher suite support in OpenSSL originally written by
  Vipul Gupta and Sumit Gupta of Sun Microsystems Laboratories.
 
 */

#include "ipsi_ssl_build_conf.h"

#ifndef _IPSI_HEADER_TLS1_H 
#define _IPSI_HEADER_TLS1_H 


/*
  TODO: have to add includes - jb
 */

#include "ipsi_types.h"
#include "sec_sys.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define tls1_PRF IPSI_tls1_PRF


#define TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES	1

#define TLS1_VERSION			0x0301
#define TLS1_VERSION_MAJOR		0x03
#define TLS1_VERSION_MINOR		0x01

#define IPSI_TLS_MAX_VERSION    TLS12_VERSION


#define TLS1_AD_DECRYPTION_FAILED	21
#define TLS1_AD_RECORD_OVERFLOW		22
#define TLS1_AD_UNKNOWN_CA		48	/* fatal */
#define TLS1_AD_ACCESS_DENIED		49	/* fatal */
#define TLS1_AD_DECODE_ERROR		50	/* fatal */
#define TLS1_AD_DECRYPT_ERROR		51
#define TLS1_AD_EXPORT_RESTRICTION	60	/* fatal */
#define TLS1_AD_PROTOCOL_VERSION	70	/* fatal */
#define TLS1_AD_INSUFFICIENT_SECURITY	71	/* fatal */
#define TLS1_AD_INTERNAL_ERROR		80	/* fatal */
#define TLS1_AD_INAPPROPRIATE_FALLBACK  86  /* fatal */
#define TLS1_AD_USER_CANCELLED		90
#define TLS1_AD_NO_RENEGOTIATION	100

#if (!defined(SSL_NO_PSK) || !defined(SSL_NO_DH_PSK))
#define TLS1_AD_UNKNOWN_PSK_IDENTITY 115 /*fatal*/
#endif

/* 
  Below given are the ids of cipher suites supported for tls1.
  The corresponding ids which can be found in rfc2246
  are given alongside.
 */
#define TLS1_CK_RSA_NULL_MD5			0x03000001			/*TLS_RSA_WITH_NULL_MD5              */
#define TLS1_CK_RSA_NULL_SHA			0x03000002			/*TLS_RSA_WITH_NULL_SHA              */
#define TLS1_CK_RSA_RC4_40_MD5 			0x03000003			/*TLS_RSA_EXPORT_WITH_RC4_40_MD5     */
#define TLS1_CK_RSA_RC4_128_MD5			0x03000004			/*TLS_RSA_WITH_RC4_128_MD5           */
#define TLS1_CK_RSA_RC4_128_SHA			0x03000005			/*TLS_RSA_WITH_RC4_128_SHA           */
#define TLS1_CK_RSA_DES_40_CBC_SHA		0x03000008			/*TLS_RSA_EXPORT_WITH_DES40_CBC_SHA  */
#define TLS1_CK_RSA_DES_64_CBC_SHA		0x03000009			/*TLS_RSA_WITH_DES_CBC_SHA           */
#define TLS1_CK_RSA_DES_192_CBC3_SHA		0x0300000A		/*TLS_RSA_WITH_3DES_EDE_CBC_SHA      */

#define TLS1_CK_EDH_DSS_DES_40_CBC_SHA		0x03000011		/*TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA  */
#define TLS1_CK_EDH_DSS_DES_64_CBC_SHA		0x03000012		/*TLS_DHE_DSS_WITH_DES_CBC_SHA           */
#define TLS1_CK_EDH_DSS_DES_192_CBC3_SHA	0x03000013		/*TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA      */
#define TLS1_CK_EDH_RSA_DES_40_CBC_SHA		0x03000014		/*TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA  */
#define TLS1_CK_EDH_RSA_DES_64_CBC_SHA		0x03000015		/*TLS_DHE_RSA_WITH_DES_CBC_SHA           */
#define TLS1_CK_EDH_RSA_DES_192_CBC3_SHA	0x03000016		/*TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA      */

#define TLS1_CK_ADH_RC4_40_MD5			0x03000017			/*TLS_DH_anon_EXPORT_WITH_RC4_40_MD5     */
#define TLS1_CK_ADH_RC4_128_MD5			0x03000018			/*TLS_DH_anon_WITH_RC4_128_MD5           */
#define TLS1_CK_ADH_DES_40_CBC_SHA		0x03000019			/*TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA  */
#define TLS1_CK_ADH_DES_64_CBC_SHA		0x0300001A			/*TLS_DH_anon_WITH_DES_CBC_SHA           */
#define TLS1_CK_ADH_DES_192_CBC3_SHA		0x0300001B			/*TLS_DH_anon_WITH_3DES_EDE_CBC_SHA      */


/* AES ciphersuites from RFC3268 */

#define TLS1_CK_RSA_WITH_AES_128_SHA			0x0300002F	/*TLS_RSA_WITH_AES_128_CBC_SHA     */
#define TLS1_CK_DHE_DSS_WITH_AES_128_SHA		0x03000032	/*TLS_DHE_DSS_WITH_AES_128_CBC_SHA */
#define TLS1_CK_DHE_RSA_WITH_AES_128_SHA		0x03000033	/*TLS_DHE_RSA_WITH_AES_128_CBC_SHA */
#define TLS1_CK_ADH_WITH_AES_128_SHA			0x03000034	/*TLS_DH_anon_WITH_AES_128_CBC_SHA */

#define TLS1_CK_RSA_WITH_AES_256_SHA			0x03000035	/*TLS_RSA_WITH_AES_256_CBC_SHA    */
#define TLS1_CK_DHE_DSS_WITH_AES_256_SHA		0x03000038	/*TLS_DHE_DSS_WITH_AES_256_CBC_SHA*/
#define TLS1_CK_DHE_RSA_WITH_AES_256_SHA		0x03000039	/*TLS_DHE_RSA_WITH_AES_256_CBC_SHA*/
#define TLS1_CK_ADH_WITH_AES_256_SHA			0x0300003A	/*TLS_DH_anon_WITH_AES_256_CBC_SHA*/

/* PSK ciphersuites from RFC 4279 */
#ifndef SSL_NO_PSK
#define TLS1_CK_PSK_NULL_SHA      0x0300002c  /*TLS_PSK_WITH_NULL_SHA*/ 
#define TLS1_CK_PSK_RC4_128_SHA  0x0300008A   /*TLS_PSK_WITH_RC4_128_SHA*/
#define TLS1_CK_PSK_3DES_EDE_CBC_SHA 0x0300008B  /*TLS_PSK_WITH_3DES_EDE_CBC_SHA*/
#define TLS1_CK_PSK_AES_128_CBC_SHA 0x0300008C  /*T LS_PSK_WITH_AES_128_CBC_SHA*/
#define TLS1_CK_PSK_AES_256_CBC_SHA 0x0300008D  /*	TLS_PSK_WITH_AES_256_CBC_SHA*/
#endif

#ifndef SSL_NO_DH_PSK
#define TLS1_CK_DHE_PSK_NULL_SHA 0x0300002D  /*TLS_DHE_PSK_WITH_NULL_SHA*/
#define TLS1_CK_DHE_PSK_RC4_128_SHA 0x0300008E  /*	TLS_DHE_PSK_WITH_RC4_128_SHA  */
#define TLS1_CK_DHE_PSK_3DES_EDE_CBC_SHA 0x0300008F  /*TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA */
#define TLS1_CK_DHE_PSK_AES_128_CBC_SHA  0x03000090 /*TLS_DHE_PSK_WITH_AES_128_CBC_SHA  */
#define TLS1_CK_DHE_PSK_AES_256_CBC_SHA  0x03000091  /*TLS_DHE_PSK_WITH_AES_256_CBC_SHA  */
#endif

/* The strings for each cipher. IDs can be got by s/TXT/CK/ */
#define TLS1_TXT_RSA_NULL_MD5			"NULL-MD5"
#define TLS1_TXT_RSA_NULL_SHA			"NULL-SHA"
#define TLS1_TXT_RSA_RC4_40_MD5 		"EXP-RC4-MD5"
#define TLS1_TXT_RSA_RC4_128_MD5		"RC4-MD5"
#define TLS1_TXT_RSA_RC4_128_SHA		"RC4-SHA"
#define TLS1_TXT_RSA_DES_40_CBC_SHA		"EXP-DES-CBC-SHA"
#define TLS1_TXT_RSA_DES_64_CBC_SHA		"DES-CBC-SHA"
#define TLS1_TXT_RSA_DES_192_CBC3_SHA		"DES-CBC3-SHA"


#define TLS1_TXT_EDH_DSS_DES_40_CBC_SHA		"EXP-EDH-DSS-DES-CBC-SHA"
#define TLS1_TXT_EDH_DSS_DES_64_CBC_SHA		"EDH-DSS-DES-CBC-SHA"
#define TLS1_TXT_EDH_DSS_DES_192_CBC3_SHA	"EDH-DSS-DES-CBC3-SHA"
#define TLS1_TXT_EDH_RSA_DES_40_CBC_SHA		"EXP-EDH-RSA-DES-CBC-SHA"
#define TLS1_TXT_EDH_RSA_DES_64_CBC_SHA		"EDH-RSA-DES-CBC-SHA"
#define TLS1_TXT_EDH_RSA_DES_192_CBC3_SHA	"EDH-RSA-DES-CBC3-SHA"

#define TLS1_TXT_ADH_RC4_40_MD5			"EXP-ADH-RC4-MD5"
#define TLS1_TXT_ADH_RC4_128_MD5		"ADH-RC4-MD5"
#define TLS1_TXT_ADH_DES_40_CBC_SHA		"EXP-ADH-DES-CBC-SHA"
#define TLS1_TXT_ADH_DES_64_CBC_SHA		"ADH-DES-CBC-SHA"
#define TLS1_TXT_ADH_DES_192_CBC_SHA		"ADH-DES-CBC3-SHA"

/* AES ciphersuites from RFC3268 */
#define TLS1_TXT_RSA_WITH_AES_128_SHA			"AES128-SHA"
#define TLS1_TXT_DHE_DSS_WITH_AES_128_SHA		"DHE-DSS-AES128-SHA"
#define TLS1_TXT_DHE_RSA_WITH_AES_128_SHA		"DHE-RSA-AES128-SHA"
#define TLS1_TXT_ADH_WITH_AES_128_SHA			"ADH-AES128-SHA"

#define TLS1_TXT_RSA_WITH_AES_256_SHA			"AES256-SHA"
#define TLS1_TXT_DHE_DSS_WITH_AES_256_SHA		"DHE-DSS-AES256-SHA"
#define TLS1_TXT_DHE_RSA_WITH_AES_256_SHA		"DHE-RSA-AES256-SHA"
#define TLS1_TXT_ADH_WITH_AES_256_SHA			"ADH-AES256-SHA"
/* PSK ciphersuites from RFC 4279 */
#ifndef  SSL_NO_PSK
#define TLS1_TXT_PSK_NULL_SHA	 	        "PSK-NULL-SHA"	
#define TLS1_TXT_PSK_RC4_128_SHA		        "PSK-RC4-SHA"
#define TLS1_TXT_PSK_3DES_EDE_CBC_SHA	        "PSK-3DES-EDE-CBC-SHA"
#define TLS1_TXT_PSK_AES_128_CBC_SHA	        "PSK-AES128-CBC-SHA"
#define TLS1_TXT_PSK_AES_256_CBC_SHA	        "PSK-AES256-CBC-SHA"
#endif

#ifndef SSL_NO_DH_PSK
#define TLS1_TXT_DHE_PSK_NULL_SHA	 	"DHE_PSK-NULL-SHA"	
#define TLS1_TXT_DHE_PSK_RC4_128_SHA		"DHE_PSK-RC4-SHA"
#define TLS1_TXT_DHE_PSK_3DES_EDE_CBC_SHA	"DHE_PSK-3DES-EDE-CBC-SHA"
#define TLS1_TXT_DHE_PSK_AES_128_CBC_SHA	"DHE_PSK-AES128-CBC-SHA"
#define TLS1_TXT_DHE_PSK_AES_256_CBC_SHA	"DHE_PSK-AES256-CBC-SHA"
#endif

/* Begin */
#undef TLS_CT_RSA_SIGN
#undef TLS_CT_DSS_SIGN
#undef TLS_CT_RSA_FIXED_DH
#undef TLS_CT_DSS_FIXED_DH
#undef TLS_CT_ECDSA_SIGN
#undef TLS_CT_RSA_FIXED_ECDH
#undef TLS_CT_ECDSA_FIXED_ECDH
#undef TLS_CT_NUMBER

#undef TLS1_FINISH_MAC_LENGTH

#undef TLS_MD_MAX_CONST_SIZE
#undef TLS_MD_CLIENT_FINISH_CONST
#undef TLS_MD_CLIENT_FINISH_CONST_SIZE
#undef TLS_MD_SERVER_FINISH_CONST
#undef TLS_MD_SERVER_FINISH_CONST_SIZE
#undef TLS_MD_SERVER_WRITE_KEY_CONST
#undef TLS_MD_SERVER_WRITE_KEY_CONST_SIZE
#undef TLS_MD_KEY_EXPANSION_CONST
#undef TLS_MD_KEY_EXPANSION_CONST_SIZE
#undef TLS_MD_CLIENT_WRITE_KEY_CONST
#undef TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE
#undef TLS_MD_IV_BLOCK_CONST
#undef TLS_MD_IV_BLOCK_CONST_SIZE
#undef TLS_MD_MASTER_SECRET_CONST
#undef TLS_MD_MASTER_SECRET_CONST_SIZE

/* End */

#define TLS_CT_RSA_SIGN			1
#define TLS_CT_DSS_SIGN			2
#define TLS_CT_RSA_FIXED_DH		3
#define TLS_CT_DSS_FIXED_DH		4
#define TLS_CT_ECDSA_SIGN		5
#define TLS_CT_RSA_FIXED_ECDH		6
#define TLS_CT_ECDSA_FIXED_ECDH 	7
#define TLS_CT_NUMBER			7

#define TLS1_FINISH_MAC_LENGTH		12

#define TLS_MD_MAX_CONST_SIZE			20
#define TLS_MD_CLIENT_FINISH_CONST		"client finished"
#define TLS_MD_CLIENT_FINISH_CONST_SIZE		15
#define TLS_MD_SERVER_FINISH_CONST		"server finished"
#define TLS_MD_SERVER_FINISH_CONST_SIZE		15
#define TLS_MD_SERVER_WRITE_KEY_CONST		"server write key"
#define TLS_MD_SERVER_WRITE_KEY_CONST_SIZE	16
#define TLS_MD_KEY_EXPANSION_CONST		"key expansion"
#define TLS_MD_KEY_EXPANSION_CONST_SIZE		13
#define TLS_MD_CLIENT_WRITE_KEY_CONST		"client write key"
#define TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE	16
#define TLS_MD_IV_BLOCK_CONST			"IV block"
#define TLS_MD_IV_BLOCK_CONST_SIZE		8
#define TLS_MD_MASTER_SECRET_CONST		"master secret"
#define TLS_MD_MASTER_SECRET_CONST_SIZE		13

#ifdef CHARSET_EBCDIC
#undef TLS_MD_CLIENT_FINISH_CONST
#define TLS_MD_CLIENT_FINISH_CONST    "\x63\x6c\x69\x65\x6e\x74\x20\x66\x69\x6e\x69\x73\x68\x65\x64"  /*client finished*/
#undef TLS_MD_SERVER_FINISH_CONST
#define TLS_MD_SERVER_FINISH_CONST    "\x73\x65\x72\x76\x65\x72\x20\x66\x69\x6e\x69\x73\x68\x65\x64"  /*server finished*/
#undef TLS_MD_SERVER_WRITE_KEY_CONST
#define TLS_MD_SERVER_WRITE_KEY_CONST "\x73\x65\x72\x76\x65\x72\x20\x77\x72\x69\x74\x65\x20\x6b\x65\x79"  /*server write key*/
#undef TLS_MD_KEY_EXPANSION_CONST
#define TLS_MD_KEY_EXPANSION_CONST    "\x6b\x65\x79\x20\x65\x78\x70\x61\x6e\x73\x69\x6f\x6e"  /*key expansion*/
#undef TLS_MD_CLIENT_WRITE_KEY_CONST
#define TLS_MD_CLIENT_WRITE_KEY_CONST "\x63\x6c\x69\x65\x6e\x74\x20\x77\x72\x69\x74\x65\x20\x6b\x65\x79"  /*client write key*/
#undef TLS_MD_IV_BLOCK_CONST
#define TLS_MD_IV_BLOCK_CONST         "\x49\x56\x20\x62\x6c\x6f\x63\x6b"  /*IV block*/
#undef TLS_MD_MASTER_SECRET_CONST
#define TLS_MD_MASTER_SECRET_CONST    "\x6d\x61\x73\x74\x65\x72\x20\x73\x65\x63\x72\x65\x74"  /*master secret*/
#endif

/**
* @defgroup tls1
* This section contains tls_context Function.
*/

/** @defgroup tls1Function
* @ingroup tls1
* This section contains the function of tls_context.
*/

/*
    Func Name:	 tls1_PRF
*/
/** 
* @defgroup tls1_PRF
* @ingroup tls1Function
* @par Prototype
* @code
* SEC_VOID tls1_PRF(const SEC_ALGID_E md5, const SEC_ALGID_E sha1,
* SEC_UCHAR *label, SEC_INT label_len,
* const SEC_UCHAR *sec, SEC_INT slen, SEC_UCHAR *out1,
* SEC_UCHAR *out2, SEC_INT olen);
* @endcode
*
* @par Purpose
* This is used to generate Psuedo random number for tls1.
*
* @par Description
* The tls1_PRF function generates Psuedo random number for tls1 operation.
*			
* @param[in] md5 MD5 algorithm [N/A]
* @param[in] sha1 SHA1 algorithm [N/A]
* @param[in] label label used in PRF computation typically a short string [N/A]
* @param[in] label_len Length of label [N/A]
* @param[in] sec Some random seed value for PRF computation [N/A]
* @param[in] slen Length of sec. [N/A]
* @param[in] olen Length of output buffer (80 bytes) [N/A]
* @param[out] out1 Output buffer to hold the output [N/A]
* @param[out] out2 Intermediate buffer used in computation [N/A]
*
* @retval SEC_VOID Nothing is returned [N/A|N/A]
*
* @par Required Header File
* tls1.h
*
* @par Note
* \n
* N/A
* 
* @par Related Topics
* N/A
*/


SSLLINKDLL SEC_VOID tls1_PRF(const SEC_ALGID_E md5, const SEC_ALGID_E sha1,
                     SEC_UCHAR *label, SEC_INT label_len,
                     const SEC_UCHAR *sec, SEC_INT slen, SEC_UCHAR *out1,
                     SEC_UCHAR *out2, SEC_INT olen);

					 
#ifdef  __cplusplus
}
#endif
					 
#endif // _IPSI_HEADER_TLS1_H



