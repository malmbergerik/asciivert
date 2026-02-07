#include "converter.c"

int main(void){
    int width, height, channels;

    uint8_t *img = stbi_load(
        "images/smile.png",
        &width,
        &height,
        &channels,
        3           // force RGB
    );

    if (!img) {
        printf("Error when parsing the image\n");
        exit(1);
    }

    for (int y = 0; y < height; y+=2) {   // skip rows (aspect ratio fix)
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * 3;

            uint8_t r = img[idx + 0];
            uint8_t g = img[idx + 1];
            uint8_t b = img[idx + 2];

            uint8_t gray = rgbToGray(r, g, b);
            char c = grayToAscii(gray);
            putchar(c);
        }
        putchar('\n');
    }

    printf("Loaded image with a width of %ipx, a height of %ipx, and %i channels",width,height,channels);
    stbi_image_free(img);
    return 0;
}
