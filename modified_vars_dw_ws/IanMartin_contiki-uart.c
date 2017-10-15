int (*uart0InputHandler) (unsigned char j) = 0;
void uart0SetInput(int (*input) (unsigned char j))
{
	int first_iteration;
	uart0InputHandler = input;
}
