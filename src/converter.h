#ifndef CONVERTER_H
#define CONVERTER_H

extern char ascii[];                // declare global variable
char intToAscii(int i);
char getAsciiFromLevel(float level, char arr[], int n);
float rgbToBWLevel(int red, int green, int blue);

#endif