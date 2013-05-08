#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_motion_Actuate
#include <motion/Actuate.h>
#endif
#ifndef INCLUDED_motion__Actuate_EffectsOptions
#include <motion/_Actuate/EffectsOptions.h>
#endif
#ifndef INCLUDED_motion__Actuate_ObjectHash
#include <motion/_Actuate/ObjectHash.h>
#endif
#ifndef INCLUDED_motion__Actuate_TransformOptions
#include <motion/_Actuate/TransformOptions.h>
#endif
#ifndef INCLUDED_motion__Actuate_TweenTimer
#include <motion/_Actuate/TweenTimer.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_MethodActuator
#include <motion/actuators/MethodActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_MotionPathActuator
#include <motion/actuators/MotionPathActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_motion_easing_Expo
#include <motion/easing/Expo.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace motion{

Void Actuate_obj::__construct()
{
	return null();
}

Actuate_obj::~Actuate_obj() { }

Dynamic Actuate_obj::__CreateEmpty() { return  new Actuate_obj; }
hx::ObjectPtr< Actuate_obj > Actuate_obj::__new()
{  hx::ObjectPtr< Actuate_obj > result = new Actuate_obj();
	result->__construct();
	return result;}

Dynamic Actuate_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Actuate_obj > result = new Actuate_obj();
	result->__construct();
	return result;}

::Class Actuate_obj::defaultActuator;

::motion::easing::IEasing Actuate_obj::defaultEase;

::motion::_Actuate::ObjectHash Actuate_obj::targetLibraries;

::motion::actuators::IGenericActuator Actuate_obj::apply( Dynamic target,Dynamic properties,::Class customActuator){
	HX_STACK_PUSH("Actuate::apply","motion/Actuate.hx",37);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(customActuator,"customActuator");
	HX_STACK_LINE(39)
	::motion::Actuate_obj::stop(target,properties,null(),null());
	HX_STACK_LINE(41)
	if (((customActuator == null()))){
		HX_STACK_LINE(41)
		customActuator = ::motion::Actuate_obj::defaultActuator;
	}
	HX_STACK_LINE(47)
	::motion::actuators::GenericActuator actuator = ::Type_obj::createInstance(customActuator,Dynamic( Array_obj<Dynamic>::__new().Add(target).Add((int)0).Add(properties)));		HX_STACK_VAR(actuator,"actuator");
	HX_STACK_LINE(48)
	actuator->apply();
	HX_STACK_LINE(50)
	return actuator;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,apply,return )

::motion::_Actuate::EffectsOptions Actuate_obj::effects( ::native::display::DisplayObject target,Float duration,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::effects","motion/Actuate.hx",64);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(64)
		return ::motion::_Actuate::EffectsOptions_obj::__new(target,duration,overwrite);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,effects,return )

Array< ::motion::actuators::GenericActuator > Actuate_obj::getLibrary( Dynamic target){
	HX_STACK_PUSH("Actuate::getLibrary","motion/Actuate.hx",73);
	HX_STACK_ARG(target,"target");
	HX_STACK_LINE(75)
	if ((!(::motion::Actuate_obj::targetLibraries->hash->exists(::__hxcpp_obj_id(target))))){
		HX_STACK_LINE(75)
		::motion::Actuate_obj::targetLibraries->hash->set(::__hxcpp_obj_id(target),Array_obj< ::motion::actuators::GenericActuator >::__new());
	}
	HX_STACK_LINE(81)
	return ::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,getLibrary,return )

::motion::actuators::IGenericActuator Actuate_obj::motionPath( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::motionPath","motion/Actuate.hx",94);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(94)
		return ::motion::Actuate_obj::tween(target,duration,properties,overwrite,hx::ClassOf< ::motion::actuators::MotionPathActuator >());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Actuate_obj,motionPath,return )

Void Actuate_obj::pause( Dynamic target){
{
		HX_STACK_PUSH("Actuate::pause","motion/Actuate.hx",106);
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(106)
		if ((::Std_obj::is(target,hx::ClassOf< ::motion::actuators::GenericActuator >()))){
			HX_STACK_LINE(108)
			(hx::TCast< motion::actuators::GenericActuator >::cast(target))->pause();
		}
		else{
			HX_STACK_LINE(114)
			Array< ::motion::actuators::GenericActuator > library = ::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
			HX_STACK_LINE(116)
			{
				HX_STACK_LINE(116)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(116)
				while(((_g < library->length))){
					HX_STACK_LINE(116)
					::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(116)
					++(_g);
					HX_STACK_LINE(118)
					actuator->pause();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,pause,(void))

Void Actuate_obj::pauseAll( ){
{
		HX_STACK_PUSH("Actuate::pauseAll","motion/Actuate.hx",127);
		HX_STACK_LINE(127)
		for(::cpp::FastIterator_obj< Array< ::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::motion::actuators::GenericActuator > >(::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(131)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(131)
				while(((_g < library->length))){
					HX_STACK_LINE(131)
					::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(131)
					++(_g);
					HX_STACK_LINE(133)
					actuator->pause();
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Actuate_obj,pauseAll,(void))

Void Actuate_obj::reset( ){
{
		HX_STACK_PUSH("Actuate::reset","motion/Actuate.hx",145);
		HX_STACK_LINE(147)
		for(::cpp::FastIterator_obj< Array< ::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::motion::actuators::GenericActuator > >(::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(149)
				int length = library->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(151)
				{
					HX_STACK_LINE(151)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(151)
					while(((_g < length))){
						HX_STACK_LINE(151)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(153)
						library->__get(i)->stop(null(),false,false);
					}
				}
			}
;
		}
		HX_STACK_LINE(159)
		::motion::Actuate_obj::targetLibraries = ::motion::_Actuate::ObjectHash_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Actuate_obj,reset,(void))

Void Actuate_obj::resume( Dynamic target){
{
		HX_STACK_PUSH("Actuate::resume","motion/Actuate.hx",168);
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(168)
		if ((::Std_obj::is(target,hx::ClassOf< ::motion::actuators::GenericActuator >()))){
			HX_STACK_LINE(170)
			(hx::TCast< motion::actuators::GenericActuator >::cast(target))->resume();
		}
		else{
			HX_STACK_LINE(176)
			Array< ::motion::actuators::GenericActuator > library = ::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
			HX_STACK_LINE(178)
			{
				HX_STACK_LINE(178)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(178)
				while(((_g < library->length))){
					HX_STACK_LINE(178)
					::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(178)
					++(_g);
					HX_STACK_LINE(180)
					actuator->resume();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,resume,(void))

Void Actuate_obj::resumeAll( ){
{
		HX_STACK_PUSH("Actuate::resumeAll","motion/Actuate.hx",189);
		HX_STACK_LINE(189)
		for(::cpp::FastIterator_obj< Array< ::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::motion::actuators::GenericActuator > >(::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(193)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(193)
				while(((_g < library->length))){
					HX_STACK_LINE(193)
					::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(193)
					++(_g);
					HX_STACK_LINE(195)
					actuator->resume();
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Actuate_obj,resumeAll,(void))

Void Actuate_obj::stop( Dynamic target,Dynamic properties,hx::Null< bool >  __o_complete,hx::Null< bool >  __o_sendEvent){
bool complete = __o_complete.Default(false);
bool sendEvent = __o_sendEvent.Default(true);
	HX_STACK_PUSH("Actuate::stop","motion/Actuate.hx",211);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(complete,"complete");
	HX_STACK_ARG(sendEvent,"sendEvent");
{
		HX_STACK_LINE(211)
		if (((target != null()))){
			HX_STACK_LINE(213)
			if ((::Std_obj::is(target,hx::ClassOf< ::motion::actuators::GenericActuator >()))){
				HX_STACK_LINE(215)
				(hx::TCast< motion::actuators::GenericActuator >::cast(target))->stop(null(),complete,sendEvent);
			}
			else{
				HX_STACK_LINE(221)
				Array< ::motion::actuators::GenericActuator > library = ::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
				HX_STACK_LINE(223)
				if ((::Std_obj::is(properties,hx::ClassOf< ::String >()))){
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","motion/Actuate.hx",225);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(225)
					Dynamic temp = _Function_4_1::Block();		HX_STACK_VAR(temp,"temp");
					HX_STACK_LINE(226)
					if (((temp != null()))){
						HX_STACK_LINE(226)
						temp->__SetField(properties,null(),false);
					}
					HX_STACK_LINE(227)
					properties = temp;
				}
				else{
					HX_STACK_LINE(229)
					if ((::Std_obj::is(properties,hx::ClassOf< Array<int> >()))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_PUSH("*::closure","motion/Actuate.hx",231);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(231)
						Dynamic temp = _Function_5_1::Block();		HX_STACK_VAR(temp,"temp");
						HX_STACK_LINE(233)
						{
							HX_STACK_LINE(233)
							int _g = (int)0;		HX_STACK_VAR(_g,"_g");
							Dynamic _g1 = hx::TCastToArray(properties);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(233)
							while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
								HX_STACK_LINE(233)
								Dynamic property = _g1->__GetItem(_g);		HX_STACK_VAR(property,"property");
								HX_STACK_LINE(233)
								++(_g);
								HX_STACK_LINE(235)
								if (((temp != null()))){
									HX_STACK_LINE(235)
									temp->__SetField(property,null(),false);
								}
							}
						}
						HX_STACK_LINE(239)
						properties = temp;
					}
				}
				HX_STACK_LINE(243)
				int length = library->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(245)
				{
					HX_STACK_LINE(245)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(245)
					while(((_g < length))){
						HX_STACK_LINE(245)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(247)
						library->__get(i)->stop(properties,complete,sendEvent);
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Actuate_obj,stop,(void))

::motion::actuators::IGenericActuator Actuate_obj::timer( Float duration,::Class customActuator){
	HX_STACK_PUSH("Actuate::timer","motion/Actuate.hx",265);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(customActuator,"customActuator");
	HX_STACK_LINE(265)
	return ::motion::Actuate_obj::tween(::motion::_Actuate::TweenTimer_obj::__new((int)0),duration,::motion::_Actuate::TweenTimer_obj::__new((int)1),false,customActuator);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Actuate_obj,timer,return )

::motion::_Actuate::TransformOptions Actuate_obj::transform( Dynamic target,hx::Null< Float >  __o_duration,hx::Null< bool >  __o_overwrite){
Float duration = __o_duration.Default(0);
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::transform","motion/Actuate.hx",282);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(282)
		return ::motion::_Actuate::TransformOptions_obj::__new(target,duration,overwrite);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,transform,return )

::motion::actuators::IGenericActuator Actuate_obj::tween( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  __o_overwrite,::Class customActuator){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::tween","motion/Actuate.hx",301);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(overwrite,"overwrite");
	HX_STACK_ARG(customActuator,"customActuator");
{
		HX_STACK_LINE(303)
		if (((target != null()))){
			HX_STACK_LINE(303)
			if (((duration > (int)0))){
				HX_STACK_LINE(307)
				if (((customActuator == null()))){
					HX_STACK_LINE(307)
					customActuator = ::motion::Actuate_obj::defaultActuator;
				}
				HX_STACK_LINE(313)
				::motion::actuators::GenericActuator actuator = ::Type_obj::createInstance(customActuator,Dynamic( Array_obj<Dynamic>::__new().Add(target).Add(duration).Add(properties)));		HX_STACK_VAR(actuator,"actuator");
				HX_STACK_LINE(314)
				Array< ::motion::actuators::GenericActuator > library = ::motion::Actuate_obj::getLibrary(actuator->target);		HX_STACK_VAR(library,"library");
				HX_STACK_LINE(316)
				if ((overwrite)){
					HX_STACK_LINE(318)
					int length = library->length;		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(320)
					{
						HX_STACK_LINE(320)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(320)
						while(((_g < length))){
							HX_STACK_LINE(320)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(322)
							library->__get(i)->stop(actuator->properties,false,false);
						}
					}
				}
				HX_STACK_LINE(328)
				library->push(actuator);
				HX_STACK_LINE(329)
				actuator->move();
				HX_STACK_LINE(344)
				return actuator;
			}
			else{
				HX_STACK_LINE(346)
				return ::motion::Actuate_obj::apply(target,properties,customActuator);
			}
		}
		HX_STACK_LINE(354)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Actuate_obj,tween,return )

Void Actuate_obj::unload( ::motion::actuators::GenericActuator actuator){
{
		HX_STACK_PUSH("Actuate::unload","motion/Actuate.hx",359);
		HX_STACK_ARG(actuator,"actuator");
		HX_STACK_LINE(361)
		Dynamic target = actuator->target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(363)
		if ((::motion::Actuate_obj::targetLibraries->hash->exists(::__hxcpp_obj_id(target)))){
			HX_STACK_LINE(365)
			::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target))->__Field(HX_CSTRING("remove"),true)(actuator);
			HX_STACK_LINE(367)
			if (((::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target))->__Field(HX_CSTRING("length"),true) == (int)0))){
				HX_STACK_LINE(367)
				::motion::Actuate_obj::targetLibraries->hash->remove(::__hxcpp_obj_id(target));
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,unload,(void))

::motion::actuators::IGenericActuator Actuate_obj::update( Dynamic target,Float duration,Dynamic start,Dynamic end,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::update","motion/Actuate.hx",388);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(end,"end");
	HX_STACK_ARG(overwrite,"overwrite");
{
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &start,Dynamic &end){
				HX_STACK_PUSH("*::closure","motion/Actuate.hx",390);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("start") , start,false);
					__result->Add(HX_CSTRING("end") , end,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(390)
		Dynamic properties = _Function_1_1::Block(start,end);		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(392)
		return ::motion::Actuate_obj::tween(target,duration,properties,overwrite,hx::ClassOf< ::motion::actuators::MethodActuator >());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Actuate_obj,update,return )


Actuate_obj::Actuate_obj()
{
}

void Actuate_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Actuate);
	HX_MARK_END_CLASS();
}

void Actuate_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Actuate_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer_dyn(); }
		if (HX_FIELD_EQ(inName,"tween") ) { return tween_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"unload") ) { return unload_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"effects") ) { return effects_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"pauseAll") ) { return pauseAll_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resumeAll") ) { return resumeAll_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getLibrary") ) { return getLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"motionPath") ) { return motionPath_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultEase") ) { return defaultEase; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"defaultActuator") ) { return defaultActuator; }
		if (HX_FIELD_EQ(inName,"targetLibraries") ) { return targetLibraries; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Actuate_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"defaultEase") ) { defaultEase=inValue.Cast< ::motion::easing::IEasing >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"defaultActuator") ) { defaultActuator=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"targetLibraries") ) { targetLibraries=inValue.Cast< ::motion::_Actuate::ObjectHash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Actuate_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("defaultActuator"),
	HX_CSTRING("defaultEase"),
	HX_CSTRING("targetLibraries"),
	HX_CSTRING("apply"),
	HX_CSTRING("effects"),
	HX_CSTRING("getLibrary"),
	HX_CSTRING("motionPath"),
	HX_CSTRING("pause"),
	HX_CSTRING("pauseAll"),
	HX_CSTRING("reset"),
	HX_CSTRING("resume"),
	HX_CSTRING("resumeAll"),
	HX_CSTRING("stop"),
	HX_CSTRING("timer"),
	HX_CSTRING("transform"),
	HX_CSTRING("tween"),
	HX_CSTRING("unload"),
	HX_CSTRING("update"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Actuate_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Actuate_obj::defaultActuator,"defaultActuator");
	HX_MARK_MEMBER_NAME(Actuate_obj::defaultEase,"defaultEase");
	HX_MARK_MEMBER_NAME(Actuate_obj::targetLibraries,"targetLibraries");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Actuate_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Actuate_obj::defaultActuator,"defaultActuator");
	HX_VISIT_MEMBER_NAME(Actuate_obj::defaultEase,"defaultEase");
	HX_VISIT_MEMBER_NAME(Actuate_obj::targetLibraries,"targetLibraries");
};

Class Actuate_obj::__mClass;

void Actuate_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.Actuate"), hx::TCanCast< Actuate_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Actuate_obj::__boot()
{
	defaultActuator= hx::ClassOf< ::motion::actuators::SimpleActuator >();
	defaultEase= ::motion::easing::Expo_obj::get_easeOut();
	targetLibraries= ::motion::_Actuate::ObjectHash_obj::__new();
}

} // end namespace motion
