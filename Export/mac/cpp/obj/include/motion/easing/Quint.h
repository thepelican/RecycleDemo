#ifndef INCLUDED_motion_easing_Quint
#define INCLUDED_motion_easing_Quint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(motion,easing,IEasing)
HX_DECLARE_CLASS2(motion,easing,Quint)
namespace motion{
namespace easing{


class Quint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Quint_obj OBJ_;
		Quint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Quint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Quint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Quint"); }

		static ::motion::easing::IEasing easeIn; /* REM */ 
		static ::motion::easing::IEasing easeInOut; /* REM */ 
		static ::motion::easing::IEasing easeOut; /* REM */ 
		static ::motion::easing::IEasing get_easeIn( );
		static Dynamic get_easeIn_dyn();

		static ::motion::easing::IEasing get_easeInOut( );
		static Dynamic get_easeInOut_dyn();

		static ::motion::easing::IEasing get_easeOut( );
		static Dynamic get_easeOut_dyn();

};

} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_motion_easing_Quint */ 
