#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_TweenTimer
#define INCLUDED_com_eclecticdesignstudio_motion__Actuate_TweenTimer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,_Actuate,TweenTimer)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace _Actuate{


class TweenTimer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TweenTimer_obj OBJ_;
		TweenTimer_obj();
		Void __construct(Float progress);

	public:
		static hx::ObjectPtr< TweenTimer_obj > __new(Float progress);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TweenTimer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TweenTimer"); }

		Float progress; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace _Actuate

#endif /* INCLUDED_com_eclecticdesignstudio_motion__Actuate_TweenTimer */ 
