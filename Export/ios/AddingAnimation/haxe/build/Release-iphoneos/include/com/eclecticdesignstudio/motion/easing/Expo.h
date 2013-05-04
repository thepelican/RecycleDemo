#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Expo
#define INCLUDED_com_eclecticdesignstudio_motion_easing_Expo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,Expo)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{


class Expo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Expo_obj OBJ_;
		Expo_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Expo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Expo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Expo"); }

		static ::com::eclecticdesignstudio::motion::easing::IEasing easeIn; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing easeInOut; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing easeOut; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing get_easeIn( );
		static Dynamic get_easeIn_dyn();

		static ::com::eclecticdesignstudio::motion::easing::IEasing get_easeInOut( );
		static Dynamic get_easeInOut_dyn();

		static ::com::eclecticdesignstudio::motion::easing::IEasing get_easeOut( );
		static Dynamic get_easeOut_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_com_eclecticdesignstudio_motion_easing_Expo */ 
