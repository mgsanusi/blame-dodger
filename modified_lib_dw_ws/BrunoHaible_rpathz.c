extern int rpathx_value(void);
extern int rpathy_value(void);
int rpathz_value()
{
	int first_iteration;
	return (1000 * rpathx_value()) + (3 * rpathy_value());
}
