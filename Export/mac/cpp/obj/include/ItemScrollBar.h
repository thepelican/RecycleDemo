#ifndef INCLUDED_ItemScrollBar
#define INCLUDED_ItemScrollBar

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS0(ItemScrollBar)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)


class ItemScrollBar_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef ItemScrollBar_obj OBJ_;
		ItemScrollBar_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ItemScrollBar_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ItemScrollBar_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ItemScrollBar"); }

		virtual Void setModel( Array< ::String > model);
		Dynamic setModel_dyn();

		virtual Void finishDrag( ::native::events::MouseEvent e);
		Dynamic finishDrag_dyn();

		virtual Void dragMove( ::native::events::MouseEvent e);
		Dynamic dragMove_dyn();

		virtual Void beginDrag( ::native::events::MouseEvent e);
		Dynamic beginDrag_dyn();

		virtual Void drawScrollingPanel( Float w,Float h);
		Dynamic drawScrollingPanel_dyn();

		virtual Void setSize( Float newWidth,Float newHeight);
		Dynamic setSize_dyn();

		Float panelStartX; /* REM */ 
		Float touchStartX; /* REM */ 
		Float padding; /* REM */ 
		::native::display::Sprite scrollingPanel; /* REM */ 
};


#endif /* INCLUDED_ItemScrollBar */ 
