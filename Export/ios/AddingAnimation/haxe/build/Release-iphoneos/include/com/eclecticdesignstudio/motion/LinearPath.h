#ifndef INCLUDED_com_eclecticdesignstudio_motion_LinearPath
#define INCLUDED_com_eclecticdesignstudio_motion_LinearPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/BezierPath.h>
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,BezierPath)
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,LinearPath)
namespace com{
namespace eclecticdesignstudio{
namespace motion{


class LinearPath_obj : public ::com::eclecticdesignstudio::motion::BezierPath_obj{
	public:
		typedef ::com::eclecticdesignstudio::motion::BezierPath_obj super;
		typedef LinearPath_obj OBJ_;
		LinearPath_obj();
		Void __construct(Float end,Float strength);

	public:
		static hx::ObjectPtr< LinearPath_obj > __new(Float end,Float strength);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LinearPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LinearPath"); }

		virtual Float calculate( Float start,Float k);

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion

#endif /* INCLUDED_com_eclecticdesignstudio_motion_LinearPath */ 
