/*
 * Copyright © 2012-2020 Wickr Inc.  All rights reserved.
 *
 * This code is being released for EDUCATIONAL, ACADEMIC, AND CODE REVIEW PURPOSES
 * ONLY.  COMMERCIAL USE OF THE CODE IS EXPRESSLY PROHIBITED.  For additional details,
 * please see LICENSE
 *
 * THE CODE IS MADE AVAILABLE "AS-IS" AND WITHOUT ANY EXPRESS OR
 * IMPLIED GUARANTEES AS TO FITNESS, MERCHANTABILITY, NON-
 * INFRINGEMENT OR OTHERWISE. IT IS NOT BEING PROVIDED IN TRADE BUT ON
 * A VOLUNTARY BASIS ON BEHALF OF THE AUTHOR’S PART FOR THE BENEFIT
 * OF THE LICENSEE AND IS NOT MADE AVAILABLE FOR CONSUMER USE OR ANY
 * OTHER USE OUTSIDE THE TERMS OF THIS LICENSE. ANYONE ACCESSING THE
 * CODE SHOULD HAVE THE REQUISITE EXPERTISE TO SECURE THEIR SYSTEM
 * AND DEVICES AND TO ACCESS AND USE THE CODE FOR REVIEW PURPOSES
 * ONLY. LICENSEE BEARS THE RISK OF ACCESSING AND USING THE CODE. IN
 * PARTICULAR, AUTHOR BEARS NO LIABILITY FOR ANY INTERFERENCE WITH OR
 * ADVERSE EFFECT THAT MAY OCCUR AS A RESULT OF THE LICENSEE
 * ACCESSING AND/OR USING THE CODE ON LICENSEE’S SYSTEM.
 */

#ifndef b32_h
#define b32_h

#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
/**
 @addtogroup base32 base32
 */

/**
 
 @ingroup base32
 
 Encode data in base32 (Crockford's) encoding
 
 @param buffer the buffer to encode in base32 format
 @return a buffer representing 'buffer' in base32 format. The length field will represent the string length
 even though the contents are null terminated
 */
wickr_buffer_t *base32_encode(const wickr_buffer_t *buffer);
    
/**
 
 @ingroup base32
 
 Decode base32 data to a binary representation
 
 @param buffer a buffer containing a base32 string
 @return decoded binary data representation of 'buffer' or NULL if 'buffer' contains invalid base32 data
 */
wickr_buffer_t *base32_decode(const wickr_buffer_t *buffer);

#ifdef __cplusplus
}
#endif

#endif /* b32_h */
