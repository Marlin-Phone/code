#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("zifu.txt", "r"); 
    output_file = fopen("jieguo.txt", "w");
    
    if (input_file == NULL || output_file == NULL) {
        printf("无法打开文件。\n");
        return 1;
    }

    char buffer[4];
    int count = 0; 

    while (fread(buffer, sizeof(char), 3, input_file) == 3) {
        count += 3;
        if (count % 3 == 0) {
            fwrite(buffer, sizeof(char), 3, output_file);
            fputc('*', output_file);
        }
    }

    if (count % 3 != 0) {
        int remainder = count % 3;
        fwrite(buffer, sizeof(char), remainder, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("处理完成。\n");
    return 0;
}

