package au.com.recyclesmart.events;

import nme.events.Event;

class AppEvent extends Event
{
    private var _data:Dynamic;

    static public inline var NEW_ITEM_SELECTED:String = 'newItemSelected';

    public function new(type:String, o:Dynamic = null, bubbles:Bool=false, cancelable:Bool=false)
    {
        super(type, bubbles, cancelable);
        _data = o;
    }

    public function getData():Dynamic
    {
        return _data;
    }

    public override function clone():Event
    {
        return new AppEvent(type, bubbles, cancelable, _data);
    }

    public override function toString():String
    {
        return "[AppeEvent "+ this.type +"]";
        // return formatToString("AppEvent","bubbles","cancelable","_data");
    }
}