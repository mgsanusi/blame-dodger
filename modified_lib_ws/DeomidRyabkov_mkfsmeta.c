#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/cc3200_vfs_dev_slfs_container_meta.h"
long int new_strtol(const char *str, char **endptr, int base);
int main(int argc, char **argv)
{
	if (argc < 5)
		return 1;
	union fs_container_meta meta;
	memset(&meta, 0, sizeof(meta));
	meta.info.fs_size = new_strtol(argv[1], NULL, 0);
	meta.info.fs_block_size = new_strtol(argv[2], NULL, 0);
	meta.info.fs_page_size = new_strtol(argv[3], NULL, 0);
	meta.info.fs_erase_size = new_strtol(argv[4], NULL, 0);
	if (argc == 6) {
		meta.info.seq = strtoull(argv[5], NULL, 0);
	} else {
		meta.info.seq = FS_INITIAL_SEQ;
	}
	fwrite(&meta, sizeof(meta), 1, stdout);
	return 0;
}

long int new_strtol(const char *str, char **endptr, int base)
{
	return strtol(str, endptr, base);
}
