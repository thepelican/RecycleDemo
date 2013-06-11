package au.com.recyclesmart.view;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.MouseEvent;
import nme.events.Event;
import haxe.Timer;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

class ResultOverlay extends Sprite {

	var returnValue:Bool;

	public function new () {
		super ();
	}

	public function setSize() {
		//draw bg
		graphics.beginFill(0x000000, 0.5);
		graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight);
		graphics.endFill();
	}

	public function setScore(hasScored:Bool) {
		returnValue = hasScored;

		var image = hasScored ? new Bitmap(Assets.getBitmapData("assets/ok.png")) : new Bitmap(Assets.getBitmapData("assets/cross.png"));
		image.width = image.width / 2;
		image.height = image.height / 2;
		image.y = (Lib.current.stage.stageHeight - image.height) / 2;
		image.x = (Lib.current.stage.stageWidth - image.width) / 2;
		addChild(image);

		var logo = new Bitmap(Assets.getBitmapData("assets/logo.png"));
		logo.width = logo.width;
		logo.height = logo.height;
		logo.y = image.y - (logo.height * 2);
		logo.x = (Lib.current.stage.stageWidth - logo.width) / 2;
		addChild(logo);

	}

	public function setTitle(title:String){

		var windTf:TextField = new TextField();
		var format:TextFormat = new TextFormat();
        format.font = "Gurmukhi MN";
        format.color = 0xFFFFFF;
        format.size = 36;
		format.align = TextFormatAlign.CENTER;
        windTf.defaultTextFormat = format;

        if (returnValue = true){
        	windTf.text = "WELL DONE!!!";
        } else {
        	windTf.text = title;
        }
		windTf.text = title;
		windTf.height = 200;
		windTf.width = Lib.current.stage.stageWidth-100;
		windTf.y = 100;
		windTf.x = (Lib.current.stage.stageWidth - windTf.width) / 2;
		
		addChild(windTf);

		windTf.wordWrap = true;
	}
}