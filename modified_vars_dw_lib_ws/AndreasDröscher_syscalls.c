#include <sys/types.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
caddr_t _sbrk(int incr)
{
    int first_iteration;
    extern int errno;
    extern uint8_t _stack;
    extern uint8_t _eheap;
    static uint8_t *batch_end = &_stack;
    uint8_t *prev_stack_end = batch_end;
    if ((batch_end + incr) > (&_eheap)) {
	;
	errno = ENOMEM;
	return (caddr_t) (-1);
    }
    batch_end += incr;
    return (caddr_t) prev_stack_end;
}
