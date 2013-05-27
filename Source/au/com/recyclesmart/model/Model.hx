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
    private var _currentBinType:String;
    private var throwableItems:Array<ThrowableVO>;

    public function new()
    {
        if(_instance != null)
            throw new Error("Only one Model instance can be instantiated");

        _dispatcher = CentralDispatcher.getInstance();

        createDummyItems();
        createDummyBin();
    }

    // Singleton handler

    public static function getInstance():Model
    {
        if (_instance == null)
            _instance = new Model();

        return _instance;
    }

    /**
    *   Creates 4 dummy items, one for each bin color.
    *   Later on we will probably load from an external file/api instead of hard-coding it
    */
    private function createDummyItems():Void {
        var dummyItem2:ThrowableVO = new ThrowableVO("pizza", Bin.RED, 0xFF0000);
        var dummyItem1:ThrowableVO = new ThrowableVO("water-bottle", Bin.YELLOW,0xFFFF00);
        var dummyItem3:ThrowableVO = new ThrowableVO("newspaper", Bin.BLUE, 0x0000FF);
        var dummyItem4:ThrowableVO = new ThrowableVO("can", Bin.GREEN, 0x00FF00);

        throwableItems = new Array<ThrowableVO>();

        throwableItems.push(dummyItem2);
        throwableItems.push(dummyItem1);
        throwableItems.push(dummyItem3);
        throwableItems.push(dummyItem4);

        _currentItem = throwableItems[1];
    }

    // Our first bin will be YELLOW, but we can change it each time with the setter method

    private function createDummyBin():Void {
        _currentBinType = Bin.YELLOW;
    }

    // Accessor methods for the _throwableVOs

    public function setThrowableVOs(items:Array<ThrowableVO>):Void {
        this.throwableItems = items;
        //qui bisognerebbe lanciare un evento globale cosi' la barra puo' aggiornare le icone degli oggetti da tirare
    }

    public function getThrowableVOs():Array<ThrowableVO> {

        return this.throwableItems;
    }

    // Accessor methods for the _currentItem

    public function setCurrentItem(newItem:ThrowableVO):Void {
        // Questa funzione viene chiamata dalla barra degli oggetti, quando l'utente tocca un oggetto diverso da quello corrente.
        // Quindi aggiorniamo il modello con il nuovo oggetto

        _currentItem = newItem;

        // E poi lanciamo 1 evento globale di tipo NEW_ITEM_SELECTED cosi' il Main cambiera' l'icona dell'oggetto da tirare con quella selezionata.

        _dispatcher.dispatchEvent(new AppEvent(AppEvent.NEW_ITEM_SELECTED));
    }

    public function getCurrentItem():ThrowableVO {
        return _currentItem;
    }

    // Accessor methods for the _currentBinType

    public function setCurrentBinType(type:String):Void {
        this._currentBinType = type;
    }

    public function getCurrentBinType():String {
        return this._currentBinType;
    }
}