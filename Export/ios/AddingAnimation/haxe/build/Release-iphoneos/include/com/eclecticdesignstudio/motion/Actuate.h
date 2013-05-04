#ifndef INCLUDED_com_eclecticdesignstudio_motion_Actuate
#define INCLUDED_com_eclecticdesignstudio_motion_Actuate

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,Actuate)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,_Actuate,EffectsOptions)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,_Actuate,ObjectHash)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,_Actuate,TransformOptions)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,GenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,IGenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace eclecticdesignstudio{
namespace motion{


class Actuate_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Actuate_obj OBJ_;
		Actuate_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Actuate_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Actuate_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Actuate"); }

		static ::Class defaultActuator; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing defaultEase; /* REM */ 
		static ::com::eclecticdesignstudio::motion::_Actuate::ObjectHash targetLibraries; /* REM */ 
		static ::com::eclecticdesignstudio::motion::actuators::IGenericActuator apply( Dynamic target,Dynamic properties,::Class customActuator);
		static Dynamic apply_dyn();

		static ::com::eclecticdesignstudio::motion::actuators::GenericActuator createInstance( ::Class actuator,Dynamic target,Float duration,Dynamic properties);
		static Dynamic createInstance_dyn();

		static ::com::eclecticdesignstudio::motion::_Actuate::EffectsOptions effects( ::native::display::DisplayObject target,Float duration,hx::Null< bool >  overwrite);
		static Dynamic effects_dyn();

		static Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > getLibrary( Dynamic target);
		static Dynamic getLibrary_dyn();

		static ::com::eclecticdesignstudio::motion::actuators::IGenericActuator motionPath( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  overwrite);
		static Dynamic motionPath_dyn();

		static Void pause( Dynamic target);
		static Dynamic pause_dyn();

		static Void pauseAll( );
		static Dynamic pauseAll_dyn();

		static Void reset( );
		static Dynamic reset_dyn();

		static Void resume( Dynamic target);
		static Dynamic resume_dyn();

		static Void resumeAll( );
		static Dynamic resumeAll_dyn();

		static Void stop( Dynamic target,Dynamic properties,hx::Null< bool >  complete,hx::Null< bool >  sendEvent);
		static Dynamic stop_dyn();

		static ::com::eclecticdesignstudio::motion::actuators::IGenericActuator timer( Float duration,::Class customActuator);
		static Dynamic timer_dyn();

		static ::com::eclecticdesignstudio::motion::_Actuate::TransformOptions transform( Dynamic target,hx::Null< Float >  duration,hx::Null< bool >  overwrite);
		static Dynamic transform_dyn();

		static ::com::eclecticdesignstudio::motion::actuators::IGenericActuator tween( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  overwrite,::Class customActuator);
		static Dynamic tween_dyn();

		static Void unload( ::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator);
		static Dynamic unload_dyn();

		static ::com::eclecticdesignstudio::motion::actuators::IGenericActuator update( Dynamic target,Float duration,Dynamic start,Dynamic end,hx::Null< bool >  overwrite);
		static Dynamic update_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion

#endif /* INCLUDED_com_eclecticdesignstudio_motion_Actuate */ 
