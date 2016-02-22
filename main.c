#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;

	line = NULL;
	if (ac == 3)
	{
		fd1 = open(av[1], O_RDONLY, S_IREAD);
		fd2 = open(av[2], O_RDONLY, S_IREAD);
		ac = 0;
		while (ac < 7)
		{
			ft_putnbr(get_next_line(fd1, &line));
			ft_putstr("\n");
			ft_putstr(line);
			ft_putstr("\n");
			ft_putnbr(get_next_line(fd2, &line));
			ft_putstr("\n");
			ft_putstr(line);
			ft_putstr("\n");
			ac++;
		}
		close(fd1);
		close(fd2);
	}
	return (0);
}
