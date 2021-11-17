#ifndef GCC_H
#define GCC_H

#define READ_A            GPIO9_DR & (1 << 5)
#define READ_B            GPIO9_DR & (1 << 6)
#define READ_X            GPIO9_DR & (1 << 7)
#define READ_Y            GPIO6_DR & (1 << 10)

#define READ_L            GPIO6_DR & (1 << 17)
#define READ_R            GPIO6_DR & (1 << 16)
#define READ_Z            GPIO7_DR & (1 << 11)

#define READ_START        GPIO8_DR & (1 << 12)
#define READ_MACRO        GPIO8_DR & (1 << 14)
#define READ_TILT         GPIO8_DR & (1 << 13)

#define READ_UP           GPIO6_DR & (1 << 12)
#define READ_DOWN         GPIO6_DR & (1 << 13)
#define READ_LEFT         GPIO6_DR & (1 << 30)
#define READ_RIGHT        GPIO6_DR & (1 << 31)

#define READ_C_UP         GPIO6_DR & (1 << 12)
#define READ_C_DOWN       GPIO6_DR & (1 << 13)
#define READ_C_LEFT       GPIO6_DR & (1 << 30)
#define READ_C_RIGHT      GPIO6_DR & (1 << 31)

#define READ_DPAD_UP      GPIO8_DR & (1 << 18)
#define READ_DPAD_DOWN    GPIO8_DR & (1 << 17)
#define READ_DPAD_LEFT    GPIO8_DR & (1 << 23)
#define READ_DPAD_RIGHT   GPIO8_DR & (1 << 22)

#endif