namespace SnailHttp;

use Psr\Http\Message\MessageInterface;
use Psr\Http\Message\StreamInterface;

class Message implements MessageInterface
{
    protected protocolVersion = "1.1";
    protected headers;
    protected body;
    
    static valid = [
        "1.0": true,
        "1.1": true,
        "2.0": true
    ];
    
    public function getProtocolVersion()
    {
        return this->protocolVersion;
    }

    public function withProtocolVersion(string version)
    {
        var cloneObj;
        

        
        if !isset self::valid[version] {
            throw new \InvalidArgumentException("Invalid HTTP version. Must be one of: 1.0, 1.1, 2.0");
        }
        
        let cloneObj = clone this;
        let cloneObj->protocolVersion = version;

        return cloneObj;
    }
    
    
    public function getHeaders()
    {
        return this->headers->all();
    }

    public function hasHeader(string name)
    {
        return this->headers->has(name);
    }

    public function getHeader(string name)
    {
        return this->headers->get(name, []);
    }

    public function getHeaderLine(string name)
    {
        return implode(",", this->headers->get(name, []));
    }

    public function withHeader(string name, var value)
    {   
        var cloneObj;
        
        let cloneObj = clone this;
        cloneObj->headers->set(name, value);

        return cloneObj;
    }

    public function withAddedHeader(string name, var value)
    {
        var cloneObj;
    
        let cloneObj = clone this;
        cloneObj->headers->add(name, value);

        return cloneObj;
    }

    public function withoutHeader(string name)
    {
        var cloneObj;
    
        let cloneObj = clone this;
        cloneObj->headers->remove(name);

        return cloneObj;
    }

    public function getBody()
    {
        return this->body;
    }

    public function withBody(<StreamInterface> body)
    {
        // TODO: Test for invalid body?
        
        var cloneObj;
         
        let cloneObj = clone this;
        let cloneObj->body = body;

        return cloneObj;
    }
    
}