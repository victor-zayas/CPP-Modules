#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &src);
		~Array<T>(void);

		Array<T> & operator=(Array<T> const & rhs);
		T & operator[](unsigned int i) const;

		unsigned int getSize(void) const;
		T getElement(unsigned int i) const;
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & rhs);

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) :
	_array(new T[n]),
	_size(n)
{
}

template <typename T>
Array<T>::Array(Array<T> const & src)
{
	*this = src;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs.getSize();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs.getElement(i);
	}
	return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::getSize(void) const
{
	return (this->_size);
}

template <typename T>
T Array<T>::getElement(unsigned int i) const
{
	return (this->_array[i]);
}

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & rhs)
{
	o << "[";
	for (unsigned int i = 0; i < rhs.getSize(); i++)
	{
		o << rhs.getElement(i);
		if (i < rhs.getSize() - 1)
			o << ", ";
	}
	o << "]";
	return (o);
}

#endif