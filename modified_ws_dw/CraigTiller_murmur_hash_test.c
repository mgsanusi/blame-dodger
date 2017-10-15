#include "src/core/lib/support/murmur_hash.h"
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "test/core/util/test_config.h"
#include <string.h>
typedef uint32_t (*hash_func) (const void *key, size_t len, uint32_t seed);

