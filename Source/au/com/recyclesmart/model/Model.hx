package au.com.recyclesmart.model;

import nme.errors.Error;

import au.com.recyclesmart.vo.ThrowableVO;
import au.com.recyclesmart.vo.Bin;
import au.com.recyclesmart.eventbus.CentralDispatcher;

import au.com.recyclesmart.events.AppEvent;

class Model {

    private static var _instance:Model;
    private var _dispatcher:CentralDispatcher;
    private var _currentItem:ThrowableVO;

    private var throwableItems:Array<ThrowableVO>;

    public function new()
    {
        if(_instance != null)
            throw new Error("Only one Model instance can be instantiated");

        _dispatcher = CentralDispatcher.getInstance();

        createDummyItems();
    }

    public static function getInstance():Model
    {
        if (_instance == null)
            _instance = new Model();

        return _instance;
    }

    private function createDummyItems():Void {
        var dummyItem1:ThrowableVO = new ThrowableVO("cacca", Bin.BIN_YELLOW,0x00FF00);
        var dummyItem2:ThrowableVO = new ThrowableVO("culo", Bin.BIN_RED, 0xFF0000);
        var dummyItem3:ThrowableVO = new ThrowableVO("sticazzi", Bin.BIN_BLUE, 0x0000FF);

        throwableItems = new Array<ThrowableVO>();

        throwableItems.push(dummyItem1);
        throwableItems.push(dummyItem2);
        throwableItems.push(dummyItem3);
    }

    public function setThrowableVOs(items:Array<ThrowableVO>):Void {
        this.throwableItems = items;
        //qui bisognerebbe lanciare un evento globale cosi' la barra puo' aggiornare le icone degli oggetti da tirare
    }

    public function getThrowableVOs():Array<ThrowableVO> {

        return this.throwableItems;
    }

    public function setCurrentItem(newItem:ThrowableVO):Void {
        // Questa funzione viene chiamata dalla barra degli oggetti, quando l'utente tocca un oggetto diverso da quello corrente.
        // Quindi aggiorniamo il modello con il nuovo oggetto

        this._currentItem = newItem;

        // E poi lanciamo 1 evento globale di tipo NEW_ITEM_SELECTED cosi' il Main cambiera' l'icona dell'oggetto da tirare con quella selezionata.

        _dispatcher.dispatchEvent(new AppEvent(AppEvent.NEW_ITEM_SELECTED));
    }

    public function getCurrentItem():ThrowableVO {
        return _currentItem;
    }
}