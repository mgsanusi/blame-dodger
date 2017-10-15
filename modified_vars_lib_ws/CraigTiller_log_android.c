#include <grpc/support/port_platform.h>
#include <android/log.h>
#include <grpc/support/log.h>
#include <grpc/support/time.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
void new_free(void *ptr);
void new_free(void *ptr)
{
    return free(ptr);
}
