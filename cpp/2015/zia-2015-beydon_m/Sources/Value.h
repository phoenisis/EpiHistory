#ifndef		__VALUE_HPP__
# define	__VALUE_HPP__

namespace Function
{
	namespace detail
	{
		template<typename T>
		class		Value
		{
		public:
			Value(T t): _val(t) {};
			~Value() {};
			T &	getValue() { return (this->_val); };
		private:
			T		_val;
		};


		template<typename T>
		class		GetType
		{
		public:
		  typedef Value<T> Type;
		};
	}

	template<typename T>
	struct		TypeTraits
	{
	};

}

#endif
