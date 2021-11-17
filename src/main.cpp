#include "gcc.h"

typedef struct __attribute__((__packed__))
{
  unsigned char byte0;
  unsigned char byte1;
  unsigned char byte2;
  unsigned char byte3;
  unsigned char byte4;
  unsigned char byte5;
  unsigned char byte6;
  unsigned char byte7;
} GCC_report;

int main(void)
{
  GCC_report report;

  // Setup block
  {
    // TODO: Startup handshake ?
  }

  // Loop block
  while(1)
  {
    // Byte 0
    if (READ_START) report.byte0 &= GCC_START;
    else report.byte0 ^= GCC_START;
    
    if (READ_Y) report.byte0 &= GCC_Y;
    else report.byte0 ^= GCC_Y;

    if (READ_X) report.byte0 &= GCC_X;
    else report.byte0 ^= GCC_X;

    if (READ_B) report.byte0 &= GCC_B;
    else report.byte0 ^= GCC_B;
    
    if (READ_A) report.byte0 &= GCC_A;
    else report.byte0 ^= GCC_A;

    // Byte 1
    if (READ_L) report.byte1 &= GCC_L;
    else report.byte1 ^= GCC_L;

    if (READ_R) report.byte1 &= GCC_R;
    else report.byte1 ^= GCC_R;

    if (READ_Z) report.byte1 &= GCC_Z;
    else report.byte1 ^= GCC_Z;

    if (READ_DPAD_UP) report.byte1 &= GCC_DPAD_UP;
    else report.byte1 ^= GCC_DPAD_UP;

    if (READ_DPAD_DOWN) report.byte1 &= GCC_DPAD_DOWN;
    else report.byte1 ^= GCC_DPAD_DOWN;

    if (READ_DPAD_LEFT) report.byte1 &= GCC_DPAD_LEFT;
    else report.byte1 ^= GCC_DPAD_LEFT;

    if (READ_DPAD_RIGHT) report.byte1 &= GCC_DPAD_RIGHT;
    else report.byte1 ^= GCC_DPAD_RIGHT;

    // Byte 2
    if (((READ_LEFT)) && (!(READ_RIGHT)))
    {
      if (READ_TILT)
        report.byte2 = 76; // 40% tilt
      else
        report.byte2 = 0;
    }
    else if ((!(READ_LEFT)) && ((READ_RIGHT)))
    {
      if (READ_TILT)
        report.byte2 = 177;
      else
        report.byte2 = 255;
    }
    else report.byte2 = 127;

    // Byte 3
    if (((READ_DOWN)) && (!(READ_UP)))
    {
      if (READ_TILT)
        report.byte3 = 76;
      else
        report.byte3 = 0;
    }
    else if ((!(READ_DOWN)) && ((READ_UP)))
    {
      if (READ_TILT)
        report.byte3 = 177;
      else
        report.byte3 = 255;
    }
    else if (((READ_DOWN)) && ((READ_UP)))
    {
      // Up takes priority
      if (READ_TILT)
        report.byte3 = 177;
      else
        report.byte3 = 255;
    }
    else report.byte3 = 127;

    // Byte 4
    if (((READ_C_LEFT)) && (!(READ_C_RIGHT))) report.byte4 = 0;
    else if ((!(READ_C_LEFT)) && ((READ_C_RIGHT))) report.byte4 = 255;
    else report.byte4 = 127;

    // Byte 5
    if (((READ_C_UP)) && (!(READ_C_DOWN))) report.byte5 = 0;
    else if ((!(READ_C_UP)) && ((READ_C_DOWN))) report.byte5 = 255;
    else report.byte5 = 127;

    // Byte 6 & 7
    if (report.byte1 & READ_L) report.byte6 = 255;
    else report.byte6 = 0;

    if (report.byte1 & READ_R) report.byte7 = 255;
    else report.byte7 = 0;

    // TODO: Send  
  }
}