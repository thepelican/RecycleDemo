package au.com.recyclesmart.view;

import nme.display.Sprite;

import au.com.recyclesmart.vo.ThrowableVO;

class ThrowableItem extends Sprite {

    private var _data:ThrowableVO;
    private var _dimension:Float;

    public function new(data:ThrowableVO, dimension:Float) {
        super();
        this._data = data;
        this._dimension = dimension;
        draw();
    }

    //disegnamo l'oggetto
    private function draw():Void{
        graphics.beginFill(_data.bgColor, 1);
        graphics.drawRect(0, 0, _dimension, _dimension);
        graphics.endFill();
    }

    public function getData():ThrowableVO {
        return this._data;
    }

    public override function toString():String {
        return '[ThrowableItem of type '+ _data.type +']';
    }
}