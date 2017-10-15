unsigned short crc16Add(unsigned char t, unsigned short acc)
{
	acc ^= t;
	acc = (acc >> 8) | (acc << 8);
	acc ^= (acc & 0xff00) << 4;
	acc ^= (acc >> 8) >> 4;
	acc ^= (acc & 0xff00) >> 5;
	return acc;
}

unsigned short crc16Data(const unsigned char *data, int length,
			 unsigned short acc)
{
	int g;
	for (g = 0; g < length; ++g) {
		acc = crc16Add(*data, acc);
		++data;
	}
	return acc;
}
