#include<stdio.h>
#include<stdbool.h>
#include <stdarg.h>

static int sprintf_s(char *buf, size_t n, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int retval = vsnprintf(buf, n , fmt, args);
    puts(buf);
    va_end(args);
    return retval;
}

static void PrintFError ( char * buf, size_t n, const char * format, ... )
{
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsnprintf (buf,100,format, args);
  puts(buf);
  perror (buffer);
  va_end (args);
}

bool main(void)
{
    // Add linux version of Read BIOS Version
    FILE *biosFile = fopen("/sys/class/dmi/id/bios_version", "r");
    if (!biosFile)
    {
        return false;
    }
    char buf[100], buf2[100];
    int readBytes = fread((void *) buf, sizeof(buf) , 1 ,biosFile);
    printf("Number of Bytes read: %d\n",readBytes);
    printf("Bios version: %s\n", buf);

    int r = 5;
    int rv = 1;
    //PrintFError (buf2, 100, "Error opening %s %d %s",buf, r, buf);
    rv = sprintf_s(buf2, 100, "Number of Bytes read: %d, %d, %s, %s", r, 1542, buf, buf);
    printf("Return value: %d\n", rv);
    fclose(biosFile);
    return true;
}
