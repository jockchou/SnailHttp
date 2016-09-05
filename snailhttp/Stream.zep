
namespace SnailHttp;

use Psr\Http\Message\StreamInterface;


class Stream implements StreamInterface
{
    public function __toString() -> string
    {
    
    }

    public function close() -> void
    {
    
    }

    public function detach() -> resource|null
    {
    
    }

    public function getSize() -> int | null
    {
    
    }

    public function tell() -> int
    {
    
    }

    public function eof() -> boolean
    {
    
    }

    public function isSeekable() -> boolean
    {
    
    }

    public function seek(int offset, int whence = self::SEEK_SET)
    {
    
    }

    public function rewind()
    {
    
    }

    public function isWritable() -> boolean
    {
    
    }

    public function write(string str) -> int
    {
    
    }

    public function isReadable() -> boolean
    {
    
    }

    public function read(int length) -> string
    {
    
    }

    public function getContents() -> string
    {
    
    }

    public function getMetadata(key = null) -> var
    {
    
    }
}
