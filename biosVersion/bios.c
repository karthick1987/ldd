#include<stdio.h>
#include<stdbool.h>

bool main(void)
{
    // Add linux version of Read BIOS Version
    FILE *biosFile = fopen("/sys/class/dmi/id/bios_version1", "r");
    if (!biosFile)
    {
        return false;
    }
    char buf[100];
    int readBytes = fread((void *) buf, sizeof(buf) , 1 ,biosFile);
    printf("Number of Bytes read: %d\n",readBytes);
    printf("Bios version: %s\n", buf);
    fclose(biosFile);
    return true;
}
