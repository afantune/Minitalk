#include "../includes/libft.h"

void	ft_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_error("Error: Invalid PID\n");
	}
}
