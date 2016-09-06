namespace SnailHttp;

use Psr\Http\Message\StreamInterface;

class Stream implements StreamInterface
{
    private stream;
    private size;
    private seekable;
    private readable;
    private writable;
    private uri;
    private customMetadata = [];
    
    /** @var array Hash of readable and writable stream types */
    private static readWriteHash = [
        "read": [
            "r": true, "w+": true, "r+": true, "x+": true, "c+": true,
            "rb": true, "w+b": true, "r+b": true, "x+b": true,
            "c+b": true, "rt": true, "w+t": true, "r+t": true,
            "x+t": true, "c+t": true, "a+": true
        ],
        "write": [
            "w": true, "w+": true, "rw": true, "r+": true, "x+": true,
            "c+": true, "wb": true, "w+b": true, "r+b": true,
            "x+b": true, "c+b": true, "w+t": true, "r+t": true,
            "x+t": true, "c+t": true, "a": true, "a+": true
        ]
    ];
    
    public function __construct(resource stream, array options = [])
    {   
        var meta = null;
        
        if isset options["size"] {
            let this->size = options["size"];
        }
        
        if isset options["metadata"] {
            let this->customMetadata = options["metadata"];
        }
        
        let this->stream = stream;
        let meta = stream_get_meta_data(this->stream);
        
        let this->seekable = meta["seekable "];
        let this->readable = isset(self::readWriteHash["read"][meta["mode"]]);
        let this->writable = isset(self::readWriteHash["write"][meta["mode"]]);
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
        if isset this->stream {
            if is_resource(this->stream) {
                fclose(this->stream);
            }
            
            this->detach();
        }
    }

    public function detach() -> resource|null
    {   
        var result;
        
        if !isset this->stream {
            return null;
        }
        
        let result = this->stream;
        unset(this->stream);
        
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
        
        if !isset this->stream {
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
        return $this->readable;
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
        
        if !isset this->stream {
            return key ? null : [];
        } elseif !key {
            let meta = stream_get_meta_data(this->stream);
            return array_merge(this->customMetadata, meta);
        } elseif isset this->customMetadata[key] {
            return this->customMetadata[key];
        }
        
        let meta = stream_get_meta_data(this->stream);
        return isset meta[key] ? meta[key] : null;
    }
}
