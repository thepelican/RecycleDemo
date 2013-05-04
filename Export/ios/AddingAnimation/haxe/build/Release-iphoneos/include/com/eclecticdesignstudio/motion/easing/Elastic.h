#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Elastic
#define INCLUDED_com_eclecticdesignstudio_motion_easing_Elastic

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,Elastic)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{


class Elastic_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Elastic_obj OBJ_;
		Elastic_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Elastic_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Elastic_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Elastic"); }

		static ::com::eclecticdesignstudio::motion::easing::IEasing easeIn; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing easeInOut; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing easeOut; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing getEaseIn( );
		static Dynamic getEaseIn_dyn();

		static ::com::eclecticdesignstudio::motion::easing::IEasing getEaseInOut( );
		static Dynamic getEaseInOut_dyn();

		static ::com::eclecticdesignstudio::motion::easing::IEasing getEaseOut( );
		static Dynamic getEaseOut_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_com_eclecticdesignstudio_motion_easing_Elastic */ 
