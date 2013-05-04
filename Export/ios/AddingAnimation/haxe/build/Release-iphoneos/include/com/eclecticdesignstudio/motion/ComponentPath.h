#ifndef INCLUDED_com_eclecticdesignstudio_motion_ComponentPath
#define INCLUDED_com_eclecticdesignstudio_motion_ComponentPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/IComponentPath.h>
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,BezierPath)
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,ComponentPath)
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,IComponentPath)
namespace com{
namespace eclecticdesignstudio{
namespace motion{


class ComponentPath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ComponentPath_obj OBJ_;
		ComponentPath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ComponentPath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ComponentPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::eclecticdesignstudio::motion::IComponentPath_obj *()
			{ return new ::com::eclecticdesignstudio::motion::IComponentPath_delegate_< ComponentPath_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("ComponentPath"); }

		virtual Float get_end( );
		Dynamic get_end_dyn();

		virtual Float calculate( Float k);
		Dynamic calculate_dyn();

		virtual Void addPath( ::com::eclecticdesignstudio::motion::BezierPath path);
		Dynamic addPath_dyn();

		Float totalStrength; /* REM */ 
		Array< ::com::eclecticdesignstudio::motion::BezierPath > paths; /* REM */ 
		Float end; /* REM */ 
		Float start; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion

#endif /* INCLUDED_com_eclecticdesignstudio_motion_ComponentPath */ 
