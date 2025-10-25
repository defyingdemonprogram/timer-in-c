#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static const char *shift_arg(int *argc, char ***argv) {
    assert(*argc > 0);
    const char *arg = **argv;
    (*argc)--;
    (*argv)++;
    return arg;
}

int main(int argc, char *argv[]) {
    // skip program name
    shift_arg(&argc, &argv);

    if (argc <= 1) {
        fprintf(stderr, "Usage: png2c <image.png> <variable_name>\n");
        fprintf(stderr, "ERROR: expected a file path and a variable name.\n");
        exit(1);
    }

    const char *filepath = shift_arg(&argc, &argv);
    const char *name = shift_arg(&argc, &argv);

    int x, y, n;
    uint32_t *data = (uint32_t *)stbi_load(filepath, &x, &y, &n, 4);

    if (data == NULL) {
        fprintf(stderr, "Could not load file `%s`\n", filepath);
        exit(1);
    }

    printf("#ifndef PNG_%s_H_\n", name);
    printf("#define PNG_%s_H_\n\n", name);
    printf("static const size_t %s_width  = %d;\n", name, x);
    printf("static const size_t %s_height = %d;\n", name, y);
    printf("static const uint32_t %s_data[] = {\n    ", name);
    
    // Convert RGBA bytes to uint32_t
    for (size_t i = 0; i < (size_t)(x * y); ++i) {
        printf("0x%08x, ", data[i]);
    }
    printf("\n};\n");
    printf("#endif // PNG_%s_H_\n", name);
    stbi_image_free(data);

    return 0;
}

