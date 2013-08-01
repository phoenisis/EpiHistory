#ifndef		__TRAITS_HPP__
# define	__TRAITS_HPP__
# include	"Value.h"
# include	"TypeList.h"

namespace Function
{
	namespace detail
	{
		template<typename T1>
		struct TypeList1;
		template<typename T1, typename T2>
		struct TypeList2;
		template<typename T1, typename T2, typename T3>
		struct TypeList3;
		template<typename T1, typename T2, typename T3, typename T4>
		struct TypeList4;
		template<typename T1, typename T2, typename T3, typename T4, typename T5>
		struct TypeList5;
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		struct TypeList6;


		struct		Traits
		{  
		};

		template<typename T1>
		struct		Traits1
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef TypeList1<Type1>		Type;
		};

		template<typename T1, typename T2>
		struct		Traits2
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef typename GetType<T2>::Type	Type2;
		  typedef TypeList2<Type1, Type2>      	Type;
		};

		template<typename T1, typename T2, typename T3>
		struct		Traits3
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef typename GetType<T2>::Type	Type2;
		  typedef typename GetType<T3>::Type	Type3;
		  typedef TypeList3<Type1, Type2, Type3>      	Type;
		};

		template<typename T1, typename T2, typename T3, typename T4>
		struct		Traits4
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef typename GetType<T2>::Type	Type2;
		  typedef typename GetType<T3>::Type	Type3;
		  typedef typename GetType<T4>::Type	Type4;
		  typedef TypeList4<Type1, Type2, Type3, Type4>      	Type;
		};

		template<typename T1, typename T2, typename T3, typename T4, typename T5>
		struct		Traits5
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef typename GetType<T2>::Type	Type2;
		  typedef typename GetType<T3>::Type	Type3;
		  typedef typename GetType<T4>::Type	Type4;
		  typedef typename GetType<T5>::Type	Type5;
		  typedef TypeList5<Type1, Type2, Type3, Type4, Type5>      	Type;
		};

		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		struct		Traits6
		{
		  typedef typename GetType<T1>::Type	Type1;
		  typedef typename GetType<T2>::Type	Type2;
		  typedef typename GetType<T3>::Type	Type3;
		  typedef typename GetType<T4>::Type	Type4;
		  typedef typename GetType<T5>::Type	Type5;
		  typedef typename GetType<T6>::Type	Type6;
		  typedef TypeList6<Type1, Type2, Type3, Type4, Type5, Type6>      	Type;
		};
	}
}
#endif
