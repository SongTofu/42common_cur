#pragma once

#include <iostream>

namespace ft
{
	template <class T, T v>
	class integral_constant
	{
	public:
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		const value_type operator()() const {return value;}
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type
	{
	};

	template <class T>
	struct is_integral<const T> : public is_integral<T>
	{
	};
	template <class T>
	struct is_integral<volatile const T> : public is_integral<T>
	{
	};
	template <class T>
	struct is_integral<volatile T> : public is_integral<T>
	{
	};

	template<>
	struct is_integral<unsigned char> : public true_type
	{
	};
	template<>
	struct is_integral<unsigned short> : public true_type
	{
	};
	template<>
	struct is_integral<unsigned int> : public true_type
	{
	};
	template<>
	struct is_integral<unsigned long> : public true_type
	{
	};
	template <>
	struct is_integral<signed char> : public true_type
	{
	};
	template <>
	struct is_integral<short> : public true_type
	{
	};
	template <>
	struct is_integral<int> : public true_type
	{
	};
	template <>
	struct is_integral<long int> : public true_type
	{
	};
	template <>
	struct is_integral<long long int> : public true_type
	{
	};
	template <>
	struct is_integral<unsigned long long int> : public true_type
	{
	};
	template <>
	struct is_integral<char> : public true_type
	{
	};
	template <>
	struct is_integral<bool> : public true_type
	{
	};

	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	class iterator_traits<T *>
	{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	class iterator_traits<const T *>
	{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <bool B, typename T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
}

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)//왜 void?
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ( (first1 == last1 ) && ( first2 != last2) );
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return ( (first1 == last1) && (first2 != last2));
	}
}

namespace ft
{
	template <typename T1, typename T2>
	class pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() :  first(T1()) , second(T2()) {};
		template <typename U, typename V>
		pair(pair<U, V> const &src) : first(src.first), second(src.second) {};
		pair(first_type const &a, second_type const &b) : first(a), second(b) {};

		pair &operator=(pair const &src)
		{
			if (this != &src)
			{
				first = src.first;
				second = src.second;
			}
			return (*(this));
		}
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}
	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	// https://qa.apthow.com/archives/21443
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}