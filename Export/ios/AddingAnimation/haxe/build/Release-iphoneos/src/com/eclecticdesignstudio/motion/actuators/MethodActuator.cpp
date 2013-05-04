#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator
#include <com/eclecticdesignstudio/motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_IGenericActuator
#include <com/eclecticdesignstudio/motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_MethodActuator
#include <com/eclecticdesignstudio/motion/actuators/MethodActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails
#include <com/eclecticdesignstudio/motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{

Void MethodActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("MethodActuator::new","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",15);
{
	HX_STACK_LINE(17)
	this->currentParameters = Dynamic( Array_obj<Dynamic>::__new() );
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",18);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(18)
	this->tweenProperties = _Function_1_1::Block();
	HX_STACK_LINE(20)
	super::__construct(target,duration,properties);
	HX_STACK_LINE(22)
	if ((!(::Reflect_obj::hasField(properties,HX_CSTRING("start"))))){
		HX_STACK_LINE(22)
		this->properties->__FieldRef(HX_CSTRING("start")) = Dynamic( Array_obj<Dynamic>::__new() );
	}
	HX_STACK_LINE(28)
	if ((!(::Reflect_obj::hasField(properties,HX_CSTRING("end"))))){
		HX_STACK_LINE(28)
		this->properties->__FieldRef(HX_CSTRING("end")) = this->properties->__Field(HX_CSTRING("start"),true);
	}
	HX_STACK_LINE(34)
	{
		HX_STACK_LINE(34)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->properties->__Field(HX_CSTRING("start"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(34)
		while(((_g1 < _g))){
			HX_STACK_LINE(34)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(36)
			this->currentParameters->__Field(HX_CSTRING("push"),true)(null());
		}
	}
}
;
	return null();
}

MethodActuator_obj::~MethodActuator_obj() { }

Dynamic MethodActuator_obj::__CreateEmpty() { return  new MethodActuator_obj; }
hx::ObjectPtr< MethodActuator_obj > MethodActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< MethodActuator_obj > result = new MethodActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic MethodActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MethodActuator_obj > result = new MethodActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void MethodActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("MethodActuator::update","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(111)
		this->super::update(currentTime);
		HX_STACK_LINE(113)
		if ((this->active)){
			HX_STACK_LINE(115)
			{
				HX_STACK_LINE(115)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				int _g = this->properties->__Field(HX_CSTRING("start"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(115)
				while(((_g1 < _g))){
					HX_STACK_LINE(115)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(117)
					hx::IndexRef((this->currentParameters).mPtr,i) = ::Reflect_obj::field(this->tweenProperties,(HX_CSTRING("param") + i));
				}
			}
			HX_STACK_LINE(127)
			::Reflect_obj::callMethod(null(),this->target,this->currentParameters);
		}
	}
return null();
}


Void MethodActuator_obj::initialize( ){
{
		HX_STACK_PUSH("MethodActuator::initialize","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_LINE(83)
		::com::eclecticdesignstudio::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(84)
		::String propertyName;		HX_STACK_VAR(propertyName,"propertyName");
		HX_STACK_LINE(85)
		Dynamic start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(87)
		{
			HX_STACK_LINE(87)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->properties->__Field(HX_CSTRING("start"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(87)
			while(((_g1 < _g))){
				HX_STACK_LINE(87)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(89)
				propertyName = (HX_CSTRING("param") + i);
				HX_STACK_LINE(90)
				start = this->properties->__Field(HX_CSTRING("start"),true)->__GetItem(i);
				HX_STACK_LINE(92)
				{
					HX_STACK_LINE(92)
					Dynamic o = this->tweenProperties;		HX_STACK_VAR(o,"o");
					HX_STACK_LINE(92)
					if (((o != null()))){
						HX_STACK_LINE(92)
						o->__SetField(propertyName,start,false);
					}
				}
				HX_STACK_LINE(94)
				if (((bool(::Std_obj::is(start,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(start,hx::ClassOf< ::Int >()))))){
					HX_STACK_LINE(96)
					details = ::com::eclecticdesignstudio::motion::actuators::PropertyDetails_obj::__new(this->tweenProperties,propertyName,start,(this->properties->__Field(HX_CSTRING("end"),true)->__GetItem(i) - start),null());
					HX_STACK_LINE(97)
					this->propertyDetails->push(details);
				}
			}
		}
		HX_STACK_LINE(103)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(104)
		this->initialized = true;
	}
return null();
}


Void MethodActuator_obj::complete( hx::Null< bool >  __o_sendEvent){
bool sendEvent = __o_sendEvent.Default(true);
	HX_STACK_PUSH("MethodActuator::complete","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sendEvent,"sendEvent");
{
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->properties->__Field(HX_CSTRING("start"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(60)
			while(((_g1 < _g))){
				HX_STACK_LINE(60)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(62)
				hx::IndexRef((this->currentParameters).mPtr,i) = ::Reflect_obj::field(this->tweenProperties,(HX_CSTRING("param") + i));
			}
		}
		HX_STACK_LINE(72)
		::Reflect_obj::callMethod(null(),this->target,this->currentParameters);
		HX_STACK_LINE(76)
		this->super::complete(sendEvent);
	}
return null();
}


Void MethodActuator_obj::apply( ){
{
		HX_STACK_PUSH("MethodActuator::apply","com/eclecticdesignstudio/motion/actuators/MethodActuator.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_LINE(43)
		::Reflect_obj::callMethod(null(),this->target,this->properties->__Field(HX_CSTRING("end"),true));
	}
return null();
}



MethodActuator_obj::MethodActuator_obj()
{
}

void MethodActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MethodActuator);
	HX_MARK_MEMBER_NAME(tweenProperties,"tweenProperties");
	HX_MARK_MEMBER_NAME(currentParameters,"currentParameters");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MethodActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tweenProperties,"tweenProperties");
	HX_VISIT_MEMBER_NAME(currentParameters,"currentParameters");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MethodActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { return complete_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tweenProperties") ) { return tweenProperties; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"currentParameters") ) { return currentParameters; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MethodActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"tweenProperties") ) { tweenProperties=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"currentParameters") ) { currentParameters=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MethodActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tweenProperties"));
	outFields->push(HX_CSTRING("currentParameters"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initialize"),
	HX_CSTRING("complete"),
	HX_CSTRING("apply"),
	HX_CSTRING("tweenProperties"),
	HX_CSTRING("currentParameters"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MethodActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MethodActuator_obj::__mClass,"__mClass");
};

Class MethodActuator_obj::__mClass;

void MethodActuator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.actuators.MethodActuator"), hx::TCanCast< MethodActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MethodActuator_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators
