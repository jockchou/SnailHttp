namespace SnailHttp;

use \ArrayIterator;


class Collection implements CollectionInterface
{

    protected data = [];


    public function __construct(array items = [])
    {
        var key, val;
        
        for key, val in items {
            this->set(key, val);
        }
    }

    /********************************************************************************
     * Collection interface
     *******************************************************************************/


    public function set(string key, var val) -> void
    {
        let this->data[key] = val;
    }


    public function get(string key, var def = null) -> var
    {
        return this->has(key) ? this->data[key] : def;
    }


    public function replace(array items = null) -> void
    {
        var key, val;
        
        for key, val in items {
            this->set(key, val);
        }
    }


    public function all() -> array
    {
        return this->data;
    }


    public function keys() -> array
    {
        return array_keys(this->data);
    }


    public function has(string key) -> boolean
    {
        return array_key_exists(key, this->data);
    }


    public function remove(string key) -> void
    {
        unset(this->data[key]);
    }


    public function clear()
    {
        let this->data = [];
    }

    /********************************************************************************
     * ArrayAccess interface
     *******************************************************************************/


    public function offsetExists(string key)
    {
        return this->has(key);
    }


    public function offsetGet(string key)
    {
        return this->get(key);
    }


    public function offsetSet(string key, var val)
    {
        this->set(key, val);
    }


    public function offsetUnset(string key)
    {
        this->remove(key);
    }


    public function count() -> int
    {
        return count(this->data);
    }

    /********************************************************************************
     * IteratorAggregate interface
     *******************************************************************************/


    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->data);
    }
}