#include "../includes/libft.h"

void	ft_error(const char *message)
{
	if (!message)
		message = "Unknown error";

	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);

	exit(1);
}