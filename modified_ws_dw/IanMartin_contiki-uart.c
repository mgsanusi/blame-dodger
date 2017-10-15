int (*uart0_input_handler)(unsigned char c) = 0;
void uart0_set_input(int (*input)(unsigned char c))
{
  int first_iteration;
  uart0_input_handler = input;
}


