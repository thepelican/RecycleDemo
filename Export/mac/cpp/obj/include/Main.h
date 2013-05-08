#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS0(ItemScrollBar)
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)


class Main_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void drawBucket( );
		Dynamic drawBucket_dyn();

		virtual Void onEnterFrame( Dynamic event);
		Dynamic onEnterFrame_dyn();

		virtual Void bouncedTweenInside( Float offest,Float wind);
		Dynamic bouncedTweenInside_dyn();

		virtual Void bouncedTweenOutside( Float offest,Float wind);
		Dynamic bouncedTweenOutside_dyn();

		virtual Void normalTweenPlusWind( Float offest,Float wind);
		Dynamic normalTweenPlusWind_dyn();

		virtual Void onTouchUp( Dynamic event);
		Dynamic onTouchUp_dyn();

		virtual Void onTouchDown( Dynamic event);
		Dynamic onTouchDown_dyn();

		::ItemScrollBar scrollBar; /* REM */ 
		Float rightEdge; /* REM */ 
		Float leftEdge; /* REM */ 
		Float originalScale; /* REM */ 
		Float previousY; /* REM */ 
		bool falling; /* REM */ 
		bool inTheBin; /* REM */ 
		Float scaleFactor; /* REM */ 
		Float horizon; /* REM */ 
		Float objectToThrowHalfWidth; /* REM */ 
		Float top; /* REM */ 
		::native::display::Sprite ballContainer; /* REM */ 
		Float startY; /* REM */ 
		Float startX; /* REM */ 
		bool isDragging; /* REM */ 
};


#endif /* INCLUDED_Main */ 
