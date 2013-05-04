#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_IComponentPath
#include <com/eclecticdesignstudio/motion/IComponentPath.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{

HX_DEFINE_DYNAMIC_FUNC1(IComponentPath_obj,calculate,return )


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IComponentPath_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IComponentPath_obj::__mClass,"__mClass");
};

Class IComponentPath_obj::__mClass;

void IComponentPath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.IComponentPath"), hx::TCanCast< IComponentPath_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IComponentPath_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
