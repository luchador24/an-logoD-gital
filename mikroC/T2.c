sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

unsigned int x;
unsigned long tlong;
unsigned char ch;
void main() {
ANSEL = 0x04; // configura el A2 como analogo
ANSELH = 0;
TRISA = 1;
TRISB = 0;
TRISC = 0;
TRISD = 0;
ADC_Init();  //inicializa la libreria ADC
Lcd_Init(); //Inicializa la libreria lcd
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Cmd(_LCD_CLEAR);

//Convertir un numero ASCII
while(1){
x = ADC_Read(2);
LCD_Out(1,2,"arquitectura");
LCD_Out(2,1,"voltios");
tlong=(long)x*5000;
tlong=tlong/1023;
ch=tlong/1000;

Lcd_Chr(2,9,46+ch);
Lcd_Chr_CP('.');
ch=(tlong/100)%10;
Lcd_Chr_CP(48+ch);
ch=(tlong/10)%10;
Lcd_Chr_CP(48+ch);
ch=tlong%10;
Lcd_Chr_CP(48+ch);
Lcd_Chr_CP('V');
Delay_ms(1);
}




/*
//ANALOGO DIGITAL
ANSEL = 0x04; // configura el A2 como analogo
ANSELH = 0;
TRISA = 1;
TRISB = 0;
TRISC = 0;
TRISD = 0;
ADC_Init();  //inicializa la libreria ADC
Lcd_Init(); //Inicializa la libreria lcd
do{
x=ADC_Read(2);
PortC=x;
PortD=x>>2 ;
}while(1);
*/
}