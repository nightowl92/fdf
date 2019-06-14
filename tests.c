/*
line(0, 0, 250, 250, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 0, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 50, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 100, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 150, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 200, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 250, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 300, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 350, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 400, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 450, mlx_ptr, win_ptr, 0);
	line(250, 250, 0, 500, mlx_ptr, win_ptr, 0);

	line(250, 250, 500, 0, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 50, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 100, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 150, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 200, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 250, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 300, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 350, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 400, mlx_ptr, win_ptr, 2);
	line(250, 250, 500, 450, mlx_ptr, win_ptr,2);
	line(250, 250, 500, 500, mlx_ptr, win_ptr,2);	

	line(250, 250, 0, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 50, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 100, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 150, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 200, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 250, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 300, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 350, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 400, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 450, 0, mlx_ptr, win_ptr,1);
	line(250, 250, 500, 0, mlx_ptr, win_ptr,1);

	line(250, 250, 0, 500, mlx_ptr, win_ptr,0);
	line(250, 250, 50, 500, mlx_ptr, win_ptr,0);
	line(250, 250, 100, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 150, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 200, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 250, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 300, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 350, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 400, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 450, 500, mlx_ptr, win_ptr, 0);
	line(250, 250, 500, 500, mlx_ptr, win_ptr, 0);

	while (++i < len)
	{
		j = -1;
		while (w[i][++j])
			if (w[i][j] != ' ' && w[i][j] != '0')
				line(j * 5, i * 5, j * 5 + 5, i * 5 + 5, mlx_ptr, win_ptr, 0);
	}
	line(0, 0, 200, 0, mlx_ptr, win_ptr, 0);
	line(0, 100, 200, 100, mlx_ptr, win_ptr, 0);
	line(0, 200, 200, 200, mlx_ptr, win_ptr, 0);
	line(0, 300, 200, 300, mlx_ptr, win_ptr, 0);
	line(0, 300, 200, 300, mlx_ptr, win_ptr, 0);

	//line(100 + 0 * 5 + 0 * 5, 100 + 0 * 5 + 0 * 5, 100 + 0 * 5 + (0 + 1) * 5, 100 + 0 * 5 + 5 * 0, mlx_ptr, win_ptr, 0);
//line(100 + 0 * 5 + 0 * 5, 100 + 0 * 5 + 0 * 5, 100 + 0 * 5 + 5 * 0, 100 + (0 + 1) * 5 + 0 * 5, mlx_ptr, win_ptr, 0);
/*
i = 0;
j = 0;
int fat = 100;

line(100 + i * fat , 100 + j * fat , 100 + i * fat, 100 + fat * (j + 1), mlx_ptr, win_ptr, 1);
line(100 + i * fat , 100 + j * fat , 100 + (i + 1) * fat, 100 + fat * j, mlx_ptr, win_ptr, 1);
i = 1;
j = 0;
line(100 + i * fat , 100 + j * fat , 100 + i * fat + 10, 100 + fat * (j + 1) + 10, mlx_ptr, win_ptr, 2);
line(100 + i * fat , 100 + j * fat , 100 + (i + 1) * fat, 100 + fat * j, mlx_ptr, win_ptr, 2);
i = 0;
j = 1;
line(100 + i * fat , 100 + j * fat , 100 + i * fat, 100 + fat * (j + 1), mlx_ptr, win_ptr, 0);
line(100 + i * fat , 100 + j * fat , 100 + (i + 1) * fat + 10, 100 + fat * j + 10, mlx_ptr, win_ptr, 0);

i = 1;
j = 1;
line(100 + i * fat + 10, 100 + j * fat + 10, 100 + i * fat, 100 + fat * (j + 1), mlx_ptr, win_ptr, 1);
line(100 + i * fat + 10, 100 + j * fat + 10, 100 + (i + 1) * fat, 100 + fat * j , mlx_ptr, win_ptr, 1);
*/

	/*
	   i = 0;
	   j = 0;
	   int fat = 100;
	   int angle = 15;
	   printf("result is %lf", tandeg(5) * fat);
	   printf("result is %lf", tandeg(30) * fat);
	   printf("result is %lf", tandeg(45) * fat);
	   printf("result is %lf", tandeg(60) * fat);
	   printf("result is %lf", tandeg(90) * fat);

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);

	   i = 1;
	   j = 0;

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);

	   i = 0;
	   j = 1;

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);


	   i = 1;
	   j = 1;

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);

	   i = 2;
	   j = 1;

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);
	   i = 1;
	   j = 2;
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);

	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + i * fat - tandeg(angle) * (j + 1) * fat, 100 + fat * (j + 1) + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 1);
	   line(100 + i * fat - tandeg(angle) * j * fat, 100 + j * fat + tandeg(angle) * i * fat, 100 + (i + 1) * fat - tandeg(angle) * j * fat, 100 + fat * j + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 1);
	   */