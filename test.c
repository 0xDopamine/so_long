#include <mlx.h>
#include <stdio.h>

int key_hook(int keycode, void *ptr)
{
    printf("ana hmar");
    return 0;
}

int main()
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "abida hmar");

    mlx_key_hook(win, key_hook, (void *)0);
    mlx_loop(mlx);
    return 0;
}