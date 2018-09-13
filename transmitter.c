#include<p18f4550.h>
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}
void uart_init()
{
    TRISC = 0X80;
    TXSTA = 0X20;
    RCSTA = 0X90;
    SPBRG = 12;
}
void uart_send(char a)
{
    TXREG = a;
    while(!(PIR1&0X10));
}
int main()
{
    uart_init();
    delay(50);
    while(1)
    {
    uart_send('A');
    delay(100);
    }
}
