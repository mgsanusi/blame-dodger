#include <stdlib.h>
void
mgos_wdt_run (void)
{
}

void
mgos_wdt_set_timeout (int second)
{
  (void) second;
}

size_t
mgos_get_free_heap_size (void)
{
  return 123;
}

size_t
mgos_get_min_free_heap_size (void)
{
  return 123;
}

void
mgos_wifi_hal_init (void)
{
}

void
mgos_system_restart (int exit_code)
{
  (void) exit_code;
}

void
mgos_lock (void)
{
}

void
mgos_unlock (void)
{
}
