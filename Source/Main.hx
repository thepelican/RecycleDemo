import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Cubic;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Expo;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.eclecticdesignstudio.motion.easing.Quart;
import com.eclecticdesignstudio.motion.easing.Quint;
import com.eclecticdesignstudio.motion.easing.Sine;
import com.eclecticdesignstudio.motion.MotionPath;
import com.eclecticdesignstudio.motion.easing.Back;


import com.eclecticdesignstudio.motion.Actuate;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.MouseEvent;
import nme.events.Event;
import nme.events.Event;
import haxe.Timer;
class Main extends Sprite {

	var isDragging = false;
	var startX:Float;
	var startY:Float;
	var ballContainer:Sprite;
	var top:Float;

	var horizon:Float;
	var scaleFactor:Float;
	var inTheBin:Bool;
	var falling:Bool;
	var previousY:Float;
	//physics

	public function new () {

		super ();

		// background

		// var background = new Sprite();
		// background.graphics.beginFill(0xFF0000, 1);
		// background.graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight);
		// background.graphics.endFill();

		// addChild(background);
 
		// ball and container


		ballContainer = new Sprite();

		var ball = new Bitmap(Assets.getBitmapData("assets/nme.png"));
		ball.x = - ball.width / 2;
		ball.y = - ball.height / 2;

		startX = Lib.current.stage.stageWidth / 2;
		startY = Lib.current.stage.stageHeight / 12 * 8;
		top = Lib.current.stage.stageHeight / 6;
		horizon  =  Lib.current.stage.stageHeight / 12 * 5;
		previousY =  Lib.current.stage.stageHeight ;
		drawBucket();

		scaleFactor = 3;
		ballContainer.addChild(ball);
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.scaleX = ballContainer.scaleY = .2;

		addChild(ballContainer);

		// items container
		// var bar = new Sprite();
		// bar.graphics.beginFill(0xFFFF00, 1);
		// bar.graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight/6);
		// bar.graphics.endFill();

		// bar.y = Lib.current.stage.stageHeight / 6 * 5;
		// addChild(bar);

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

		addEventListener(Event.ENTER_FRAME, onEnterFrame);

		trace('Touch end');
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_UP, onTouchUp);

		var originalScale = .2;

		if(event.stageY < startY) {
			Actuate.tween(ballContainer, 1.5, {x: event.stageX}).ease(Linear.easeNone);
			Actuate.tween(ballContainer, 1.0, {y: top}).ease(Quad.easeOut);
			Actuate.tween(ballContainer, .50, {y: horizon - ((ballContainer.height/ 2) / scaleFactor)}, false).delay(1.0).ease(Quad.easeIn);
			// // //fai la roba che puzza e non melo dici
			Actuate.tween(ballContainer, 1.50, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
				
				var path = new MotionPath ().bezier (ballContainer.x, ballContainer.y , ballContainer.x, ballContainer.y - 30,0);
                                                //x,y, offestx, offsety, strenght?
				Actuate.motionPath (ballContainer, 0.5, { x: path.x, y: path.y } ).ease (Quad.easeOut);
			});

			// var path = new MotionPath ().bezier (300, 100, 300, -400, 2.5);//.line (450, 25); //!!!!!it bounces
			// var path = new MotionPath ().bezier (event.stageX, horizon - ((ballContainer.height / 2) / scaleFactor) , Lib.stage.stageWidth / 2, 0, 0);
                                                //x,y, offestx, offsety, strenght?
			// Actuate.motionPath (ballContainer, 1, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
			// 	removeEventListener(Event.ENTER_FRAME, onEnterFrame);

			// 	Timer.delay(callback(reset), 2000);
			// });
		}
	}

	function onEnterFrame(event) {

		//check if falling 
		if (previousY > ballContainer.y) {
			falling = false;
		} else {
			falling = true;
		}
		previousY = ballContainer.y;


		if(ballContainer.y >= (horizon)) {
			//null : under horizont
		} else {

			if (ballContainer.y > top && falling){
				//understand if is gonna fall inthe bin or not:)
			}
		}
	}

	function drawBucket() {
		graphics.lineStyle(1, 0, 1);
		graphics.moveTo(0, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth, horizon);

		graphics.moveTo(Lib.current.stage.stageWidth / 3, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth / 3, Lib.current.stage.stageHeight / 12 * 4);

		graphics.moveTo(Lib.current.stage.stageWidth / 3 * 2, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth / 3 * 2, Lib.current.stage.stageHeight / 12 * 4);
	}
	

	function reset(){

		trace("bravo bischero");
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.scaleX = ballContainer.scaleY = .2;
	}
}