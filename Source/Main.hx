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
import haxe.Timer;

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
	var wind:Float;

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

		wind = createWind();
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

		trace(event.stageX);
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_UP, onTouchUp);

		if(event.stageY < startY) {
			//Lib.current.stage.stageWidth / 21 * 9    FIRST SIDE BIN
		leftEdge = Lib.current.stage.stageWidth / 21 * 9;
		rightEdge = Lib.current.stage.stageWidth / 21 * 12;

			//Lib.current.stage.stageWidth / 21 * 12   SECOND SIDE BIN
			var hitTest:Float;

			hitTest = event.stageX + ((Lib.stage.stageWidth / 2)*wind);

			// hitTest = event.stageX;
			  trace('event stage ' + event.stageX +' quanto levo ' +(Lib.stage.stageWidth / 2)*wind);

			 if (hitTest < (leftEdge - objectToThrowHalfWidth)) {
				// left rebound.. goes to left
				trace('left out');
				normalTweenPlusWind(hitTest, wind);

			} else if (hitTest > leftEdge - objectToThrowHalfWidth && hitTest < leftEdge) {
					// left rebound.. touch the left  bordr and goes left

				trace('left on left side ');
				bouncedTweenOutside(hitTest,wind);


			} else if (hitTest > leftEdge && hitTest < leftEdge + objectToThrowHalfWidth) {
				trace('left on right side');
				bouncedTweenInside(hitTest,wind);


			} else if (hitTest > leftEdge + objectToThrowHalfWidth && hitTest < rightEdge - objectToThrowHalfWidth){
						
				trace('IN THE MIDDLE');
			
				normalTweenPlusWind(hitTest, wind);

			} else if (hitTest > (rightEdge + objectToThrowHalfWidth)) {
				// left rebound.. goes to left
				trace('rightEdge out');
				normalTweenPlusWind(hitTest, wind);


			} else if (hitTest < rightEdge + objectToThrowHalfWidth && hitTest > rightEdge) {
					// left rebound.. touch the left  bordr and goes left
				trace('right on right side ');
				bouncedTweenOutside(hitTest,wind);


			} else if (hitTest < rightEdge && hitTest > rightEdge - objectToThrowHalfWidth) {
					trace('right in left side');
					bouncedTweenInside(hitTest,wind);
			}



			// var path = new MotionPath ().bezier (300, 100, 300, -400, 2.5);//.line (450, 25); //!!!!!it bounces
			// var path = new MotionPath ().bezier (event.stageX, horizon - ((ballContainer.height / 2) / scaleFactor) , Lib.stage.stageWidth / 2, 0, 0);
                                                //x,y, offestx, offsety, strenght?
			// Actuate.motionPath (ballContainer, 1, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
			// 	removeEventListener(Event.ENTER_FRAME, onEnterFrame);

			// });
		}
	}

	function normalTweenPlusWind(offest:Float, wind:Float){

		 var path = new MotionPath ().bezier (offest, horizon - ((ballContainer.height / 2) / scaleFactor) , (Lib.stage.stageWidth / 2)*(-wind +1), 0, 0);
                                                //x,y, offestx, offsety, strenght?   //(Lib.stage.stageWidth / 2)*wind
                                                trace('de quanto mi sposto '+(Lib.stage.stageWidth / 2)*(wind +1));
		Actuate.motionPath (ballContainer, 1.5, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
		removeEventListener(Event.ENTER_FRAME, onEnterFrame);

		});

		// Actuate.tween(ballContainer, 1.5, {x: offest+(50*wind)}).ease(Linear.easeNone);
		// Actuate.tween(ballContainer, 1.0, {y: top}).ease(Quad.easeOut);
		// Actuate.tween(ballContainer, .50, {y: horizon - ((ballContainer.height/ 2) / scaleFactor)}, false).delay(1).ease(Quad.easeIn);
			// // //fai la roba che puzza e non melo dici
		// Actuate.tween(ballContainer, 1.50, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {
		// // 		var path = new MotionPath ().bezier (ballContainer.x, ballContainer.y , ballContainer.x, ballContainer.y - 30,0);
  // //                                               //x,y, offestx, offsety, strenght?
		// // Actuate.motionPath (ballContainer, 0.5, { x: path.x, y: path.y } ).ease (Quad.easeOut);
		// 	if (offest < Lib.current.stage.stageWidth / 2) {
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x-objectToThrowHalfWidth}).ease(Linear.easeNone);

		// 	} else {
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);

		// 	}
		// });

		//  if (offest > leftEdge + objectToThrowHalfWidth && offest < rightEdge - objectToThrowHalfWidth){// in the middle
		//  		//disapper
		//  		Actuate.tween(ballContainer, .05, {alpha: .0}).delay(1.5).ease(Linear.easeNone);

		//  }
				
		Timer.delay(callback(reset), 3500);

	}

	function bouncedTweenOutside(offest:Float, wind:Float){
				normalTweenPlusWind(offest, wind);

 	// var path = new MotionPath ().bezier (offest, horizon - ((ballContainer.height / 2) / scaleFactor) , Lib.stage.stageWidth / 2, top, 0);
  //                                               //x,y, offestx, offsety, strenght?
		// 	 Actuate.motionPath (ballContainer, 1.5, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
		// 	 	removeEventListener(Event.ENTER_FRAME, onEnterFrame);

		// 	 });

		// var offestFirstBounce:Float = (Lib.current.stage.stageHeight / 12 * 4) - top- objectToThrowHalfWidth;
		// // Actuate.tween(ballContainer, 1.25, {x: offest+(50*wind)}).ease(Linear.easeNone);
		// // Actuate.tween(ballContainer, 1.0, {y: top}).ease(Quad.easeOut);

		// if (offest < Lib.current.stage.stageWidth / 2) {
		 	
		//  	Actuate.tween(ballContainer, .35, {y: top + offestFirstBounce} , false).delay(1.0).ease(Quad.easeIn).onComplete(function(){

		// 		 Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
		// 		 Actuate.tween(ballContainer, .45, {x: offest - (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);

		// 	 });

		// 	Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {					
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x-objectToThrowHalfWidth}).ease(Linear.easeNone);
		// 	});

		// } else{
		// 	Actuate.tween(ballContainer, .35, {y: top + offestFirstBounce} , false).delay(1.0).ease(Quad.easeIn).onComplete(function(){

		// 		 Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
		// 		 Actuate.tween(ballContainer, .45, {x: offest + (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);

		// 	 });

		// 	Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {					
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);
		// 	});
		// }

		// Timer.delay(callback(reset), 3500);

	}

	function bouncedTweenInside(offest:Float, wind:Float){
				normalTweenPlusWind(offest, wind);

 // var path = new MotionPath ().bezier (offest, horizon - ((ballContainer.height / 2) / scaleFactor) , Lib.stage.stageWidth / 2, top, 0);
 //                                                //x,y, offestx, offsety, strenght?
	// 		 Actuate.motionPath (ballContainer, 1.5, { x: path.x, y: path.y } ).ease (Linear.easeNone).onComplete(function() {
	// 		 	removeEventListener(Event.ENTER_FRAME, onEnterFrame);

	// 		});


		// var offestFirstBounce:Float = (Lib.current.stage.stageHeight / 12 * 4) - top- objectToThrowHalfWidth;
		// // Actuate.tween(ballContainer, 1.25, {x: offest+(50*wind)}).ease(Linear.easeNone);
		// // Actuate.tween(ballContainer, 1.0, {y: top}).ease(Quad.easeOut);

		// if (offest < Lib.current.stage.stageWidth / 2) {
		 	
		// Actuate.tween(ballContainer, .35, {y: top + offestFirstBounce} , false).delay(1.0).ease(Quad.easeIn).onComplete(function(){

		// 		 Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
		// 		 Actuate.tween(ballContainer, .45, {x: offest + (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);

		// 	 });

		// 	Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {					
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x+objectToThrowHalfWidth}).ease(Linear.easeNone);
		// 	});

		// } else{
		// 	Actuate.tween(ballContainer, .35, {y: top + offestFirstBounce} , false).delay(1.0).ease(Quad.easeIn).onComplete(function(){

		// 		 Actuate.tween(ballContainer, .45, {y: horizon - 2 *((ballContainer.height/ 2) / scaleFactor)}, false).ease(Quad.easeIn);
		// 		 Actuate.tween(ballContainer, .45, {x: offest - (Lib.current.stage.stageWidth / 21)}).ease(Linear.easeNone);

		// 	 });

		// 	Actuate.tween(ballContainer, 1.85, {scaleX: originalScale / scaleFactor, scaleY: originalScale / scaleFactor}).ease(Linear.easeNone).onComplete(function() {					
		// 		Actuate.tween(ballContainer, .5, {y: ballContainer.y-(objectToThrowHalfWidth/2), x: ballContainer.x-objectToThrowHalfWidth}).ease(Linear.easeNone);
		// 	});
		// }
		// //disappear
		// Actuate.tween(ballContainer, .15, {alpha: .0}).delay(1.80).ease(Linear.easeNone);


		// Timer.delay(callback(reset), 3500);

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

	function createWind():Float{


//POSITIVE NUMBER: WIND PUSH FROM RIGHT LO LEFT
//NEGATIVE NUMBER : WIND PUSH FROM LEFT TO RIGHT
		var random:Float = Math.random();

		if (random < 0.14){
			//strong left
			trace('strong FROM RIGHT');
			random = -0.7;
		} else if (random > 0.14 && random < 0.29){
			//middle left
			trace('middle FROM RIGHT');

			random = -0.55;

		} else if (random > 0.29 && random < 0.43){
			//light left
			trace('light FROM RIGHT');

			random = -0.3;

		} else if (random > 0.43 && random < 0.57){
			//light left
			trace('NO wind');

			random = 0.0;

		} else if (random > 0.57 && random < 0.72){
			//light right
			trace('light FRMO LEFT');

			random = 0.3;

		} else if (random > 0.72 && random < 0.86){
			//middle right
			trace('middle FROM LEFT');

			random = 0.55;

		} else if (random > 0.86 && random < 1.0){
			//strogn right
		 	trace('strong FROM LEFT');

			 random = 0.7;
		}
		return	random;

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
	

	function reset(){

		trace("reset");
		ballContainer.x = startX;
		ballContainer.y = startY;
		wind = createWind();
		Actuate.tween(ballContainer, .30, {alpha: .99}).ease(Linear.easeNone);
		ballContainer.scaleX = ballContainer.scaleY = .2;
	}
}