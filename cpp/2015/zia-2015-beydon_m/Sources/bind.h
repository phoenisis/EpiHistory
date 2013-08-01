#ifndef			__BIND_HPP__
# define		__BIND_HPP__
# include		"MemberFunction.h"
# include		"Value.h"
# include		"Caller.h"
# include		"TypeList.h"


namespace Function
{
	// C Functions

	template<typename Ret, typename T1, typename Param>
	detail::Caller<Ret, Ret (*)(T1), typename detail::Traits1<Param>::Type>
	bind(Ret (*func)(T1), Param p)
	{
	  typedef typename detail::GetType<Param>::Type	P1;
	  typedef detail::TypeList1<P1>			List;

	  List	l(p);
	  return (detail::Caller<Ret, Ret (*)(T1), List>(func, l));
	}

	template<typename Ret, typename T1, typename T2, typename Param1, typename Param2>
	detail::Caller<Ret, Ret (*)(T1, T2), typename detail::Traits2<Param1, Param2>::Type>
	bind(Ret (*func)(T1, T2), Param1 p1, Param2 p2)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef detail::TypeList2<P1, P2>			List;

	  List	l(p1, p2);
	  return (detail::Caller<Ret, Ret (*)(T1, T2), List>(func, l));
	}

	template<typename Ret, typename T1, typename T2, typename T3, typename Param1, typename Param2, typename Param3>
	detail::Caller<Ret, Ret (*)(T1, T2, T3), typename detail::Traits3<Param1, Param2, Param3>::Type>
	bind(Ret (*func)(T1, T2, T3), Param1 p1, Param2 p2, Param3 p3)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef detail::TypeList3<P1, P2, P3>			List;

	  List	l(p1, p2, p3);
	  return (detail::Caller<Ret, Ret (*)(T1, T2, T3), List>(func, l));
	}

	template<typename Ret, typename T1, typename T2, typename T3, typename T4, typename Param1, typename Param2, typename Param3, typename Param4>
	detail::Caller<Ret, Ret (*)(T1, T2, T3, T4), typename detail::Traits4<Param1, Param2, Param3, Param4>::Type>
	bind(Ret (*func)(T1, T2, T3, T4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef detail::TypeList4<P1, P2, P3, P4>			List;

	  List	l(p1, p2, p3, p4);
	  return (detail::Caller<Ret, Ret (*)(T1, T2, T3, T4), List>(func, l));
	}

	template<typename Ret, typename T1, typename T2, typename T3, typename T4, typename T5,
		typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
	detail::Caller<Ret, Ret (*)(T1, T2, T3, T4, T5), typename detail::Traits5<Param1, Param2, Param3, Param4, Param5>::Type>
	bind(Ret (*func)(T1, T2, T3, T4, T5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef detail::TypeList5<P1, P2, P3, P4, P5>			List;

	  List	l(p1, p2, p3, p4, p5);
	  return (detail::Caller<Ret, Ret (*)(T1, T2, T3, T4, T5), List>(func, l));
	}

	template<typename Ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
		typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
	detail::Caller<Ret, Ret (*)(T1, T2, T3, T4, T5, T6), typename detail::Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type>
	bind(Ret (*func)(T1, T2, T3, T4, T5, T6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef typename detail::GetType<Param6>::Type	P6;
	  typedef detail::TypeList6<P1, P2, P3, P4, P5, P6>			List;

	  List	l(p1, p2, p3, p4, p5, p6);
	  return (detail::Caller<Ret, Ret (*)(T1, T2, T3, T4, T5, T6), List>(func, l));
	}

	// Functors

	template<typename Ret, typename Callable, typename Param>
	detail::Caller<Ret, Callable, typename detail::Traits1<Param>::Type>
	bind(TypeTraits<Ret>, Callable func, Param p)
	{
	  typedef typename detail::GetType<Param>::Type	P1;
	  typedef detail::TypeList1<P1>			List;

	  List	l(p);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	template<typename Ret, typename Callable, typename Param1, typename Param2>
	detail::Caller<Ret, Callable, typename detail::Traits2<Param1, Param2>::Type>
	bind(TypeTraits<Ret>, Callable func, Param1 p1, Param2 p2)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef detail::TypeList2<P1, P2>			List;

	  List	l(p1, p2);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	template<typename Ret, typename Callable, typename Param1, typename Param2, typename Param3>
	detail::Caller<Ret, Callable, typename detail::Traits3<Param1, Param2, Param3>::Type>
	bind(TypeTraits<Ret>, Callable func, Param1 p1, Param2 p2, Param3 p3)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef detail::TypeList3<P1, P2, P3>			List;

	  List	l(p1, p2, p3);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	template<typename Ret, typename Callable, typename Param1, typename Param2, typename Param3, typename Param4>
	detail::Caller<Ret, Callable, typename detail::Traits4<Param1, Param2, Param3, Param4>::Type>
	bind(TypeTraits<Ret>, Callable func, Param1 p1, Param2 p2, Param3 p3, Param4 p4)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef detail::TypeList4<P1, P2, P3, P4>			List;

	  List	l(p1, p2, p3, p4);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	template<typename Ret, typename Callable, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
	detail::Caller<Ret, Callable, typename detail::Traits5<Param1, Param2, Param3, Param4, Param5>::Type>
	bind(TypeTraits<Ret>, Callable func, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef detail::TypeList5<P1, P2, P3, P4, P5>			List;

	  List	l(p1, p2, p3, p4, p5);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	template<typename Ret, typename Callable, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
	detail::Caller<Ret, Callable, typename detail::Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type>
	bind(TypeTraits<Ret>, Callable func, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef typename detail::GetType<Param6>::Type	P6;
	  typedef detail::TypeList6<P1, P2, P3, P4, P5, P6>			List;

	  List	l(p1, p2, p3, p4, p5, p6);
	  return (detail::Caller<Ret, Callable, List>(func, l));
	}

	// Member Function

	template<typename Ret, typename Obj, typename T1, typename Param>
	detail::Caller<Ret, detail::MemberFunction1<Ret, Obj, T1>, typename detail::Traits1<Param>::Type>
	bind(Ret (Obj::*func)(T1), Obj *obj, Param p)
	{
		typedef typename detail::GetType<Param>::Type	P1;
		typedef detail::TypeList1<P1>			List;
		typedef detail::MemberFunction1<Ret, Obj, T1>	binder;

		List	l(p);
		return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

	template<typename Ret, typename Obj, typename T1, typename T2, typename Param1, typename Param2>
	detail::Caller<Ret, detail::MemberFunction2<Ret, Obj, T1, T2>, typename detail::Traits2<Param1, Param2>::Type>
	bind(Ret (Obj::*func)(T1, T2), Obj *obj, Param1 p1, Param2 p2)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef detail::TypeList2<P1, P2>			List;
	  typedef detail::MemberFunction2<Ret, Obj, T1, T2>	binder;

	  List	l(p1, p2);
	  return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

	template<typename Ret, typename Obj, typename T1, typename T2, typename T3, typename Param1, typename Param2, typename Param3>
	detail::Caller<Ret, detail::MemberFunction3<Ret, Obj, T1, T2, T3>, typename detail::Traits3<Param1, Param2, Param3>::Type>
	bind(Ret (Obj::*func)(T1, T2, T3), Obj *obj, Param1 p1, Param2 p2, Param3 p3)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef detail::TypeList3<P1, P2, P3>			List;
	  typedef detail::MemberFunction3<Ret, Obj, T1, T2, T3>	binder;

	  List	l(p1, p2, p3);
	  return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

	template<typename Ret, typename Obj, typename T1, typename T2, typename T3, typename T4,
		typename Param1, typename Param2, typename Param3, typename Param4>
	detail::Caller<Ret, detail::MemberFunction4<Ret, Obj, T1, T2, T3, T4>, typename detail::Traits4<Param1, Param2, Param3, Param4>::Type>
	bind(Ret (Obj::*func)(T1, T2, T3, T4), Obj *obj, Param1 p1, Param2 p2, Param3 p3, Param4 p4)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef detail::TypeList4<P1, P2, P3, P4>			List;
	  typedef detail::MemberFunction4<Ret, Obj, T1, T2, T3, T4> binder;

		List	l(p1, p2, p3, p4);
		return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

	template<typename Ret, typename Obj, typename T1, typename T2, typename T3, typename T4, typename T5,
		typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
	detail::Caller<Ret, detail::MemberFunction5<Ret, Obj, T1, T2, T3, T4, T5>, typename detail::Traits5<Param1, Param2, Param3, Param4, Param5>::Type>
	bind(Ret (Obj::*func)(T1, T2, T3, T4, T5), Obj *obj, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef detail::TypeList5<P1, P2, P3, P4, P5>			List;
	  typedef detail::MemberFunction5<Ret, Obj, T1, T2, T3, T4, T5> binder;

	  List	l(p1, p2, p3, p4, p5);
	  return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

	template<typename Ret, typename Obj, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
		typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
	detail::Caller<Ret, detail::MemberFunction6<Ret, Obj, T1, T2, T3, T4, T5, T6>, typename detail::Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type>
	bind(Ret (Obj::*func)(T1, T2, T3, T4, T5, T6), Obj *obj, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
	{
	  typedef typename detail::GetType<Param1>::Type	P1;
	  typedef typename detail::GetType<Param2>::Type	P2;
	  typedef typename detail::GetType<Param3>::Type	P3;
	  typedef typename detail::GetType<Param4>::Type	P4;
	  typedef typename detail::GetType<Param5>::Type	P5;
	  typedef typename detail::GetType<Param6>::Type	P6;
	  typedef detail::TypeList6<P1, P2, P3, P4, P5, P6>			List;
	  typedef detail::MemberFunction6<Ret, Obj, T1, T2, T3, T4, T5, T6> binder;

	  List	l(p1, p2, p3, p4, p5, p6);
	  return (detail::Caller<Ret, binder, List>(binder(func, obj), l));
	}

}

#endif
