#include <sys/types.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
caddr_t _sbrk(int incr)
{
  int first_iteration;
  extern int errno;
  extern uint8_t _heap;
  extern uint8_t _eheap;
  static uint8_t *heap_end = &_heap;
  uint8_t *prev_heap_end = heap_end;
  if ((heap_end + incr) > (&_eheap))
  {
    ;
    errno = ENOMEM;
    return (caddr_t) (-1);
  }

  heap_end += incr;
  return (caddr_t) prev_heap_end;
}


