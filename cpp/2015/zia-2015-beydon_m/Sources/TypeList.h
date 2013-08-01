#ifndef		__TYPELIST_HPP__
# define	__TYPELIST_HPP__
# include	"Traits.h"
# include	"Storage.h"

namespace Function
{
	namespace detail
	{
		struct		TypeList0 : private Storage0
		{
		};


		template<typename T1>
		struct		TypeList1 : private Storage1<T1>
		{
		  typedef Storage1<T1>	storage;

		  TypeList1(T1 t) : storage(t)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & l)
		  {
			return (c(l[storage::_t1]));
		  }
		};

		template<typename T1, typename T2>
		struct		TypeList2 : private Storage2<T1, T2>
		{
		  typedef Storage2<T1, T2>	storage;

		  TypeList2(T1 t, T2 t2) : storage(t, t2)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & l)
		  {
			return (c(l[storage::_t1], l[storage::_t2]));
		  }  
		};

		template<typename T1, typename T2, typename T3>
		struct		TypeList3 : private Storage3<T1, T2, T3>
		{
		  typedef Storage3<T1, T2, T3>	storage;

		  TypeList3(T1 t, T2 t2, T3 t3) : storage(t, t2, t3)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & list)
		  {
			return (c(list[storage::_t1],
				  list[storage::_t2],
				  list[storage::_t3]));
		  }  
		};

		template<typename T1, typename T2, typename T3, typename T4>
		struct		TypeList4 : private Storage4<T1, T2, T3, T4>
		{
		  typedef Storage4<T1, T2, T3, T4>	storage;

		  TypeList4(T1 t, T2 t2, T3 t3, T4 t4) : storage(t, t2, t3, t4)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & list)
		  {
			return (c(list[storage::_t1],
				  list[storage::_t2],
				  list[storage::_t3],
				  list[storage::_t4]));
		  }  
		};

		template<typename T1, typename T2, typename T3, typename T4, typename T5>
		struct		TypeList5 : private Storage5<T1, T2, T3, T4, T5>
		{
		  typedef Storage5<T1, T2, T3, T4, T5>	storage;

		  TypeList5(T1 t, T2 t2, T3 t3, T4 t4, T5 t5) : storage(t, t2, t3, t4, t5)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & list)
		  {
			return (c(list[storage::_t1],
				  list[storage::_t2],
				  list[storage::_t3],
				  list[storage::_t4],
				  list[storage::_t5]));
		  }    
		};

		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		struct		TypeList6 : private Storage6<T1, T2, T3, T4, T5, T6>
		{
		  typedef Storage6<T1, T2, T3, T4, T5, T6>	storage;

		  TypeList6(T1 t, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) : storage(t, t2, t3, t4, t5, t6)
		  {
		  }
		  template<typename U>
		  U &	operator[](Value<U> & val)
		  {
			return (val.getValue());
		  }
		  template<typename Ret, typename Caller, typename List>
		  Ret	operator()(TypeTraits<Ret>, Caller &c, List & list)
		  {
			return (c(list[storage::_t1],
				  list[storage::_t2],
				  list[storage::_t3],
				  list[storage::_t4],
				  list[storage::_t5],
				  list[storage::_t6]));
		  }  
		};
	}
}

#endif
