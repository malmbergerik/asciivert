#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

/* Dark → Light */
static const char ascii[] =
"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

/* Map grayscale [0..255] → ASCII */
char grayToAscii(uint8_t gray) {
    int n = sizeof(ascii) - 1;   // exclude '\0'
    int index = (gray * (n - 1)) / 255;
    return ascii[index];
}

// Approximating RGB
uint8_t rgbToGray(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(
        (77  * r +   // 0.299 * 256
         150 * g +   // 0.587 * 256
         29  * b) >> 8
    );
}
