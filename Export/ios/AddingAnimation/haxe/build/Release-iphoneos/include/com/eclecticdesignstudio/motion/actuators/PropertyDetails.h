#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,PropertyDetails)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{


class PropertyDetails_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PropertyDetails_obj OBJ_;
		PropertyDetails_obj();
		Void __construct(Dynamic target,::String propertyName,Float start,Float change,hx::Null< bool >  __o_isField);

	public:
		static hx::ObjectPtr< PropertyDetails_obj > __new(Dynamic target,::String propertyName,Float start,Float change,hx::Null< bool >  __o_isField);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PropertyDetails_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PropertyDetails"); }

		Dynamic target; /* REM */ 
		Float start; /* REM */ 
		::String propertyName; /* REM */ 
		bool isField; /* REM */ 
		Float change; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails */ 
