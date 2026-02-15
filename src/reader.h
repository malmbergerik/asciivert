#ifndef READER_H
#define READER_H
void buff_read(unsigned char *buffer, int width, int height, int channels, int target_w, int target_h);
void process_frame(unsigned char *buffer, int width, int height, int channels, int target_w);
void read_image(void);
#endif