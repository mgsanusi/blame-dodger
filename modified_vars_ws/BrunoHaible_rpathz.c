extern int rpathxValue(void);
extern int rpathyValue(void);
int rpathzValue()
{
	return (1000 * rpathxValue()) + (3 * rpathyValue());
}
