#include "../mlx/mlx.h"
#include "../incs/so_long.h"

typedef	struct s_data
{
	void	*img;
	void 	*img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void 	*img2;
	void 	*img3;
	char	*relative_path = "./medium_jchevet.xpm";
	int		img_width;
	int		img_height;
	int		i;
	int 	j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./medium_jreverdy.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./medium_mpontill.xpm", &img_width, &img_height);
	i = 0;
	while (i <= 500)
	{
		j = 0;
		while (j <= 1000)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i, j);
			j += 250;
		}
		i += 500;
	}
	mlx_put_image_to_window(mlx, mlx_win, img3, 700, 500);
	mlx_put_image_to_window(mlx, mlx_win, img2, 500, 500);

mlx_loop(mlx);
}

//int	main()
//{
//
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
//	t_data	img2;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img2 = mlx_xpm_file_to_image(mlx, "./medium_jchevet.xpm", &img.img_width, &img.img_height);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	mlx_put_image_to_window(mlx, mlx_win, img2.img, 0, 0);
//	mlx_loop(mlx);
//
//}
//int i;
//int j;
//int k;
//k = 3;
//i = 500;
////	while (i < 700)
////	{
////		j = 500;
////		while (j < k + 500)
////		{
////			my_mlx_pixel_put(&img, j - k / 2, i, 0x00FF0000);
////			j++;
////		}
////		i++;
////		if (i % 2 == 1)
////			k++;
////		if (i % 4 == 2)
////			k++;
////		if (i % 8 == 3)
////			k++;
////	}