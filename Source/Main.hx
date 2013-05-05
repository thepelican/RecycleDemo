import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Cubic;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Expo;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.eclecticdesignstudio.motion.easing.Quart;
import com.eclecticdesignstudio.motion.easing.Quint;
import com.eclecticdesignstudio.motion.easing.Sine;

import com.eclecticdesignstudio.motion.Actuate;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.MouseEvent;

class Main extends Sprite {

	var isDragging = false;
	var startX:Float;
	var startY:Float;
	var ballContainer:Sprite;
	var top:Float;

	public function new () {

		super ();

		// background

		var background = new Sprite();
		background.graphics.beginFill(0xFF0000, 1);
		background.graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight);
		background.graphics.endFill();

		addChild(background);
 
		// ball and container

		ballContainer = new Sprite();

		var ball = new Bitmap(Assets.getBitmapData("assets/nme.png"));
		ball.x = - ball.width / 2;
		ball.y = - ball.height / 2;

		startX = Lib.current.stage.stageWidth / 2;
		startY = Lib.current.stage.stageHeight / 12 * 8;
		top = Lib.current.stage.stageHeight / 6;


		ballContainer.addChild(ball);
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.scaleX = ballContainer.scaleY = .2;

		addChild(ballContainer);

		// items container


		var bar = new Sprite();
		bar.graphics.beginFill(0xFFFF00, 1);
		bar.graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight/6);
		bar.graphics.endFill();

		bar.y = Lib.current.stage.stageHeight / 6 * 5;
		addChild(bar);

		ballContainer.addEventListener(MouseEvent.MOUSE_DOWN, onTouchDown);
	}

	// User started to drag the ball

	function onTouchDown(event) {
		trace('Touch start');
		this.isDragging = true;

		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, onTouchUp);
	}

	//User released touch

	function onTouchUp(event) {
		trace('Touch end');
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_UP, onTouchUp);

		var originalScale = .2;

		if(event.stageY < startY) {
			Actuate.tween(ballContainer, 1.5, {x: event.stageX}).ease(Quad.easeInOut);
			Actuate.tween(ballContainer, 1.0, {y: top}).ease(Quad.easeOut);
			Actuate.tween(ballContainer, .50, {y: (top * 2)}, false).delay(1.0).ease(Quad.easeIn);
			//fai la roba che puzza e non melo dici
			Actuate.tween(ballContainer, 1.5, {scaleX: originalScale / 3, scaleY: originalScale / 3}).ease(Linear.easeNone);
		}
	}

}