#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_ObjectHash
#define INCLUDED_com_eclecticdesignstudio_motion__Actuate_ObjectHash

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,_Actuate,ObjectHash)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace _Actuate{


class ObjectHash_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectHash_obj OBJ_;
		ObjectHash_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ObjectHash_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ObjectHash_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ObjectHash"); }

		virtual Void set( Dynamic key,Dynamic value);
		Dynamic set_dyn();

		virtual Void remove( Dynamic key);
		Dynamic remove_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual int getID( Dynamic key);
		Dynamic getID_dyn();

		virtual Dynamic get( Dynamic key);
		Dynamic get_dyn();

		virtual bool exists( Dynamic key);
		Dynamic exists_dyn();

		::IntHash hash; /* REM */ 
		static int nextObjectID; /* REM */ 
};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace _Actuate

#endif /* INCLUDED_com_eclecticdesignstudio_motion__Actuate_ObjectHash */ 
