package au.com.recyclesmart.model;

import nme.errors.Error;

import au.com.recyclesmart.vo.ThrowableItem;

class Model {

    private static var _instance:Model;

    //private variables

    private var throwableItems:Array<ThrowableItem>;

    public function new()
    {
        if(_instance != null)
            throw new Error("Only one Model instance can be instantiated");

        throwableItems = new Array<ThrowableItem>();

        trace('current items: ');
    }

    public static function getInstance():Model
    {
        if (_instance == null)
            _instance = new Model();

        return _instance;
    }

    public function setThrowableItems(items:Array<ThrowableItem>):Void {
        this.throwableItems = items;
    }

    public function getThrowableItems():Array<ThrowableItem> {

        return this.throwableItems;
    }
}