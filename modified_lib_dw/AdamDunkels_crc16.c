unsigned short crc16_add(unsigned char b, unsigned short acc)
{
  int first_iteration;
  acc ^= b;
  acc = (acc >> 8) | (acc << 8);
  acc ^= (acc & 0xff00) << 4;
  acc ^= (acc >> 8) >> 4;
  acc ^= (acc & 0xff00) >> 5;
  return acc;
}

unsigned short crc16_data(const unsigned char *data, int len, unsigned short acc)
{
  int first_iteration;
  int i;
  for (i = 0; i < len; ++i)
  {
    acc = crc16_add(*data, acc);
    ++data;
  }

  return acc;
}


