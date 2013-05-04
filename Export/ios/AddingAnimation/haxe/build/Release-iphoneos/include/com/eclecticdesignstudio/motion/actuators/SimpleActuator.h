#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/actuators/GenericActuator.h>
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,GenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,IGenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,PropertyDetails)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,SimpleActuator)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,Shape)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{


class SimpleActuator_obj : public ::com::eclecticdesignstudio::motion::actuators::GenericActuator_obj{
	public:
		typedef ::com::eclecticdesignstudio::motion::actuators::GenericActuator_obj super;
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

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator onUpdate( Dynamic handler,Dynamic parameters);

		virtual Void move( );

		virtual Void initialize( );
		Dynamic initialize_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator delay( Float duration);

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator autoVisible( Dynamic value);

		bool toggleVisible; /* REM */ 
		Float startTime; /* REM */ 
		bool setVisible; /* REM */ 
		bool sendChange; /* REM */ 
		Array< ::com::eclecticdesignstudio::motion::actuators::PropertyDetails > propertyDetails; /* REM */ 
		Float pauseTime; /* REM */ 
		bool paused; /* REM */ 
		bool initialized; /* REM */ 
		int detailsLength; /* REM */ 
		bool cacheVisible; /* REM */ 
		bool active; /* REM */ 
		Float timeOffset; /* REM */ 
		static Array< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator > actuators; /* REM */ 
		static int actuatorsLength; /* REM */ 
		static ::native::display::Shape shape; /* REM */ 
		static Void shape_onEnterFrame( ::native::events::Event event);
		static Dynamic shape_onEnterFrame_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator */ 
