namespace SnailHttp;

use Psr\Http\Message\StreamInterface;

class Stream implements StreamInterface
{
    protected  stream;
    protected  size;
    protected  seekable;
    protected  readable;
    protected  writable;
    protected  uri;
    
    /** @var array Hash of readable and writable stream types */
    protected static readWriteHash = [
        "read": ["r", "r+", "w+", "a+", "x+", "c+"],
        "write": ["r+", "w", "w+", "a", "a+", "x", "x+", "c", "c+"]
    ];
    
    
    public function __construct(resource stream)
    {   
        var meta = null, mode;
        
        let this->stream = stream;
        let meta = stream_get_meta_data(this->stream);
        
        let mode = meta["mode"];
        let this->seekable = meta["seekable "];
        let this->readable = in_array(mode, self::readWriteHash["read"]);
        let this->writable = in_array(mode, self::readWriteHash["write"]);
        let this->uri = this->getMetadata("uri");
    }
    
    
    public function __toString() -> string
    {
        this->seek(0);
        return (string)stream_get_contents(this->stream);
    }
    
    /**
     * Closes the stream when the destructed
     */
    public function __destruct()
    {
        this->close();
    }

    public function close() -> void
    {
        if is_resource(this->stream) {
            fclose(this->stream);
        }
        
        this->detach();
    }

    public function detach() -> resource|null
    {   
        var result;
        
        if !is_resource(this->stream) {
            return null;
        }
        
        let result = this->stream;
        
        let this->stream = null;
        let this->size = null;
        let this->uri = null;
        let this->readable = false;
        let this->writable = false;
        let this->seekable = false;
        
        return result;
    }

    public function getSize() -> int | null
    {
        var stats;
        
        if this->size !== null {
            return this->size;
        }
        
        if !is_resource(this->stream) {
            return null;
        }
        
        // Clear the stat cache if the stream has a URI
        if this->uri {
            clearstatcache(true, this->uri);
        }
        
        let stats = fstat(this->stream);
        
        if isset stats["size"] {
            let this->size = stats["size"];
            return this->size;
        }
        
        return null;
    }

    public function tell() -> int
    {
        var result;
        
        let result = ftell(this->stream);
        if (result === false) {
            throw new \RuntimeException("Unable to determine stream position");
        }
        
        return result;
    }

    public function eof() -> boolean
    {
        return !this->stream || feof(this->stream);
    }

    public function isSeekable() -> boolean
    {
        return this->seekable;
    }

    public function seek(int offset, int whence = self::SEEK_SET)
    {
        if !$this->seekable {
            throw new \RuntimeException("Stream is not seekable");
        } elseif (fseek(this->stream, offset, whence) === -1) {
            throw new \RuntimeException(sprintf("Unable to seek to stream position %d with whence %d", offset, whence));
        }
    }

    public function rewind()
    {
        this->seek(0);
    }

    public function isWritable() -> boolean
    {
        return $this->writable;
    }

    public function write(string str) -> int
    {
        var result;
        
        if !this->writable {
            throw new \RuntimeException("Cannot write to a non-writable stream");
        }
        
        // We can't know the size after writing anything
        let this->size = null;
        let result = fwrite(this->stream, str);
        
        if result === false {
            throw new \RuntimeException("Write to stream fail");
        }
        
        return result;
    }

    public function isReadable() -> boolean
    {
        return this->readable;
    }

    public function read(int length) -> string
    {
        var result;
        
        if !this->readable {
            throw new \RuntimeException("Cannot read from non-readable stream");
        }
        
        let result = fread(this->stream, length);
        
        if result === false {
            throw new \RuntimeException("Read from stream fail");
        }
        
        return result;
    }

    public function getContents() -> string
    {
        var contents = stream_get_contents(this->stream);
        if contents === false {
            throw new \RuntimeException("Read contents from stream fail");
        }
        
        return contents;
    }

    public function getMetadata(key = null) -> var
    {
        var meta = null;
        
        if !is_resource(this->stream) {
            return key ? null : [];
        }
        
        let meta = stream_get_meta_data(this->stream);
        
        if !key {
            return meta; 
        } else {
            return isset meta[key] ? meta[key] : null;
        }
    }
}
