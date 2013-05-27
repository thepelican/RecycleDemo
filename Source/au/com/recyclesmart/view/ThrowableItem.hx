package au.com.recyclesmart.view;

import nme.display.Sprite;
import nme.display.Bitmap;
import nme.Assets;

import au.com.recyclesmart.vo.ThrowableVO;

class ThrowableItem extends Sprite {

    private var _data:ThrowableVO;
    private var _bitmap:Bitmap;

    public function new(data:ThrowableVO) {
        super();
        this._data = data;

        //initialize bitmap
        _bitmap = new Bitmap(Assets.getBitmapData(_data.iconPath));

        draw();
    }

    //disegnamo l'oggetto
    private function draw():Void {
        _bitmap.bitmapData = Assets.getBitmapData(_data.iconPath);
        _bitmap.x = - _bitmap.width / 2;
        _bitmap.y = - _bitmap.height / 2;
        _bitmap.smoothing = true;
        addChild(_bitmap);

        // graphics.clear();
        // graphics.beginFill(_data.bgColor, 1);
        // graphics.drawRect(0, 0, _bitmap.height / 2, _bitmap.height / 2);
        // graphics.endFill();
    }

    public function getData():ThrowableVO {
        return _data;
    }

    public function setData(data:ThrowableVO):Void {
        if(data.type == _data.type)
            return;

        _data = data;
        draw();
    }
}