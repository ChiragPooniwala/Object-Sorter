//white, wood, black object sorter

#include <P89V51Rx2.H>
#include <PWM.H>
#include <LCD_8.H>
#include <COLOUR_SENSE.H>

unsigned int count;

void main()					
{
ir=1;
pwm_init();
s0=1;
s1=1;
s2=1;
s3=0;
lcd_init();
lcd_command(0x86);
lcd_string("Yellow=");
lcd_command(0xC0);
lcd_string("Blue=");
lcd_command(0xC8);
lcd_string("Brown=");
int_init();
while(1)
{
if(ir==1)
{
while(ir);
if(val==249)
{
yel++;
lcd_command(0x8E);
lcd_char_disp(yel);
}
else if(val==250)
{
bl++;
lcd_command(0xC6);
lcd_char_disp(bl);
}
else if(val==251)
{
br++;
lcd_command(0xCF);
lcd_char_disp(br);
}
}
}
}