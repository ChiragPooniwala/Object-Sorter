//Header file for 16x2 LCD in 8-bit mode
//Kalpesh and Chirag   17.8.14

#include <STRING.H>

//lcd data bus connected to P0
sbit rs=P2^5;
sbit rw=P2^6;
sbit e=P2^7;
sbit busy=P0^7;
//unsigned char name[]=" POONIWALA";

void lcd_delay()
{
unsigned char i;
for(i=255;i>0;i--);
}

void read_busy()
{
rs=0;
rw=1;
busy=1;
e=0;
lcd_delay();
e=1;
while(busy);
}

void send_value(unsigned char c)
{
rw=0;
P0=c;
e=1;
lcd_delay();
e=0;
}

void lcd_command(unsigned char c)
{
read_busy();
send_value(c);
}

void lcd_data(unsigned char c)
{
read_busy();
rs=1;
send_value(c);
}

void lcd_char_disp(unsigned char v)
{
unsigned char i;
lcd_command(0x04); //auto decrement
for(i=2;i>0;i--)
{
lcd_data(0x30|(v%10));
v=v/10;
}
}

void lcd_int_disp(unsigned int v)
{
unsigned char i;
lcd_command(0x04); //auto decrement
lcd_command(0x84);
for(i=5;i>0;i--)
{
lcd_data(0x30|(v%10));
v=v/10;
}
}

void lcd_string(unsigned char *s)
{
unsigned char l,i;
l = strlen(s); // get the length of string
for(i=1;i <=l;i++)
{
lcd_data(*s); // write every char one by one
s++;
}
}

void lcd_init()
{
lcd_command(0x38);
lcd_command(0x0E);
lcd_command(0x01);
lcd_command(0x06);
lcd_command(0x80);
}