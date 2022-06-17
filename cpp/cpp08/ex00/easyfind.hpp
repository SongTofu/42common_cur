#ifndef EASTFIND_HPP
# define EASTFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T> typename T::iterator	easyfind(T &t, int n)
{
	return (std::find(t.begin(), t.end(), n));
}

#endif