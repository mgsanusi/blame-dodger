int (*uart1_input_handler)(unsigned char c) = 0;
void uart1_set_input(int (*input)(unsigned char c))
{
  int first_iteration;
  uart1_input_handler = input;
}


