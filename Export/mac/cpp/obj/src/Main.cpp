#include <hxcpp.h>

#ifndef INCLUDED_ItemScrollBar
#include <ItemScrollBar.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_motion_Actuate
#include <motion/Actuate.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
#ifndef INCLUDED_motion_easing_Linear
#include <motion/easing/Linear.h>
#endif
#ifndef INCLUDED_motion_easing_Quad
#include <motion/easing/Quad.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_CapsStyle
#include <native/display/CapsStyle.h>
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
#ifndef INCLUDED_native_display_JointStyle
#include <native/display/JointStyle.h>
#endif
#ifndef INCLUDED_native_display_LineScaleMode
#include <native/display/LineScaleMode.h>
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
HX_STACK_PUSH("Main::new","Main.hx",22);
{
	HX_STACK_LINE(24)
	this->isDragging = false;
	HX_STACK_LINE(44)
	super::__construct();
	HX_STACK_LINE(58)
	this->ballContainer = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(60)
	::native::display::Bitmap ball = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/nme.png"),null()),null(),null());		HX_STACK_VAR(ball,"ball");
	HX_STACK_LINE(61)
	ball->set_x((Float(-(ball->get_width())) / Float((int)2)));
	HX_STACK_LINE(62)
	ball->set_y((Float(-(ball->get_height())) / Float((int)2)));
	HX_STACK_LINE(63)
	this->startX = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2));
	HX_STACK_LINE(64)
	this->startY = ((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)8);
	HX_STACK_LINE(65)
	this->top = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)6));
	HX_STACK_LINE(66)
	this->horizon = ((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)5);
	HX_STACK_LINE(67)
	this->previousY = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(68)
	this->drawBucket();
	HX_STACK_LINE(69)
	this->originalScale = .2;
	HX_STACK_LINE(70)
	this->scaleFactor = (int)3;
	HX_STACK_LINE(71)
	this->ballContainer->addChild(ball);
	HX_STACK_LINE(72)
	this->ballContainer->set_x(this->startX);
	HX_STACK_LINE(73)
	this->ballContainer->set_y(this->startY);
	HX_STACK_LINE(74)
	this->ballContainer->set_scaleX(this->ballContainer->set_scaleY(.2));
	HX_STACK_LINE(75)
	this->objectToThrowHalfWidth = (Float(this->ballContainer->get_width()) / Float((int)2));
	HX_STACK_LINE(76)
	this->objectToThrowHalfWidth = (Float(this->objectToThrowHalfWidth) / Float(this->scaleFactor));
	HX_STACK_LINE(77)
	this->addChild(this->ballContainer);
	HX_STACK_LINE(81)
	this->scrollBar = ::ItemScrollBar_obj::__new();
	HX_STACK_LINE(82)
	this->scrollBar->setSize(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth(),(Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)6)));
	HX_STACK_LINE(83)
	this->scrollBar->set_y((::nme::Lib_obj::get_current()->get_stage()->get_stageHeight() - this->scrollBar->get_height()));
	HX_STACK_LINE(84)
	this->addChild(this->scrollBar);
	HX_STACK_LINE(95)
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

Void Main_obj::reset( ){
{
		HX_STACK_PUSH("Main::reset","Main.hx",316);
		HX_STACK_THIS(this);
		HX_STACK_LINE(318)
		::haxe::Log_obj::trace(HX_CSTRING("reset"),hx::SourceInfo(HX_CSTRING("Main.hx"),318,HX_CSTRING("Main"),HX_CSTRING("reset")));
		HX_STACK_LINE(319)
		this->ballContainer->set_x(this->startX);
		HX_STACK_LINE(320)
		this->ballContainer->set_y(this->startY);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","Main.hx",321);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("alpha") , .99,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(321)
		::motion::Actuate_obj::tween(this->ballContainer,.30,_Function_1_1::Block(),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
		HX_STACK_LINE(322)
		this->ballContainer->set_scaleX(this->ballContainer->set_scaleY(.2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,reset,(void))

Void Main_obj::drawBucket( ){
{
		HX_STACK_PUSH("Main::drawBucket","Main.hx",303);
		HX_STACK_THIS(this);
		HX_STACK_LINE(304)
		this->get_graphics()->lineStyle((int)1,(int)0,(int)1,null(),null(),null(),null(),null());
		HX_STACK_LINE(305)
		this->get_graphics()->moveTo((int)0,this->horizon);
		HX_STACK_LINE(306)
		this->get_graphics()->lineTo(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth(),this->horizon);
		HX_STACK_LINE(308)
		this->get_graphics()->moveTo(((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)9),this->horizon);
		HX_STACK_LINE(309)
		this->get_graphics()->lineTo(((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)9),((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)4));
		HX_STACK_LINE(311)
		this->get_graphics()->moveTo(((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)12),this->horizon);
		HX_STACK_LINE(312)
		this->get_graphics()->lineTo(((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)12),((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)4));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,drawBucket,(void))

Void Main_obj::onEnterFrame( Dynamic event){
{
		HX_STACK_PUSH("Main::onEnterFrame","Main.hx",282);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(285)
		if (((this->previousY > this->ballContainer->get_y()))){
			HX_STACK_LINE(285)
			this->falling = false;
		}
		else{
			HX_STACK_LINE(287)
			this->falling = true;
		}
		HX_STACK_LINE(290)
		this->previousY = this->ballContainer->get_y();
		HX_STACK_LINE(293)
		if (((this->ballContainer->get_y() >= this->horizon))){
		}
		else{
			HX_STACK_LINE(295)
			if (((bool((this->ballContainer->get_y() > this->top)) && bool(this->falling)))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onEnterFrame,(void))

Void Main_obj::bouncedTweenInside( Float offest,Float wind){
{
		HX_STACK_PUSH("Main::bouncedTweenInside","Main.hx",243);
		HX_STACK_THIS(this);
		HX_STACK_ARG(offest,"offest");
		HX_STACK_ARG(wind,"wind");
		HX_STACK_LINE(243)
		Array< Float > offest1 = Array_obj< Float >::__new().Add(offest);		HX_STACK_VAR(offest1,"offest1");
		HX_STACK_LINE(243)
		Array< ::Main > _g = Array_obj< ::Main >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(245)
		Float offestFirstBounce = ((((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)4) - this->top) - this->objectToThrowHalfWidth);		HX_STACK_VAR(offestFirstBounce,"offestFirstBounce");
		struct _Function_1_1{
			inline static Dynamic Block( Array< Float > &offest1){
				HX_STACK_PUSH("*::closure","Main.hx",246);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , offest1->__get((int)0),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(246)
		::motion::Actuate_obj::tween(this->ballContainer,1.25,_Function_1_1::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
		struct _Function_1_2{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",247);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("y") , __this->top,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(247)
		::motion::Actuate_obj::tween(this->ballContainer,1.0,_Function_1_2::Block(this),null(),null())->ease(::motion::easing::Quad_obj::get_easeOut());
		HX_STACK_LINE(249)
		if (((offest1->__get((int)0) < (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2))))){
			struct _Function_2_1{
				inline static Dynamic Block( ::Main_obj *__this,Float &offestFirstBounce){
					HX_STACK_PUSH("*::closure","Main.hx",251);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (__this->top + offestFirstBounce),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Main >,_g,Array< Float >,offest1)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_2","Main.hx",251);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",253);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->horizon - ((int)2 * ((Float((Float(_g->__get((int)0)->ballContainer->get_height()) / Float((int)2))) / Float(_g->__get((int)0)->scaleFactor))))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(253)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_1::Block(_g),false,null())->ease(::motion::easing::Quad_obj::get_easeIn());
					struct _Function_3_2{
						inline static Dynamic Block( Array< Float > &offest1){
							HX_STACK_PUSH("*::closure","Main.hx",254);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , (offest1->__get((int)0) + (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(254)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_2::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(251)
			::motion::Actuate_obj::tween(this->ballContainer,.35,_Function_2_1::Block(this,offestFirstBounce),false,null())->delay(1.0)->ease(::motion::easing::Quad_obj::get_easeIn())->onComplete( Dynamic(new _Function_2_2(_g,offest1)),null());
			struct _Function_2_3{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",258);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("scaleX") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						__result->Add(HX_CSTRING("scaleY") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_4,Array< ::Main >,_g)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_4","Main.hx",258);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",259);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() + _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(258)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(258)
			::motion::Actuate_obj::tween(this->ballContainer,1.85,_Function_2_3::Block(this),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone())->onComplete( Dynamic(new _Function_2_4(_g)),null());
		}
		else{
			struct _Function_2_1{
				inline static Dynamic Block( ::Main_obj *__this,Float &offestFirstBounce){
					HX_STACK_PUSH("*::closure","Main.hx",263);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (__this->top + offestFirstBounce),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Main >,_g,Array< Float >,offest1)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_2","Main.hx",263);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",265);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->horizon - ((int)2 * ((Float((Float(_g->__get((int)0)->ballContainer->get_height()) / Float((int)2))) / Float(_g->__get((int)0)->scaleFactor))))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(265)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_1::Block(_g),false,null())->ease(::motion::easing::Quad_obj::get_easeIn());
					struct _Function_3_2{
						inline static Dynamic Block( Array< Float > &offest1){
							HX_STACK_PUSH("*::closure","Main.hx",266);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , (offest1->__get((int)0) - (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(266)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_2::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(263)
			::motion::Actuate_obj::tween(this->ballContainer,.35,_Function_2_1::Block(this,offestFirstBounce),false,null())->delay(1.0)->ease(::motion::easing::Quad_obj::get_easeIn())->onComplete( Dynamic(new _Function_2_2(_g,offest1)),null());
			struct _Function_2_3{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",270);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("scaleX") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						__result->Add(HX_CSTRING("scaleY") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_4,Array< ::Main >,_g)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_4","Main.hx",270);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",271);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() - _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(270)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(270)
			::motion::Actuate_obj::tween(this->ballContainer,1.85,_Function_2_3::Block(this),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone())->onComplete( Dynamic(new _Function_2_4(_g)),null());
		}
		struct _Function_1_3{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","Main.hx",275);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("alpha") , .0,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(275)
		::motion::Actuate_obj::tween(this->ballContainer,.15,_Function_1_3::Block(),null(),null())->delay(1.80)->ease(::motion::easing::Linear_obj::get_easeNone());
		struct _Function_1_4{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",278);
				{
					HX_STACK_LINE(278)
					Dynamic f = Dynamic( Array_obj<Dynamic>::__new().Add(__this->reset_dyn()));		HX_STACK_VAR(f,"f");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,f)
					Void run(){
						HX_STACK_PUSH("*::_Function_2_1","Main.hx",278);
						{
							HX_STACK_LINE(278)
							return null(f->__GetItem((int)0)().Cast< Void >());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0((void))

					HX_STACK_LINE(278)
					return  Dynamic(new _Function_2_1(f));
				}
				return null();
			}
		};
		HX_STACK_LINE(278)
		::haxe::Timer_obj::delay(_Function_1_4::Block(this),(int)3500);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,bouncedTweenInside,(void))

Void Main_obj::bouncedTweenOutside( Float offest,Float wind){
{
		HX_STACK_PUSH("Main::bouncedTweenOutside","Main.hx",207);
		HX_STACK_THIS(this);
		HX_STACK_ARG(offest,"offest");
		HX_STACK_ARG(wind,"wind");
		HX_STACK_LINE(207)
		Array< Float > offest1 = Array_obj< Float >::__new().Add(offest);		HX_STACK_VAR(offest1,"offest1");
		HX_STACK_LINE(207)
		Array< ::Main > _g = Array_obj< ::Main >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(209)
		Float offestFirstBounce = ((((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)12)) * (int)4) - this->top) - this->objectToThrowHalfWidth);		HX_STACK_VAR(offestFirstBounce,"offestFirstBounce");
		struct _Function_1_1{
			inline static Dynamic Block( Array< Float > &offest1){
				HX_STACK_PUSH("*::closure","Main.hx",210);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , offest1->__get((int)0),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(210)
		::motion::Actuate_obj::tween(this->ballContainer,1.25,_Function_1_1::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
		struct _Function_1_2{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",211);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("y") , __this->top,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(211)
		::motion::Actuate_obj::tween(this->ballContainer,1.0,_Function_1_2::Block(this),null(),null())->ease(::motion::easing::Quad_obj::get_easeOut());
		HX_STACK_LINE(213)
		if (((offest1->__get((int)0) < (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2))))){
			struct _Function_2_1{
				inline static Dynamic Block( ::Main_obj *__this,Float &offestFirstBounce){
					HX_STACK_PUSH("*::closure","Main.hx",215);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (__this->top + offestFirstBounce),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Main >,_g,Array< Float >,offest1)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_2","Main.hx",215);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",217);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->horizon - ((int)2 * ((Float((Float(_g->__get((int)0)->ballContainer->get_height()) / Float((int)2))) / Float(_g->__get((int)0)->scaleFactor))))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(217)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_1::Block(_g),false,null())->ease(::motion::easing::Quad_obj::get_easeIn());
					struct _Function_3_2{
						inline static Dynamic Block( Array< Float > &offest1){
							HX_STACK_PUSH("*::closure","Main.hx",218);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , (offest1->__get((int)0) - (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(218)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_2::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(215)
			::motion::Actuate_obj::tween(this->ballContainer,.35,_Function_2_1::Block(this,offestFirstBounce),false,null())->delay(1.0)->ease(::motion::easing::Quad_obj::get_easeIn())->onComplete( Dynamic(new _Function_2_2(_g,offest1)),null());
			struct _Function_2_3{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",222);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("scaleX") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						__result->Add(HX_CSTRING("scaleY") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_4,Array< ::Main >,_g)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_4","Main.hx",222);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",223);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() - _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(222)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(222)
			::motion::Actuate_obj::tween(this->ballContainer,1.85,_Function_2_3::Block(this),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone())->onComplete( Dynamic(new _Function_2_4(_g)),null());
		}
		else{
			struct _Function_2_1{
				inline static Dynamic Block( ::Main_obj *__this,Float &offestFirstBounce){
					HX_STACK_PUSH("*::closure","Main.hx",227);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (__this->top + offestFirstBounce),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Main >,_g,Array< Float >,offest1)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_2","Main.hx",227);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",229);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->horizon - ((int)2 * ((Float((Float(_g->__get((int)0)->ballContainer->get_height()) / Float((int)2))) / Float(_g->__get((int)0)->scaleFactor))))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(229)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_1::Block(_g),false,null())->ease(::motion::easing::Quad_obj::get_easeIn());
					struct _Function_3_2{
						inline static Dynamic Block( Array< Float > &offest1){
							HX_STACK_PUSH("*::closure","Main.hx",230);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , (offest1->__get((int)0) + (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(230)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.45,_Function_3_2::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(227)
			::motion::Actuate_obj::tween(this->ballContainer,.35,_Function_2_1::Block(this,offestFirstBounce),false,null())->delay(1.0)->ease(::motion::easing::Quad_obj::get_easeIn())->onComplete( Dynamic(new _Function_2_2(_g,offest1)),null());
			struct _Function_2_3{
				inline static Dynamic Block( ::Main_obj *__this){
					HX_STACK_PUSH("*::closure","Main.hx",234);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("scaleX") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						__result->Add(HX_CSTRING("scaleY") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
						return __result;
					}
					return null();
				}
			};

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_4,Array< ::Main >,_g)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_4","Main.hx",234);
				{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",235);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() + _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(234)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(234)
			::motion::Actuate_obj::tween(this->ballContainer,1.85,_Function_2_3::Block(this),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone())->onComplete( Dynamic(new _Function_2_4(_g)),null());
		}
		struct _Function_1_3{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",239);
				{
					HX_STACK_LINE(239)
					Dynamic f = Dynamic( Array_obj<Dynamic>::__new().Add(__this->reset_dyn()));		HX_STACK_VAR(f,"f");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,f)
					Void run(){
						HX_STACK_PUSH("*::_Function_2_1","Main.hx",239);
						{
							HX_STACK_LINE(239)
							return null(f->__GetItem((int)0)().Cast< Void >());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0((void))

					HX_STACK_LINE(239)
					return  Dynamic(new _Function_2_1(f));
				}
				return null();
			}
		};
		HX_STACK_LINE(239)
		::haxe::Timer_obj::delay(_Function_1_3::Block(this),(int)3500);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,bouncedTweenOutside,(void))

Void Main_obj::normalTweenPlusWind( Float offest,Float wind){
{
		HX_STACK_PUSH("Main::normalTweenPlusWind","Main.hx",178);
		HX_STACK_THIS(this);
		HX_STACK_ARG(offest,"offest");
		HX_STACK_ARG(wind,"wind");
		HX_STACK_LINE(178)
		Array< Float > offest1 = Array_obj< Float >::__new().Add(offest);		HX_STACK_VAR(offest1,"offest1");
		HX_STACK_LINE(178)
		Array< ::Main > _g = Array_obj< ::Main >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static Dynamic Block( Array< Float > &offest1){
				HX_STACK_PUSH("*::closure","Main.hx",180);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , offest1->__get((int)0),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(180)
		::motion::Actuate_obj::tween(this->ballContainer,1.5,_Function_1_1::Block(offest1),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
		struct _Function_1_2{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",181);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("y") , __this->top,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(181)
		::motion::Actuate_obj::tween(this->ballContainer,1.0,_Function_1_2::Block(this),null(),null())->ease(::motion::easing::Quad_obj::get_easeOut());
		struct _Function_1_3{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",182);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("y") , (__this->horizon - (Float((Float(__this->ballContainer->get_height()) / Float((int)2))) / Float(__this->scaleFactor))),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(182)
		::motion::Actuate_obj::tween(this->ballContainer,.50,_Function_1_3::Block(this),false,null())->delay((int)1)->ease(::motion::easing::Quad_obj::get_easeIn());
		struct _Function_1_4{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",184);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
					__result->Add(HX_CSTRING("scaleY") , (Float(__this->originalScale) / Float(__this->scaleFactor)),false);
					return __result;
				}
				return null();
			}
		};

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_5,Array< Float >,offest1,Array< ::Main >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_5","Main.hx",184);
			{
				HX_STACK_LINE(184)
				if (((offest1->__get((int)0) < (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2))))){
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",189);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() - _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(188)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
				else{
					struct _Function_3_1{
						inline static Dynamic Block( Array< ::Main > &_g){
							HX_STACK_PUSH("*::closure","Main.hx",192);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("y") , (_g->__get((int)0)->ballContainer->get_y() - (Float(_g->__get((int)0)->objectToThrowHalfWidth) / Float((int)2))),false);
								__result->Add(HX_CSTRING("x") , (_g->__get((int)0)->ballContainer->get_x() + _g->__get((int)0)->objectToThrowHalfWidth),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(191)
					::motion::Actuate_obj::tween(_g->__get((int)0)->ballContainer,.5,_Function_3_1::Block(_g),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone());
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(184)
		::motion::Actuate_obj::tween(this->ballContainer,1.50,_Function_1_4::Block(this),null(),null())->ease(::motion::easing::Linear_obj::get_easeNone())->onComplete( Dynamic(new _Function_1_5(offest1,_g)),null());
		HX_STACK_LINE(197)
		if (((bool((offest1->__get((int)0) > (this->leftEdge + this->objectToThrowHalfWidth))) && bool((offest1->__get((int)0) < (this->rightEdge - this->objectToThrowHalfWidth)))))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","Main.hx",199);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("alpha") , .0,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(197)
			::motion::Actuate_obj::tween(this->ballContainer,.05,_Function_2_1::Block(),null(),null())->delay(1.5)->ease(::motion::easing::Linear_obj::get_easeNone());
		}
		struct _Function_1_6{
			inline static Dynamic Block( ::Main_obj *__this){
				HX_STACK_PUSH("*::closure","Main.hx",203);
				{
					HX_STACK_LINE(203)
					Dynamic f = Dynamic( Array_obj<Dynamic>::__new().Add(__this->reset_dyn()));		HX_STACK_VAR(f,"f");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,f)
					Void run(){
						HX_STACK_PUSH("*::_Function_2_1","Main.hx",203);
						{
							HX_STACK_LINE(203)
							return null(f->__GetItem((int)0)().Cast< Void >());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0((void))

					HX_STACK_LINE(203)
					return  Dynamic(new _Function_2_1(f));
				}
				return null();
			}
		};
		HX_STACK_LINE(203)
		::haxe::Timer_obj::delay(_Function_1_6::Block(this),(int)3500);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,normalTweenPlusWind,(void))

Void Main_obj::onTouchUp( Dynamic event){
{
		HX_STACK_PUSH("Main::onTouchUp","Main.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(109)
		this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(111)
		::haxe::Log_obj::trace(HX_CSTRING("Touch end"),hx::SourceInfo(HX_CSTRING("Main.hx"),111,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
		HX_STACK_LINE(112)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onTouchUp_dyn(),null());
		HX_STACK_LINE(116)
		if (((event->__Field(HX_CSTRING("stageY"),true) < this->startY))){
			HX_STACK_LINE(118)
			this->leftEdge = ((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)9);
			HX_STACK_LINE(119)
			this->rightEdge = ((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)21)) * (int)12);
			HX_STACK_LINE(122)
			int hitTest;		HX_STACK_VAR(hitTest,"hitTest");
			HX_STACK_LINE(123)
			hitTest = event->__Field(HX_CSTRING("stageX"),true);
			HX_STACK_LINE(124)
			::haxe::Log_obj::trace((((((((HX_CSTRING("") + hitTest) + HX_CSTRING(" + ")) + this->objectToThrowHalfWidth) + HX_CSTRING(" | ")) + this->leftEdge) + HX_CSTRING(" | ")) + this->rightEdge),hx::SourceInfo(HX_CSTRING("Main.hx"),124,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
			HX_STACK_LINE(126)
			if (((hitTest < (this->leftEdge - this->objectToThrowHalfWidth)))){
				HX_STACK_LINE(128)
				::haxe::Log_obj::trace(HX_CSTRING("left out"),hx::SourceInfo(HX_CSTRING("Main.hx"),128,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
				HX_STACK_LINE(129)
				this->normalTweenPlusWind(hitTest,(int)0);
			}
			else{
				HX_STACK_LINE(131)
				if (((bool((hitTest > (this->leftEdge - this->objectToThrowHalfWidth))) && bool((hitTest < this->leftEdge))))){
					HX_STACK_LINE(134)
					::haxe::Log_obj::trace(HX_CSTRING("left on left side "),hx::SourceInfo(HX_CSTRING("Main.hx"),134,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
					HX_STACK_LINE(135)
					this->bouncedTweenOutside(hitTest,(int)0);
				}
				else{
					HX_STACK_LINE(138)
					if (((bool((hitTest > this->leftEdge)) && bool((hitTest < (this->leftEdge + this->objectToThrowHalfWidth)))))){
						HX_STACK_LINE(139)
						::haxe::Log_obj::trace(HX_CSTRING("left on right side"),hx::SourceInfo(HX_CSTRING("Main.hx"),139,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
						HX_STACK_LINE(140)
						this->bouncedTweenInside(hitTest,(int)0);
					}
					else{
						HX_STACK_LINE(143)
						if (((bool((hitTest > (this->leftEdge + this->objectToThrowHalfWidth))) && bool((hitTest < (this->rightEdge - this->objectToThrowHalfWidth)))))){
							HX_STACK_LINE(145)
							::haxe::Log_obj::trace(HX_CSTRING("IN THE MIDDLE"),hx::SourceInfo(HX_CSTRING("Main.hx"),145,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
							HX_STACK_LINE(147)
							this->normalTweenPlusWind(hitTest,(int)0);
						}
						else{
							HX_STACK_LINE(149)
							if (((hitTest > (this->rightEdge + this->objectToThrowHalfWidth)))){
								HX_STACK_LINE(151)
								::haxe::Log_obj::trace(HX_CSTRING("rightEdge out"),hx::SourceInfo(HX_CSTRING("Main.hx"),151,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
								HX_STACK_LINE(152)
								this->normalTweenPlusWind(hitTest,(int)0);
							}
							else{
								HX_STACK_LINE(155)
								if (((bool((hitTest < (this->rightEdge + this->objectToThrowHalfWidth))) && bool((hitTest > this->rightEdge))))){
									HX_STACK_LINE(157)
									::haxe::Log_obj::trace(HX_CSTRING("right on right side "),hx::SourceInfo(HX_CSTRING("Main.hx"),157,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
									HX_STACK_LINE(158)
									this->bouncedTweenOutside(hitTest,(int)0);
								}
								else{
									HX_STACK_LINE(161)
									if (((bool((hitTest < this->rightEdge)) && bool((hitTest > (this->rightEdge - this->objectToThrowHalfWidth)))))){
										HX_STACK_LINE(162)
										::haxe::Log_obj::trace(HX_CSTRING("right in left side"),hx::SourceInfo(HX_CSTRING("Main.hx"),162,HX_CSTRING("Main"),HX_CSTRING("onTouchUp")));
										HX_STACK_LINE(163)
										this->bouncedTweenInside(hitTest,(int)0);
									}
								}
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onTouchUp,(void))

Void Main_obj::onTouchDown( Dynamic event){
{
		HX_STACK_PUSH("Main::onTouchDown","Main.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(100)
		::haxe::Log_obj::trace(HX_CSTRING("Touch start"),hx::SourceInfo(HX_CSTRING("Main.hx"),100,HX_CSTRING("Main"),HX_CSTRING("onTouchDown")));
		HX_STACK_LINE(101)
		this->isDragging = true;
		HX_STACK_LINE(103)
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
	HX_MARK_MEMBER_NAME(scrollBar,"scrollBar");
	HX_MARK_MEMBER_NAME(rightEdge,"rightEdge");
	HX_MARK_MEMBER_NAME(leftEdge,"leftEdge");
	HX_MARK_MEMBER_NAME(originalScale,"originalScale");
	HX_MARK_MEMBER_NAME(previousY,"previousY");
	HX_MARK_MEMBER_NAME(falling,"falling");
	HX_MARK_MEMBER_NAME(inTheBin,"inTheBin");
	HX_MARK_MEMBER_NAME(scaleFactor,"scaleFactor");
	HX_MARK_MEMBER_NAME(horizon,"horizon");
	HX_MARK_MEMBER_NAME(objectToThrowHalfWidth,"objectToThrowHalfWidth");
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
	HX_VISIT_MEMBER_NAME(scrollBar,"scrollBar");
	HX_VISIT_MEMBER_NAME(rightEdge,"rightEdge");
	HX_VISIT_MEMBER_NAME(leftEdge,"leftEdge");
	HX_VISIT_MEMBER_NAME(originalScale,"originalScale");
	HX_VISIT_MEMBER_NAME(previousY,"previousY");
	HX_VISIT_MEMBER_NAME(falling,"falling");
	HX_VISIT_MEMBER_NAME(inTheBin,"inTheBin");
	HX_VISIT_MEMBER_NAME(scaleFactor,"scaleFactor");
	HX_VISIT_MEMBER_NAME(horizon,"horizon");
	HX_VISIT_MEMBER_NAME(objectToThrowHalfWidth,"objectToThrowHalfWidth");
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
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"startY") ) { return startY; }
		if (HX_FIELD_EQ(inName,"startX") ) { return startX; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"falling") ) { return falling; }
		if (HX_FIELD_EQ(inName,"horizon") ) { return horizon; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftEdge") ) { return leftEdge; }
		if (HX_FIELD_EQ(inName,"inTheBin") ) { return inTheBin; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onTouchUp") ) { return onTouchUp_dyn(); }
		if (HX_FIELD_EQ(inName,"scrollBar") ) { return scrollBar; }
		if (HX_FIELD_EQ(inName,"rightEdge") ) { return rightEdge; }
		if (HX_FIELD_EQ(inName,"previousY") ) { return previousY; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawBucket") ) { return drawBucket_dyn(); }
		if (HX_FIELD_EQ(inName,"isDragging") ) { return isDragging; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onTouchDown") ) { return onTouchDown_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleFactor") ) { return scaleFactor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"originalScale") ) { return originalScale; }
		if (HX_FIELD_EQ(inName,"ballContainer") ) { return ballContainer; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"bouncedTweenInside") ) { return bouncedTweenInside_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"bouncedTweenOutside") ) { return bouncedTweenOutside_dyn(); }
		if (HX_FIELD_EQ(inName,"normalTweenPlusWind") ) { return normalTweenPlusWind_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"objectToThrowHalfWidth") ) { return objectToThrowHalfWidth; }
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
	case 7:
		if (HX_FIELD_EQ(inName,"falling") ) { falling=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"horizon") ) { horizon=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftEdge") ) { leftEdge=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"inTheBin") ) { inTheBin=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"scrollBar") ) { scrollBar=inValue.Cast< ::ItemScrollBar >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightEdge") ) { rightEdge=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"previousY") ) { previousY=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isDragging") ) { isDragging=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"scaleFactor") ) { scaleFactor=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"originalScale") ) { originalScale=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ballContainer") ) { ballContainer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"objectToThrowHalfWidth") ) { objectToThrowHalfWidth=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scrollBar"));
	outFields->push(HX_CSTRING("rightEdge"));
	outFields->push(HX_CSTRING("leftEdge"));
	outFields->push(HX_CSTRING("originalScale"));
	outFields->push(HX_CSTRING("previousY"));
	outFields->push(HX_CSTRING("falling"));
	outFields->push(HX_CSTRING("inTheBin"));
	outFields->push(HX_CSTRING("scaleFactor"));
	outFields->push(HX_CSTRING("horizon"));
	outFields->push(HX_CSTRING("objectToThrowHalfWidth"));
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
	HX_CSTRING("reset"),
	HX_CSTRING("drawBucket"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("bouncedTweenInside"),
	HX_CSTRING("bouncedTweenOutside"),
	HX_CSTRING("normalTweenPlusWind"),
	HX_CSTRING("onTouchUp"),
	HX_CSTRING("onTouchDown"),
	HX_CSTRING("scrollBar"),
	HX_CSTRING("rightEdge"),
	HX_CSTRING("leftEdge"),
	HX_CSTRING("originalScale"),
	HX_CSTRING("previousY"),
	HX_CSTRING("falling"),
	HX_CSTRING("inTheBin"),
	HX_CSTRING("scaleFactor"),
	HX_CSTRING("horizon"),
	HX_CSTRING("objectToThrowHalfWidth"),
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

