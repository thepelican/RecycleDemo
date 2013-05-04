#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/actuators/IGenericActuator.h>
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,GenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,IGenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
namespace com{
namespace eclecticdesignstudio{
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
		inline operator ::com::eclecticdesignstudio::motion::actuators::IGenericActuator_obj *()
			{ return new ::com::eclecticdesignstudio::motion::actuators::IGenericActuator_delegate_< GenericActuator_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("GenericActuator"); }

		virtual Void stop( Dynamic properties,bool complete,bool sendEvent);
		Dynamic stop_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator snapping( Dynamic value);
		Dynamic snapping_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator smartRotation( Dynamic value);
		Dynamic smartRotation_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator reverse( Dynamic value);
		Dynamic reverse_dyn();

		virtual Void resume( );
		Dynamic resume_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator repeat( Dynamic times);
		Dynamic repeat_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator reflect( Dynamic value);
		Dynamic reflect_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator onUpdate( Dynamic handler,Dynamic parameters);
		Dynamic onUpdate_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator onRepeat( Dynamic handler,Dynamic parameters);
		Dynamic onRepeat_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator onComplete( Dynamic handler,Dynamic parameters);
		Dynamic onComplete_dyn();

		virtual Void move( );
		Dynamic move_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator ease( ::com::eclecticdesignstudio::motion::easing::IEasing easing);
		Dynamic ease_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator delay( Float duration);
		Dynamic delay_dyn();

		virtual Void complete( hx::Null< bool >  sendEvent);
		Dynamic complete_dyn();

		virtual Void change( );
		Dynamic change_dyn();

		virtual ::com::eclecticdesignstudio::motion::actuators::IGenericActuator autoVisible( Dynamic value);
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
		::com::eclecticdesignstudio::motion::easing::IEasing _ease; /* REM */ 
		Float _delay; /* REM */ 
		bool _autoVisible; /* REM */ 
		Dynamic target; /* REM */ 
		Dynamic properties; /* REM */ 
		::String id; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator */ 
