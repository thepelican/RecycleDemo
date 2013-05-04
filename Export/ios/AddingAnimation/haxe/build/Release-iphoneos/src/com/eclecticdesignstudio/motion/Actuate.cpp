#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_Actuate
#include <com/eclecticdesignstudio/motion/Actuate.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_EffectsOptions
#include <com/eclecticdesignstudio/motion/_Actuate/EffectsOptions.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_ObjectHash
#include <com/eclecticdesignstudio/motion/_Actuate/ObjectHash.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_TransformOptions
#include <com/eclecticdesignstudio/motion/_Actuate/TransformOptions.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_TweenTimer
#include <com/eclecticdesignstudio/motion/_Actuate/TweenTimer.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_FilterActuator
#include <com/eclecticdesignstudio/motion/actuators/FilterActuator.h>
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
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_MotionPathActuator
#include <com/eclecticdesignstudio/motion/actuators/MotionPathActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_TransformActuator
#include <com/eclecticdesignstudio/motion/actuators/TransformActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Expo
#include <com/eclecticdesignstudio/motion/easing/Expo.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
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
namespace com{
namespace eclecticdesignstudio{
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

::com::eclecticdesignstudio::motion::easing::IEasing Actuate_obj::defaultEase;

::com::eclecticdesignstudio::motion::_Actuate::ObjectHash Actuate_obj::targetLibraries;

::com::eclecticdesignstudio::motion::actuators::IGenericActuator Actuate_obj::apply( Dynamic target,Dynamic properties,::Class customActuator){
	HX_STACK_PUSH("Actuate::apply","com/eclecticdesignstudio/motion/Actuate.hx",41);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(customActuator,"customActuator");
	HX_STACK_LINE(43)
	::com::eclecticdesignstudio::motion::Actuate_obj::stop(target,properties,null(),null());
	HX_STACK_LINE(45)
	if (((customActuator == null()))){
		HX_STACK_LINE(45)
		customActuator = ::com::eclecticdesignstudio::motion::Actuate_obj::defaultActuator;
	}
	HX_STACK_LINE(51)
	::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = ::com::eclecticdesignstudio::motion::Actuate_obj::createInstance(customActuator,target,(int)0,properties);		HX_STACK_VAR(actuator,"actuator");
	HX_STACK_LINE(52)
	actuator->apply();
	HX_STACK_LINE(54)
	return actuator;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,apply,return )

::com::eclecticdesignstudio::motion::actuators::GenericActuator Actuate_obj::createInstance( ::Class actuator,Dynamic target,Float duration,Dynamic properties){
	HX_STACK_PUSH("Actuate::createInstance","com/eclecticdesignstudio/motion/Actuate.hx",59);
	HX_STACK_ARG(actuator,"actuator");
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_LINE(63)
	if (((actuator == hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator >()))){
		HX_STACK_LINE(63)
		return ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::__new(target,duration,properties);
	}
	HX_STACK_LINE(69)
	if (((actuator == hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::FilterActuator >()))){
		HX_STACK_LINE(69)
		return ::com::eclecticdesignstudio::motion::actuators::FilterActuator_obj::__new(target,duration,properties);
	}
	HX_STACK_LINE(75)
	if (((actuator == hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::TransformActuator >()))){
		HX_STACK_LINE(75)
		return ::com::eclecticdesignstudio::motion::actuators::TransformActuator_obj::__new(target,duration,properties);
	}
	HX_STACK_LINE(81)
	if (((actuator == hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::MethodActuator >()))){
		HX_STACK_LINE(81)
		return ::com::eclecticdesignstudio::motion::actuators::MethodActuator_obj::__new(target,duration,properties);
	}
	HX_STACK_LINE(87)
	if (((actuator == hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::MotionPathActuator >()))){
		HX_STACK_LINE(87)
		return ::com::eclecticdesignstudio::motion::actuators::MotionPathActuator_obj::__new(target,duration,properties);
	}
	HX_STACK_LINE(93)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Actuate_obj,createInstance,return )

::com::eclecticdesignstudio::motion::_Actuate::EffectsOptions Actuate_obj::effects( ::native::display::DisplayObject target,Float duration,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::effects","com/eclecticdesignstudio/motion/Actuate.hx",105);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(105)
		return ::com::eclecticdesignstudio::motion::_Actuate::EffectsOptions_obj::__new(target,duration,overwrite);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,effects,return )

Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > Actuate_obj::getLibrary( Dynamic target){
	HX_STACK_PUSH("Actuate::getLibrary","com/eclecticdesignstudio/motion/Actuate.hx",112);
	HX_STACK_ARG(target,"target");
	HX_STACK_LINE(114)
	if ((!(::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->exists(::__hxcpp_obj_id(target))))){
		HX_STACK_LINE(114)
		::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->set(::__hxcpp_obj_id(target),Array_obj< ::com::eclecticdesignstudio::motion::actuators::GenericActuator >::__new());
	}
	HX_STACK_LINE(120)
	return ::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,getLibrary,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator Actuate_obj::motionPath( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::motionPath","com/eclecticdesignstudio/motion/Actuate.hx",133);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(133)
		return ::com::eclecticdesignstudio::motion::Actuate_obj::tween(target,duration,properties,overwrite,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::MotionPathActuator >());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Actuate_obj,motionPath,return )

Void Actuate_obj::pause( Dynamic target){
{
		HX_STACK_PUSH("Actuate::pause","com/eclecticdesignstudio/motion/Actuate.hx",145);
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(145)
		if ((::Std_obj::is(target,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::GenericActuator >()))){
			HX_STACK_LINE(147)
			(hx::TCast< com::eclecticdesignstudio::motion::actuators::GenericActuator >::cast(target))->pause();
		}
		else{
			HX_STACK_LINE(153)
			Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = ::com::eclecticdesignstudio::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
			HX_STACK_LINE(155)
			{
				HX_STACK_LINE(155)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(155)
				while(((_g < library->length))){
					HX_STACK_LINE(155)
					::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(155)
					++(_g);
					HX_STACK_LINE(157)
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
		HX_STACK_PUSH("Actuate::pauseAll","com/eclecticdesignstudio/motion/Actuate.hx",166);
		HX_STACK_LINE(166)
		for(::cpp::FastIterator_obj< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > >(::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(170)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(170)
				while(((_g < library->length))){
					HX_STACK_LINE(170)
					::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(170)
					++(_g);
					HX_STACK_LINE(172)
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
		HX_STACK_PUSH("Actuate::reset","com/eclecticdesignstudio/motion/Actuate.hx",184);
		HX_STACK_LINE(186)
		for(::cpp::FastIterator_obj< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > >(::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(188)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(188)
				while(((_g < library->length))){
					HX_STACK_LINE(188)
					::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(188)
					++(_g);
					HX_STACK_LINE(190)
					actuator->stop(null(),false,false);
				}
			}
;
		}
		HX_STACK_LINE(196)
		::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries = ::com::eclecticdesignstudio::motion::_Actuate::ObjectHash_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Actuate_obj,reset,(void))

Void Actuate_obj::resume( Dynamic target){
{
		HX_STACK_PUSH("Actuate::resume","com/eclecticdesignstudio/motion/Actuate.hx",205);
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(205)
		if ((::Std_obj::is(target,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::GenericActuator >()))){
			HX_STACK_LINE(207)
			(hx::TCast< com::eclecticdesignstudio::motion::actuators::GenericActuator >::cast(target))->resume();
		}
		else{
			HX_STACK_LINE(213)
			Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = ::com::eclecticdesignstudio::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
			HX_STACK_LINE(215)
			{
				HX_STACK_LINE(215)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(215)
				while(((_g < library->length))){
					HX_STACK_LINE(215)
					::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(215)
					++(_g);
					HX_STACK_LINE(217)
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
		HX_STACK_PUSH("Actuate::resumeAll","com/eclecticdesignstudio/motion/Actuate.hx",226);
		HX_STACK_LINE(226)
		for(::cpp::FastIterator_obj< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > > *__it = ::cpp::CreateFastIterator< Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > >(::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->iterator());  __it->hasNext(); ){
			Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = __it->next();
			{
				HX_STACK_LINE(230)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(230)
				while(((_g < library->length))){
					HX_STACK_LINE(230)
					::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
					HX_STACK_LINE(230)
					++(_g);
					HX_STACK_LINE(232)
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
	HX_STACK_PUSH("Actuate::stop","com/eclecticdesignstudio/motion/Actuate.hx",248);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(complete,"complete");
	HX_STACK_ARG(sendEvent,"sendEvent");
{
		HX_STACK_LINE(248)
		if (((target != null()))){
			HX_STACK_LINE(250)
			if ((::Std_obj::is(target,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::GenericActuator >()))){
				HX_STACK_LINE(252)
				(hx::TCast< com::eclecticdesignstudio::motion::actuators::GenericActuator >::cast(target))->stop(null(),complete,sendEvent);
			}
			else{
				HX_STACK_LINE(258)
				Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = ::com::eclecticdesignstudio::motion::Actuate_obj::getLibrary(target);		HX_STACK_VAR(library,"library");
				HX_STACK_LINE(260)
				if ((::Std_obj::is(properties,hx::ClassOf< ::String >()))){
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/Actuate.hx",262);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(262)
					Dynamic temp = _Function_4_1::Block();		HX_STACK_VAR(temp,"temp");
					HX_STACK_LINE(263)
					if (((temp != null()))){
						HX_STACK_LINE(263)
						temp->__SetField(properties,null(),false);
					}
					HX_STACK_LINE(264)
					properties = temp;
				}
				else{
					HX_STACK_LINE(266)
					if ((::Std_obj::is(properties,hx::ClassOf< Array<int> >()))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/Actuate.hx",268);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(268)
						Dynamic temp = _Function_5_1::Block();		HX_STACK_VAR(temp,"temp");
						HX_STACK_LINE(270)
						{
							HX_STACK_LINE(270)
							int _g = (int)0;		HX_STACK_VAR(_g,"_g");
							Dynamic _g1 = hx::TCastToArray(properties);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(270)
							while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
								HX_STACK_LINE(270)
								Dynamic property = _g1->__GetItem(_g);		HX_STACK_VAR(property,"property");
								HX_STACK_LINE(270)
								++(_g);
								HX_STACK_LINE(272)
								if (((temp != null()))){
									HX_STACK_LINE(272)
									temp->__SetField(property,null(),false);
								}
							}
						}
						HX_STACK_LINE(276)
						properties = temp;
					}
				}
				HX_STACK_LINE(280)
				{
					HX_STACK_LINE(280)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(280)
					while(((_g < library->length))){
						HX_STACK_LINE(280)
						::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = library->__get(_g);		HX_STACK_VAR(actuator,"actuator");
						HX_STACK_LINE(280)
						++(_g);
						HX_STACK_LINE(282)
						actuator->stop(properties,complete,sendEvent);
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Actuate_obj,stop,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator Actuate_obj::timer( Float duration,::Class customActuator){
	HX_STACK_PUSH("Actuate::timer","com/eclecticdesignstudio/motion/Actuate.hx",300);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(customActuator,"customActuator");
	HX_STACK_LINE(300)
	return ::com::eclecticdesignstudio::motion::Actuate_obj::tween(::com::eclecticdesignstudio::motion::_Actuate::TweenTimer_obj::__new((int)0),duration,::com::eclecticdesignstudio::motion::_Actuate::TweenTimer_obj::__new((int)1),false,customActuator);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Actuate_obj,timer,return )

::com::eclecticdesignstudio::motion::_Actuate::TransformOptions Actuate_obj::transform( Dynamic target,hx::Null< Float >  __o_duration,hx::Null< bool >  __o_overwrite){
Float duration = __o_duration.Default(0);
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::transform","com/eclecticdesignstudio/motion/Actuate.hx",315);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(overwrite,"overwrite");
{
		HX_STACK_LINE(315)
		return ::com::eclecticdesignstudio::motion::_Actuate::TransformOptions_obj::__new(target,duration,overwrite);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Actuate_obj,transform,return )

::com::eclecticdesignstudio::motion::actuators::IGenericActuator Actuate_obj::tween( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  __o_overwrite,::Class customActuator){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::tween","com/eclecticdesignstudio/motion/Actuate.hx",332);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_ARG(overwrite,"overwrite");
	HX_STACK_ARG(customActuator,"customActuator");
{
		HX_STACK_LINE(334)
		if (((target != null()))){
			HX_STACK_LINE(334)
			if (((duration > (int)0))){
				HX_STACK_LINE(338)
				if (((customActuator == null()))){
					HX_STACK_LINE(338)
					customActuator = ::com::eclecticdesignstudio::motion::Actuate_obj::defaultActuator;
				}
				HX_STACK_LINE(344)
				::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator = ::com::eclecticdesignstudio::motion::Actuate_obj::createInstance(customActuator,target,duration,properties);		HX_STACK_VAR(actuator,"actuator");
				HX_STACK_LINE(345)
				Array< ::com::eclecticdesignstudio::motion::actuators::GenericActuator > library = ::com::eclecticdesignstudio::motion::Actuate_obj::getLibrary(actuator->target);		HX_STACK_VAR(library,"library");
				HX_STACK_LINE(347)
				if ((overwrite)){
					HX_STACK_LINE(349)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(349)
					while(((_g < library->length))){
						HX_STACK_LINE(349)
						::com::eclecticdesignstudio::motion::actuators::GenericActuator childActuator = library->__get(_g);		HX_STACK_VAR(childActuator,"childActuator");
						HX_STACK_LINE(349)
						++(_g);
						HX_STACK_LINE(351)
						childActuator->stop(actuator->properties,false,false);
					}
				}
				HX_STACK_LINE(357)
				library->push(actuator);
				HX_STACK_LINE(358)
				actuator->move();
				HX_STACK_LINE(373)
				return actuator;
			}
			else{
				HX_STACK_LINE(375)
				return ::com::eclecticdesignstudio::motion::Actuate_obj::apply(target,properties,customActuator);
			}
		}
		HX_STACK_LINE(383)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Actuate_obj,tween,return )

Void Actuate_obj::unload( ::com::eclecticdesignstudio::motion::actuators::GenericActuator actuator){
{
		HX_STACK_PUSH("Actuate::unload","com/eclecticdesignstudio/motion/Actuate.hx",388);
		HX_STACK_ARG(actuator,"actuator");
		HX_STACK_LINE(390)
		Dynamic target = actuator->target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(392)
		if ((::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->exists(::__hxcpp_obj_id(target)))){
			HX_STACK_LINE(394)
			::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target))->__Field(HX_CSTRING("remove"),true)(actuator);
			HX_STACK_LINE(396)
			if (((::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->get(::__hxcpp_obj_id(target))->__Field(HX_CSTRING("length"),true) == (int)0))){
				HX_STACK_LINE(396)
				::com::eclecticdesignstudio::motion::Actuate_obj::targetLibraries->hash->remove(::__hxcpp_obj_id(target));
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Actuate_obj,unload,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator Actuate_obj::update( Dynamic target,Float duration,Dynamic start,Dynamic end,hx::Null< bool >  __o_overwrite){
bool overwrite = __o_overwrite.Default(true);
	HX_STACK_PUSH("Actuate::update","com/eclecticdesignstudio/motion/Actuate.hx",417);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(end,"end");
	HX_STACK_ARG(overwrite,"overwrite");
{
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &start,Dynamic &end){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/Actuate.hx",419);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("start") , start,false);
					__result->Add(HX_CSTRING("end") , end,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(419)
		Dynamic properties = _Function_1_1::Block(start,end);		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(421)
		return ::com::eclecticdesignstudio::motion::Actuate_obj::tween(target,duration,properties,overwrite,hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::MethodActuator >());
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
	case 14:
		if (HX_FIELD_EQ(inName,"createInstance") ) { return createInstance_dyn(); }
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
		if (HX_FIELD_EQ(inName,"defaultEase") ) { defaultEase=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"defaultActuator") ) { defaultActuator=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"targetLibraries") ) { targetLibraries=inValue.Cast< ::com::eclecticdesignstudio::motion::_Actuate::ObjectHash >(); return inValue; }
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
	HX_CSTRING("createInstance"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.Actuate"), hx::TCanCast< Actuate_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Actuate_obj::__boot()
{
	defaultActuator= hx::ClassOf< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator >();
	defaultEase= ::com::eclecticdesignstudio::motion::easing::Expo_obj::get_easeOut();
	targetLibraries= ::com::eclecticdesignstudio::motion::_Actuate::ObjectHash_obj::__new();
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
