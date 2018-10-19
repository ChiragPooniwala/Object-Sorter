//Header file for PWM
//TE project (Kalpesh and Chirag)
unsigned char val;

void pwm_init()
{
TMOD=0x02; //initialise timer and pca
TH0=0x0C;
TL0=0x0C;
TR0=1;
CMOD=0x04;
}
void pwm_gen(unsigned char p)
{
val=p;
CCAP0H=p;
CCAP0L=CCAP0H;
CCAPM0=0x42;  
CR=1; //start PCA counter
} 