#include "malloc_wrappers.h"
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

static size_t alloc_count = 0;

/* Allocate memory and place check values before and after. */
void* new_malloc(size_t size);

void new_assert(int expression);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr);

void* malloc_with_check(size_t size)
{
    size_t size32 = (size + 3) / 4 + 3;
    uint32_t *buf = new_malloc(size32 * sizeof(uint32_t));
    buf[0] = size32;
    buf[1] = 0xDEADBEEF;
    buf[size32 - 1] = 0xBADBAD;
    return buf + 2;
}

/* Free memory allocated with malloc_with_check() and do the checks. */
void free_with_check(void *mem)
{
    uint32_t *buf = (uint32_t*)mem - 2;
    new_assert(buf[1] == 0xDEADBEEF);
    new_assert(buf[buf[0] - 1] == 0xBADBAD);
    new_free(buf);
}

/* Track memory usage */
void* counting_new_realloc(void *ptr, size_t size)
{
    /* Don't allocate crazy amounts of RAM when fuzzing */
    if (size > 1000000)
        return NULL;

    if (!ptr && size)
        alloc_count++;
    
    return new_realloc(ptr, size);
}

void counting_new_free(void *ptr)
{
    if (ptr)
    {
        new_assert(alloc_count > 0);
        alloc_count--;
        new_free(ptr);
    }
}

size_t get_alloc_count()
{
    return alloc_count;
}

void* new_malloc(size_t size);

void new_assert(int expression);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size);

void new_assert(int expression);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
void* new_malloc(size_t size);

void new_assert(int expression) {
  return assert(expression);
}
void* new_malloc(size_t size) {
  return malloc(size);
}