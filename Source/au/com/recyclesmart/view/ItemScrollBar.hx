package au.com.recyclesmart.view;

import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.Lib;

import au.com.recyclesmart.eventbus.CentralDispatcher;
import au.com.recyclesmart.model.Model;

import au.com.recyclesmart.vo.ThrowableVO;
import au.com.recyclesmart.view.ThrowableItem;

/**
*	A scrollable horizontal list to display a collection of items that user can throw in the bin.
*
*	@param w Float The desired witdth for the component
*	@param h Float The desired height for the component
*/
class ItemScrollBar extends Sprite {

	//var model:Array;
	var scrollingPanel:Sprite;
	var padding:Float;
	var touchStartX:Float;
	var panelStartX:Float;
	var maxX:Float;
	var minX:Float;
	var marginBetweenItems:Float;

	private var model:Model;
	private var dispatcher:CentralDispatcher;

	public function new(w:Float, h:Float) {
		super();
		this.padding = 5;
		this.marginBetweenItems = 10;

		dispatcher = CentralDispatcher.getInstance();
		model = Model.getInstance();

		draw(w, h);

		loadItems();

		addEventListener(MouseEvent.MOUSE_DOWN, beginDrag);
	}

	public function loadItems():Void {
		var items:Array<ThrowableVO> = model.getThrowableVOs();
		var numItems = items.length;

		for(i in 0...numItems) {
			var item:ThrowableItem = new ThrowableItem(items[i]);
			item.x = 75 +  padding + i * (item.width + marginBetweenItems);
			item.y = item.height / 2 + padding;

			// Quando l'utente tocca un nuovo oggetto chiamiamo la nostra funzione changeItem
			item.addEventListener(MouseEvent.MOUSE_DOWN, changeItem);
			scrollingPanel.addChild(item);
		}
	}

	/**
	*	Estraiamo il nostro oggetto base (contenente le info sull'oggetto come il tipo, o il tipo di cestino con cui e' compatibile)
	* 	e lo salviamo nel modello centrale, cosi' lui lancera' un bell'evento, e chi sta in ascolto agira' di conseguenza
	*	come ad esempio il Main aggiornera' l'icona dell'oggetto da tirare
	*/
	private function changeItem(e:MouseEvent):Void {
		var selectedItem:ThrowableItem = e.target;
		model.setCurrentItem(selectedItem.getData());
	}

	private function draw(newWidth:Float, newHeight:Float) {
		//draw bg
		graphics.beginFill(0, 1);
		graphics.drawRect(0, 0, newWidth, newHeight);
		graphics.endFill();

		drawScrollingPanel(newWidth, newHeight);

		this.maxX = 0;
		this.minX = newWidth - (scrollingPanel.width + 2 * this.padding);
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
}