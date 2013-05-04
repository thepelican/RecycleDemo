#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion__Actuate_ObjectHash
#include <com/eclecticdesignstudio/motion/_Actuate/ObjectHash.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace _Actuate{

Void ObjectHash_obj::__construct()
{
HX_STACK_PUSH("ObjectHash::new","com/eclecticdesignstudio/motion/Actuate.hx",582);
{
	HX_STACK_LINE(582)
	this->hash = ::IntHash_obj::__new();
}
;
	return null();
}

ObjectHash_obj::~ObjectHash_obj() { }

Dynamic ObjectHash_obj::__CreateEmpty() { return  new ObjectHash_obj; }
hx::ObjectPtr< ObjectHash_obj > ObjectHash_obj::__new()
{  hx::ObjectPtr< ObjectHash_obj > result = new ObjectHash_obj();
	result->__construct();
	return result;}

Dynamic ObjectHash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectHash_obj > result = new ObjectHash_obj();
	result->__construct();
	return result;}

Void ObjectHash_obj::set( Dynamic key,Dynamic value){
{
		HX_STACK_PUSH("ObjectHash::set","com/eclecticdesignstudio/motion/Actuate.hx",696);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(696)
		this->hash->set(::__hxcpp_obj_id(key),value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ObjectHash_obj,set,(void))

Void ObjectHash_obj::remove( Dynamic key){
{
		HX_STACK_PUSH("ObjectHash::remove","com/eclecticdesignstudio/motion/Actuate.hx",681);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_LINE(681)
		this->hash->remove(::__hxcpp_obj_id(key));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,remove,(void))

Dynamic ObjectHash_obj::iterator( ){
	HX_STACK_PUSH("ObjectHash::iterator","com/eclecticdesignstudio/motion/Actuate.hx",658);
	HX_STACK_THIS(this);
	HX_STACK_LINE(658)
	return this->hash->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectHash_obj,iterator,return )

int ObjectHash_obj::getID( Dynamic key){
	HX_STACK_PUSH("ObjectHash::getID","com/eclecticdesignstudio/motion/Actuate.hx",627);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(627)
	return ::__hxcpp_obj_id(key);
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,getID,return )

Dynamic ObjectHash_obj::get( Dynamic key){
	HX_STACK_PUSH("ObjectHash::get","com/eclecticdesignstudio/motion/Actuate.hx",612);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(612)
	return this->hash->get(::__hxcpp_obj_id(key));
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,get,return )

bool ObjectHash_obj::exists( Dynamic key){
	HX_STACK_PUSH("ObjectHash::exists","com/eclecticdesignstudio/motion/Actuate.hx",597);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(597)
	return this->hash->exists(::__hxcpp_obj_id(key));
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,exists,return )

int ObjectHash_obj::nextObjectID;


ObjectHash_obj::ObjectHash_obj()
{
}

void ObjectHash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectHash);
	HX_MARK_MEMBER_NAME(hash,"hash");
	HX_MARK_END_CLASS();
}

void ObjectHash_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hash,"hash");
}

Dynamic ObjectHash_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"hash") ) { return hash; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"getID") ) { return getID_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nextObjectID") ) { return nextObjectID; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectHash_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hash") ) { hash=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nextObjectID") ) { nextObjectID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectHash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hash"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nextObjectID"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("remove"),
	HX_CSTRING("iterator"),
	HX_CSTRING("getID"),
	HX_CSTRING("get"),
	HX_CSTRING("exists"),
	HX_CSTRING("hash"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectHash_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ObjectHash_obj::nextObjectID,"nextObjectID");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectHash_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ObjectHash_obj::nextObjectID,"nextObjectID");
};

Class ObjectHash_obj::__mClass;

void ObjectHash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion._Actuate.ObjectHash"), hx::TCanCast< ObjectHash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ObjectHash_obj::__boot()
{
	nextObjectID= (int)0;
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace _Actuate
