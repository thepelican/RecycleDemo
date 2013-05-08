#ifndef INCLUDED_motion_actuators_GenericActuator
#define INCLUDED_motion_actuators_GenericActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/actuators/IGenericActuator.h>
HX_DECLARE_CLASS2(motion,actuators,GenericActuator)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
HX_DECLARE_CLASS2(motion,easing,IEasing)
namespace motion{
namespace actuators{


class GenericActuator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GenericActuator_obj OBJ_;
		GenericActuator_obj();
		Void __construct(Dynamic target,Float duration,Dynamic properties);

	public:
		static hx::ObjectPtr< GenericActuator_obj > __new(Dynamic target,Float duration,Dynamic properties);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GenericActuator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::motion::actuators::IGenericActuator_obj *()
			{ return new ::motion::actuators::IGenericActuator_delegate_< GenericActuator_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("GenericActuator"); }

		virtual Void stop( Dynamic properties,bool complete,bool sendEvent);
		Dynamic stop_dyn();

		virtual ::motion::actuators::IGenericActuator snapping( Dynamic value);
		Dynamic snapping_dyn();

		virtual ::motion::actuators::IGenericActuator smartRotation( Dynamic value);
		Dynamic smartRotation_dyn();

		virtual ::motion::actuators::IGenericActuator reverse( Dynamic value);
		Dynamic reverse_dyn();

		virtual Void resume( );
		Dynamic resume_dyn();

		virtual ::motion::actuators::IGenericActuator repeat( Dynamic times);
		Dynamic repeat_dyn();

		virtual ::motion::actuators::IGenericActuator reflect( Dynamic value);
		Dynamic reflect_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual ::motion::actuators::IGenericActuator onUpdate( Dynamic handler,Dynamic parameters);
		Dynamic onUpdate_dyn();

		virtual ::motion::actuators::IGenericActuator onRepeat( Dynamic handler,Dynamic parameters);
		Dynamic onRepeat_dyn();

		virtual ::motion::actuators::IGenericActuator onComplete( Dynamic handler,Dynamic parameters);
		Dynamic onComplete_dyn();

		virtual Void move( );
		Dynamic move_dyn();

		virtual ::motion::actuators::IGenericActuator ease( ::motion::easing::IEasing easing);
		Dynamic ease_dyn();

		virtual ::motion::actuators::IGenericActuator delay( Float duration);
		Dynamic delay_dyn();

		virtual Void complete( hx::Null< bool >  sendEvent);
		Dynamic complete_dyn();

		virtual Void change( );
		Dynamic change_dyn();

		virtual ::motion::actuators::IGenericActuator autoVisible( Dynamic value);
		Dynamic autoVisible_dyn();

		virtual Void apply( );
		Dynamic apply_dyn();

		bool special; /* REM */ 
		bool _snapping; /* REM */ 
		bool _smartRotation; /* REM */ 
		bool _reverse; /* REM */ 
		int _repeat; /* REM */ 
		bool _reflect; /* REM */ 
		Dynamic _onUpdateParams; /* REM */ 
		Dynamic _onUpdate; /* REM */ 
		Dynamic _onRepeatParams; /* REM */ 
		Dynamic _onRepeat; /* REM */ 
		Dynamic _onCompleteParams; /* REM */ 
		Dynamic _onComplete; /* REM */ 
		::motion::easing::IEasing _ease; /* REM */ 
		Float _delay; /* REM */ 
		bool _autoVisible; /* REM */ 
		Dynamic target; /* REM */ 
		Dynamic properties; /* REM */ 
		::String id; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_motion_actuators_GenericActuator */ 
