#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_FilterActuator
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_FilterActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,FilterActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,GenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,IGenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,SimpleActuator)
HX_DECLARE_CLASS2(native,filters,BitmapFilter)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{


class FilterActuator_obj : public ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj{
	public:
		typedef ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj super;
		typedef FilterActuator_obj OBJ_;
		FilterActuator_obj();
		Void __construct(Dynamic target,Float duration,Dynamic properties);

	public:
		static hx::ObjectPtr< FilterActuator_obj > __new(Dynamic target,Float duration,Dynamic properties);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FilterActuator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FilterActuator"); }

		virtual Void update( Float currentTime);

		virtual Void initialize( );

		virtual Void apply( );

		int filterIndex; /* REM */ 
		::Class filterClass; /* REM */ 
		::native::filters::BitmapFilter filter; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_FilterActuator */ 
