#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(const T *arr, int len, void(*f)(const T &e))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	ft_printf(const T &data)
{
	std::cout << data << " ";
}

#endif