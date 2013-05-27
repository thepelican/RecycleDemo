package au.com.recyclesmart.view;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.MouseEvent;
import nme.events.Event;
import haxe.Timer;

class ResultOverlay extends Sprite {

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
		var image = hasScored ? new Bitmap(Assets.getBitmapData("assets/ok.png")) : new Bitmap(Assets.getBitmapData("assets/cross.png"));
		image.width = image.width / 2;
		image.height = image.height / 2;
		image.y = (Lib.current.stage.stageHeight - image.height) / 2;
		image.x = (Lib.current.stage.stageWidth - image.width) / 2;
		addChild(image);

		var logo = new Bitmap(Assets.getBitmapData("assets/logo.png"));
		logo.width = logo.width / 2;
		logo.height = logo.height / 2;
		logo.y = image.y - (logo.height * 2);
		logo.x = (Lib.current.stage.stageWidth - logo.width) / 2;
		addChild(logo);
	}
}