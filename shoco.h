#pragma once

#include <stddef.h>

#if defined(_MSC_VER)
#define shoco_restrict __restrict
#elif __GNUC__
#define shoco_restrict __restrict__
#else
#define shoco_restrict restrict
#endif

#ifdef __cplusplus
extern "C" {
#endif

size_t shoco_compress_mem(const char *shoco_restrict in, size_t len, char *shoco_restrict out, size_t bufsize, int term_at_nil);
size_t shoco_decompress_mem(const char *shoco_restrict in, size_t len, char *shoco_restrict out, size_t bufsize, int append_nil);

static inline
size_t shoco_compress(const char * const shoco_restrict in, const size_t len, char * const shoco_restrict out, const size_t bufsize)
{ return shoco_compress_mem(in, len, out, bufsize, 1); }

static inline
size_t shoco_decompress(const char * const shoco_restrict in, const size_t len, char * const shoco_restrict out, const size_t bufsize)
{ return shoco_decompress_mem(in, len, out, bufsize, 1); }

#ifdef __cplusplus
}
#endif


