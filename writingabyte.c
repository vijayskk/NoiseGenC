#define HEADER_SIZE 54
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL) * 1000);
    char * p;
    const int size = 500; // strtol(argv[1],&p,10);
    const int datasize = HEADER_SIZE + size * size * 3;
    char data[datasize];

    const char header[HEADER_SIZE] = {
        0x42,0x4D,
        0xE6,0x71,0x0B,0x00,
        0x00,0x00,
        0x00,0x00,
        0x36,0x00,0x00,0x00,
        0x28,0x00,0x00,0x00,
        0xF4,0x00,0x00,0x00,
        0xF4,0x00,0x00,0x00,
        0x01,0x00,
        0x18,0x00,
        0x00,0x00,0x00,0x00,
        0xB0,0x71,0x0B,0x00,
        0xC4,0x0E,0x00,0x00,
        0xC4,0x0E,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00
    };

    FILE * fp = fopen("image.bmp","w");

    for (int i = 0; i < HEADER_SIZE; i++)
    {
        data[i] = header[i];
    }

    for (int j = HEADER_SIZE; j < datasize - 1; j+=3)
    {
        char randed = rand() % 2 == 0 ? 0xFF : 0x00;
        data[j] = randed;
        data[j+1] = randed;
        data[j+2] = randed;
    }
    

    fwrite(&data,1,datasize,fp);
    fclose(fp);
    return 0;
}
