namespace SnailHttp;

/**
 * Collection Interface
 *
 */
interface CollectionInterface extends \ArrayAccess, \Countable, \IteratorAggregate
{
    public function set(string key, var value) -> void;

    public function get(string key, var def = null) -> var;

    public function replace(array items) -> void;

    public function all() -> array;

    public function has(string key) -> boolean;

    public function remove(string key) -> void;

    public function clear() -> void;
}