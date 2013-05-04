#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_Actuate
#include <com/eclecticdesignstudio/motion/Actuate.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_GenericActuator
#include <com/eclecticdesignstudio/motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_IGenericActuator
#include <com/eclecticdesignstudio/motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{

Void GenericActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("GenericActuator::new","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",40);
{
	HX_STACK_LINE(42)
	this->_autoVisible = true;
	HX_STACK_LINE(43)
	this->_delay = (int)0;
	HX_STACK_LINE(44)
	this->_reflect = false;
	HX_STACK_LINE(45)
	this->_repeat = (int)0;
	HX_STACK_LINE(46)
	this->_reverse = false;
	HX_STACK_LINE(47)
	this->_smartRotation = false;
	HX_STACK_LINE(48)
	this->_snapping = false;
	HX_STACK_LINE(49)
	this->special = false;
	HX_STACK_LINE(51)
	this->target = target;
	HX_STACK_LINE(52)
	this->properties = properties;
	HX_STACK_LINE(53)
	this->duration = duration;
	HX_STACK_LINE(55)
	this->_ease = ::com::eclecticdesignstudio::motion::Actuate_obj::defaultEase;
}
;
	return null();
}

GenericActuator_obj::~GenericActuator_obj() { }

Dynamic GenericActuator_obj::__CreateEmpty() { return  new GenericActuator_obj; }
hx::ObjectPtr< GenericActuator_obj > GenericActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< GenericActuator_obj > result = new GenericActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic GenericActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GenericActuator_obj > result = new GenericActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *GenericActuator_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::eclecticdesignstudio::motion::actuators::IGenericActuator_obj)) return operator ::com::eclecticdesignstudio::motion::actuators::IGenericActuator_obj *();
	return super::__ToInterface(inType);
}

Void GenericActuator_obj::stop( Dynamic properties,bool complete,bool sendEvent){
{
		HX_STACK_PUSH("GenericActuator::stop","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",389);
		HX_STACK_THIS(this);
		HX_STACK_ARG(properties,"properties");
		HX_STACK_ARG(complete,"complete");
		HX_STACK_ARG(sendEvent,"sendEvent");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GenericActuator_obj,stop,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::snapping( Dynamic value){
	HX_STACK_PUSH("GenericActuator::snapping","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",373);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(375)
	if (((value == null()))){
		HX_STACK_LINE(375)
		value = true;
	}
	HX_STACK_LINE(381)
	this->_snapping = value;
	HX_STACK_LINE(382)
	this->special = true;
	HX_STACK_LINE(384)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,snapping,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::smartRotation( Dynamic value){
	HX_STACK_PUSH("GenericActuator::smartRotation","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",352);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(354)
	if (((value == null()))){
		HX_STACK_LINE(354)
		value = true;
	}
	HX_STACK_LINE(360)
	this->_smartRotation = value;
	HX_STACK_LINE(361)
	this->special = true;
	HX_STACK_LINE(363)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,smartRotation,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::reverse( Dynamic value){
	HX_STACK_PUSH("GenericActuator::reverse","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",331);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(333)
	if (((value == null()))){
		HX_STACK_LINE(333)
		value = true;
	}
	HX_STACK_LINE(339)
	this->_reverse = value;
	HX_STACK_LINE(340)
	this->special = true;
	HX_STACK_LINE(342)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,reverse,return )

Void GenericActuator_obj::resume( ){
{
		HX_STACK_PUSH("GenericActuator::resume","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",319);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,resume,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::repeat( Dynamic times){
	HX_STACK_PUSH("GenericActuator::repeat","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",304);
	HX_STACK_THIS(this);
	HX_STACK_ARG(times,"times");
	HX_STACK_LINE(306)
	if (((times == null()))){
		HX_STACK_LINE(306)
		times = (int)-1;
	}
	HX_STACK_LINE(312)
	this->_repeat = times;
	HX_STACK_LINE(314)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,repeat,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::reflect( Dynamic value){
	HX_STACK_PUSH("GenericActuator::reflect","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",283);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(285)
	if (((value == null()))){
		HX_STACK_LINE(285)
		value = true;
	}
	HX_STACK_LINE(291)
	this->_reflect = value;
	HX_STACK_LINE(292)
	this->special = true;
	HX_STACK_LINE(294)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,reflect,return )

Void GenericActuator_obj::pause( ){
{
		HX_STACK_PUSH("GenericActuator::pause","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",271);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,pause,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::onUpdate( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onUpdate","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",252);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(254)
	this->_onUpdate = handler;
	HX_STACK_LINE(256)
	if (((parameters == null()))){
		HX_STACK_LINE(256)
		this->_onUpdateParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(260)
		this->_onUpdateParams = parameters;
	}
	HX_STACK_LINE(266)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onUpdate,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::onRepeat( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onRepeat","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",227);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(229)
	this->_onRepeat = handler;
	HX_STACK_LINE(231)
	if (((parameters == null()))){
		HX_STACK_LINE(231)
		this->_onRepeatParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(235)
		this->_onRepeatParams = parameters;
	}
	HX_STACK_LINE(241)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onRepeat,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::onComplete( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onComplete","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",196);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(198)
	this->_onComplete = handler;
	HX_STACK_LINE(200)
	if (((parameters == null()))){
		HX_STACK_LINE(200)
		this->_onCompleteParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(204)
		this->_onCompleteParams = parameters;
	}
	HX_STACK_LINE(210)
	if (((this->duration == (int)0))){
		HX_STACK_LINE(210)
		this->complete(null());
	}
	HX_STACK_LINE(216)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onComplete,return )

Void GenericActuator_obj::move( ){
{
		HX_STACK_PUSH("GenericActuator::move","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",183);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,move,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::ease( ::com::eclecticdesignstudio::motion::easing::IEasing easing){
	HX_STACK_PUSH("GenericActuator::ease","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",174);
	HX_STACK_THIS(this);
	HX_STACK_ARG(easing,"easing");
	HX_STACK_LINE(176)
	this->_ease = easing;
	HX_STACK_LINE(178)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,ease,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::delay( Float duration){
	HX_STACK_PUSH("GenericActuator::delay","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",160);
	HX_STACK_THIS(this);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_LINE(162)
	this->_delay = duration;
	HX_STACK_LINE(164)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,delay,return )

Void GenericActuator_obj::complete( hx::Null< bool >  __o_sendEvent){
bool sendEvent = __o_sendEvent.Default(true);
	HX_STACK_PUSH("GenericActuator::complete","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sendEvent,"sendEvent");
{
		HX_STACK_LINE(129)
		if ((sendEvent)){
			HX_STACK_LINE(131)
			this->change();
			HX_STACK_LINE(133)
			if (((this->_onComplete != null()))){
				HX_STACK_LINE(133)
				::Reflect_obj::callMethod(this->_onComplete,this->_onComplete,this->_onCompleteParams);
			}
		}
		HX_STACK_LINE(150)
		::com::eclecticdesignstudio::motion::Actuate_obj::unload(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,complete,(void))

Void GenericActuator_obj::change( ){
{
		HX_STACK_PUSH("GenericActuator::change","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_LINE(107)
		if (((this->_onUpdate != null()))){
			HX_STACK_LINE(109)
			::Reflect_obj::callMethod(this->_onUpdate,this->_onUpdate,this->_onUpdateParams);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,change,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator GenericActuator_obj::autoVisible( Dynamic value){
	HX_STACK_PUSH("GenericActuator::autoVisible","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(94)
	if (((value == null()))){
		HX_STACK_LINE(94)
		value = true;
	}
	HX_STACK_LINE(100)
	this->_autoVisible = value;
	HX_STACK_LINE(102)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,autoVisible,return )

Void GenericActuator_obj::apply( ){
{
		HX_STACK_PUSH("GenericActuator::apply","com/eclecticdesignstudio/motion/actuators/GenericActuator.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_LINE(62)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		while(((_g < _g1->length))){
			HX_STACK_LINE(62)
			::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(62)
			++(_g);
			HX_STACK_LINE(66)
			if ((::Reflect_obj::hasField(this->target,i))){
				HX_STACK_LINE(68)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(68)
				if (((o != null()))){
					HX_STACK_LINE(68)
					o->__SetField(i,::Reflect_obj::field(this->properties,i),false);
				}
			}
			else{
				HX_STACK_LINE(72)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(72)
				if (((o != null()))){
					HX_STACK_LINE(72)
					o->__SetField(i,::Reflect_obj::field(this->properties,i),true);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,apply,(void))


GenericActuator_obj::GenericActuator_obj()
{
}

void GenericActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GenericActuator);
	HX_MARK_MEMBER_NAME(special,"special");
	HX_MARK_MEMBER_NAME(_snapping,"_snapping");
	HX_MARK_MEMBER_NAME(_smartRotation,"_smartRotation");
	HX_MARK_MEMBER_NAME(_reverse,"_reverse");
	HX_MARK_MEMBER_NAME(_repeat,"_repeat");
	HX_MARK_MEMBER_NAME(_reflect,"_reflect");
	HX_MARK_MEMBER_NAME(_onUpdateParams,"_onUpdateParams");
	HX_MARK_MEMBER_NAME(_onUpdate,"_onUpdate");
	HX_MARK_MEMBER_NAME(_onRepeatParams,"_onRepeatParams");
	HX_MARK_MEMBER_NAME(_onRepeat,"_onRepeat");
	HX_MARK_MEMBER_NAME(_onCompleteParams,"_onCompleteParams");
	HX_MARK_MEMBER_NAME(_onComplete,"_onComplete");
	HX_MARK_MEMBER_NAME(_ease,"_ease");
	HX_MARK_MEMBER_NAME(_delay,"_delay");
	HX_MARK_MEMBER_NAME(_autoVisible,"_autoVisible");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(properties,"properties");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void GenericActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(special,"special");
	HX_VISIT_MEMBER_NAME(_snapping,"_snapping");
	HX_VISIT_MEMBER_NAME(_smartRotation,"_smartRotation");
	HX_VISIT_MEMBER_NAME(_reverse,"_reverse");
	HX_VISIT_MEMBER_NAME(_repeat,"_repeat");
	HX_VISIT_MEMBER_NAME(_reflect,"_reflect");
	HX_VISIT_MEMBER_NAME(_onUpdateParams,"_onUpdateParams");
	HX_VISIT_MEMBER_NAME(_onUpdate,"_onUpdate");
	HX_VISIT_MEMBER_NAME(_onRepeatParams,"_onRepeatParams");
	HX_VISIT_MEMBER_NAME(_onRepeat,"_onRepeat");
	HX_VISIT_MEMBER_NAME(_onCompleteParams,"_onCompleteParams");
	HX_VISIT_MEMBER_NAME(_onComplete,"_onComplete");
	HX_VISIT_MEMBER_NAME(_ease,"_ease");
	HX_VISIT_MEMBER_NAME(_delay,"_delay");
	HX_VISIT_MEMBER_NAME(_autoVisible,"_autoVisible");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(properties,"properties");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic GenericActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay_dyn(); }
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		if (HX_FIELD_EQ(inName,"_ease") ) { return _ease; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat_dyn(); }
		if (HX_FIELD_EQ(inName,"change") ) { return change_dyn(); }
		if (HX_FIELD_EQ(inName,"_delay") ) { return _delay; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse_dyn(); }
		if (HX_FIELD_EQ(inName,"reflect") ) { return reflect_dyn(); }
		if (HX_FIELD_EQ(inName,"special") ) { return special; }
		if (HX_FIELD_EQ(inName,"_repeat") ) { return _repeat; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"snapping") ) { return snapping_dyn(); }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"onRepeat") ) { return onRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete_dyn(); }
		if (HX_FIELD_EQ(inName,"_reverse") ) { return _reverse; }
		if (HX_FIELD_EQ(inName,"_reflect") ) { return _reflect; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_snapping") ) { return _snapping; }
		if (HX_FIELD_EQ(inName,"_onUpdate") ) { return _onUpdate; }
		if (HX_FIELD_EQ(inName,"_onRepeat") ) { return _onRepeat; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"properties") ) { return properties; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"autoVisible") ) { return autoVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"_onComplete") ) { return _onComplete; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_autoVisible") ) { return _autoVisible; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"smartRotation") ) { return smartRotation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_smartRotation") ) { return _smartRotation; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onUpdateParams") ) { return _onUpdateParams; }
		if (HX_FIELD_EQ(inName,"_onRepeatParams") ) { return _onRepeatParams; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onCompleteParams") ) { return _onCompleteParams; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GenericActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_ease") ) { _ease=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_delay") ) { _delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"special") ) { special=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_repeat") ) { _repeat=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_reverse") ) { _reverse=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_reflect") ) { _reflect=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_snapping") ) { _snapping=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onUpdate") ) { _onUpdate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onRepeat") ) { _onRepeat=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"properties") ) { properties=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_onComplete") ) { _onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_autoVisible") ) { _autoVisible=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_smartRotation") ) { _smartRotation=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onUpdateParams") ) { _onUpdateParams=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onRepeatParams") ) { _onRepeatParams=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onCompleteParams") ) { _onCompleteParams=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GenericActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("special"));
	outFields->push(HX_CSTRING("_snapping"));
	outFields->push(HX_CSTRING("_smartRotation"));
	outFields->push(HX_CSTRING("_reverse"));
	outFields->push(HX_CSTRING("_repeat"));
	outFields->push(HX_CSTRING("_reflect"));
	outFields->push(HX_CSTRING("_onUpdateParams"));
	outFields->push(HX_CSTRING("_onUpdate"));
	outFields->push(HX_CSTRING("_onRepeatParams"));
	outFields->push(HX_CSTRING("_onRepeat"));
	outFields->push(HX_CSTRING("_onCompleteParams"));
	outFields->push(HX_CSTRING("_onComplete"));
	outFields->push(HX_CSTRING("_ease"));
	outFields->push(HX_CSTRING("_delay"));
	outFields->push(HX_CSTRING("_autoVisible"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("properties"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stop"),
	HX_CSTRING("snapping"),
	HX_CSTRING("smartRotation"),
	HX_CSTRING("reverse"),
	HX_CSTRING("resume"),
	HX_CSTRING("repeat"),
	HX_CSTRING("reflect"),
	HX_CSTRING("pause"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("onRepeat"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("move"),
	HX_CSTRING("ease"),
	HX_CSTRING("delay"),
	HX_CSTRING("complete"),
	HX_CSTRING("change"),
	HX_CSTRING("autoVisible"),
	HX_CSTRING("apply"),
	HX_CSTRING("special"),
	HX_CSTRING("_snapping"),
	HX_CSTRING("_smartRotation"),
	HX_CSTRING("_reverse"),
	HX_CSTRING("_repeat"),
	HX_CSTRING("_reflect"),
	HX_CSTRING("_onUpdateParams"),
	HX_CSTRING("_onUpdate"),
	HX_CSTRING("_onRepeatParams"),
	HX_CSTRING("_onRepeat"),
	HX_CSTRING("_onCompleteParams"),
	HX_CSTRING("_onComplete"),
	HX_CSTRING("_ease"),
	HX_CSTRING("_delay"),
	HX_CSTRING("_autoVisible"),
	HX_CSTRING("target"),
	HX_CSTRING("properties"),
	HX_CSTRING("id"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GenericActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GenericActuator_obj::__mClass,"__mClass");
};

Class GenericActuator_obj::__mClass;

void GenericActuator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.actuators.GenericActuator"), hx::TCanCast< GenericActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GenericActuator_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators
