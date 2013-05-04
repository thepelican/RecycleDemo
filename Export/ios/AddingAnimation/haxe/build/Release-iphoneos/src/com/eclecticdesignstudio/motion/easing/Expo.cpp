#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Expo
#include <com/eclecticdesignstudio/motion/easing/Expo.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ExpoEaseIn
#include <com/eclecticdesignstudio/motion/easing/ExpoEaseIn.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ExpoEaseInOut
#include <com/eclecticdesignstudio/motion/easing/ExpoEaseInOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ExpoEaseOut
#include <com/eclecticdesignstudio/motion/easing/ExpoEaseOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{

Void Expo_obj::__construct()
{
	return null();
}

Expo_obj::~Expo_obj() { }

Dynamic Expo_obj::__CreateEmpty() { return  new Expo_obj; }
hx::ObjectPtr< Expo_obj > Expo_obj::__new()
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

Dynamic Expo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::easeIn;

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::easeInOut;

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::easeOut;

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::get_easeIn( ){
	HX_STACK_PUSH("Expo::get_easeIn","com/eclecticdesignstudio/motion/easing/Expo.hx",19);
	HX_STACK_LINE(19)
	return ::com::eclecticdesignstudio::motion::easing::ExpoEaseIn_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeIn,return )

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::get_easeInOut( ){
	HX_STACK_PUSH("Expo::get_easeInOut","com/eclecticdesignstudio/motion/easing/Expo.hx",26);
	HX_STACK_LINE(26)
	return ::com::eclecticdesignstudio::motion::easing::ExpoEaseInOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeInOut,return )

::com::eclecticdesignstudio::motion::easing::IEasing Expo_obj::get_easeOut( ){
	HX_STACK_PUSH("Expo::get_easeOut","com/eclecticdesignstudio/motion/easing/Expo.hx",33);
	HX_STACK_LINE(33)
	return ::com::eclecticdesignstudio::motion::easing::ExpoEaseOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeOut,return )


Expo_obj::Expo_obj()
{
}

void Expo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Expo);
	HX_MARK_END_CLASS();
}

void Expo_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Expo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return inCallProp ? get_easeIn() : easeIn; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return inCallProp ? get_easeOut() : easeOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return inCallProp ? get_easeInOut() : easeInOut; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_easeIn") ) { return get_easeIn_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_easeOut") ) { return get_easeOut_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_easeInOut") ) { return get_easeInOut_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Expo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { easeIn=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { easeOut=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { easeInOut=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Expo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeInOut"),
	HX_CSTRING("easeOut"),
	HX_CSTRING("get_easeIn"),
	HX_CSTRING("get_easeInOut"),
	HX_CSTRING("get_easeOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Expo_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Expo_obj::easeIn,"easeIn");
	HX_MARK_MEMBER_NAME(Expo_obj::easeInOut,"easeInOut");
	HX_MARK_MEMBER_NAME(Expo_obj::easeOut,"easeOut");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Expo_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Expo_obj::easeIn,"easeIn");
	HX_VISIT_MEMBER_NAME(Expo_obj::easeInOut,"easeInOut");
	HX_VISIT_MEMBER_NAME(Expo_obj::easeOut,"easeOut");
};

Class Expo_obj::__mClass;

void Expo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.Expo"), hx::TCanCast< Expo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Expo_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
