#include "WProgram.h"

#include "Phillips6610LCD.h"


// Define Software SPI Pin Signal

#define BL 2          // Digital 2 --> BL
#define CS 3          // Digital 3 --> #CS
#define CLK 4         // Digital 4 --> SCLK
#define SDA 5         // Digital 5 --> SDATA
#define RESET 6       // Digital 6 --> #RESET


// Phillips PCF8833 Command Set 
#define NOP 0x00 	// nop
#define SWRESET  0x01 	// software reset
#define BSTROFF  0x02 	// booster voltage OFF
#define BSTRON   0x03 	// booster voltage ON
#define RDDIDIF  0x04 	// read display identification
#define RDDST    0x09 	// read display status
#define SLEEPIN  0x10 	// sleep in
#define SLEEPOUT 0x11 	// sleep out
#define PTLON    0x12 	// partial display mode
#define NORON    0x13 	// display normal mode
#define INVOFF   0x20 	// inversion OFF
#define INVON    0x21 	// inversion ON
#define DALO     0x22 	// all pixel OFF
#define DAL      0x23 	// all pixel ON
#define SETCON   0x25 	// write contrast
#define DISPOFF  0x28 	// display OFF
#define DISPON   0x29 	// display ON
#define CASET    0x2A 	// column address set
#define PASET    0x2B 	// page address set
#define RAMWR    0x2C 	// memory write
#define RGBSET   0x2D 	// colour set
#define PTLAR    0x30 	// partial area
#define VSCRDEF  0x33 	// vertical scrolling definition
#define TEOFF    0x34 	// test mode
#define TEON     0x35 	// test mode
#define MADCTL   0x36 	// memory access control
#define SEP      0x37 	// vertical scrolling start address
#define IDMOFF   0x38 	// idle mode OFF
#define IDMON    0x39 	// idle mode ON
#define COLMOD   0x3A 	// interface pixel format
#define SETVOP   0xB0 	// set Vop
#define BRS      0xB4 	// bottom row swap
#define TRS      0xB6 	// top row swap
#define DISCTR   0xB9 	// display control
//#define DAOR   0xBA 	// data order(DOR)
#define TCDFE    0xBD 	// enable/disable DF temperature compensation
#define TCVOPE   0xBF 	// enable/disable Vop temp comp
#define EC       0xC0 	// internal or external oscillator
#define SETMUL   0xC2 	// set multiplication factor
#define TCVOPAB  0xC3 	// set TCVOP slopes A and B
#define TCVOPCD  0xC4 	// set TCVOP slopes c and d
#define TCDF     0xC5 	// set divider frequency
#define DF8COLOR 0xC6 	// set divider frequency 8-color mode
#define SETBS    0xC7 	// set bias system
#define RDTEMP   0xC8 	// temperature read back
#define NLI      0xC9 	// n-line inversion
#define RDID1    0xDA 	// read ID1
#define RDID2    0xDB 	// read ID2
#define RDID3    0xDC 	// read ID3

//a few basic colors
#define RED			0xE0
#define GREEN			0x1C
#define BLUE			0x03
#define YELLOW			0xFC
#define MAGENTA			0xE3
#define CYAN			0x1F
#define BLACK			0x00
#define WHITE			0xFF

#define cbi(reg, bit) (reg&=~(1<<bit))
#define sbi(reg, bit) (reg|= (1<<bit))

#define CS0 cbi(PORTD,CS);
#define CS1 sbi(PORTD,CS);
#define CLK0 cbi(PORTD,CLK);
#define CLK1 sbi(PORTD,CLK);
#define SDA0 cbi(PORTD,SDA);
#define SDA1 sbi(PORTD,SDA);
#define RESET0 cbi(PORTD,RESET);
#define RESET1 sbi(PORTD,RESET);
#define BL0 cbi(PORTD,BL);
#define BL1 sbi(PORTD,BL);

byte const font[475] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x06 , 0x5F , 0x06 , 0x00 ,                      // !
0x07 , 0x03 , 0x00 , 0x07 , 0x03 ,                      // ,
0x24 , 0x7E , 0x24 , 0x7E , 0x24 ,                      // #
0x24 , 0x2B , 0x6A , 0x12 , 0x00 ,                      // $
0x63 , 0x13 , 0x08 , 0x64 , 0x63 ,                      // %
0x36 , 0x49 , 0x56 , 0x20 , 0x50 ,                      // &
0x00 , 0x07 , 0x03 , 0x00 , 0x00 ,                      // //
0x00 , 0x3E , 0x41 , 0x00 , 0x00 ,                      // (
0x00 , 0x41 , 0x3E , 0x00 , 0x00 ,                      // )
0x08 , 0x3E , 0x1C , 0x3E , 0x08 ,                      // *
0x08 , 0x08 , 0x3E , 0x08 , 0x08 ,                      // +
0x00 , 0xE0 , 0x60 , 0x00 , 0x00 ,                      // ,
0x08 , 0x08 , 0x08 , 0x08 , 0x08 ,                      // -
0x00 , 0x60 , 0x60 , 0x00 , 0x00 ,                      // .
0x20 , 0x10 , 0x08 , 0x04 , 0x02 ,                      // /
0x3E , 0x51 , 0x49 , 0x45 , 0x3E ,                      // 0
0x00 , 0x42 , 0x7F , 0x40 , 0x00 ,                      // 1
0x62 , 0x51 , 0x49 , 0x49 , 0x46 ,                      // 2
0x22 , 0x49 , 0x49 , 0x49 , 0x36 ,                      // 3
0x18 , 0x14 , 0x12 , 0x7F , 0x10 ,                      // 4
0x2F , 0x49 , 0x49 , 0x49 , 0x31 ,                      // 5
0x3C , 0x4A , 0x49 , 0x49 , 0x30 ,                      // 6
0x01 , 0x71 , 0x09 , 0x05 , 0x03 ,                      // 7
0x36 , 0x49 , 0x49 , 0x49 , 0x36 ,                      // 8
0x06 , 0x49 , 0x49 , 0x29 , 0x1E ,                      // 9
0x00 , 0x6C , 0x6C , 0x00 , 0x00 ,                      // :
0x00 , 0xEC , 0x6C , 0x00 , 0x00 ,                      // ;
0x08 , 0x14 , 0x22 , 0x41 , 0x00 ,                      // <
0x24 , 0x24 , 0x24 , 0x24 , 0x24 ,                      // =
0x00 , 0x41 , 0x22 , 0x14 , 0x08 ,                      // >
0x02 , 0x01 , 0x59 , 0x09 , 0x06 ,                      // ?
0x3E , 0x41 , 0x5D , 0x55 , 0x1E ,                      // @
0x7E , 0x09 , 0x09 , 0x09 , 0x7E ,                      // A
0x7F , 0x49 , 0x49 , 0x49 , 0x36 ,                      // B
0x3E , 0x41 , 0x41 , 0x41 , 0x22 ,                      // C
0x7F , 0x41 , 0x41 , 0x41 , 0x3E ,                      // D
0x7F , 0x49 , 0x49 , 0x49 , 0x41 ,                      // E
0x7F , 0x09 , 0x09 , 0x09 , 0x01 ,                      // F
0x3E , 0x41 , 0x49 , 0x49 , 0x7A ,                      // G
0x7F , 0x08 , 0x08 , 0x08 , 0x7F ,                      // H
0x00 , 0x41 , 0x7F , 0x41 , 0x00 ,                      // I
0x30 , 0x40 , 0x40 , 0x40 , 0x3F ,                      // J
0x7F , 0x08 , 0x14 , 0x22 , 0x41 ,                      // K
0x7F , 0x40 , 0x40 , 0x40 , 0x40 ,                      // L
0x7F , 0x02 , 0x04 , 0x02 , 0x7F ,                      // M
0x7F , 0x02 , 0x04 , 0x08 , 0x7F ,                      // N
0x3E , 0x41 , 0x41 , 0x41 , 0x3E ,                      // O
0x7F , 0x09 , 0x09 , 0x09 , 0x06 ,                      // P
0x3E , 0x41 , 0x51 , 0x21 , 0x5E ,                      // Q
0x7F , 0x09 , 0x09 , 0x19 , 0x66 ,                      // R
0x26 , 0x49 , 0x49 , 0x49 , 0x32 ,                      // S
0x01 , 0x01 , 0x7F , 0x01 , 0x01 ,                      // T
0x3F , 0x40 , 0x40 , 0x40 , 0x3F ,                      // U
0x1F , 0x20 , 0x40 , 0x20 , 0x1F ,                      // V
0x3F , 0x40 , 0x3C , 0x40 , 0x3F ,                      // W
0x63 , 0x14 , 0x08 , 0x14 , 0x63 ,                      // X
0x07 , 0x08 , 0x70 , 0x08 , 0x07 ,                      // Y
0x71 , 0x49 , 0x45 , 0x43 , 0x00 ,                      // Z
0x00 , 0x7F , 0x41 , 0x41 , 0x00 ,                      // [
0x02 , 0x04 , 0x08 , 0x10 , 0x20 ,                      // Back slash
0x00 , 0x41 , 0x41 , 0x7F , 0x00 ,                      // ]
0x04 , 0x02 , 0x01 , 0x02 , 0x04 ,                      // ^
0x80 , 0x80 , 0x80 , 0x80 , 0x80 ,                      // _
//0x00 , 0x03 , 0x07 , 0x00 , 0x00 ,                      // `
0x20 , 0x40 , 0x80 , 0x40 , 0x20 ,                      // `
0x20 , 0x54 , 0x54 , 0x54 , 0x78 ,                      // a
0x7F , 0x44 , 0x44 , 0x44 , 0x38 ,                      // b
0x38 , 0x44 , 0x44 , 0x44 , 0x28 ,                      // c
0x38 , 0x44 , 0x44 , 0x44 , 0x7F ,                      // d
0x38 , 0x54 , 0x54 , 0x54 , 0x18 ,                      // e
0x08 , 0x7E , 0x09 , 0x09 , 0x00 ,                      // f
0x18 , 0xA4 , 0xA4 , 0xA4 , 0x7C ,                      // g
0x7F , 0x04 , 0x04 , 0x78 , 0x00 ,                      // h
0x00 , 0x00 , 0x7D , 0x00 , 0x00 ,                      // i
0x40 , 0x80 , 0x84 , 0x7D , 0x00 ,                      // j
0x7F , 0x10 , 0x28 , 0x44 , 0x00 ,                      // k
0x00 , 0x00 , 0x7F , 0x40 , 0x00 ,                      // l
0x7C , 0x04 , 0x18 , 0x04 , 0x78 ,                      // m
0x7C , 0x04 , 0x04 , 0x78 , 0x00 ,                      // n
0x38 , 0x44 , 0x44 , 0x44 , 0x38 ,                      // o
0xFC , 0x44 , 0x44 , 0x44 , 0x38 ,                      // p
0x38 , 0x44 , 0x44 , 0x44 , 0xFC ,                      // q
0x44 , 0x78 , 0x44 , 0x04 , 0x08 ,                      // r
0x08 , 0x54 , 0x54 , 0x54 , 0x20 ,                      // s
0x04 , 0x3E , 0x44 , 0x24 , 0x00 ,                      // t
0x3C , 0x40 , 0x20 , 0x7C , 0x00 ,                      // u
0x1C , 0x20 , 0x40 , 0x20 , 0x1C ,                      // v
0x3C , 0x60 , 0x30 , 0x60 , 0x3C ,                      // w
0x6C , 0x10 , 0x10 , 0x6C , 0x00 ,                      // x
0x9C , 0xA0 , 0x60 , 0x3C , 0x00 ,                      // y
0x64 , 0x54 , 0x54 , 0x4C , 0x00 ,                      // z
//0x08 , 0x3E , 0x41 , 0x41 , 0x00 ,                      // {
0x33 , 0x66 , 0xCC , 0x66 , 0x33 ,                      // {
0x00 , 0x00 , 0x7F , 0x00 , 0x00 ,                      // |
//0x00 , 0x41 , 0x41 , 0x3E , 0x08 ,                      // }
0xCC , 0x66 , 0x33 , 0x66 , 0xCC ,                      // }
0x02 , 0x01 , 0x02 , 0x01 , 0x00                        // ~
};


Phillips6610LCD::Phillips6610LCD()
{

  DDRD |= B01111100;   // Set SPI pins as output 
  PORTD |= B01111100;  // Set SPI pins HIGH
}



void Phillips6610LCD::shiftBits(byte b) 
{
  byte Bit;
  
  for (Bit = 0; Bit < 8; Bit++)     // 8 Bit Write
  {
    CLK0          // Standby SCLK
    if((b&0x80)>>7)
    {
      SDA1
    }
    else
    {
      SDA0
    }
    CLK1          // Strobe signal bit 
    b <<= 1;   // Next bit data
  }  
}

void Phillips6610LCD::sendData(byte data) {
  CS1
  CLK0
  CS0
  SDA1
  CLK1
  CLK0

  shiftBits(data);
  CLK0
  CS1
}

void Phillips6610LCD::sendCMD(byte data) {
  CS1
  CLK0
  CS0
  SDA0
  CLK1
  CLK0

  shiftBits(data);
  CLK0
  CS1

}

void Phillips6610LCD::lcd_set_box(byte x1, byte y1, byte x2, byte y2)
{
  sendCMD(CASET);   // page start/end ram
  sendData(x1);     // for some reason starts at 2
  sendData(x2);

  sendCMD(PASET);   // column start/end ram
  sendData(y1);
  sendData(y2);
}

void Phillips6610LCD::lcd_clear(byte color, byte x1, byte y1, byte x2, byte y2)
{
  uint16_t xmin, xmax, ymin, ymax;
  uint16_t i;
  
  // best way to create a filled rectangle is to define a drawing box
  // and loop two pixels at a time
  // calculate the min and max for x and y directions
  xmin = (x1 <= x2) ? x1 : x2;
  xmax = (x1 > x2) ? x1 : x2;
  ymin = (y1 <= y2) ? y1 : y2;
  ymax = (y1 > y2) ? y1 : y2;

  // specify the controller drawing box according to those limits
  // Row address set (command 0x2B)
  sendCMD(CASET);
  sendData(xmin);
  sendData(xmax);

  // Column address set (command 0x2A)
  sendCMD(PASET);
  sendData(ymin);
  sendData(ymax);

  // WRITE MEMORY
  sendCMD(RAMWR);

  // loop on total number of pixels / 2
  for (i = 0; i < ((xmax - xmin + 1) * (ymax - ymin + 1)) ; i++) 
  {
    // use the color value to output three data bytes covering two pixels
    // For some reason, it has to send blue first then green and red
    //sendData((color << 4) | ((color & 0xF0) >> 4));
    //sendData(((color >> 4) & 0xF0) | (color & 0x0F));
    //sendData((color & 0xF0) | (color >> 8));
    sendData(color);
  }
}

void Phillips6610LCD::lcd_init()
{
  // Initial state
  CLK0
  CS1
  SDA1
  
  // Hardware Reset LCD
  RESET0
  delay(100);
  RESET1
  delay(100);
  
  // Sleep out (commmand 0x11)
  sendCMD(SLEEPOUT);

  // Inversion on (command 0x20)
  //sendCMD(INVON);    // seems to be required for this controller
  sendCMD(INVOFF); 
  
  // Memory access controler (command 0x36)
  sendCMD(MADCTL);
  sendData(0xc0); // 0xC0 = mirror x and y, reverse rgb
  
  // Write contrast (command 0x25)
  sendCMD(SETCON);
  sendData(0x20); // contrast 0x30

  // Color Interface Pixel Format (command 0x3A)
  sendCMD(COLMOD);
  sendData(0x02);    // 0x03 = 12 bits-per-pixel
  
  sendCMD(BSTROFF);

  lcd_clear(0xff,0,0,131,131);

  sendCMD(DISPON);

}

void Phillips6610LCD::lcd_Sleep()
{
  sendCMD(DISPOFF);
  sendCMD(SLEEPIN);
  lcd_BacklightOff();
}

void Phillips6610LCD::lcd_Wake()
{
  lcd_BacklightOn();
  sendCMD(SLEEPOUT);
  sendCMD(DISPON);
}

void Phillips6610LCD::lcd_BacklightOn()
{
  BL1
}

void Phillips6610LCD::lcd_BacklightOff()
{
  BL0
}


void Phillips6610LCD::draw_text_line(byte fcolor, byte bcolor,byte x, byte y,char c)
{
  unsigned int i;
  lcd_set_box(x,y,x,y+7);
  sendCMD(RAMWR);
  for(i=0;i<8;i++)
  {
    if (1<<i & c)
      sendData(fcolor);
    else
      sendData(bcolor);
  }
}

void Phillips6610LCD::lcd_draw_text(byte fcolor, byte bcolor, byte x, byte y,char *text)
{
  byte c;
  byte t;
  unsigned int i;
  unsigned int j;
  while(*text != 0)
   {
     t = *text;
     i = t - 32;
     i = i * 5;
     for(j = i; j < i+5; j++)
     {
       c = font[j];
       draw_text_line(fcolor, bcolor, x++, y, c);
     }
     draw_text_line(fcolor, bcolor, x++, y, 0);
     text++;
   }
}

void Phillips6610LCD::lcd_put_pixel(byte color, byte x, byte y)
{
  sendCMD(CASET);   // page start/end ram
  sendData(x);      // for some reason starts at 2
  sendData(x+1);

  sendCMD(PASET);   // column start/end ram
  sendData(y);
  sendData(y+1);
  sendCMD(RAMWR);
  sendData(color);
}
