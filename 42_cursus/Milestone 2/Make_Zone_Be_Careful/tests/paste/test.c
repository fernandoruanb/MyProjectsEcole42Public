#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 32

void print_texture_dimensions(void *mlx_ptr, char *path)
{
    int width, height;
    void *img;

    img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
    if (!img)
    {
        printf("Error loading texture: %s\n", path);
        return;
    }
    printf("Texture: %s | Width: %d | Height: %d\n", path, width, height);

    // Liberar imagem após carregar e verificar
    mlx_destroy_image(mlx_ptr, img);
}

int main(void)
{
    void *mlx_ptr;

    // Inicializar MLX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        printf("Error initializing MLX\n");
        return (1);
    }

    // Lista de texturas para verificar
    char *textures[] = {
        "Kaelor.xpm",
        "Divine-Diamond.xpm",
        "wall.xpm",
        "Rocket.xpm",
        "floor.xpm",
        NULL
    };

    // Iterar sobre a lista e imprimir dimensões
    for (int i = 0; textures[i] != NULL; i++)
        print_texture_dimensions(mlx_ptr, textures[i]);

    // Finalizar MLX (não precisa abrir janela para apenas verificar imagens)
    return (0);
}

