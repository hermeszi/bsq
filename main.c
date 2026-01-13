#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 1. validate argc
    if (argc != 2) 
    {
       //printf("Usage: %s <map> \n", argv[0]);
        return 1;
    }
    const char *mapFile = argv[1];
    // 2. open file
    FILE *fp = fopen(mapFile, "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
    
    int line_count;
    char empty_char, obstacle_char, full_char;
    
    int result = fscanf(fp, "%d %c %c %c", &line_count, &empty_char, &obstacle_char, &full_char);
    if (result != 4)
    {
        fclose(fp);
        fprintf(stderr, "map error\n");
        return 1; // Parse error
    }
    // 3.check first line
    if (line_count <= 0 || empty_char == obstacle_char || empty_char == full_char || obstacle_char == full_char)
    {
        fclose(fp);
        fprintf(stderr, "map error\n");
        return 1; // Invalid line count
    }
    
    fclose(fp);
    return 0;
}