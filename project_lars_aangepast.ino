#include <Adafruit_NeoPixel.h>

#define PIN 9    //pin van data strip
#define AANTAL 100  //aantal leds op strip
#define KNOPPIN 2  //pin nummer van knop
  
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(AANTAL, PIN, NEO_RGB + NEO_KHZ800);

//in deze array zitten de bitpatronen van alle letters (7x11) 0=A - 1=B - 2=C
int letter[61][11]={
  {0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xc3,0xc3,0xc3,0xc3,0xc3}, //A
  {0xfd,0xc5,0xc5,0xc5,0xc5,0xfd,0xc3,0xc3,0xc3,0xc3,0xff}, //B
  {0xff,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xff}, //C
  {0xf9,0xc5,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc5,0xf9}, //D
  {0xff,0xc1,0xc1,0xc1,0xc1,0xff,0xc1,0xc1,0xc1,0xc1,0xff}, //E
  {0xff,0xc1,0xc1,0xc1,0xc1,0xff,0xc1,0xc1,0xc1,0xc1,0xc1}, //F
  {0xff,0xc1,0xc1,0xc1,0xc1,0xcf,0xcf,0xc3,0xc3,0xc3,0xff}, //G
  {0xc3,0xc3,0xc3,0xc3,0xc3,0xff,0xc3,0xc3,0xc3,0xc3,0xc3}, //H
  {0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0xff,0xff}, //I
  {0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x87,0x87,0xff}, //J
  {0xc3,0xc5,0xc9,0xd1,0xe1,0xc1,0xe1,0xd1,0xc9,0xc5,0xc3}, //K
  {0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xc1,0xff}, //L
  {0x83,0xc7,0xeb,0xd3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3}, //M
  {0x83,0xc3,0xe3,0xd3,0xcb,0xc7,0xc3,0xc3,0xc3,0xc3,0xc3}, //N
  {0xff,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xff}, //O
  {0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xc1,0xc1,0xc1,0xc1,0xc1}, //P
  {0xfd,0xc5,0xc5,0xc5,0xc5,0xc5,0xc5,0xc5,0xc7,0xc7,0xfd}, //Q
  {0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xe1,0xd1,0xc9,0xc5,0xc3}, //R
  {0xff,0xc1,0xc1,0xc1,0xc1,0xff,0x07,0x07,0x07,0x07,0xff}, //S
  {0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11}, //T
  {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xff}, //U
  {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x45,0x29,0x11}, //V
  {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xd3,0xeb,0xc7,0x83}, //W
  {0xc7,0xc7,0xc7,0x45,0x29,0x11,0x29,0x45,0xc7,0xc7,0xc7}, //X
  {0xc7,0xc7,0xc7,0x45,0x29,0x11,0x11,0x11,0x11,0x11,0x11}, //Y
  {0xff,0x07,0x07,0x05,0x09,0x11,0x21,0x41,0xc1,0xc1,0xff}, //Z
{0x01, 0x01, 0xff, 0x07, 0x07, 0x07, 0xff, 0x87, 0x87, 0x87, 0xff}, // a
{0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xff, 0xc3, 0xc3, 0xc3, 0xff}, // b
{0x01, 0x01, 0xff, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xff}, // c
{0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff, 0x87, 0x87, 0x87, 0xff}, // d
{0x01, 0x01, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xc1, 0xc1, 0xc1, 0xff}, // e
{0x7f, 0x61, 0x61, 0x61, 0x61, 0xfd, 0x61, 0x61, 0x61, 0x61, 0x61}, // f
{0xff, 0x87, 0x87, 0x87, 0x87, 0xff, 0x07, 0x07, 0xe7, 0x87, 0xff}, // g
{0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, // h
{0x11, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11}, // i
{0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0xff}, // j
{0xc1, 0xc1, 0xc3, 0xc5, 0xc9, 0xd1, 0xe1, 0xd1, 0xc9, 0xc5, 0xc3}, // k
{0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11}, // l
{0x01, 0x01, 0xff, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb}, // m
{0x01, 0x01, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, // n
{0x01, 0x01, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff}, // o
{0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1}, // p
{0xff, 0x87, 0x87, 0x87, 0x87, 0xff, 0x07, 0x07, 0x07, 0x07, 0x07}, // q
{0x01, 0x01, 0xdf, 0xe1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1}, // r
{0x01, 0x01, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0x07, 0x07, 0x07, 0xff}, // s
{0x01, 0x61, 0x61, 0x61, 0x61, 0xfd, 0x61, 0x61, 0x61, 0x61, 0x7f}, // t
{0x01, 0x01, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff}, // u
{0x01, 0x01, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x45, 0x29, 0x11}, // v
{0x01, 0x01, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xff}, // w
{0x01, 0x01, 0xc7, 0xc7, 0x45, 0x29, 0x11, 0x29, 0x45, 0xc7, 0xc7}, // x
{0x87, 0x87, 0x87, 0x87, 0x87, 0xff, 0x07, 0x07, 0xc7, 0x87, 0xff}, // y
{0x01, 0x01, 0xff, 0x07, 0x05, 0x09, 0x11, 0x21, 0x41, 0xc1, 0xff}, // z
{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11}, // .
{0xff, 0x87, 0x87, 0x87, 0x07, 0x05, 0x09, 0x11, 0x11, 0x01, 0x11}, // ?
{0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x11}, // !
{0x01, 0x01, 0x01, 0x01, 0x01, 0x7d, 0x01, 0x01, 0x01, 0x01, 0x01}, // -
{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff}, // _
{0x01, 0x01, 0x11, 0x11, 0x11, 0xff, 0x11, 0x11, 0x11, 0x01, 0x01}, // +
{0x29, 0x29, 0x29, 0x29, 0xff, 0x29, 0xff, 0x29, 0x29, 0x29, 0x29}, // #
{0xff, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xff}, // (
{0xff, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff} // )
};


void setup() {
  strip.begin();
  strip.show();
}

char i,j,k;

void loop() {
  for (i=1;i<=61;i++)
  {
    for(j=20;j>0;j--)
    {
      printletter(i,j);
      strip.show();
      delay(50);
    }
  }
}
/*******************************************/
void printletter(char alpha, char br)
{
  char i,j,k,l;
  char lednr=0;
  alpha--;
  for(i=0;i<11;i++) //i staat voor de 11 arrays om de letter te vormen
  {
    if(i%2) //bij oneven rijen (1 3 5 7 9)
    {                    //j staat voor de 7 bits per register die nodig zijn
      for(j=1;j<8;j++)   //van LSB naar MSB en skip bit0
      {                
        if(letter[alpha][i] & (0x01<<j))
        {
          strip.setPixelColor(lednr,strip.Color(br,br,br));
          lednr++;
          //Serial.print("1");
        }
        else
        {
          strip.setPixelColor(lednr,strip.Color(0,0,0));
          lednr++;
          //Serial.print("0");
        }
      }
    }
/***/
    else //bij even rijen (0 2 4 6 8 10)
    {                    //j staat voor de 7 bits per register die nodig zijn
      for(j=0;j<7;j++)   //van MSB naar LSB en skip bit0
      {                
        if(letter[alpha][i] & (0x80>>j))
        {
          strip.setPixelColor(lednr,strip.Color(br,br,br));
          lednr++;
          //Serial.print("1");
        }
        else
        {
          strip.setPixelColor(lednr,strip.Color(0,0,0));
          lednr++;
          //Serial.print("0");
        }
      }
    }
  }
}
