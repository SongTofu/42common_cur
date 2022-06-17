#include "ex01_h.hpp"

void	wait_command()
{
	std::cout << "-------COMMAND PLZ-------" << std::endl;
	std::cout << "| ADD || SEARCH || EXIT |" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

void	print_for_people(std::string str)
{
	std::cout << "Input " << str << std::endl;
}

void	Phonebook::add(int idx)
{
	int	i;
	std::string contact[5] = {"Fisrt Name", "Last Name", "NickName", "Phone Number", "Darkest Secret"};
	std::string	input;

	i = -1;
	while (++i < 5)
	{
		print_for_people(contact[i]);
		if (!std::getline(std::cin, input))
			exit(0);
		if (i == 0)
			peoples[idx].set_first_name(input);
		else if (i == 1)
			peoples[idx].set_last_name(input);
		else if (i == 2)
			peoples[idx].set_nickname(input);
		else if (i == 3)
			peoples[idx].set_phone_number(input);
		else if (i == 4)
			peoples[idx].set_darkest_secret(input);
	}
}

void	print_correct_length(std::string str)
{
	size_t	len;

	len = str.length();
	if (len <= 10)
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
	else
	{
		std::cout << str.substr(0, 9);
		if (isprint(str[9]))
			std::cout << '.';
	}
	std::cout << "|";
}

void	People::print_for_search()
{
	print_correct_length(first_name);
	print_correct_length(last_name);
	print_correct_length(nickname);
}

void	People::print_find_idx()
{
	std::string contact[5] = {"Fisrt Name", "Last Name", "NickName", "Phone Number", "Darkest Secret"};

	std::cout << contact[0] << " :: " << first_name << std::endl;
	std::cout << contact[1] << " :: " << last_name << std::endl;
	std::cout << contact[2] << " :: " << nickname << std::endl;
	std::cout << contact[3] << " :: " << phone_number << std::endl;
	std::cout << contact[4] << " :: " << darkest_secret << std::endl;
}

void	Phonebook::idx_search(int count)
{
	std::string	find;
	int	f;

	std::cout << "PUT CONTACT INDEX" << std::endl;
	while (1)
	{
		if (!std::getline(std::cin, find))
			exit(0);
		if (find.length() == 1 && find[0] >= '0' && find[0] <= '7' && atoi(&find[0]) < count)
		{
			f = atoi(&find[0]);
			peoples[f].print_find_idx();
			break;
		}
		else
			std::cout << "NOT CORRECT CONTACT INDEX" << std::endl;
	}
}

void	Phonebook::search(int full, int idx)
{
	int	count = 0;

	if (full == 1)
		count = 8;
	else if (idx == 0 && !full)
	{
		std::cout << "-------EMPTY BOOK-------" << std::endl;
		return;
	}
	else
		count = idx;
	for (int i = 0 ; i < count ; i++)
	{
		std::cout << "|" << i << "|";
		peoples[i].print_for_search();
		std::cout << std::endl;
	}
	idx_search(count);
}

int	main()
{
	Phonebook	book;
	std::string	cmd;
	int	idx;
	int	full;

	idx = 0;
	full = 0;
	while (cmd != "EXIT")
	{
		wait_command();
		if (!std::getline(std::cin, cmd))
			exit(0);
		if (cmd == "ADD")
		{
			book.add(idx);
			idx++;
		}
		if (cmd == "SEARCH")
			book.search(full, idx);
		if (idx == 8)
		{
			idx = 0;
			full = 1;
		}
	}
}