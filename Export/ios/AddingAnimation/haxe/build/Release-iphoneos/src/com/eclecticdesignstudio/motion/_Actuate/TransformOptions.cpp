#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_Actuate
#include <com/eclecticdesignstudio/motion/Actuate.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_TransformOptions
#include <com/eclecticdesignstudio/motion/_Actuate/TransformOptions.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator
#include <com/eclecticdesignstudio/motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_IGenericActuator
#include <com/eclecticdesignstudio/motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_TransformActuator
#include <com/eclecticdesignstudio/motion/actuators/TransformActuator.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace _Actuate{

Void TransformOptions_obj::__construct(Dynamic target,Float duration,bool overwrite)
{
HX_STACK_PUSH("TransformOptions::new","com/eclecticdesignstudio/motion/Actuate.hx",484);
{
	HX_STACK_LINE(486)
	this->target = target;
	HX_STACK_LINE(487)
	this->duration = duration;
	HX_STACK_LINE(488)
	this->overwrite = overwrite;
}
;
	return null();
}

TransformOptions_obj::~TransformOptions_obj() { }

Dynamic TransformOptions_obj::__CreateEmpty() { return  new TransformOptions_obj; }
hx::ObjectPtr< TransformOptions_obj > TransformOptions_obj::__new(Dynamic target,Float duration,bool overwrite)
{  hx::ObjectPtr< TransformOptions_obj > result = new TransformOptions_obj();
	result->__construct(target,duration,overwrite);
	return result;}

Dynamic TransformOptions_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransformOptions_obj > result = new TransformOptions_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::com::eclecticdesignstudio::motion::actuators::IGenericActuator TransformOptions_obj::sound( Dynamic volume,Dynamic pan){
	HX_STACK_PUSH("TransformOptions::sound","com/eclecticdesignstudio/motion/Actuate.hx",521);
	HX_STACK_THIS(this);
	HX_STACK_ARG(volume,"volume");
	HX_STACK_ARG(pan,"pan");
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/Actuate.hx",523);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(523)
	Dynamic properties = _Function_1_1::Block();		HX_STACK_VAR(properties,"properties");
	HX_STACK_LINE(525)
	if (((volume != null()))){
		HX_STACK_LINE(525)
		properties->__FieldRef(HX_CSTRING("soundVolume")) = volume;
	}
	HX_STACK_LINE(531)
	if (((pan != null()))){
		HX_STACK_LINE(531)
		properties->__FieldRef(HX_CSTRING("soundPan")) = pan;
	}
	HX_STACK_LINE(537)
	return ::com::eclecticdesignstudio::motion::Actuate_obj::tween(this->target,this->duration,properties,this->overwrite,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::TransformActuator >());
}


HX_DEFINE_DYNAMIC_FUNC2(TransformOptions_obj,sound,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator TransformOptions_obj::color( hx::Null< Float >  __o_value,hx::Null< Float >  __o_strength,Dynamic alpha){
Float value = __o_value.Default(0);
Float strength = __o_strength.Default(1);
	HX_STACK_PUSH("TransformOptions::color","com/eclecticdesignstudio/motion/Actuate.hx",500);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(strength,"strength");
	HX_STACK_ARG(alpha,"alpha");
{
		struct _Function_1_1{
			inline static Dynamic Block( Float &value,Float &strength){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/Actuate.hx",502);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("colorValue") , value,false);
					__result->Add(HX_CSTRING("colorStrength") , strength,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(502)
		Dynamic properties = _Function_1_1::Block(value,strength);		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(504)
		if (((alpha != null()))){
			HX_STACK_LINE(504)
			properties->__FieldRef(HX_CSTRING("colorAlpha")) = alpha;
		}
		HX_STACK_LINE(510)
		return ::com::eclecticdesignstudio::motion::Actuate_obj::tween(this->target,this->duration,properties,this->overwrite,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::TransformActuator >());
	}
}


HX_DEFINE_DYNAMIC_FUNC3(TransformOptions_obj,color,return )


TransformOptions_obj::TransformOptions_obj()
{
}

void TransformOptions_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransformOptions);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(overwrite,"overwrite");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void TransformOptions_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(overwrite,"overwrite");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic TransformOptions_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { return sound_dyn(); }
		if (HX_FIELD_EQ(inName,"color") ) { return color_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overwrite") ) { return overwrite; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransformOptions_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overwrite") ) { overwrite=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransformOptions_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("overwrite"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sound"),
	HX_CSTRING("color"),
	HX_CSTRING("target"),
	HX_CSTRING("overwrite"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransformOptions_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransformOptions_obj::__mClass,"__mClass");
};

Class TransformOptions_obj::__mClass;

void TransformOptions_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion._Actuate.TransformOptions"), hx::TCanCast< TransformOptions_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TransformOptions_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace _Actuate
