#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyPathDetails
#define INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyPathDetails

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/actuators/PropertyDetails.h>
HX_DECLARE_CLASS3(com,eclecticdesignstudio,motion,IComponentPath)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,PropertyDetails)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,actuators,PropertyPathDetails)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{


class PropertyPathDetails_obj : public ::com::eclecticdesignstudio::motion::actuators::PropertyDetails_obj{
	public:
		typedef ::com::eclecticdesignstudio::motion::actuators::PropertyDetails_obj super;
		typedef PropertyPathDetails_obj OBJ_;
		PropertyPathDetails_obj();
		Void __construct(Dynamic target,::String propertyName,::com::eclecticdesignstudio::motion::IComponentPath path,hx::Null< bool >  __o_isField);

	public:
		static hx::ObjectPtr< PropertyPathDetails_obj > __new(Dynamic target,::String propertyName,::com::eclecticdesignstudio::motion::IComponentPath path,hx::Null< bool >  __o_isField);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PropertyPathDetails_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PropertyPathDetails"); }

		::com::eclecticdesignstudio::motion::IComponentPath path; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyPathDetails */ 
