#define HEADER_SIZE 54
#define BIAS 90 // 0  -->  99 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float calcDist(int a,int b,int size){
    a /= 3;
    b /= 3;
    int ax = a % size;
    int ay = (a / size) + 1;
    int bx = b % size;
    int by = (b / size) + 1;
    return sqrt( pow(ax - bx , 2) + pow(ay - by , 2) );
}


int main(int argc, char const *argv[])
{
    srand(time(NULL) * 1000);
    char * p;
    const int size = 500; // strtol(argv[1],&p,10);
    const int datasize = HEADER_SIZE + size * size * 3;
    char data[datasize];
    int peaks[size * size];
    
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
    int index = 0;
    for (int j = HEADER_SIZE; j < datasize - 1; j+=3)
    {
        int randed = rand() % 1000 < abs(900 + BIAS) ? 255 : 0;
        if (randed == 0)
        {
            //printf("\n%d",j - HEADER_SIZE);
            peaks[index] = j - HEADER_SIZE;
            index++;
        }
        
        data[j] = randed;
        data[j+1] = randed;
        data[j+2] = randed;
    }
    float max = fabsf(calcDist(0,size*size,size));
    for (int j = HEADER_SIZE; j < datasize - 1; j+=3)
    {
        int min = calcDist(peaks[1],j,size);
        int mini = 0;
        int l;
        for (l = 0; l < index + 1; l++)
        {
            if(calcDist(peaks[l],j,size) < min){
                mini = l;
                min = calcDist(peaks[l],j,size);
            }
        }
        float value = calcDist(peaks[mini],j,size) * 10;
        data[j] = (int)((value) / (max) * 255);
        data[j+1] = (int)((value) / (max) * 255);
        data[j+2] = (int)((value) / (max) * 255);
    }
    

    fwrite(&data,1,datasize,fp);
    fclose(fp);
    return 0;
}
