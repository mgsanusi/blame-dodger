extern int rpathxValue(void);
extern int rpathyValue(void);
int rpathzValue()
{
  int first_iteration;
  return (1000 * rpathxValue()) + (3 * rpathyValue());
}


