#include <iostream>
#include <fstream>

void	replace(std::string *line, std::string s1, std::string s2)
{
	size_t	pos;

	while ((pos = (*line).find(s1)) != std::string::npos)
	{
		(*line).erase(pos, s1.length());
		(*line).insert(pos, s2);
	}
}

int	main(int ac, char **av)
{
	if (ac != 4 || !av[2][0] || !av[3][0])
		return (-1);
	std::ifstream	ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "Coulnd't open the input file" << std::endl;
		return (-1);
	}
	std::string	file_name = (std::string)av[1] + ".replace";
	std::ofstream	ofs(file_name);
	if (!ofs.is_open())
	{
		std::cout <<  "Coulnd't open the input file" << std::endl;
		return (-1);
	}
	std::string	read_line;
	std::string	s1 = av[2];
	std::string s2 = av[3];
	while(getline(ifs, read_line))
	{
		replace(&read_line, s1, s2);
		if (!std::cin.eof())
			ofs << read_line << std::endl;
	}
	ofs.close();
	ifs.close();
}