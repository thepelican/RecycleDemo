 import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.eclecticdesignstudio.motion.MotionPath;
import com.eclecticdesignstudio.motion.easing.Back;
import com.eclecticdesignstudio.motion.Actuate;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.MouseEvent;
import nme.events.Event;
import haxe.Timer;
import au.com.recyclesmart.view.ResultOverlay;
import nme.text.TextField;

class Main extends Sprite {

	var isDragging = false;
	var startX:Float;
	var startY:Float;
	var ballContainer:Sprite;
	var top:Float;
	var objectToThrowHalfWidth:Float;
	var horizon:Float;
	var scaleFactor:Float;
	var inTheBin:Bool;
	var falling:Bool;
	var previousY:Float;
	var originalScale:Float;
	//physics
	var leftEdge:Float;
	var rightEdge:Float;
	//view components
	var scrollBar:ItemScrollBar;
	var containerBin:Bitmap;
	var halfBin:Bitmap;
	var wind:Float;
	//to print out wind strength
	var windTf:TextField;

	public function new () {

		super ();

		ballContainer = new Sprite();

		var ball = new Bitmap(Assets.getBitmapData("assets/water-bottle.png"));
		ball.x = - ball.width / 2;
		ball.y = - ball.height / 2;
		startX = Lib.current.stage.stageWidth / 2;
		startY = Lib.current.stage.stageHeight / 12 * 8;
		top = Lib.current.stage.stageHeight / 6;
		horizon  =  Lib.current.stage.stageHeight / 12 * 5;
		previousY =  Lib.current.stage.stageHeight ;
		
		//bin setup
		drawBucket();
		createBinImage();
		createHalfBin();

		originalScale = .2;
		scaleFactor = 3;
		ballContainer.addChild(ball);
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.scaleX = ballContainer.scaleY = .2;
		objectToThrowHalfWidth = ballContainer.width/2;
		objectToThrowHalfWidth = objectToThrowHalfWidth/scaleFactor;
		addChild(ballContainer);

		// bottom scrollbar

		scrollBar = new ItemScrollBar();
		scrollBar.setSize(Lib.current.stage.stageWidth, Lib.current.stage.stageHeight / 6);
		scrollBar.y = Lib.current.stage.stageHeight - scrollBar.height;
		addChild(scrollBar);

		createWindTf();
		wind = createWind();
		ballContainer.addEventListener(MouseEvent.MOUSE_DOWN, onTouchDown);
	}

	// private function initialize ():Void {
	 
	//     Lib.current.stage.align = StageAlign.TOP_LEFT;
	//     Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
	 
	//     Global.stageWidth = Lib.current.stage.stageWidth;
	//     Global.stageHeight = Lib.current.stage.stageHeight;
	 
	//     trace("Lib.current.stage.stageWidth: " + Lib.current.stage.stageWidth);
	//     trace("Lib.current.stage.stageHeight: " + Lib.current.stage.stageHeight);
	 
	//     trace("Capabilities.screenResolutionX: "+ Capabilities.screenResolutionX);
	 
	//     /** adjust for multi res iOS devices, iPhone 3, 4 ² iPad 1&amp;2, 3(new) */
	//     #if iphone
	//     if (Capabilities.screenResolutionX &lt;= 320) { // iPhone classic (3 &amp; 3GS)
	//         trace("should be classic iphone (3 &amp; 3GS) " + "Global.stageWidth " + Global.stageWidth + "stageHeight " + Global.stageHeight);
	//     }
	//     else if (Capabilities.screenResolutionX &lt;= 640) { // iPad 1&amp;2
	//         trace("should be iPhone 4 &amp; 4S) " + "Global.stageWidth " + Global.stageWidth + "stageHeight " + Global.stageHeight);
	//     }
	//     else if (Capabilities.screenResolutionX &lt;= 768) { // iPad 1 &amp; 2
	//         trace("should be iPad 1 &amp; 2 " + "Global.stageWidth " + Global.stageWidth + "stageHeight " + Global.stageHeight);
	//     }
	//     else if (Capabilities.screenResolutionX &lt;= 1536) { // iPad retina
	//         trace("should be iPad retina " + "Global.stageWidth " + Global.stageWidth + "stageHeight " + Global.stageHeight);
	//     }
	//     #elseif flash
	//     Lib.current.stage.quality = StageQuality.LOW;
	//     trace("should be flash " + "Global.stageWidth " + Global.stageWidth + "stageHeight " + Global.stageHeight);
	//     #end
	// }

	function createWindTf() {
		windTf = new TextField();
		windTf.text = "ciao";
		windTf.height = windTf.textHeight + 5;
		windTf.width = Lib.current.stage.stageWidth;
		windTf.y = scrollBar.y - windTf.height;
		windTf.text = "";
		addChild(windTf);
	}

	//has to be managed
	function createBinImage() {

		containerBin = new Bitmap(Assets.getBitmapData("assets/yellow.png"));
		containerBin.x = Lib.current.stage.stageWidth / 22 * 9;
		containerBin.y = Lib.current.stage.stageHeight / 12 * 4;
		containerBin.scaleX = containerBin.scaleY = .30;

		addChild(containerBin);
	}

	function createHalfBin() {
		trace('createHalfBin');
		halfBin = new Bitmap(Assets.getBitmapData("assets/half-bin.png"));
		halfBin.x = Lib.current.stage.stageWidth / 22 * 9;
		halfBin.y = Lib.current.stage.stageHeight / 12 * 4;
		halfBin.scaleX = halfBin.scaleY = .30;

		addChild(halfBin);
	}	
	// User started to drag the ball
	function onTouchDown(event) {
		this.isDragging = true;
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, onTouchUp);
	}

	//User released touch
	function onTouchUp(event) {

		addEventListener(Event.ENTER_FRAME, onEnterFrame);

		//trace(event.stageX);
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_UP, onTouchUp);

		//rotation tween
		Actuate.tween (ballContainer, 1.5, { rotation: windInt(wind) } ).smartRotation ().ease(Linear.easeNone);
		
		if(event.stageY < startY) {
			//Lib.current.stage.stageWidth / 21 * 9    FIRST SIDE BIN
			leftEdge = Lib.current.stage.stageWidth / 21 * 9;
			rightEdge = Lib.current.stage.stageWidth / 21 * 12;

			//Lib.current.stage.stageWidth / 21 * 12   SECOND SIDE BIN
			var hitPoint:Float;

			hitPoint = event.stageX + ((Lib.stage.stageWidth / 2) * wind);

			// trace('event stage ' + event.stageX +' quanto levo ' +(Lib.stage.stageWidth / 2)*wind);

			if (hitPoint < (leftEdge - objectToThrowHalfWidth)) {
				// left rebound.. goes to left
				// trace('left out');
				normalTweenPlusWind(hitPoint, event.stageX);

			} else if (hitPoint > leftEdge - objectToThrowHalfWidth && hitPoint < leftEdge) {
				// left rebound.. touch the left  bordr and goes left
				// trace('left on left side ');
				bouncedTweenOutside(hitPoint,event.stageX);
			} else if (hitPoint > leftEdge && hitPoint < leftEdge + objectToThrowHalfWidth) {
				// trace('left on right side');
				bouncedTweenInside(hitPoint,event.stageX);
			} else if (hitPoint > leftEdge + objectToThrowHalfWidth && hitPoint < rightEdge - objectToThrowHalfWidth){
				// trace('IN THE MIDDLE');
				normalTweenPlusWind(hitPoint, event.stageX);
			} else if (hitPoint > (rightEdge + objectToThrowHalfWidth)) {
				// left rebound.. goes to left
				// trace('rightEdge out');
				normalTweenPlusWind(hitPoint, event.stageX);
			} else if (hitPoint < rightEdge + objectToThrowHalfWidth && hitPoint > rightEdge) {
				// left rebound.. touch the left  bordr and goes left
				// trace('right on right side ');
				bouncedTweenOutside(hitPoint,event.stageX);
			} else if (hitPoint < rightEdge && hitPoint > rightEdge - objectToThrowHalfWidth) {
				// trace('right in left side');
				bouncedTweenInside(hitPoint,event.stageX);
			}
		}
	}

	function normalTweenPlusWind(offset:Float, originalHitPoint:Float) {
		var path = new MotionPath ().bezier (offset, horizon - ((ballContainer.height / 2) / scaleFactor), originalHitPoint, 0, 0);
												//x,y, offsetx, offsety, strenght?   //(Lib.stage.stageWidth / 2)*wind
		Actuate.motionPath (ballContainer, 1.5, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
			removeEventListener(Event.ENTER_FRAME, onEnterFrame);
		});

		// graphics.lineStyle(2, 0xFF0000);
		// graphics.moveTo(ballContainer.x, ballContainer.y);
  //   	graphics.curveTo(originalHitPoint, 0, offset, horizon - ((ballContainer.height / 2) / scaleFactor));

		Actuate.tween(ballContainer, 1.50, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
			if (offset < Lib.current.stage.stageWidth / 2) {
				Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x-objectToThrowHalfWidth}).ease(Linear.easeNone);
			} else {
				Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);
			}
		});

		if (offset > leftEdge + objectToThrowHalfWidth && offset < rightEdge - objectToThrowHalfWidth) {// in the middle
			Actuate.tween(ballContainer, .05, {alpha: .0}).delay(1.5).ease(Linear.easeNone);	//disapper
		}

		//show the result ok ionly if inthe bin
		if (offset > leftEdge + objectToThrowHalfWidth && offset < rightEdge - objectToThrowHalfWidth){
			Timer.delay(callback(showResult), 2000);

		} else {
			Timer.delay(callback(reset), 3500);
		}
	}

	function bouncedTweenOutside(offset:Float, originalHitPoint:Float) {
		var offsetFirstBounce:Float = (Lib.current.stage.stageHeight / 12 * 4) - top - objectToThrowHalfWidth;
		var path = new MotionPath ().bezier (offset, top + offsetFirstBounce, originalHitPoint, 0, 0);

		// graphics.lineStyle(2, 0xFF0000);
		// graphics.moveTo(ballContainer.x, ballContainer.y);
  //   	graphics.curveTo(originalHitPoint, 0, offset, top + offsetFirstBounce);

		Actuate.motionPath (ballContainer, 1.25, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {

			Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);

			if (offset < Lib.current.stage.stageWidth / 2) {
				Actuate.tween(ballContainer, .45, {x: offset - (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);
			} else{
				Actuate.tween(ballContainer, .45, {x: offset + (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);
			}
			removeEventListener(Event.ENTER_FRAME, onEnterFrame);
		});

		if (offset < Lib.current.stage.stageWidth / 2) {
			Actuate.tween(ballContainer, 1.70, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
				Actuate.tween(ballContainer, 1.5, {y: ballContainer.y - (objectToThrowHalfWidth / 2), x: ballContainer.x - objectToThrowHalfWidth}, false).ease(Linear.easeNone);
				});

			} else{
				Actuate.tween(ballContainer, 1.70, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
					Actuate.tween(ballContainer, 1.5, {y: ballContainer.y - (objectToThrowHalfWidth / 2), x: ballContainer.x + objectToThrowHalfWidth}, false).ease(Linear.easeNone);
					});
			}

		Timer.delay(callback(reset), 3500);
	}

	function bouncedTweenInside(offset:Float, originalHitPoint:Float){

		var offsetFirstBounce:Float = (Lib.current.stage.stageHeight / 12 * 4) - top- objectToThrowHalfWidth;
		var path = new MotionPath ().bezier (offset, top + offsetFirstBounce , originalHitPoint, 0, 0);

		// graphics.lineStyle(2, 0xFF0000);
		// graphics.moveTo(ballContainer.x, ballContainer.y);
  //   	graphics.curveTo(originalHitPoint, 0, offset, top + offsetFirstBounce);

		Actuate.motionPath (ballContainer, 1.25, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
			if (offset < Lib.current.stage.stageWidth / 2) {
				Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
				Actuate.tween(ballContainer, .45, {x: offset + (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);
			} else{
				Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
				Actuate.tween(ballContainer, .45, {x: offset - (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);
			}

			removeEventListener(Event.ENTER_FRAME, onEnterFrame);
		});

		if (offset < Lib.current.stage.stageWidth / 2) {
			Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
				Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);
			});

		} else {
			Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
				Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x-objectToThrowHalfWidth}).ease(Linear.easeNone);
			});
		}
		//disappear
		Actuate.tween(ballContainer, .15, {alpha: .0}).delay(1.80).ease(Linear.easeNone);

		Timer.delay(callback(showResult), 2000);
	}

	function onEnterFrame(event) {
		//check if falling
		falling = previousY <= ballContainer.y;
		// if (falling)
			// addChild(halfBin);
		// else
			// removeChild(halfBin);
		previousY = ballContainer.y;
	}

	function createWind():Float {

		//POSITIVE NUMBER: WIND PUSH FROM RIGHT LO LEFT
		//NEGATIVE NUMBER : WIND PUSH FROM LEFT TO RIGHT

		var random:Float = Math.random();

		if (random < 0.14) {
			//strong left
			windTf.text = 'strong FROM RIGHT';
			random = -0.7;
		} else if (random > 0.14 && random < 0.29) {
			//middle left
			windTf.text = 'middle FROM RIGHT';
			random = -0.55;
		} else if (random > 0.29 && random < 0.43) {
			//light left
			windTf.text = 'light FROM RIGHT';
			random = -0.3;
		} else if (random > 0.43 && random < 0.57) {
			//light left
			windTf.text = 'NO wind';
			random = 0.0;
		} else if (random > 0.57 && random < 0.72) {
			//light right
			windTf.text = 'light FROM LEFT';
			random = 0.3;
		} else if (random > 0.72 && random < 0.86) {
			//middle right
			windTf.text = 'middle FROM LEFT';
			random = 0.55;
		} else if (random > 0.86 && random < 1.0) {
			//strogn right
			windTf.text = 'strong FROM LEFT';
			random = 0.7;
		}

		return	random;
	}


	function windInt(wind:Float):Int{
		var rotation:Float = 360 * wind;
		return Math.round(rotation);
	}

	function drawBucket() {
		graphics.lineStyle(1, 0, 1);
		graphics.moveTo(0, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth, horizon);

		graphics.moveTo(Lib.current.stage.stageWidth / 21 * 9, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth / 21 * 9, Lib.current.stage.stageHeight / 12 * 4);

		graphics.moveTo(Lib.current.stage.stageWidth / 21 * 12, horizon);
		graphics.lineTo(Lib.current.stage.stageWidth / 21 * 12, Lib.current.stage.stageHeight / 12 * 4);
	}

	function showResult(){

		// trace('showResult');
		var result = new ResultOverlay();
		addChild(result);
		result.setSize();
		result.setScore(true);
		 result.alpha = 0;
		Actuate.tween(result, 1.5, {alpha: 1}).ease(Linear.easeNone).onComplete(function() {					
			 Actuate.tween(result, 1.0, {alpha: 0}).ease(Linear.easeNone).delay(1.0).onComplete(function() {					
				removeChild(result);
			 });			
		});	
		Timer.delay(callback(reset), 3000);

	}



	function reset() {
		// trace("reset");
		ballContainer.x = startX;
		ballContainer.y = startY;
		wind = createWind();
		Actuate.tween(ballContainer, .30, {alpha: 1}).ease(Linear.easeNone);
		ballContainer.scaleX = ballContainer.scaleY = .2;
	}
}