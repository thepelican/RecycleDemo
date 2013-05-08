#ifndef INCLUDED_motion_easing_SineEaseIn
#define INCLUDED_motion_easing_SineEaseIn

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/easing/IEasing.h>
HX_DECLARE_CLASS2(motion,easing,IEasing)
HX_DECLARE_CLASS2(motion,easing,SineEaseIn)
namespace motion{
namespace easing{


class SineEaseIn_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SineEaseIn_obj OBJ_;
		SineEaseIn_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SineEaseIn_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SineEaseIn_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::motion::easing::IEasing_obj *()
			{ return new ::motion::easing::IEasing_delegate_< SineEaseIn_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SineEaseIn"); }

		virtual Float ease( Float t,Float b,Float c,Float d);
		Dynamic ease_dyn();

		virtual Float calculate( Float k);
		Dynamic calculate_dyn();

};

} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_motion_easing_SineEaseIn */ 
