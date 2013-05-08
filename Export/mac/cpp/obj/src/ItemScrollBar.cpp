#include <hxcpp.h>

#ifndef INCLUDED_ItemScrollBar
#include <ItemScrollBar.h>
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
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
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

Void ItemScrollBar_obj::__construct()
{
HX_STACK_PUSH("ItemScrollBar::new","ItemScrollBar.hx",12);
{
	HX_STACK_LINE(13)
	super::__construct();
	HX_STACK_LINE(15)
	this->padding = (int)5;
}
;
	return null();
}

ItemScrollBar_obj::~ItemScrollBar_obj() { }

Dynamic ItemScrollBar_obj::__CreateEmpty() { return  new ItemScrollBar_obj; }
hx::ObjectPtr< ItemScrollBar_obj > ItemScrollBar_obj::__new()
{  hx::ObjectPtr< ItemScrollBar_obj > result = new ItemScrollBar_obj();
	result->__construct();
	return result;}

Dynamic ItemScrollBar_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ItemScrollBar_obj > result = new ItemScrollBar_obj();
	result->__construct();
	return result;}

Void ItemScrollBar_obj::setModel( Array< ::String > model){
{
		HX_STACK_PUSH("ItemScrollBar::setModel","ItemScrollBar.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(model,"model");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ItemScrollBar_obj,setModel,(void))

Void ItemScrollBar_obj::finishDrag( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("ItemScrollBar::finishDrag","ItemScrollBar.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(55)
		this->removeEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->dragMove_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ItemScrollBar_obj,finishDrag,(void))

Void ItemScrollBar_obj::dragMove( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("ItemScrollBar::dragMove","ItemScrollBar.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(48)
		Float deltaX = (e->stageX - this->touchStartX);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(52)
		this->scrollingPanel->set_x((this->panelStartX + deltaX));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ItemScrollBar_obj,dragMove,(void))

Void ItemScrollBar_obj::beginDrag( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("ItemScrollBar::beginDrag","ItemScrollBar.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(40)
		this->panelStartX = this->scrollingPanel->get_x();
		HX_STACK_LINE(41)
		this->touchStartX = e->stageX;
		HX_STACK_LINE(43)
		this->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->dragMove_dyn(),null(),null(),null());
		HX_STACK_LINE(44)
		this->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->finishDrag_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ItemScrollBar_obj,beginDrag,(void))

Void ItemScrollBar_obj::drawScrollingPanel( Float w,Float h){
{
		HX_STACK_PUSH("ItemScrollBar::drawScrollingPanel","ItemScrollBar.hx",30);
		HX_STACK_THIS(this);
		HX_STACK_ARG(w,"w");
		HX_STACK_ARG(h,"h");
		HX_STACK_LINE(31)
		this->scrollingPanel = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(32)
		this->scrollingPanel->get_graphics()->beginFill((int)0,(int)1);
		HX_STACK_LINE(33)
		this->scrollingPanel->get_graphics()->drawRect(this->padding,this->padding,(w * (int)2),(h - (this->padding * (int)2)));
		HX_STACK_LINE(34)
		this->scrollingPanel->get_graphics()->endFill();
		HX_STACK_LINE(35)
		this->addChild(this->scrollingPanel);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ItemScrollBar_obj,drawScrollingPanel,(void))

Void ItemScrollBar_obj::setSize( Float newWidth,Float newHeight){
{
		HX_STACK_PUSH("ItemScrollBar::setSize","ItemScrollBar.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newWidth,"newWidth");
		HX_STACK_ARG(newHeight,"newHeight");
		HX_STACK_LINE(21)
		this->get_graphics()->beginFill((int)16711680,(int)1);
		HX_STACK_LINE(22)
		this->get_graphics()->drawRect((int)0,(int)0,newWidth,newHeight);
		HX_STACK_LINE(23)
		this->get_graphics()->endFill();
		HX_STACK_LINE(25)
		this->drawScrollingPanel(newWidth,newHeight);
		HX_STACK_LINE(27)
		this->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->beginDrag_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ItemScrollBar_obj,setSize,(void))


ItemScrollBar_obj::ItemScrollBar_obj()
{
}

void ItemScrollBar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ItemScrollBar);
	HX_MARK_MEMBER_NAME(panelStartX,"panelStartX");
	HX_MARK_MEMBER_NAME(touchStartX,"touchStartX");
	HX_MARK_MEMBER_NAME(padding,"padding");
	HX_MARK_MEMBER_NAME(scrollingPanel,"scrollingPanel");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ItemScrollBar_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(panelStartX,"panelStartX");
	HX_VISIT_MEMBER_NAME(touchStartX,"touchStartX");
	HX_VISIT_MEMBER_NAME(padding,"padding");
	HX_VISIT_MEMBER_NAME(scrollingPanel,"scrollingPanel");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ItemScrollBar_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"setSize") ) { return setSize_dyn(); }
		if (HX_FIELD_EQ(inName,"padding") ) { return padding; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setModel") ) { return setModel_dyn(); }
		if (HX_FIELD_EQ(inName,"dragMove") ) { return dragMove_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"beginDrag") ) { return beginDrag_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishDrag") ) { return finishDrag_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"panelStartX") ) { return panelStartX; }
		if (HX_FIELD_EQ(inName,"touchStartX") ) { return touchStartX; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"scrollingPanel") ) { return scrollingPanel; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"drawScrollingPanel") ) { return drawScrollingPanel_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ItemScrollBar_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"padding") ) { padding=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"panelStartX") ) { panelStartX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchStartX") ) { touchStartX=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"scrollingPanel") ) { scrollingPanel=inValue.Cast< ::native::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ItemScrollBar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("panelStartX"));
	outFields->push(HX_CSTRING("touchStartX"));
	outFields->push(HX_CSTRING("padding"));
	outFields->push(HX_CSTRING("scrollingPanel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setModel"),
	HX_CSTRING("finishDrag"),
	HX_CSTRING("dragMove"),
	HX_CSTRING("beginDrag"),
	HX_CSTRING("drawScrollingPanel"),
	HX_CSTRING("setSize"),
	HX_CSTRING("panelStartX"),
	HX_CSTRING("touchStartX"),
	HX_CSTRING("padding"),
	HX_CSTRING("scrollingPanel"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ItemScrollBar_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ItemScrollBar_obj::__mClass,"__mClass");
};

Class ItemScrollBar_obj::__mClass;

void ItemScrollBar_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("ItemScrollBar"), hx::TCanCast< ItemScrollBar_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ItemScrollBar_obj::__boot()
{
}

