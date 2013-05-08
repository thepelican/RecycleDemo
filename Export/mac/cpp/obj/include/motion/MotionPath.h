#ifndef INCLUDED_motion_MotionPath
#define INCLUDED_motion_MotionPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(motion,ComponentPath)
HX_DECLARE_CLASS1(motion,IComponentPath)
HX_DECLARE_CLASS1(motion,MotionPath)
namespace motion{


class MotionPath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MotionPath_obj OBJ_;
		MotionPath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MotionPath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MotionPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MotionPath"); }

		virtual ::motion::IComponentPath get_y( );
		Dynamic get_y_dyn();

		virtual ::motion::IComponentPath get_x( );
		Dynamic get_x_dyn();

		virtual ::motion::MotionPath line( Float x,Float y,hx::Null< Float >  strength);
		Dynamic line_dyn();

		virtual ::motion::MotionPath bezier( Float x,Float y,Float controlX,Float controlY,hx::Null< Float >  strength);
		Dynamic bezier_dyn();

		::motion::ComponentPath _y; /* REM */ 
		::motion::ComponentPath _x; /* REM */ 
		::motion::IComponentPath y; /* REM */ 
		::motion::IComponentPath x; /* REM */ 
};

} // end namespace motion

#endif /* INCLUDED_motion_MotionPath */ 
