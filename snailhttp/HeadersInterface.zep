namespace SnailHttp;

/**
 * Headers Interface
 *
 */
interface HeadersInterface extends CollectionInterface
{
    public function add(string key, var value);

    public function normalizeKey(string key);
}