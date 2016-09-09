namespace SnailHttp;

/**
 * Cookies Interface
 */
interface CookiesInterface
{
    public function get(string name, string def = null) -> string;
    public function set(string name, string value) -> void;
    public function toHeaders() -> array;
    public static function parseHeader(var header) -> array;
}