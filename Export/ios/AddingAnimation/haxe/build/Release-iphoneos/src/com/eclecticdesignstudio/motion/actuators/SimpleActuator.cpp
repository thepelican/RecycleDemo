#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
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
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails
#include <com/eclecticdesignstudio/motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Shape
#include <native/display/Shape.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{

Void SimpleActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("SimpleActuator::new","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",39);
{
	HX_STACK_LINE(41)
	this->active = true;
	HX_STACK_LINE(42)
	this->propertyDetails = Array_obj< ::com::eclecticdesignstudio::motion::actuators::PropertyDetails >::__new();
	HX_STACK_LINE(43)
	this->sendChange = false;
	HX_STACK_LINE(44)
	this->paused = false;
	HX_STACK_LINE(45)
	this->cacheVisible = false;
	HX_STACK_LINE(46)
	this->initialized = false;
	HX_STACK_LINE(47)
	this->setVisible = false;
	HX_STACK_LINE(48)
	this->toggleVisible = false;
	HX_STACK_LINE(49)
	this->startTime = (Float(::native::Lib_obj::getTimer()) / Float((int)1000));
	HX_STACK_LINE(51)
	super::__construct(target,duration,properties);
	HX_STACK_LINE(53)
	if (((::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::shape == null()))){
		HX_STACK_LINE(55)
		::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::shape = ::native::display::Shape_obj::__new();
		HX_STACK_LINE(56)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ENTER_FRAME,::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::shape_onEnterFrame_dyn(),null(),null(),null());
	}
}
;
	return null();
}

SimpleActuator_obj::~SimpleActuator_obj() { }

Dynamic SimpleActuator_obj::__CreateEmpty() { return  new SimpleActuator_obj; }
hx::ObjectPtr< SimpleActuator_obj > SimpleActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< SimpleActuator_obj > result = new SimpleActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic SimpleActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleActuator_obj > result = new SimpleActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void SimpleActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("SimpleActuator::update","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",241);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(241)
		if ((!(this->paused))){
			HX_STACK_LINE(245)
			::com::eclecticdesignstudio::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
			HX_STACK_LINE(246)
			Float easing;		HX_STACK_VAR(easing,"easing");
			HX_STACK_LINE(247)
			int i;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(249)
			Float tweenPosition = (Float(((currentTime - this->timeOffset))) / Float(this->duration));		HX_STACK_VAR(tweenPosition,"tweenPosition");
			HX_STACK_LINE(251)
			if (((tweenPosition > (int)1))){
				HX_STACK_LINE(251)
				tweenPosition = (int)1;
			}
			HX_STACK_LINE(257)
			if ((!(this->initialized))){
				HX_STACK_LINE(257)
				this->initialize();
			}
			HX_STACK_LINE(263)
			if ((!(this->special))){
				HX_STACK_LINE(265)
				easing = this->_ease->calculate(tweenPosition);
				HX_STACK_LINE(267)
				{
					HX_STACK_LINE(267)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->detailsLength;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(267)
					while(((_g1 < _g))){
						HX_STACK_LINE(267)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(269)
						details = this->propertyDetails->__get(i1);
						HX_STACK_LINE(271)
						if ((details->isField)){
							HX_STACK_LINE(273)
							Dynamic o = details->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(273)
							if (((o != null()))){
								HX_STACK_LINE(273)
								o->__SetField(details->propertyName,(details->start + (details->change * easing)),false);
							}
						}
						else{
							HX_STACK_LINE(278)
							Dynamic o = details->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(278)
							if (((o != null()))){
								HX_STACK_LINE(278)
								o->__SetField(details->propertyName,(details->start + (details->change * easing)),true);
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(287)
				if ((!(this->_reverse))){
					HX_STACK_LINE(287)
					easing = this->_ease->calculate(tweenPosition);
				}
				else{
					HX_STACK_LINE(291)
					easing = this->_ease->calculate(((int)1 - tweenPosition));
				}
				HX_STACK_LINE(297)
				Float endValue;		HX_STACK_VAR(endValue,"endValue");
				HX_STACK_LINE(299)
				{
					HX_STACK_LINE(299)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->detailsLength;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(299)
					while(((_g1 < _g))){
						HX_STACK_LINE(299)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(301)
						details = this->propertyDetails->__get(i1);
						HX_STACK_LINE(303)
						if (((bool(this->_smartRotation) && bool(((bool((bool((bool((details->propertyName == HX_CSTRING("rotation"))) || bool((details->propertyName == HX_CSTRING("rotationX"))))) || bool((details->propertyName == HX_CSTRING("rotationY"))))) || bool((details->propertyName == HX_CSTRING("rotationZ"))))))))){
							HX_STACK_LINE(305)
							Float rotation = hx::Mod(details->change,(int)360);		HX_STACK_VAR(rotation,"rotation");
							HX_STACK_LINE(307)
							if (((rotation > (int)180))){
								HX_STACK_LINE(307)
								hx::SubEq(rotation,(int)360);
							}
							else{
								HX_STACK_LINE(311)
								if (((rotation < (int)-180))){
									HX_STACK_LINE(311)
									hx::AddEq(rotation,(int)360);
								}
							}
							HX_STACK_LINE(317)
							endValue = (details->start + (rotation * easing));
						}
						else{
							HX_STACK_LINE(319)
							endValue = (details->start + (details->change * easing));
						}
						HX_STACK_LINE(325)
						if ((!(this->_snapping))){
							HX_STACK_LINE(325)
							if ((details->isField)){
								HX_STACK_LINE(329)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(329)
								if (((o != null()))){
									HX_STACK_LINE(329)
									o->__SetField(details->propertyName,endValue,false);
								}
							}
							else{
								HX_STACK_LINE(334)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(334)
								if (((o != null()))){
									HX_STACK_LINE(334)
									o->__SetField(details->propertyName,endValue,true);
								}
							}
						}
						else{
							HX_STACK_LINE(339)
							if ((details->isField)){
								HX_STACK_LINE(343)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(343)
								if (((o != null()))){
									HX_STACK_LINE(343)
									o->__SetField(details->propertyName,::Math_obj::round(endValue),false);
								}
							}
							else{
								HX_STACK_LINE(348)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(348)
								if (((o != null()))){
									HX_STACK_LINE(348)
									o->__SetField(details->propertyName,::Math_obj::round(endValue),true);
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(359)
			if (((tweenPosition == (int)1))){
				HX_STACK_LINE(359)
				if (((this->_repeat == (int)0))){
					HX_STACK_LINE(363)
					this->active = false;
					HX_STACK_LINE(365)
					if (((bool(this->toggleVisible) && bool((this->target->__Field(HX_CSTRING("alpha"),true) == (int)0))))){
						HX_STACK_LINE(365)
						this->target->__FieldRef(HX_CSTRING("visible")) = false;
					}
					HX_STACK_LINE(371)
					this->complete(true);
					HX_STACK_LINE(372)
					return null();
				}
				else{
					HX_STACK_LINE(376)
					if (((this->_onRepeat != null()))){
						HX_STACK_LINE(376)
						::Reflect_obj::callMethod(this->_onRepeat,this->_onRepeat,this->_onRepeatParams);
					}
					HX_STACK_LINE(391)
					if ((this->_reflect)){
						HX_STACK_LINE(391)
						this->_reverse = !(this->_reverse);
					}
					HX_STACK_LINE(397)
					this->startTime = currentTime;
					HX_STACK_LINE(398)
					this->timeOffset = (this->startTime + this->_delay);
					HX_STACK_LINE(400)
					if (((this->_repeat > (int)0))){
						HX_STACK_LINE(400)
						(this->_repeat)--;
					}
				}
			}
			HX_STACK_LINE(410)
			if ((this->sendChange)){
				HX_STACK_LINE(410)
				this->change();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleActuator_obj,update,(void))

Void SimpleActuator_obj::stop( Dynamic properties,bool complete,bool sendEvent){
{
		HX_STACK_PUSH("SimpleActuator::stop","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",198);
		HX_STACK_THIS(this);
		HX_STACK_ARG(properties,"properties");
		HX_STACK_ARG(complete,"complete");
		HX_STACK_ARG(sendEvent,"sendEvent");
		HX_STACK_LINE(198)
		if ((this->active)){
			HX_STACK_LINE(202)
			if (((properties == null()))){
				HX_STACK_LINE(204)
				this->active = false;
				HX_STACK_LINE(206)
				if ((complete)){
					HX_STACK_LINE(206)
					this->apply();
				}
				HX_STACK_LINE(212)
				this->complete(sendEvent);
				HX_STACK_LINE(213)
				return null();
			}
			HX_STACK_LINE(217)
			{
				HX_STACK_LINE(217)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::String > _g1 = ::Reflect_obj::fields(properties);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(217)
				while(((_g < _g1->length))){
					HX_STACK_LINE(217)
					::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(217)
					++(_g);
					HX_STACK_LINE(219)
					if ((::Reflect_obj::hasField(this->properties,i))){
						HX_STACK_LINE(221)
						this->active = false;
						HX_STACK_LINE(223)
						if ((complete)){
							HX_STACK_LINE(223)
							this->apply();
						}
						HX_STACK_LINE(229)
						this->complete(sendEvent);
						HX_STACK_LINE(230)
						return null();
					}
				}
			}
		}
	}
return null();
}


Void SimpleActuator_obj::resume( ){
{
		HX_STACK_PUSH("SimpleActuator::resume","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",186);
		HX_STACK_THIS(this);
		HX_STACK_LINE(186)
		if ((this->paused)){
			HX_STACK_LINE(190)
			this->paused = false;
			HX_STACK_LINE(191)
			hx::AddEq(this->timeOffset,(Float(((::native::Lib_obj::getTimer() - this->pauseTime))) / Float((int)1000)));
		}
	}
return null();
}


Void SimpleActuator_obj::pause( ){
{
		HX_STACK_PUSH("SimpleActuator::pause","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",178);
		HX_STACK_THIS(this);
		HX_STACK_LINE(180)
		this->paused = true;
		HX_STACK_LINE(181)
		this->pauseTime = ::native::Lib_obj::getTimer();
	}
return null();
}


::com::eclecticdesignstudio::motion::actuators::IGenericActuator SimpleActuator_obj::onUpdate( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("SimpleActuator::onUpdate","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",167);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(169)
	this->_onUpdate = handler;
	HX_STACK_LINE(170)
	this->_onUpdateParams = parameters;
	HX_STACK_LINE(171)
	this->sendChange = true;
	HX_STACK_LINE(173)
	return hx::ObjectPtr<OBJ_>(this);
}


Void SimpleActuator_obj::move( ){
{
		HX_STACK_PUSH("SimpleActuator::move","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",145);
		HX_STACK_THIS(this);
		HX_STACK_LINE(147)
		this->toggleVisible = (bool(::Reflect_obj::hasField(this->properties,HX_CSTRING("alpha"))) && bool(::Std_obj::is(this->target,hx::ClassOf< ::native::display::DisplayObject >())));
		HX_STACK_LINE(149)
		if (((bool((bool(this->toggleVisible) && bool(!(this->target->__Field(HX_CSTRING("visible"),true))))) && bool((this->properties->__Field(HX_CSTRING("alpha"),true) != (int)0))))){
			HX_STACK_LINE(151)
			this->setVisible = true;
			HX_STACK_LINE(152)
			this->cacheVisible = this->target->__Field(HX_CSTRING("visible"),true);
			HX_STACK_LINE(153)
			this->target->__FieldRef(HX_CSTRING("visible")) = true;
		}
		HX_STACK_LINE(157)
		this->timeOffset = this->startTime;
		HX_STACK_LINE(158)
		::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuators->push(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(159)
		++(::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuatorsLength);
	}
return null();
}


Void SimpleActuator_obj::initialize( ){
{
		HX_STACK_PUSH("SimpleActuator::initialize","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_LINE(108)
		::com::eclecticdesignstudio::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(109)
		Float start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(111)
		{
			HX_STACK_LINE(111)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(111)
			while(((_g < _g1->length))){
				HX_STACK_LINE(111)
				::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(111)
				++(_g);
				HX_STACK_LINE(113)
				bool isField = true;		HX_STACK_VAR(isField,"isField");
				HX_STACK_LINE(117)
				if ((::Reflect_obj::hasField(this->target,i))){
					HX_STACK_LINE(117)
					start = ::Reflect_obj::field(this->target,i);
				}
				else{
					HX_STACK_LINE(123)
					isField = false;
					struct _Function_4_1{
						inline static Dynamic Block( ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj *__this,::String &i){
							HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",124);
							{
								HX_STACK_LINE(124)
								Dynamic o = __this->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(124)
								return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(i,true)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(124)
					start = _Function_4_1::Block(this,i);
				}
				HX_STACK_LINE(134)
				details = ::com::eclecticdesignstudio::motion::actuators::PropertyDetails_obj::__new(this->target,i,start,(::Reflect_obj::field(this->properties,i) - start),isField);
				HX_STACK_LINE(135)
				this->propertyDetails->push(details);
			}
		}
		HX_STACK_LINE(139)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(140)
		this->initialized = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleActuator_obj,initialize,(void))

::com::eclecticdesignstudio::motion::actuators::IGenericActuator SimpleActuator_obj::delay( Float duration){
	HX_STACK_PUSH("SimpleActuator::delay","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_LINE(98)
	this->_delay = duration;
	HX_STACK_LINE(99)
	this->timeOffset = (this->startTime + duration);
	HX_STACK_LINE(101)
	return hx::ObjectPtr<OBJ_>(this);
}


::com::eclecticdesignstudio::motion::actuators::IGenericActuator SimpleActuator_obj::autoVisible( Dynamic value){
	HX_STACK_PUSH("SimpleActuator::autoVisible","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(68)
	if (((value == null()))){
		HX_STACK_LINE(68)
		value = true;
	}
	HX_STACK_LINE(74)
	this->_autoVisible = value;
	HX_STACK_LINE(76)
	if ((!(value))){
		HX_STACK_LINE(78)
		this->toggleVisible = false;
		HX_STACK_LINE(80)
		if ((this->setVisible)){
			HX_STACK_LINE(80)
			this->target->__FieldRef(HX_CSTRING("visible")) = this->cacheVisible;
		}
	}
	HX_STACK_LINE(88)
	return hx::ObjectPtr<OBJ_>(this);
}


Array< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator > SimpleActuator_obj::actuators;

int SimpleActuator_obj::actuatorsLength;

::native::display::Shape SimpleActuator_obj::shape;

Void SimpleActuator_obj::shape_onEnterFrame( ::native::events::Event event){
{
		HX_STACK_PUSH("SimpleActuator::shape_onEnterFrame","com/eclecticdesignstudio/motion/actuators/SimpleActuator.hx",428);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(430)
		Float currentTime = (Float(::native::Lib_obj::getTimer()) / Float((int)1000));		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(431)
		::com::eclecticdesignstudio::motion::actuators::SimpleActuator actuator;		HX_STACK_VAR(actuator,"actuator");
		HX_STACK_LINE(433)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(435)
		{
			HX_STACK_LINE(435)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuatorsLength;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(435)
			while(((_g1 < _g))){
				HX_STACK_LINE(435)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(437)
				actuator = ::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuators->__get(j);
				HX_STACK_LINE(439)
				if ((actuator->active)){
					HX_STACK_LINE(441)
					if (((currentTime > actuator->timeOffset))){
						HX_STACK_LINE(441)
						actuator->update(currentTime);
					}
					HX_STACK_LINE(447)
					(j)++;
				}
				else{
					HX_STACK_LINE(451)
					::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuators->splice(j,(int)1);
					HX_STACK_LINE(452)
					--(::com::eclecticdesignstudio::motion::actuators::SimpleActuator_obj::actuatorsLength);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleActuator_obj,shape_onEnterFrame,(void))


SimpleActuator_obj::SimpleActuator_obj()
{
}

void SimpleActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleActuator);
	HX_MARK_MEMBER_NAME(toggleVisible,"toggleVisible");
	HX_MARK_MEMBER_NAME(startTime,"startTime");
	HX_MARK_MEMBER_NAME(setVisible,"setVisible");
	HX_MARK_MEMBER_NAME(sendChange,"sendChange");
	HX_MARK_MEMBER_NAME(propertyDetails,"propertyDetails");
	HX_MARK_MEMBER_NAME(pauseTime,"pauseTime");
	HX_MARK_MEMBER_NAME(paused,"paused");
	HX_MARK_MEMBER_NAME(initialized,"initialized");
	HX_MARK_MEMBER_NAME(detailsLength,"detailsLength");
	HX_MARK_MEMBER_NAME(cacheVisible,"cacheVisible");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(timeOffset,"timeOffset");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SimpleActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(toggleVisible,"toggleVisible");
	HX_VISIT_MEMBER_NAME(startTime,"startTime");
	HX_VISIT_MEMBER_NAME(setVisible,"setVisible");
	HX_VISIT_MEMBER_NAME(sendChange,"sendChange");
	HX_VISIT_MEMBER_NAME(propertyDetails,"propertyDetails");
	HX_VISIT_MEMBER_NAME(pauseTime,"pauseTime");
	HX_VISIT_MEMBER_NAME(paused,"paused");
	HX_VISIT_MEMBER_NAME(initialized,"initialized");
	HX_VISIT_MEMBER_NAME(detailsLength,"detailsLength");
	HX_VISIT_MEMBER_NAME(cacheVisible,"cacheVisible");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(timeOffset,"timeOffset");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SimpleActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shape") ) { return shape; }
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"actuators") ) { return actuators; }
		if (HX_FIELD_EQ(inName,"startTime") ) { return startTime; }
		if (HX_FIELD_EQ(inName,"pauseTime") ) { return pauseTime; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"setVisible") ) { return setVisible; }
		if (HX_FIELD_EQ(inName,"sendChange") ) { return sendChange; }
		if (HX_FIELD_EQ(inName,"timeOffset") ) { return timeOffset; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"autoVisible") ) { return autoVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"initialized") ) { return initialized; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cacheVisible") ) { return cacheVisible; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"toggleVisible") ) { return toggleVisible; }
		if (HX_FIELD_EQ(inName,"detailsLength") ) { return detailsLength; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"actuatorsLength") ) { return actuatorsLength; }
		if (HX_FIELD_EQ(inName,"propertyDetails") ) { return propertyDetails; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"shape_onEnterFrame") ) { return shape_onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shape") ) { shape=inValue.Cast< ::native::display::Shape >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"actuators") ) { actuators=inValue.Cast< Array< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startTime") ) { startTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pauseTime") ) { pauseTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setVisible") ) { setVisible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sendChange") ) { sendChange=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeOffset") ) { timeOffset=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { initialized=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cacheVisible") ) { cacheVisible=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"toggleVisible") ) { toggleVisible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"detailsLength") ) { detailsLength=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"actuatorsLength") ) { actuatorsLength=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"propertyDetails") ) { propertyDetails=inValue.Cast< Array< ::com::eclecticdesignstudio::motion::actuators::PropertyDetails > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("toggleVisible"));
	outFields->push(HX_CSTRING("startTime"));
	outFields->push(HX_CSTRING("setVisible"));
	outFields->push(HX_CSTRING("sendChange"));
	outFields->push(HX_CSTRING("propertyDetails"));
	outFields->push(HX_CSTRING("pauseTime"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("initialized"));
	outFields->push(HX_CSTRING("detailsLength"));
	outFields->push(HX_CSTRING("cacheVisible"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("timeOffset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("actuators"),
	HX_CSTRING("actuatorsLength"),
	HX_CSTRING("shape"),
	HX_CSTRING("shape_onEnterFrame"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("stop"),
	HX_CSTRING("resume"),
	HX_CSTRING("pause"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("move"),
	HX_CSTRING("initialize"),
	HX_CSTRING("delay"),
	HX_CSTRING("autoVisible"),
	HX_CSTRING("toggleVisible"),
	HX_CSTRING("startTime"),
	HX_CSTRING("setVisible"),
	HX_CSTRING("sendChange"),
	HX_CSTRING("propertyDetails"),
	HX_CSTRING("pauseTime"),
	HX_CSTRING("paused"),
	HX_CSTRING("initialized"),
	HX_CSTRING("detailsLength"),
	HX_CSTRING("cacheVisible"),
	HX_CSTRING("active"),
	HX_CSTRING("timeOffset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleActuator_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SimpleActuator_obj::actuators,"actuators");
	HX_MARK_MEMBER_NAME(SimpleActuator_obj::actuatorsLength,"actuatorsLength");
	HX_MARK_MEMBER_NAME(SimpleActuator_obj::shape,"shape");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::actuators,"actuators");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::actuatorsLength,"actuatorsLength");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::shape,"shape");
};

Class SimpleActuator_obj::__mClass;

void SimpleActuator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.actuators.SimpleActuator"), hx::TCanCast< SimpleActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SimpleActuator_obj::__boot()
{
	actuators= Array_obj< ::com::eclecticdesignstudio::motion::actuators::SimpleActuator >::__new();
	actuatorsLength= (int)0;
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators
