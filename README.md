# Noise Image Generator

This program generates a noise image and saves it as a BMP file. The user can specify the width and height of the image.

## Features

- Generates a random noise image.
- Saves the image as a BMP file.

## Requirements

- C Compiler (e.g., GCC)

## How to Use

1. **Compile the Program**

    ```sh
    gcc -o noise_image_generator noise_image_generator.c
    ```

2. **Run the Program**

    ```sh
    ./noise_image_generator <width> <height> <output_file>
    ```

    - `<width>`: Width of the image.
    - `<height>`: Height of the image.
    - `<output_file>`: Name of the output BMP file.

    Example:

    ```sh
    ./noise_image_generator 800 600 noise.bmp
    ```


