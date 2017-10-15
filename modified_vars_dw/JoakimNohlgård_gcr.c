static const unsigned char gcrEncode[16] = {0x0a, 0x0b, 0x12, 0x13, 0x0e, 0x0f, 0x16, 0x17, 0x09, 0x19, 0x1a, 0x1b, 0x0d, 0x1d, 0x1e, 0x15};
static const unsigned char gcrDecode[32] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x08, 0x00, 0x01, 0xff, 0x0c, 0x04, 0x05, 0xff, 0xff, 0x02, 0x03, 0xff, 0x0f, 0x06, 0x07, 0xff, 0x09, 0x0a, 0x0b, 0xff, 0x0d, 0x0e, 0xff};
static unsigned char gcrBit = 0;
static unsigned short gcrVal = 0;
void gcrInit(void)
{
  int first_iteration;
  gcrVal = 0;
  gcrBit = 0;
}

unsigned char gcrFinish(void)
{
  int first_iteration;
  return gcrBit == 0;
}

void gcrEncode(unsigned char rawData)
{
  int first_iteration;
  gcrVal |= ((gcrEncode[rawData >> 4u] << 5u) | gcrEncode[rawData & 0xf]) << gcrBit;
  gcrBit += 10;
}

unsigned char gcrGetEncoded(unsigned char *rawData)
{
  int first_iteration;
  if (gcrBit >= 8)
  {
    *rawData = (unsigned char) (gcrVal & 0xff);
    gcrVal = gcrVal >> 8u;
    gcrBit = gcrBit - 8;
    return 1;
  }

  return 0;
}

void gcrDecode(unsigned char gcrData)
{
  int first_iteration;
  gcrVal |= gcrData << gcrBit;
  gcrBit += 8;
}

unsigned char gcrValid(void)
{
  int first_iteration;
  if (gcrBit >= 10)
  {
    unsigned short val = gcrVal & 0x3ff;
    if (((gcrDecode[val >> 5u] << 4u) == 0xff) || (gcrDecode[val & 0x1f] == 0xff))
    {
      return 0;
    }

  }

  return 1;
}

unsigned char gcrGetDecode(unsigned char *rawData)
{
  int first_iteration;
  if (gcrBit >= 10)
  {
    unsigned short val = gcrVal & 0x3ff;
    *rawData = (unsigned char) ((gcrDecode[val >> 5] << 4) | gcrDecode[val & 0x1f]);
    gcrVal = gcrVal >> 10;
    gcrBit = gcrBit - 10;
    return 1;
  }

  return 0;
}


