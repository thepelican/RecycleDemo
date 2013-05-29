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
import nme.text.TextField;
import nme.text.TextFormat;
import haxe.Timer;

import au.com.recyclesmart.view.ResultOverlay;
import au.com.recyclesmart.view.ItemScrollBar;
import au.com.recyclesmart.eventbus.CentralDispatcher;
import au.com.recyclesmart.events.AppEvent;
import au.com.recyclesmart.model.Model;
import au.com.recyclesmart.view.ThrowableItem;

class Main extends Sprite {

	var isDragging = false;
	var startX:Float;
	var startY:Float;
	var ballContainer:ThrowableItem;
	var top:Float;
	var objectToThrowHalfWidth:Float;
	var horizon:Float;
	var scaleFactor:Float;
	var scaleFactorAfterTouchedGround:Float;

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
	var yogaWindGirl:Bitmap;

	var wind:Float;
	//to print out wind strength
	var windTf:TextField;
	var background:Bitmap;


	//scaling factor
	var globalScaleX:Float;
	var globalScaleY:Float;
	var globalScale:Float;

	//global event dispatcher
	private var dispatcher:CentralDispatcher;

	//global model
	private var model:Model;

	public function new () {

		super ();

		dispatcher = CentralDispatcher.getInstance();
		model = Model.getInstance();

		createBackgroundImage();

		startX = Lib.current.stage.stageWidth / 2;
		startY = Lib.current.stage.stageHeight / 12 * 8;
		top = Lib.current.stage.stageHeight / 6;
		horizon  = Lib.current.stage.stageHeight / 12 * 5;
		previousY = Lib.current.stage.stageHeight;

		//bin  setup
		drawBucket();
		createBinImage();
		createHalfBin();

		originalScale = globalScale;
		scaleFactor = 3;
		scaleFactorAfterTouchedGround = 1.3;

		createBall();

		objectToThrowHalfWidth = ballContainer.width/2;
		objectToThrowHalfWidth = objectToThrowHalfWidth/scaleFactor;

		// bottom scrollbar

		createScrollbar();

		createYogaGirl();

		createWindTf();
		wind = createWind();
		ballContainer.addEventListener(MouseEvent.MOUSE_DOWN, onTouchDown);

		dispatcher.addEventListener(AppEvent.NEW_ITEM_SELECTED, changeItem);
		splashScreen();

	}

	function createBall() {
		ballContainer = new ThrowableItem(model.getCurrentItem());
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.scaleX = ballContainer.scaleY = globalScale;

		addChild(ballContainer);
	}

	function createScrollbar() {
		scrollBar = new ItemScrollBar(Lib.current.stage.stageWidth, 160);
		scrollBar.y = Lib.current.stage.stageHeight - 160;
		addChild(scrollBar);
	}

	function createWindTf() {

		var windLabel:TextField = new TextField();
		windLabel.text = "WIND";

		var format:TextFormat = new TextFormat();
        format.font = "Gurmukhi MN";
        format.color = 0x0c75c6;
        format.size = 36;

        windLabel.defaultTextFormat = format;

		windLabel.text = "WIND:";
		windLabel.height = windLabel.textHeight + 5;
		windLabel.width = Lib.current.stage.stageWidth / 21 * 4;
		windLabel.y = scrollBar.y - windLabel.height;

		addChild(windLabel);

		//WIND DIRECTIONS
		windTf = new TextField();
		var format:TextFormat = new TextFormat();
        format.font = "Gurmukhi MN";
        format.color = 0x000000;
        format.size = 36;

        windTf.defaultTextFormat = format;

		windTf.text = "ciao";
		windTf.height = windTf.textHeight + 5;
		windTf.width = Lib.current.stage.stageWidth;
		windTf.y = scrollBar.y - windTf.height;
		windTf.x = windLabel.width;
		windTf.text = "";

		addChild(windTf);
	}


	function createBackgroundImage() {

		background = new Bitmap(Assets.getBitmapData("assets/background.png"));

		globalScaleX = Lib.current.stage.stageWidth / background.width;
		// trace(globalScaleX);

		globalScaleY = Lib.current.stage.stageHeight / background.height;
		// trace(globalScaleY);

		globalScale = Math.max(globalScaleX, globalScaleY);

		// trace(globalScale);

		background.scaleX = background.scaleY = globalScale;

		background.x = (Lib.current.stage.stageWidth - background.width) / 2;
		background.y = (Lib.current.stage.stageHeight - background.height) / 2;

		addChild(background);
	}

	function splashScreen() {

		var splashScreen:Bitmap = new Bitmap(Assets.getBitmapData("assets/loading_page.png"));

		splashScreen.scaleX = splashScreen.scaleY = globalScale;

		splashScreen.x = (Lib.current.stage.stageWidth - splashScreen.width) / 2;
		splashScreen.y = (Lib.current.stage.stageHeight - splashScreen.height) / 2;
		// splashScreen.scaleX = splashScreen.scaleY = .5;

		addChild(splashScreen);
		Actuate.tween(splashScreen, 1.0, {alpha: 0}).ease(Linear.easeNone).delay(3.0).onComplete(function() {
			removeChild(splashScreen);
		});
	}
	//has to be managed
	function createBinImage() {

		containerBin = new Bitmap(Assets.getBitmapData("assets/yellow.png"));
		containerBin.x = Lib.current.stage.stageWidth / 22 * 9;
		containerBin.y = Lib.current.stage.stageHeight / 12 * 4;
		containerBin.scaleX = containerBin.scaleY = globalScale;
		containerBin.smoothing = true;
		addChild(containerBin);
	}

	function createHalfBin() {
		//trace('createHalfBin');
		halfBin = new Bitmap(Assets.getBitmapData("assets/half-bin.png"));
		halfBin.x = Lib.current.stage.stageWidth / 22 * 9;
		halfBin.y = Lib.current.stage.stageHeight / 12 * 4;
		halfBin.scaleX = halfBin.scaleY = globalScale;
		halfBin.smoothing = true;
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
				Actuate.tween(ballContainer, .5, {scaleX: ballContainer.scaleX / scaleFactorAfterTouchedGround, scaleY: ballContainer.scaleX / scaleFactorAfterTouchedGround}).ease(Linear.easeNone);
			} else {
				Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);
				Actuate.tween(ballContainer, .5, {scaleX: ballContainer.scaleX / scaleFactorAfterTouchedGround, scaleY: ballContainer.scaleX / scaleFactorAfterTouchedGround}).ease(Linear.easeNone);
			}
		});

		if (offset > leftEdge + objectToThrowHalfWidth && offset < rightEdge - objectToThrowHalfWidth) {// in the middle
			Actuate.tween(ballContainer, .05, {alpha: 0}).delay(1.5).ease(Linear.easeNone);	//disapper
		}

		//show the result ok only if in the bin

		if (offset > leftEdge + objectToThrowHalfWidth && offset < rightEdge - objectToThrowHalfWidth) {
			Timer.delay(callback(showResult), 2000);

			//trace('current bin: ' + model.getCurrentBinType() + ' - item type: ' + model.getCurrentItem().bin);

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
				Actuate.tween(ballContainer, 1.5, {scaleX: ballContainer.scaleX / scaleFactorAfterTouchedGround, scaleY: ballContainer.scaleX / scaleFactorAfterTouchedGround}).ease(Linear.easeNone);
				});

			} else{
				Actuate.tween(ballContainer, 1.70, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
					Actuate.tween(ballContainer, 1.5, {y: ballContainer.y - (objectToThrowHalfWidth / 2), x: ballContainer.x + objectToThrowHalfWidth}, false).ease(Linear.easeNone);
					Actuate.tween(ballContainer, 1.5, {scaleX: ballContainer.scaleX / scaleFactorAfterTouchedGround, scaleY: ballContainer.scaleX / scaleFactorAfterTouchedGround}).ease(Linear.easeNone);

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
		Actuate.tween(ballContainer, .15, {alpha: 0}).delay(1.80).ease(Linear.easeNone);

		Timer.delay(callback(showResult), 2000);
	}

	function onEnterFrame(event) {
		//check if falling
		falling = previousY <= ballContainer.y;
		if (falling)
			addChild(halfBin);
		else {
			if(contains(halfBin))
				removeChild(halfBin);
		}

		previousY = ballContainer.y;
	}

	function createYogaGirl(){
		yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_strong_right.png"));
	}

	function setYogaGirlCoordinates(){
		yogaWindGirl.y = Lib.current.stage.stageHeight / 12 * 3;
		yogaWindGirl.x = Lib.current.stage.stageWidth / 12 * 2;

	}

	function createWind():Float {

		//POSITIVE NUMBER: WIND PUSH FROM RIGHT LO LEFT
		//NEGATIVE NUMBER : WIND PUSH FROM LEFT TO RIGHT
		var random:Float = Math.random();

		// if(contains(yogaWindGirl)){
		// 	removeChild(yogaWindGirl);
		// }

		if (random < 0.14) {
			//strong left
			windTf.text = 'strong from RIGHT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_strong_right.png"));

			random = -0.7;
		} else if (random > 0.14 && random < 0.29) {
			//middle left
			windTf.text = 'medium from RIGHT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_medium_right.png"));

			random = -0.55;
		} else if (random > 0.29 && random < 0.43) {
			//light left
			windTf.text = 'light from RIGHT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_light_right.png"));

			random = -0.3;
		} else if (random > 0.43 && random < 0.57) {
			//light left
			windTf.text = 'NO wind';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_light_no_wind.png"));

			random = 0.0;
		} else if (random > 0.57 && random < 0.72) {
			//light right
			windTf.text = 'light from LEFT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_light_left.png"));

			random = 0.3;
		} else if (random > 0.72 && random < 0.86) {
			//middle right
			windTf.text = 'medium from LEFT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_medium_left.png"));

			random = 0.55;
		} else if (random > 0.86 && random < 1.0) {
			//strogn right
			windTf.text = 'strong from LEFT';
			yogaWindGirl = new Bitmap(Assets.getBitmapData("assets/yoga_strong_left.png"));

			random = 0.7;
		}
		addChild(yogaWindGirl);
		addChild(ballContainer);
		setYogaGirlCoordinates();
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


	function showResult() {
		var result = new ResultOverlay();
		result.setSize();
		result.alpha = 0;
		result.setScore(model.getCurrentBinType() == model.getCurrentItem().bin);

		addChild(result);

		Actuate.tween(result, 1.5, {alpha: 1}).ease(Linear.easeNone).onComplete(function() {
			 Actuate.tween(result, 1.0, {alpha: 0}).ease(Linear.easeNone).delay(1.0).onComplete(function() {
				removeChild(result);
			 });
		});

		Timer.delay(callback(reset), 3000);
	}

	function reset() {
		ballContainer.x = startX;
		ballContainer.y = startY;
		ballContainer.rotation = 0;
		Actuate.tween(ballContainer, .40, {alpha: 1}).ease(Linear.easeNone);
		Actuate.tween(yogaWindGirl, .5, {alpha: 0}).ease(Linear.easeNone).onComplete(function(){

			wind = createWind();
			Actuate.tween(yogaWindGirl, 1, {alpha: 1}).ease(Linear.easeNone);

		});


		ballContainer.scaleX = ballContainer.scaleY = globalScale;
	}

	private function changeItem(e:AppEvent):Void {
		// ballContainer.graphics.beginFill(model.getCurrentItem().bgColor, 1);
		// ballContainer.graphics.drawRect(-ballContainer.width / 2, -ballContainer.height / 2, ballContainer.width, ballContainer.height);
		// ballContainer.graphics.endFill();

		ballContainer.setData(model.getCurrentItem());
	}
}