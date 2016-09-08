namespace SnailHttp;

/**
 * Collection Interface
 *
 */
interface CollectionInterface extends \ArrayAccess, \Countable, \IteratorAggregate
{
    public function set(string key, var value);

    public function get(string key, var def = null);

    public function replace(array items);

    public function all();

    public function has(string key);

    public function remove(string key);

    public function clear();
}