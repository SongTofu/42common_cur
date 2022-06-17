#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T	*_data;
	unsigned int	_size;
public:
	Array() : _data(NULL), _size(0) {}
	Array(const unsigned int n) : _size(n) { _data = new T[n]; }
	Array(const Array &arr) : _data(new T[arr._size]), _size(arr._size)
	{
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = arr._data[i];
	}
	~Array()
	{
		delete []_data;
	}
	Array	&operator=(const Array &other)
	{
		if (this != &other)
		{
			if (_size > 0)
				delete [] _data;
			_size = other._size;
			_data = new T[other._size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
		return (*this);
	}
	T	&operator[](const int i) const
	{
		if (i < 0 || static_cast<unsigned int>(i) >= _size)
			throw (OutOfRange());
		return (_data[i]);
	}
	class OutOfRange : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Array::exception : index is out of range");
			}
	};
	unsigned int	size(void) const { return (_size); }
	T 				*getData(void) const { return (_data); }
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & ref)
{
	for (unsigned int i = 0; i < ref.size(); i++)
		std::cout << "T[" << i << "] : " << (ref.getData())[i] << std::endl;
	return (o);
}
#endif
