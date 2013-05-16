package au.com.recyclesmart.view;

import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.Lib;

import au.com.recyclesmart.eventbus.CentralDispatcher;
import au.com.recyclesmart.model.Model;

class ItemScrollBar extends Sprite {

	//var model:Array;
	var scrollingPanel:Sprite;
	var padding:Float;
	var touchStartX:Float;
	var panelStartX:Float;
	var maxX:Float;
	var minX:Float;

	private var model:Model;

	private var dispatcher:CentralDispatcher;

	public function new () {
		super();
		this.padding = 5;

		dispatcher = CentralDispatcher.getInstance();
		model = Model.getInstance();
	}

	public function setSize(newWidth:Float, newHeight:Float) {
		//draw bg
		graphics.beginFill(0, 1);
		graphics.drawRect(0, 0, newWidth, newHeight);
		graphics.endFill();

		drawScrollingPanel(newWidth, newHeight);

		this.maxX = 0;
		this.minX = newWidth - (scrollingPanel.width + 2 * this.padding);

		addEventListener(MouseEvent.MOUSE_DOWN, beginDrag);
	}

	function drawScrollingPanel(w:Float, h:Float) {
		scrollingPanel = new Sprite();
		scrollingPanel.graphics.beginFill(0xcccccc, 1);
		scrollingPanel.graphics.drawRect(this.padding, this.padding, w * 2, h - padding * 2);
		scrollingPanel.graphics.endFill();
		addChild(scrollingPanel);
	}

	function beginDrag(e:MouseEvent) {
		panelStartX = scrollingPanel.x;
		touchStartX = e.stageX;

		addEventListener(MouseEvent.MOUSE_MOVE, dragMove);
		addEventListener(MouseEvent.MOUSE_UP, finishDrag);
	}

	function dragMove(e:MouseEvent) {
		var deltaX =  e.stageX - touchStartX;

		scrollingPanel.x = panelStartX + deltaX;

		if(scrollingPanel.x > maxX)
			scrollingPanel.x = maxX;

		if(scrollingPanel.x < minX)
			scrollingPanel.x = minX;
	}

	function finishDrag(e:MouseEvent) {
		removeEventListener(MouseEvent.MOUSE_MOVE, dragMove);
	}

	//set the current collection of items to display
	function setModel(model:Array<String>) {
		//this.model = model;
	}
}