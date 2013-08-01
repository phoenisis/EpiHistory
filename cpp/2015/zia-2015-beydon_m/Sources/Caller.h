#ifndef		__CALLER_HPP__
# define	__CALLER_HPP__

namespace Function
{
	namespace detail
	{
		template<typename ReturnType, typename Callable, typename List>
		class		Caller
		{
		public:
			Caller(Callable c, List l): _c(c), _arg(l) {}
			~Caller() {}
			ReturnType		operator()()
			{
				 return (this->_arg(TypeTraits<ReturnType>(), this->_c, this->_arg));
			}
		private:
		  Callable	_c;
		  List		_arg;
		};
	}
}

#endif
