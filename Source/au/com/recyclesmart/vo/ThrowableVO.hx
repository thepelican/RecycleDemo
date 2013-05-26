package au.com.recyclesmart.vo;

/**
*   An object to be thrown in the bin.
*   This is just an abstract representation of our object, not its view.
*   This will be stored in the view, and eventually in the global Model when user taps on its view to select it
*/
class ThrowableVO {

    public var type:String;
    public var iconPath:String;
    public var bin:String;
    //temporanea
    public var bgColor:Int;

    public function new(type:String, bin:String, bgColor:Int) {
        this.bin = bin;
        this.type = type;
        this.iconPath = 'images/' + type + '.png';
        this.bgColor = bgColor;
    }

    public function toString() {
        return "[ThrowableVO "+ type +"]";
    }
}