#ifndef INCLUDED_com_eclecticdesignstudio_motion_BezierPath
#define INCLUDED_com_eclecticdesignstudio_motion_BezierPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,BezierPath)
namespace com{
namespace eclecticdesignstudio{
namespace motion{


class BezierPath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BezierPath_obj OBJ_;
		BezierPath_obj();
		Void __construct(Float end,Float control,Float strength);

	public:
		static hx::ObjectPtr< BezierPath_obj > __new(Float end,Float control,Float strength);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BezierPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BezierPath"); }

		virtual Float calculate( Float start,Float k);
		Dynamic calculate_dyn();

		Float strength; /* REM */ 
		Float end; /* REM */ 
		Float control; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion

#endif /* INCLUDED_com_eclecticdesignstudio_motion_BezierPath */ 
