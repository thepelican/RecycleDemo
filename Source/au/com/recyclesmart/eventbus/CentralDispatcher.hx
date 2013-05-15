package au.com.recyclesmart.eventbus;

import nme.events.EventDispatcher;
import nme.errors.Error;

/**
*   This class is our centralized event bus.
*   It's a Singleton, so we can call getInstance() and obtain a reference to it and start to listen/dispatch global events.
*
*   Example (listen):   CentralDispatcher.getInstance().addEventListener(AppEvent.SCORE_UPDATED, eventHandlerFunction);
*   Example (dispatch): CentralDispatcher.getInstance().dispatchEvent(AppEvent.SCORE_UPDATED);
*/
class CentralDispatcher extends EventDispatcher {

    private static var _instance:CentralDispatcher;

    public function new()
    {
        if(_instance != null)
            throw new Error("Only one CentralDispatcher instance can be instantiated");

        super();
    }

    public static function getInstance():CentralDispatcher
    {
        if (_instance == null)
            _instance = new CentralDispatcher();

        return _instance;
    }
}