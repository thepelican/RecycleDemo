#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_PropertyDetails
#include <com/eclecticdesignstudio/motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_actuators_SimpleActuator
#include <com/eclecticdesignstudio/motion/actuators/SimpleActuator.h>
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
#ifndef INCLUDED_native_filters_BitmapFilter
#include <native/filters/BitmapFilter.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace actuators{

Void FilterActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("FilterActuator::new","com/eclecticdesignstudio/motion/actuators/FilterActuator.hx",20);
{
	HX_STACK_LINE(22)
	this->filterIndex = (int)-1;
	HX_STACK_LINE(24)
	super::__construct(target,duration,properties);
	HX_STACK_LINE(26)
	if ((::Std_obj::is(properties->__Field(HX_CSTRING("filter"),true),hx::ClassOf< ::Class >()))){
		HX_STACK_LINE(28)
		this->filterClass = properties->__Field(HX_CSTRING("filter"),true);
		HX_STACK_LINE(30)
		{
			HX_STACK_LINE(30)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Dynamic _g1 = (hx::TCast< native::display::DisplayObject >::cast(target))->get_filters();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(30)
			while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
				HX_STACK_LINE(30)
				Dynamic filter = _g1->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(30)
				++(_g);
				HX_STACK_LINE(32)
				if ((::Std_obj::is(filter,this->filterClass))){
					HX_STACK_LINE(32)
					this->filter = filter;
				}
			}
		}
	}
	else{
		HX_STACK_LINE(42)
		this->filterIndex = properties->__Field(HX_CSTRING("filter"),true);
		HX_STACK_LINE(43)
		this->filter = (hx::TCast< native::display::DisplayObject >::cast(target))->get_filters()->__GetItem(this->filterIndex);
	}
}
;
	return null();
}

FilterActuator_obj::~FilterActuator_obj() { }

Dynamic FilterActuator_obj::__CreateEmpty() { return  new FilterActuator_obj; }
hx::ObjectPtr< FilterActuator_obj > FilterActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< FilterActuator_obj > result = new FilterActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic FilterActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FilterActuator_obj > result = new FilterActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FilterActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("FilterActuator::update","com/eclecticdesignstudio/motion/actuators/FilterActuator.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(94)
		this->super::update(currentTime);
		HX_STACK_LINE(96)
		Dynamic filters = (hx::TCast< native::display::DisplayObject >::cast(this->target))->get_filters();		HX_STACK_VAR(filters,"filters");
		HX_STACK_LINE(98)
		if (((this->filterIndex > (int)-1))){
			HX_STACK_LINE(98)
			if (((filters != null()))){
				HX_STACK_LINE(100)
				filters->__SetField(this->properties->__Field(HX_CSTRING("filter"),true),this->filter,false);
			}
		}
		else{
			HX_STACK_LINE(104)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = filters->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(104)
			while(((_g1 < _g))){
				HX_STACK_LINE(104)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(106)
				if ((::Std_obj::is(filters->__GetItem(i),this->filterClass))){
					HX_STACK_LINE(106)
					hx::IndexRef((filters).mPtr,i) = this->filter;
				}
			}
		}
		HX_STACK_LINE(116)
		this->target->__FieldRef(HX_CSTRING("filters")) = filters;
	}
return null();
}


Void FilterActuator_obj::initialize( ){
{
		HX_STACK_PUSH("FilterActuator::initialize","com/eclecticdesignstudio/motion/actuators/FilterActuator.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_LINE(71)
		::com::eclecticdesignstudio::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(72)
		Float start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(74)
		{
			HX_STACK_LINE(74)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(74)
			while(((_g < _g1->length))){
				HX_STACK_LINE(74)
				::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(74)
				++(_g);
				HX_STACK_LINE(76)
				if (((propertyName != HX_CSTRING("filter")))){
					HX_STACK_LINE(78)
					start = ::Reflect_obj::field(this->filter,propertyName);
					HX_STACK_LINE(79)
					details = ::com::eclecticdesignstudio::motion::actuators::PropertyDetails_obj::__new(this->filter,propertyName,start,(::Reflect_obj::field(this->properties,propertyName) - start),null());
					HX_STACK_LINE(80)
					this->propertyDetails->push(details);
				}
			}
		}
		HX_STACK_LINE(86)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(87)
		this->initialized = true;
	}
return null();
}


Void FilterActuator_obj::apply( ){
{
		HX_STACK_PUSH("FilterActuator::apply","com/eclecticdesignstudio/motion/actuators/FilterActuator.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		{
			HX_STACK_LINE(52)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(52)
			while(((_g < _g1->length))){
				HX_STACK_LINE(52)
				::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(52)
				++(_g);
				HX_STACK_LINE(54)
				if (((propertyName != HX_CSTRING("filter")))){
					HX_STACK_LINE(56)
					Dynamic o = this->filter;		HX_STACK_VAR(o,"o");
					HX_STACK_LINE(56)
					if (((o != null()))){
						HX_STACK_LINE(56)
						o->__SetField(propertyName,::Reflect_obj::field(this->properties,propertyName),false);
					}
				}
			}
		}
		HX_STACK_LINE(62)
		Array< ::native::filters::BitmapFilter > filters = this->target->__Field(HX_CSTRING("filters"),true);		HX_STACK_VAR(filters,"filters");
		HX_STACK_LINE(63)
		if (((filters != null()))){
			HX_STACK_LINE(63)
			filters->__SetField(this->properties->__Field(HX_CSTRING("filter"),true),this->filter,false);
		}
		HX_STACK_LINE(64)
		this->target->__FieldRef(HX_CSTRING("filters")) = filters;
	}
return null();
}



FilterActuator_obj::FilterActuator_obj()
{
}

void FilterActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FilterActuator);
	HX_MARK_MEMBER_NAME(filterIndex,"filterIndex");
	HX_MARK_MEMBER_NAME(filterClass,"filterClass");
	HX_MARK_MEMBER_NAME(filter,"filter");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FilterActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(filterIndex,"filterIndex");
	HX_VISIT_MEMBER_NAME(filterClass,"filterClass");
	HX_VISIT_MEMBER_NAME(filter,"filter");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FilterActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"filter") ) { return filter; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"filterIndex") ) { return filterIndex; }
		if (HX_FIELD_EQ(inName,"filterClass") ) { return filterClass; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FilterActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { filter=inValue.Cast< ::native::filters::BitmapFilter >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"filterIndex") ) { filterIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"filterClass") ) { filterClass=inValue.Cast< ::Class >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FilterActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("filterIndex"));
	outFields->push(HX_CSTRING("filterClass"));
	outFields->push(HX_CSTRING("filter"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initialize"),
	HX_CSTRING("apply"),
	HX_CSTRING("filterIndex"),
	HX_CSTRING("filterClass"),
	HX_CSTRING("filter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FilterActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FilterActuator_obj::__mClass,"__mClass");
};

Class FilterActuator_obj::__mClass;

void FilterActuator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.actuators.FilterActuator"), hx::TCanCast< FilterActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FilterActuator_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace actuators
