#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
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
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
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
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
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
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",9);
{
	HX_STACK_LINE(11)
	this->isDragging = false;
	HX_STACK_LINE(19)
	super::__construct();
	HX_STACK_LINE(23)
	::native::display::Sprite background = ::native::display::Sprite_obj::__new();		HX_STACK_VAR(background,"background");
	HX_STACK_LINE(24)
	background->get_graphics()->beginFill((int)16711680,(int)1);
	HX_STACK_LINE(25)
	background->get_graphics()->drawRect((int)0,(int)0,::nme::Lib_obj::get_current()->get_stage()->get_stageWidth(),::nme::Lib_obj::get_current()->get_stage()->get_stageHeight());
	HX_STACK_LINE(26)
	background->get_graphics()->endFill();
	HX_STACK_LINE(28)
	this->addChild(background);
	HX_STACK_LINE(32)
	this->ballContainer = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(34)
	::native::display::Bitmap ball = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/nme.png"),null()),null(),null());		HX_STACK_VAR(ball,"ball");
	HX_STACK_LINE(35)
	ball->set_x((Float(-(ball->get_width())) / Float((int)2)));
	HX_STACK_LINE(36)
	ball->set_y((Float(-(ball->get_height())) / Float((int)2)));
	HX_STACK_LINE(38)
	this->startX = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2));
	HX_STACK_LINE(39)
	this->startY = ((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)8);
	HX_STACK_LINE(40)
	this->top = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)6));
	HX_STACK_LINE(43)
	this->ballContainer->addChild(ball);
	HX_STACK_LINE(44)
	this->ballContainer->set_x(this->startX);
	HX_STACK_LINE(45)
	this->ballContainer->set_y(this->startY);
	HX_STACK_LINE(46)
	this->ballContainer->set_scaleX(this->ballContainer->set_scaleY(.2));
	HX_STACK_LINE(48)
	this->addChild(this->ballContainer);
	HX_STACK_LINE(53)
	::native::display::Sprite bar = ::native::display::Sprite_obj::__new();		HX_STACK_VAR(bar,"bar");
	HX_STACK_LINE(54)
	bar->get_graphics()->beginFill((int)16776960,(int)1);
	HX_STACK_LINE(55)
	bar->get_graphics()->drawRect((int)0,(int)0,::nme::Lib_obj::get_current()->get_stage()->get_stageWidth(),(Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)6)));
	HX_STACK_LINE(56)
	bar->get_graphics()->endFill();
	HX_STACK_LINE(58)
	bar->set_y(((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)6)) * (int)5));
	HX_STACK_LINE(59)
	this->addChild(bar);
	HX_STACK_LINE(61)
	this->ballContainer->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->onTouchDown_dyn(),null(),null(),null());
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::onTouchUp( Dynamic event){
{
		HX_STACK_PUSH("Main::onTouchUp","Main.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(76)
		::haxe::Log_obj::trace(HX_CSTRING("Touch end"),hx::SourceInfo(HX_CSTRING("Main.hx"),76,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
		HX_STACK_LINE(77)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onTouchUp_dyn(),null());
		HX_STACK_LINE(79)
		if (((event->__Field(HX_CSTRING("stageY"),true) < this->startY))){
			struct _Function_2_1{
				inline static Dynamic Block( Dynamic &event){
					HX_STACK_PUSH("*::closure","Main.hx",80);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("x") , event->__Field(HX_CSTRING("stageX"),true),false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(80)
			::com::eclecticdesignstudio::motion::Actuate_obj::tween(this->ballContainer,(int)3,_Function_2_1::Block(event),null(),null());
			struct _Function_2_2{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",81);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , __this->top,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(81)
			::com::eclecticdesignstudio::motion::Actuate_obj::tween(this->ballContainer,(int)2,_Function_2_2::Block(this),null(),null());
			struct _Function_2_3{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",82);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (__this->top * (int)2),false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(82)
			::com::eclecticdesignstudio::motion::Actuate_obj::tween(this->ballContainer,(int)1,_Function_2_3::Block(this),false,null())->delay((int)2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onTouchUp,(void))

Void Main_obj::onTouchDown( Dynamic event){
{
		HX_STACK_PUSH("Main::onTouchDown","Main.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(67)
		::haxe::Log_obj::trace(HX_CSTRING("Touch start"),hx::SourceInfo(HX_CSTRING("Main.hx"),67,HX_CSTRING("Main"),HX_CSTRING("onTouchDown")));
		HX_STACK_LINE(68)
		this->isDragging = true;
		HX_STACK_LINE(70)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onTouchUp_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onTouchDown,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(ballContainer,"ballContainer");
	HX_MARK_MEMBER_NAME(startY,"startY");
	HX_MARK_MEMBER_NAME(startX,"startX");
	HX_MARK_MEMBER_NAME(isDragging,"isDragging");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(top,"top");
	HX_VISIT_MEMBER_NAME(ballContainer,"ballContainer");
	HX_VISIT_MEMBER_NAME(startY,"startY");
	HX_VISIT_MEMBER_NAME(startX,"startX");
	HX_VISIT_MEMBER_NAME(isDragging,"isDragging");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return top; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"startY") ) { return startY; }
		if (HX_FIELD_EQ(inName,"startX") ) { return startX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onTouchUp") ) { return onTouchUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isDragging") ) { return isDragging; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onTouchDown") ) { return onTouchDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ballContainer") ) { return ballContainer; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { top=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"startY") ) { startY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startX") ) { startX=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isDragging") ) { isDragging=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ballContainer") ) { ballContainer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("ballContainer"));
	outFields->push(HX_CSTRING("startY"));
	outFields->push(HX_CSTRING("startX"));
	outFields->push(HX_CSTRING("isDragging"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onTouchUp"),
	HX_CSTRING("onTouchDown"),
	HX_CSTRING("top"),
	HX_CSTRING("ballContainer"),
	HX_CSTRING("startY"),
	HX_CSTRING("startX"),
	HX_CSTRING("isDragging"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

