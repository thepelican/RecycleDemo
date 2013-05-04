#ifndef INCLUDED_com_eclecticdesignstudio_motion_MotionPath
#define INCLUDED_com_eclecticdesignstudio_motion_MotionPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,ComponentPath)
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,IComponentPath)
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,MotionPath)
namespace com{
namespace eclecticdesignstudio{
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

		virtual ::com::eclecticdesignstudio::motion::IComponentPath get_y( );
		Dynamic get_y_dyn();

		virtual ::com::eclecticdesignstudio::motion::IComponentPath get_x( );
		Dynamic get_x_dyn();

		virtual ::com::eclecticdesignstudio::motion::MotionPath line( Float x,Float y,hx::Null< Float >  strength);
		Dynamic line_dyn();

		virtual ::com::eclecticdesignstudio::motion::MotionPath bezier( Float x,Float y,Float controlX,Float controlY,hx::Null< Float >  strength);
		Dynamic bezier_dyn();

		::com::eclecticdesignstudio::motion::ComponentPath _y; /* REM */ 
		::com::eclecticdesignstudio::motion::ComponentPath _x; /* REM */ 
		::com::eclecticdesignstudio::motion::IComponentPath y; /* REM */ 
		::com::eclecticdesignstudio::motion::IComponentPath x; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion

#endif /* INCLUDED_com_eclecticdesignstudio_motion_MotionPath */ 
