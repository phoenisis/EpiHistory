#ifndef __SMARTPOINTER_H__
# define	__SMARTPOINTER_H__

template<typename Ptr>
class SmartPointer
{
public:
	SmartPointer() : _ptr(0), _count(0) {};
	SmartPointer(int): _ptr(0), _count(0) {};
	SmartPointer(Ptr *ptr) : _ptr(ptr), _count(new int(1)) {};
	SmartPointer(SmartPointer<Ptr> const & ptr)
	{
		this->_ptr = const_cast<SmartPointer<Ptr> &>(ptr).getPtr();
		this->_count = const_cast<SmartPointer<Ptr> &>(ptr).getCount();
		if (this->_count)
			*(this->_count) += 1;
	}
	~SmartPointer()
	{
		if (this->_count)
		{
			if (*(this->_count) <= 1)
			{
				delete this->_ptr;
				delete this->_count;
			}
			else
				*(_count) -= 1;
		}
	}
	void			forceDelete()
	{
		delete this->_ptr;
		delete this->_count;
	}
	Ptr *			getPtr()
	{
		return (this->_ptr);
	}
	int *			getCount()
	{
		return (this->_count);
	}
	SmartPointer<Ptr> &	operator=(SmartPointer<Ptr> & ptr)
	{
		if (this->_count)
			*(this->_count) -= 1;
		this->_count = ptr.getCount();
		this->_ptr = ptr.getPtr();
		if (this->_count)
			*(this->_count) += 1;
		return (*this);
	}
	void			setCount(int *count)
	{
		this->_count = count;
	}
	void			operator=(Ptr *ptr)
	{
		this->_ptr = ptr;
		if (this->_count)
			*(this->_count) -= 1;
		this->_count = new int(1);
	}
	void			operator=(int zero)
	{
		this->_ptr = zero;
	}
	Ptr *			operator->()
	{
		return (this->_ptr);
	}
	Ptr *			operator[](const unsigned int idx)
	{
		return (this->_ptr + (idx * sizeof(Ptr)));
	}
	Ptr &			operator*()
	{
		return (*(this->_ptr));
	}
	void			swap(Ptr *ptr)
	{
		Ptr *		tmp = ptr;

		ptr = this->_ptr;
		this->_ptr = tmp;
	}
	void			reset()
	{
		this->_ptr = 0;
		if (this->_count && *(this->_count) > 0)
			(*this->_count) -= 1;
	}
private:
	Ptr		* _ptr;
	int		* _count;
};

#endif // !__SMARTPOINTER_H__
