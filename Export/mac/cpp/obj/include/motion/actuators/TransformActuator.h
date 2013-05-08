#ifndef INCLUDED_motion_actuators_TransformActuator
#define INCLUDED_motion_actuators_TransformActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/actuators/SimpleActuator.h>
HX_DECLARE_CLASS2(motion,actuators,GenericActuator)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
HX_DECLARE_CLASS2(motion,actuators,SimpleActuator)
HX_DECLARE_CLASS2(motion,actuators,TransformActuator)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,media,SoundTransform)
namespace motion{
namespace actuators{


class TransformActuator_obj : public ::motion::actuators::SimpleActuator_obj{
	public:
		typedef ::motion::actuators::SimpleActuator_obj super;
		typedef TransformActuator_obj OBJ_;
		TransformActuator_obj();
		Void __construct(Dynamic target,Float duration,Dynamic properties);

	public:
		static hx::ObjectPtr< TransformActuator_obj > __new(Dynamic target,Float duration,Dynamic properties);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransformActuator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TransformActuator"); }

		virtual Void update( Float currentTime);

		virtual Void initializeSound( );
		Dynamic initializeSound_dyn();

		virtual Void initializeColor( );
		Dynamic initializeColor_dyn();

		virtual Void initialize( );

		virtual Void apply( );

		::native::media::SoundTransform tweenSoundTransform; /* REM */ 
		::native::geom::ColorTransform tweenColorTransform; /* REM */ 
		::native::media::SoundTransform endSoundTransform; /* REM */ 
		::native::geom::ColorTransform endColorTransform; /* REM */ 
};

} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_motion_actuators_TransformActuator */ 
