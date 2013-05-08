#include <hxcpp.h>

#ifndef INCLUDED_motion_easing_Back
#include <motion/easing/Back.h>
#endif
#ifndef INCLUDED_motion_easing_BackEaseIn
#include <motion/easing/BackEaseIn.h>
#endif
#ifndef INCLUDED_motion_easing_BackEaseInOut
#include <motion/easing/BackEaseInOut.h>
#endif
#ifndef INCLUDED_motion_easing_BackEaseOut
#include <motion/easing/BackEaseOut.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void Back_obj::__construct()
{
	return null();
}

Back_obj::~Back_obj() { }

Dynamic Back_obj::__CreateEmpty() { return  new Back_obj; }
hx::ObjectPtr< Back_obj > Back_obj::__new()
{  hx::ObjectPtr< Back_obj > result = new Back_obj();
	result->__construct();
	return result;}

Dynamic Back_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Back_obj > result = new Back_obj();
	result->__construct();
	return result;}

::motion::easing::IEasing Back_obj::easeIn;

::motion::easing::IEasing Back_obj::easeInOut;

::motion::easing::IEasing Back_obj::easeOut;

::motion::easing::IEasing Back_obj::get_easeIn( ){
	HX_STACK_PUSH("Back::get_easeIn","motion/easing/Back.hx",19);
	HX_STACK_LINE(19)
	return ::motion::easing::BackEaseIn_obj::__new(1.70158);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Back_obj,get_easeIn,return )

::motion::easing::IEasing Back_obj::get_easeInOut( ){
	HX_STACK_PUSH("Back::get_easeInOut","motion/easing/Back.hx",26);
	HX_STACK_LINE(26)
	return ::motion::easing::BackEaseInOut_obj::__new(1.70158);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Back_obj,get_easeInOut,return )

::motion::easing::IEasing Back_obj::get_easeOut( ){
	HX_STACK_PUSH("Back::get_easeOut","motion/easing/Back.hx",33);
	HX_STACK_LINE(33)
	return ::motion::easing::BackEaseOut_obj::__new(1.70158);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Back_obj,get_easeOut,return )


Back_obj::Back_obj()
{
}

void Back_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Back);
	HX_MARK_END_CLASS();
}

void Back_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Back_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Back_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { easeIn=inValue.Cast< ::motion::easing::IEasing >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { easeOut=inValue.Cast< ::motion::easing::IEasing >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { easeInOut=inValue.Cast< ::motion::easing::IEasing >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Back_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Back_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Back_obj::easeIn,"easeIn");
	HX_MARK_MEMBER_NAME(Back_obj::easeInOut,"easeInOut");
	HX_MARK_MEMBER_NAME(Back_obj::easeOut,"easeOut");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Back_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Back_obj::easeIn,"easeIn");
	HX_VISIT_MEMBER_NAME(Back_obj::easeInOut,"easeInOut");
	HX_VISIT_MEMBER_NAME(Back_obj::easeOut,"easeOut");
};

Class Back_obj::__mClass;

void Back_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.Back"), hx::TCanCast< Back_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Back_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
