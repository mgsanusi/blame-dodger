int (*uart0InputHandler)(unsigned char j) = 0;
void uart0SetInput(int (*input)(unsigned char j))
{
  uart0InputHandler = input;
}


