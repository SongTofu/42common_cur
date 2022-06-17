#include "iter.hpp"

int	main(void)
{
	int			arrayInt[5] = {0, 1, 2, 3, 4};
	std::string	arrayStr[5] = {"hello", "world", "my", "name is", "yejin"};
	const char	*arrayStrC[5] = {"apple", "banana", "melon", "peach", "tomato"};
	char		arrayChar[5] = {'w', 'h', 'a', 't', 'f'};

	iter<int>(arrayInt, 5, ft_printf);
	std::cout << std::endl;
	iter<int>(arrayInt, 2, ft_printf);
	std::cout << std::endl;

	iter<std::string>(arrayStr, 5, ft_printf);
	std::cout << std::endl;

	iter<const char *>(arrayStrC, 5, ft_printf);
	std::cout << std::endl;

	iter<char>(arrayChar, 5, ft_printf);
	std::cout << std::endl;

	return (0);
}