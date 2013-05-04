#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Elastic
#include <com/eclecticdesignstudio/motion/easing/Elastic.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ElasticEaseIn
#include <com/eclecticdesignstudio/motion/easing/ElasticEaseIn.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ElasticEaseInOut
#include <com/eclecticdesignstudio/motion/easing/ElasticEaseInOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_ElasticEaseOut
#include <com/eclecticdesignstudio/motion/easing/ElasticEaseOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{

Void Elastic_obj::__construct()
{
	return null();
}

Elastic_obj::~Elastic_obj() { }

Dynamic Elastic_obj::__CreateEmpty() { return  new Elastic_obj; }
hx::ObjectPtr< Elastic_obj > Elastic_obj::__new()
{  hx::ObjectPtr< Elastic_obj > result = new Elastic_obj();
	result->__construct();
	return result;}

Dynamic Elastic_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Elastic_obj > result = new Elastic_obj();
	result->__construct();
	return result;}

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::easeIn;

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::easeInOut;

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::easeOut;

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::getEaseIn( ){
	HX_STACK_PUSH("Elastic::getEaseIn","com/eclecticdesignstudio/motion/easing/Elastic.hx",20);
	HX_STACK_LINE(20)
	return ::com::eclecticdesignstudio::motion::easing::ElasticEaseIn_obj::__new(0.1,0.4);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Elastic_obj,getEaseIn,return )

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::getEaseInOut( ){
	HX_STACK_PUSH("Elastic::getEaseInOut","com/eclecticdesignstudio/motion/easing/Elastic.hx",27);
	HX_STACK_LINE(27)
	return ::com::eclecticdesignstudio::motion::easing::ElasticEaseInOut_obj::__new(0.1,0.4);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Elastic_obj,getEaseInOut,return )

::com::eclecticdesignstudio::motion::easing::IEasing Elastic_obj::getEaseOut( ){
	HX_STACK_PUSH("Elastic::getEaseOut","com/eclecticdesignstudio/motion/easing/Elastic.hx",34);
	HX_STACK_LINE(34)
	return ::com::eclecticdesignstudio::motion::easing::ElasticEaseOut_obj::__new(0.1,0.4);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Elastic_obj,getEaseOut,return )


Elastic_obj::Elastic_obj()
{
}

void Elastic_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Elastic);
	HX_MARK_END_CLASS();
}

void Elastic_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Elastic_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return inCallProp ? getEaseIn() : easeIn; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return inCallProp ? getEaseOut() : easeOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return inCallProp ? getEaseInOut() : easeInOut; }
		if (HX_FIELD_EQ(inName,"getEaseIn") ) { return getEaseIn_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getEaseOut") ) { return getEaseOut_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getEaseInOut") ) { return getEaseInOut_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Elastic_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Elastic_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeInOut"),
	HX_CSTRING("easeOut"),
	HX_CSTRING("getEaseIn"),
	HX_CSTRING("getEaseInOut"),
	HX_CSTRING("getEaseOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Elastic_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Elastic_obj::easeIn,"easeIn");
	HX_MARK_MEMBER_NAME(Elastic_obj::easeInOut,"easeInOut");
	HX_MARK_MEMBER_NAME(Elastic_obj::easeOut,"easeOut");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Elastic_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Elastic_obj::easeIn,"easeIn");
	HX_VISIT_MEMBER_NAME(Elastic_obj::easeInOut,"easeInOut");
	HX_VISIT_MEMBER_NAME(Elastic_obj::easeOut,"easeOut");
};

Class Elastic_obj::__mClass;

void Elastic_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.Elastic"), hx::TCanCast< Elastic_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Elastic_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
