#include "whatever.hpp"

int	main(void)
{
	int		i_a = 1;
	int		i_b = 2;
	std::cout << "---------- int ----------" << std::endl;
	std::cout << "i_a : " << i_a << " i_b : " << i_b << std::endl;
	std::cout << "min : " << min(i_a, i_b) << std::endl;
	std::cout << "max : " << max(i_a, i_b) << std::endl;
	swap(i_a, i_b);
	std::cout << "swap i_a : " << i_a << " swap i_b : " << i_b << std::endl;

	char	c_a = 'a';
	char	c_b = 'b';
	std::cout << "---------- char ----------" << std::endl;
	std::cout << "c_a : " << c_a << " c_b : " << c_b << std::endl;
	std::cout << "min : " << min(c_a, c_b) << std::endl;
	std::cout << "max : " << max(c_a, c_b) << std::endl;
	swap(c_a, c_b);
	std::cout << "swap c_a : " << c_a << " swap c_b : " << c_b << std::endl;

	float	f_a = 1.5f;
	float	f_b = 2.5f;
	std::cout << "---------- float ----------" << std::endl;
	std::cout << "f_a : " << f_a << " f_b : " << f_b << std::endl;
	std::cout << "min : " << min(f_a, f_b) << std::endl;
	std::cout << "max : " << max(f_a, f_b) << std::endl;
	swap(f_a, f_b);
	std::cout << "swap f_a : " << f_a << " swap f_b : " << f_b << std::endl;

	double	d_a = 3.4e21;
	double	d_b = 3.3e21;
	std::cout << "---------- double ----------" << std::endl;
	std::cout << "d_a : " << d_a << " d_b : " << d_b << std::endl;
	std::cout << "min : " << min(d_a, d_b) << std::endl;
	std::cout << "max : " << max(d_a, d_b) << std::endl;
	swap(d_a, d_b);
	std::cout << "swap d_a : " << d_a << " swap d_b : " << d_b << std::endl;

	std::string	s_a = "abcde";
	std::string	s_b = "fghij";
	std::cout << "---------- string ----------" << std::endl;
	std::cout << "s_a : " << s_a << " s_b : " << s_b << std::endl;
	std::cout << "min : " << min(s_a, s_b) << std::endl;
	std::cout << "max : " << max(s_a, s_b) << std::endl;
	swap(s_a, s_b);
	std::cout << "swap s_a : " << s_a << " swap s_b : " << s_b << std::endl;
	return (0);
}