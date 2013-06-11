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

        createItems();
        createBin();
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
    private function createItems():Void {
        var aluminum_can:ThrowableVO = new ThrowableVO("aluminum_can", Bin.BLUE, 0xFF0000, "Aluminium goes into the BLUE bin!!");
        var bottle_reduced:ThrowableVO = new ThrowableVO("bottle-reduced", Bin.RED,0xFFFF00, "Bottle with lid goes into the RED bin!! You should separate them!!");
        var bunch_of_leaves:ThrowableVO = new ThrowableVO("bunch-of-leaves", Bin.GREEN, 0x0000FF, "Leaves go into the GREEN bin!!");
        var carton_box:ThrowableVO = new ThrowableVO("carton-box", Bin.BLUE, 0x00FF00, "Cardboard box goes into the BLUE bin!!");
        var empty_plastic_bottle:ThrowableVO = new ThrowableVO("empty-plastic-bottle", Bin.YELLOW, 0xFF0000, "Plastic bottle goes into the YELLOW bin!!");
        var newspaper:ThrowableVO = new ThrowableVO("newspaper", Bin.BLUE,0xFFFF00, "Newspaper goes into the BLUE bin!!");
        var pannolini:ThrowableVO = new ThrowableVO("pannolini", Bin.RED, 0x0000FF, "Nappy goes into the RED bin!!");
        var pizzabox:ThrowableVO = new ThrowableVO("pizzabox", Bin.RED, 0x00FF00, "Food stained pizza box goes into the RED bin!!");
        var glass_bottle:ThrowableVO = new ThrowableVO("glass-bottle", Bin.YELLOW,0xFFFF00, "Glass bottle with no lid goes into the YELLOW bin!!");

        throwableItems = new Array<ThrowableVO>();

        throwableItems.push(aluminum_can);
        throwableItems.push(bunch_of_leaves);
        throwableItems.push(carton_box);
        throwableItems.push(empty_plastic_bottle);
        throwableItems.push(newspaper);
        throwableItems.push(pannolini);
        throwableItems.push(pizzabox);
        throwableItems.push(bottle_reduced);
        throwableItems.push(glass_bottle);

        _currentItem = throwableItems[1];
    }

    // Our first bin will be YELLOW, but we can change it each time with the setter method

    public function createBin():Void {
        var random:Float = Math.random();

        if (random < 0.25) {
               _currentBinType = Bin.YELLOW;
        } else if (random > 0.25 && random <= 0.50) {
              _currentBinType = Bin.RED;
        } else if (random > 0.50 && random <= 0.75) {
              _currentBinType = Bin.BLUE;
        } else {
             _currentBinType = Bin.GREEN;
        }
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