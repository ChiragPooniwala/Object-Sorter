//Header file for colour sensor
// Kalpesh and Chirag  25.8.14

//sbit dm=P1^4;

sbit ir=P1^1;

sbit s0=P3^4;
sbit s1=P3^5;
sbit s2=P3^6;
sbit s3=P3^7;

sbit led1=P1^7;
sbit led2=P1^6;
sbit led3=P1^5;

unsigned int count=0x0000;

unsigned char br=0,bl=0,yel=0;

void compare_control(unsigned int a)
{
if(ir==1)
{
if(a>750)
{
led1=0;
led2=0;
led3=1;
pwm_gen(249);
}
else if(a>300&&a<750)
{
led1=0;
led2=1;
led3=0;
pwm_gen(250);
}
else if(a<300)
{
led1=1;
led2=0;
led3=0;
pwm_gen(251);
}
}
}

void ext1_intr(void) interrupt 2 {
count++;
}

void t2_intr(void) interrupt 5 {
lcd_int_disp(count);
compare_control(count);
count=0;
TF2=0;
}

void int_init(void)
{
RCAP2H=0;   //timer 2 initialise
RCAP2L=0;
TH2=0;
TL2=0;

TR2=1;	   //timer start
IT1=1;     //neg. edge trigered ext int 1

IEN0=0xA4;	//interrupt initialization
//PX0=1;		//priority setting
//IP0H=0x01;
PT2=1;	    
}