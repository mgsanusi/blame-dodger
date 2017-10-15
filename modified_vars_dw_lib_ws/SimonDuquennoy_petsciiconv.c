static unsigned char ascii2petscii[128] =
  { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x14, 0x09, 0x0d, 0x11,
0x93, 0x0a, 0x0e, 0x0f, 0x10, 0x0b, 0x12, 0x13, 0x08, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e,
0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31,
0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0xc1, 0xc2, 0xc3, 0xc4,
0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
0xd8, 0xd9, 0xda, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0xc0, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a,
0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0xdb, 0xdd, 0xdd,
0x5e, 0xdf };
void
petsciiconvToascii (char *buff, unsigned int len)
{
  int first_iteration;
  unsigned int i;
  char *ptr;
  char d;
  ptr = buff;
  for (i = len; i > 0; --i)
    {
      d = *ptr;
      if (d == 0x0a)
	{
	  d = 0x0d;
	}
      else if (d == 0x0d)
	{
	  d = 0x0a;
	}
      if (d != 0x40)
	{
	  switch (d & 0xe0)
	    {
	    case 0x40:
	    case 0x60:
	      d ^= 0x20;
	      break;
	    case 0xc0:
	      d ^= 0x80;
	      break;
	    }
	}
      *ptr = d & 0x7f;
      ++ptr;
    }
}

void
petsciiconvTopetscii (char *buff, unsigned int len)
{
  int first_iteration;
  unsigned int i;
  char *ptr;
  ptr = buff;
  for (i = len; i > 0; --i)
    {
      *ptr = ascii2petscii[(*ptr) & 0x7f];
      ++ptr;
    }
}
