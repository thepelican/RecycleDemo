#ifndef INCLUDED_motion_actuators_SimpleActuator
#define INCLUDED_motion_actuators_SimpleActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/actuators/GenericActuator.h>
HX_DECLARE_CLASS2(motion,actuators,GenericActuator)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
HX_DECLARE_CLASS2(motion,actuators,PropertyDetails)
HX_DECLARE_CLASS2(motion,actuators,SimpleActuator)
HX_DECLARE_CLASS2(native,events,Event)
namespace motion{
namespace actuators{


class SimpleActuator_obj : public ::motion::actuators::GenericActuator_obj{
	public:
		typedef ::motion::actuators::GenericActuator_obj super;
		typedef SimpleActuator_obj OBJ_;
		SimpleActuator_obj();
		Void __construct(Dynamic target,Float duration,Dynamic properties);

	public:
		static hx::ObjectPtr< SimpleActuator_obj > __new(Dynamic target,Float duration,Dynamic properties);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SimpleActuator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SimpleActuator"); }

		virtual Void update( Float currentTime);
		Dynamic update_dyn();

		virtual Void stop( Dynamic properties,bool complete,bool sendEvent);

		virtual Void resume( );

		virtual Void pause( );

		virtual ::motion::actuators::IGenericActuator onUpdate( Dynamic handler,Dynamic parameters);

		virtual Void move( );

		virtual Void initialize( );
		Dynamic initialize_dyn();

		virtual ::motion::actuators::IGenericActuator delay( Float duration);

		virtual ::motion::actuators::IGenericActuator autoVisible( Dynamic value);

		bool toggleVisible; /* REM */ 
		Float startTime; /* REM */ 
		bool setVisible; /* REM */ 
		bool sendChange; /* REM */ 
		Array< ::motion::actuators::PropertyDetails > propertyDetails; /* REM */ 
		Float pauseTime; /* REM */ 
		bool paused; /* REM */ 
		bool initialized; /* REM */ 
		int detailsLength; /* REM */ 
		bool cacheVisible; /* REM */ 
		bool active; /* REM */ 
		Float timeOffset; /* REM */ 
		static Array< ::motion::actuators::SimpleActuator > actuators; /* REM */ 
		static int actuatorsLength; /* REM */ 
		static bool addedEvent; /* REM */ 
		static Void stage_onEnterFrame( ::native::events::Event event);
		static Dynamic stage_onEnterFrame_dyn();

};

} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_motion_actuators_SimpleActuator */ 
