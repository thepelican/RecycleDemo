#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_MotionPathActuator
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_MotionPathActuator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,GenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,IGenericActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,MotionPathActuator)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,SimpleActuator)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{


class MotionPathActuator_obj : public ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj{
	public:
		typedef ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj super;
		typedef MotionPathActuator_obj OBJ_;
		MotionPathActuator_obj();
		Void __construct(Dynamic target,Float duration,Dynamic properties);

	public:
		static hx::ObjectPtr< MotionPathActuator_obj > __new(Dynamic target,Float duration,Dynamic properties);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MotionPathActuator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MotionPathActuator"); }

		virtual Void update( Float currentTime);

		virtual Void initialize( );

		virtual Void apply( );

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_MotionPathActuator */ 
