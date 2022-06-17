#ifndef EX01_H_HPP
# define EX01_H_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cctype>

class People
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	set_first_name(std::string str);
		void	set_last_name(std::string str);
		void	set_nickname(std::string str);
		void	set_phone_number(std::string str);
		void	set_darkest_secret(std::string str);
		void	print_for_search();
		void	print_find_idx();
};

class Phonebook
{
	public:
		People	peoples[8];
		void	add(int idx);
		void	search(int full, int idx);
		void	idx_search(int count);
};

#endif