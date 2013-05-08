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
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_PropertyDetails
#include <motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
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
namespace motion{
namespace actuators{

Void SimpleActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("SimpleActuator::new","motion/actuators/SimpleActuator.hx",49);
{
	HX_STACK_LINE(51)
	this->active = true;
	HX_STACK_LINE(52)
	this->propertyDetails = Array_obj< ::motion::actuators::PropertyDetails >::__new();
	HX_STACK_LINE(53)
	this->sendChange = false;
	HX_STACK_LINE(54)
	this->paused = false;
	HX_STACK_LINE(55)
	this->cacheVisible = false;
	HX_STACK_LINE(56)
	this->initialized = false;
	HX_STACK_LINE(57)
	this->setVisible = false;
	HX_STACK_LINE(58)
	this->toggleVisible = false;
	HX_STACK_LINE(61)
	this->startTime = (Float(::native::Lib_obj::getTimer()) / Float((int)1000));
	HX_STACK_LINE(66)
	super::__construct(target,duration,properties);
	HX_STACK_LINE(68)
	if ((!(::motion::actuators::SimpleActuator_obj::addedEvent))){
		HX_STACK_LINE(70)
		::motion::actuators::SimpleActuator_obj::addedEvent = true;
		HX_STACK_LINE(73)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ENTER_FRAME,::motion::actuators::SimpleActuator_obj::stage_onEnterFrame_dyn(),null(),null(),null());
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
		HX_STACK_PUSH("SimpleActuator::update","motion/actuators/SimpleActuator.hx",276);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(276)
		if ((!(this->paused))){
			HX_STACK_LINE(280)
			::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
			HX_STACK_LINE(281)
			Float easing;		HX_STACK_VAR(easing,"easing");
			HX_STACK_LINE(282)
			int i;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(284)
			Float tweenPosition = (Float(((currentTime - this->timeOffset))) / Float(this->duration));		HX_STACK_VAR(tweenPosition,"tweenPosition");
			HX_STACK_LINE(286)
			if (((tweenPosition > (int)1))){
				HX_STACK_LINE(286)
				tweenPosition = (int)1;
			}
			HX_STACK_LINE(292)
			if ((!(this->initialized))){
				HX_STACK_LINE(292)
				this->initialize();
			}
			HX_STACK_LINE(298)
			if ((!(this->special))){
				HX_STACK_LINE(300)
				easing = this->_ease->calculate(tweenPosition);
				HX_STACK_LINE(302)
				{
					HX_STACK_LINE(302)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->detailsLength;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(302)
					while(((_g1 < _g))){
						HX_STACK_LINE(302)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(304)
						details = this->propertyDetails->__get(i1);
						HX_STACK_LINE(306)
						if ((details->isField)){
							HX_STACK_LINE(308)
							Dynamic o = details->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(308)
							if (((o != null()))){
								HX_STACK_LINE(308)
								o->__SetField(details->propertyName,(details->start + (details->change * easing)),false);
							}
						}
						else{
							HX_STACK_LINE(313)
							Dynamic o = details->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(313)
							if (((o != null()))){
								HX_STACK_LINE(313)
								o->__SetField(details->propertyName,(details->start + (details->change * easing)),true);
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(322)
				if ((!(this->_reverse))){
					HX_STACK_LINE(322)
					easing = this->_ease->calculate(tweenPosition);
				}
				else{
					HX_STACK_LINE(326)
					easing = this->_ease->calculate(((int)1 - tweenPosition));
				}
				HX_STACK_LINE(332)
				Float endValue;		HX_STACK_VAR(endValue,"endValue");
				HX_STACK_LINE(334)
				{
					HX_STACK_LINE(334)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->detailsLength;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(334)
					while(((_g1 < _g))){
						HX_STACK_LINE(334)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(336)
						details = this->propertyDetails->__get(i1);
						HX_STACK_LINE(338)
						if (((bool(this->_smartRotation) && bool(((bool((bool((bool((details->propertyName == HX_CSTRING("rotation"))) || bool((details->propertyName == HX_CSTRING("rotationX"))))) || bool((details->propertyName == HX_CSTRING("rotationY"))))) || bool((details->propertyName == HX_CSTRING("rotationZ"))))))))){
							HX_STACK_LINE(340)
							Float rotation = hx::Mod(details->change,(int)360);		HX_STACK_VAR(rotation,"rotation");
							HX_STACK_LINE(342)
							if (((rotation > (int)180))){
								HX_STACK_LINE(342)
								hx::SubEq(rotation,(int)360);
							}
							else{
								HX_STACK_LINE(346)
								if (((rotation < (int)-180))){
									HX_STACK_LINE(346)
									hx::AddEq(rotation,(int)360);
								}
							}
							HX_STACK_LINE(352)
							endValue = (details->start + (rotation * easing));
						}
						else{
							HX_STACK_LINE(354)
							endValue = (details->start + (details->change * easing));
						}
						HX_STACK_LINE(360)
						if ((!(this->_snapping))){
							HX_STACK_LINE(360)
							if ((details->isField)){
								HX_STACK_LINE(364)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(364)
								if (((o != null()))){
									HX_STACK_LINE(364)
									o->__SetField(details->propertyName,endValue,false);
								}
							}
							else{
								HX_STACK_LINE(369)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(369)
								if (((o != null()))){
									HX_STACK_LINE(369)
									o->__SetField(details->propertyName,endValue,true);
								}
							}
						}
						else{
							HX_STACK_LINE(374)
							if ((details->isField)){
								HX_STACK_LINE(378)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(378)
								if (((o != null()))){
									HX_STACK_LINE(378)
									o->__SetField(details->propertyName,::Math_obj::round(endValue),false);
								}
							}
							else{
								HX_STACK_LINE(383)
								Dynamic o = details->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(383)
								if (((o != null()))){
									HX_STACK_LINE(383)
									o->__SetField(details->propertyName,::Math_obj::round(endValue),true);
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(394)
			if (((tweenPosition == (int)1))){
				HX_STACK_LINE(394)
				if (((this->_repeat == (int)0))){
					HX_STACK_LINE(398)
					this->active = false;
					HX_STACK_LINE(400)
					if (((bool(this->toggleVisible) && bool((this->target->__Field(HX_CSTRING("alpha"),true) == (int)0))))){
						HX_STACK_LINE(400)
						this->target->__FieldRef(HX_CSTRING("visible")) = false;
					}
					HX_STACK_LINE(406)
					this->complete(true);
					HX_STACK_LINE(407)
					return null();
				}
				else{
					HX_STACK_LINE(411)
					if (((this->_onRepeat != null()))){
						HX_STACK_LINE(411)
						::Reflect_obj::callMethod(this->_onRepeat,this->_onRepeat,this->_onRepeatParams);
					}
					HX_STACK_LINE(426)
					if ((this->_reflect)){
						HX_STACK_LINE(426)
						this->_reverse = !(this->_reverse);
					}
					HX_STACK_LINE(432)
					this->startTime = currentTime;
					HX_STACK_LINE(433)
					this->timeOffset = (this->startTime + this->_delay);
					HX_STACK_LINE(435)
					if (((this->_repeat > (int)0))){
						HX_STACK_LINE(435)
						(this->_repeat)--;
					}
				}
			}
			HX_STACK_LINE(445)
			if ((this->sendChange)){
				HX_STACK_LINE(445)
				this->change();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleActuator_obj,update,(void))

Void SimpleActuator_obj::stop( Dynamic properties,bool complete,bool sendEvent){
{
		HX_STACK_PUSH("SimpleActuator::stop","motion/actuators/SimpleActuator.hx",233);
		HX_STACK_THIS(this);
		HX_STACK_ARG(properties,"properties");
		HX_STACK_ARG(complete,"complete");
		HX_STACK_ARG(sendEvent,"sendEvent");
		HX_STACK_LINE(233)
		if ((this->active)){
			HX_STACK_LINE(237)
			if (((properties == null()))){
				HX_STACK_LINE(239)
				this->active = false;
				HX_STACK_LINE(241)
				if ((complete)){
					HX_STACK_LINE(241)
					this->apply();
				}
				HX_STACK_LINE(247)
				this->complete(sendEvent);
				HX_STACK_LINE(248)
				return null();
			}
			HX_STACK_LINE(252)
			{
				HX_STACK_LINE(252)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::String > _g1 = ::Reflect_obj::fields(properties);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(252)
				while(((_g < _g1->length))){
					HX_STACK_LINE(252)
					::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(252)
					++(_g);
					HX_STACK_LINE(254)
					if ((::Reflect_obj::hasField(this->properties,i))){
						HX_STACK_LINE(256)
						this->active = false;
						HX_STACK_LINE(258)
						if ((complete)){
							HX_STACK_LINE(258)
							this->apply();
						}
						HX_STACK_LINE(264)
						this->complete(sendEvent);
						HX_STACK_LINE(265)
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
		HX_STACK_PUSH("SimpleActuator::resume","motion/actuators/SimpleActuator.hx",216);
		HX_STACK_THIS(this);
		HX_STACK_LINE(216)
		if ((this->paused)){
			HX_STACK_LINE(220)
			this->paused = false;
			HX_STACK_LINE(223)
			hx::AddEq(this->timeOffset,(Float(((::native::Lib_obj::getTimer() - this->pauseTime))) / Float((int)1000)));
		}
	}
return null();
}


Void SimpleActuator_obj::pause( ){
{
		HX_STACK_PUSH("SimpleActuator::pause","motion/actuators/SimpleActuator.hx",203);
		HX_STACK_THIS(this);
		HX_STACK_LINE(205)
		this->paused = true;
		HX_STACK_LINE(208)
		this->pauseTime = ::native::Lib_obj::getTimer();
	}
return null();
}


::motion::actuators::IGenericActuator SimpleActuator_obj::onUpdate( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("SimpleActuator::onUpdate","motion/actuators/SimpleActuator.hx",192);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(194)
	this->_onUpdate = handler;
	HX_STACK_LINE(195)
	this->_onUpdateParams = parameters;
	HX_STACK_LINE(196)
	this->sendChange = true;
	HX_STACK_LINE(198)
	return hx::ObjectPtr<OBJ_>(this);
}


Void SimpleActuator_obj::move( ){
{
		HX_STACK_PUSH("SimpleActuator::move","motion/actuators/SimpleActuator.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_LINE(169)
		this->toggleVisible = (bool(::Reflect_obj::hasField(this->properties,HX_CSTRING("alpha"))) && bool(::Std_obj::is(this->target,hx::ClassOf< ::native::display::DisplayObject >())));
		HX_STACK_LINE(174)
		if (((bool((bool(this->toggleVisible) && bool(!(this->target->__Field(HX_CSTRING("visible"),true))))) && bool((this->properties->__Field(HX_CSTRING("alpha"),true) != (int)0))))){
			HX_STACK_LINE(176)
			this->setVisible = true;
			HX_STACK_LINE(177)
			this->cacheVisible = this->target->__Field(HX_CSTRING("visible"),true);
			HX_STACK_LINE(178)
			this->target->__FieldRef(HX_CSTRING("visible")) = true;
		}
		HX_STACK_LINE(182)
		this->timeOffset = this->startTime;
		HX_STACK_LINE(183)
		::motion::actuators::SimpleActuator_obj::actuators->push(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(184)
		++(::motion::actuators::SimpleActuator_obj::actuatorsLength);
	}
return null();
}


Void SimpleActuator_obj::initialize( ){
{
		HX_STACK_PUSH("SimpleActuator::initialize","motion/actuators/SimpleActuator.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_LINE(129)
		::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(130)
		Float start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(132)
		{
			HX_STACK_LINE(132)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(132)
			while(((_g < _g1->length))){
				HX_STACK_LINE(132)
				::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(132)
				++(_g);
				HX_STACK_LINE(134)
				bool isField = true;		HX_STACK_VAR(isField,"isField");
				HX_STACK_LINE(138)
				if ((::Reflect_obj::hasField(this->target,i))){
					HX_STACK_LINE(138)
					start = ::Reflect_obj::field(this->target,i);
				}
				else{
					HX_STACK_LINE(144)
					isField = false;
					struct _Function_4_1{
						inline static Dynamic Block( ::motion::actuators::SimpleActuator_obj *__this,::String &i){
							HX_STACK_PUSH("*::closure","motion/actuators/SimpleActuator.hx",145);
							{
								HX_STACK_LINE(145)
								Dynamic o = __this->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(145)
								return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(i,true)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(145)
					start = _Function_4_1::Block(this,i);
				}
				HX_STACK_LINE(155)
				details = ::motion::actuators::PropertyDetails_obj::__new(this->target,i,start,(::Reflect_obj::field(this->properties,i) - start),isField);
				HX_STACK_LINE(156)
				this->propertyDetails->push(details);
			}
		}
		HX_STACK_LINE(160)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(161)
		this->initialized = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleActuator_obj,initialize,(void))

::motion::actuators::IGenericActuator SimpleActuator_obj::delay( Float duration){
	HX_STACK_PUSH("SimpleActuator::delay","motion/actuators/SimpleActuator.hx",117);
	HX_STACK_THIS(this);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_LINE(119)
	this->_delay = duration;
	HX_STACK_LINE(120)
	this->timeOffset = (this->startTime + duration);
	HX_STACK_LINE(122)
	return hx::ObjectPtr<OBJ_>(this);
}


::motion::actuators::IGenericActuator SimpleActuator_obj::autoVisible( Dynamic value){
	HX_STACK_PUSH("SimpleActuator::autoVisible","motion/actuators/SimpleActuator.hx",87);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(89)
	if (((value == null()))){
		HX_STACK_LINE(89)
		value = true;
	}
	HX_STACK_LINE(95)
	this->_autoVisible = value;
	HX_STACK_LINE(97)
	if ((!(value))){
		HX_STACK_LINE(99)
		this->toggleVisible = false;
		HX_STACK_LINE(101)
		if ((this->setVisible)){
			HX_STACK_LINE(101)
			this->target->__FieldRef(HX_CSTRING("visible")) = this->cacheVisible;
		}
	}
	HX_STACK_LINE(109)
	return hx::ObjectPtr<OBJ_>(this);
}


Array< ::motion::actuators::SimpleActuator > SimpleActuator_obj::actuators;

int SimpleActuator_obj::actuatorsLength;

bool SimpleActuator_obj::addedEvent;

Void SimpleActuator_obj::stage_onEnterFrame( ::native::events::Event event){
{
		HX_STACK_PUSH("SimpleActuator::stage_onEnterFrame","motion/actuators/SimpleActuator.hx",463);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(466)
		Float currentTime = (Float(::native::Lib_obj::getTimer()) / Float((int)1000));		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(471)
		::motion::actuators::SimpleActuator actuator;		HX_STACK_VAR(actuator,"actuator");
		HX_STACK_LINE(473)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(475)
		{
			HX_STACK_LINE(475)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::motion::actuators::SimpleActuator_obj::actuatorsLength;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(475)
			while(((_g1 < _g))){
				HX_STACK_LINE(475)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(477)
				actuator = ::motion::actuators::SimpleActuator_obj::actuators->__get(j);
				HX_STACK_LINE(479)
				if ((actuator->active)){
					HX_STACK_LINE(481)
					if (((currentTime > actuator->timeOffset))){
						HX_STACK_LINE(481)
						actuator->update(currentTime);
					}
					HX_STACK_LINE(487)
					(j)++;
				}
				else{
					HX_STACK_LINE(491)
					::motion::actuators::SimpleActuator_obj::actuators->splice(j,(int)1);
					HX_STACK_LINE(492)
					--(::motion::actuators::SimpleActuator_obj::actuatorsLength);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleActuator_obj,stage_onEnterFrame,(void))


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
		if (HX_FIELD_EQ(inName,"addedEvent") ) { return addedEvent; }
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
		if (HX_FIELD_EQ(inName,"stage_onEnterFrame") ) { return stage_onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"actuators") ) { actuators=inValue.Cast< Array< ::motion::actuators::SimpleActuator > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startTime") ) { startTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pauseTime") ) { pauseTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addedEvent") ) { addedEvent=inValue.Cast< bool >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"propertyDetails") ) { propertyDetails=inValue.Cast< Array< ::motion::actuators::PropertyDetails > >(); return inValue; }
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
	HX_CSTRING("addedEvent"),
	HX_CSTRING("stage_onEnterFrame"),
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
	HX_MARK_MEMBER_NAME(SimpleActuator_obj::addedEvent,"addedEvent");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::actuators,"actuators");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::actuatorsLength,"actuatorsLength");
	HX_VISIT_MEMBER_NAME(SimpleActuator_obj::addedEvent,"addedEvent");
};

Class SimpleActuator_obj::__mClass;

void SimpleActuator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.SimpleActuator"), hx::TCanCast< SimpleActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SimpleActuator_obj::__boot()
{
	actuators= Array_obj< ::motion::actuators::SimpleActuator >::__new();
	actuatorsLength= (int)0;
	addedEvent= false;
}

} // end namespace motion
} // end namespace actuators
