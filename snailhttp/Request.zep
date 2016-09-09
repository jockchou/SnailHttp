namespace SnailHttp;

use Psr\Http\Message\UploadedFileInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\UriInterface;
use Psr\Http\Message\StreamInterface;

class Request extends Message implements ServerRequestInterface
{
    protected method;
    protected uri;
    protected requestTarget;
    protected queryParams;
    protected cookies;
    protected serverParams;
    protected attributes;
    protected bodyParsed;
    protected bodyParsers = [];
    protected uploadedFiles;
    static validMethods = [
        "CONNECT": 1,
        "DELETE": 1,
        "GET": 1,
        "HEAD": 1,
        "OPTIONS": 1,
        "PATCH": 1,
        "POST": 1,
        "PUT": 1,
        "TRACE": 1
    ];
    
    public function __construct(
        string method,
        <UriInterface> uri,
        <HeadersInterface> headers,
        array cookies,
        array serverParams,
        <StreamInterface> body,
        array uploadedFiles = []
    ){
        var protocol;
        
        let this->method = this->filterMethod(method);
        let this->uri = uri;
        let this->headers = headers;
        let this->cookies = cookies;
        let this->serverParams = serverParams;
        let this->attributes = new Collection();
        let this->body = body;
        let this->uploadedFiles = uploadedFiles;
        
        if fetch protocol, serverParams["SERVER_PROTOCOL"] {
            let this->protocolVersion = str_replace("HTTP/", "", protocol);
        }

        if !this->headers->has("Host") || this->uri->getHost() !== "" {
            $this->headers->set("Host", this->uri->getHost());
        }

        this->registerMediaTypeParser("application/json", function (input) {
            return json_decode(input, true);
        });

        this->registerMediaTypeParser("application/xml", function (input) {
            var backup, result;
            
            let backup = libxml_disable_entity_loader(true);
            let result = simplexml_load_string(input);
            libxml_disable_entity_loader(backup);
            
            return result;
        });

        this->registerMediaTypeParser("text/xml", function (input) {
            var backup, result;
            
            let backup = libxml_disable_entity_loader(true);
            let result = simplexml_load_string(input);
            libxml_disable_entity_loader(backup);
            
            return result;
        });

        this->registerMediaTypeParser("application/x-www-form-urlencoded", function (input) {
            var data = null;
            parse_str(input, data);
            return data;
        });
    }
    
    
    public function __clone()
    {
        let this->headers = clone this->headers;
        let this->attributes = clone this->attributes;
        let this->body = clone this->body;
    }


    public function getMethod()
    {
        return this->method;
    }


    public function withMethod(string method)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->method = this->filterMethod(method);

        return cloneObj;
    }
    
    protected function filterMethod(var method)
    {
        if method === null {
            return method;
        }

        if !is_string(method) {
            throw new \InvalidArgumentException(sprintf(
                "Unsupported HTTP method; must be a string, received %s",
                (is_object(method) ? get_class(method) : gettype(method))
            ));
        }

        let method = strtoupper(method);
        if !isset self::validMethods[method] {
            throw new \InvalidArgumentException(sprintf(
                "Unsupported HTTP method \"%s\" provided",
                method
            ));
        }

        return method;
    }


    public function getRequestTarget()
    {   
        var path, query;
        
        if this->requestTarget {
            return this->requestTarget;
        }

        if $this->uri === null {
            return "/";
        }

        let path = "/" . ltrim(this->uri->getPath(), "/");
        let query = this->uri->getQuery();
        if query {
            let path .= "?" . query;
        }
        let this->requestTarget = path;

        return this->requestTarget;
    }
    
    public function withRequestTarget(var requestTarget)
    {
        var cloneObj;
        
        if preg_match("#\s#", requestTarget) {
            throw new \InvalidArgumentException(
                "Invalid request target provided; must be a string and cannot contain whitespace"
            );
        }
        
        let cloneObj = clone this;
        let cloneObj->requestTarget = requestTarget;

        return cloneObj;
    }


    public function getUri()
    {
        return this->uri;
    }


    public function withUri(<UriInterface> uri, boolean preserveHost = false)
    {   
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->uri = uri;

        if !preserveHost {
            if uri->getHost() !== "" {
                cloneObj->headers->set("Host", uri->getHost());
            }
        } else {
            if this->uri->getHost() !== "" && (!this->hasHeader("Host") || this->getHeader("Host") === null) {
                cloneObj->headers->set("Host", uri->getHost());
            }
        }

        return cloneObj;
    }
    
    public function getCookieParams()
    {
        return this->cookies;
    }


    public function withCookieParams(array cookies)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->cookies = cookies;

        return cloneObj;
    }
    
    public function getQueryParams()
    {
        if this->queryParams {
            return this->queryParams;
        }

        if $this->uri === null {
            return [];
        }

        parse_str(this->uri->getQuery(), this->queryParams); // <-- URL decodes data

        return this->queryParams;
    }


    public function withQueryParams(array query)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->queryParams = query;

        return cloneObj;
    }


    public function getUploadedFiles()
    {
        return this->uploadedFiles;
    }
    
    public function withUploadedFiles(array uploadedFiles)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->uploadedFiles = uploadedFiles;

        return cloneObj;
    }


    public function getServerParams()
    {
        return this->serverParams;
    }


    public function getAttributes()
    {
        return this->attributes->all();
    }


    public function getAttribute(string name, var def = null)
    {
        return this->attributes->get(name, def);
    }
    
    public function withAttribute(string name, var value)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        cloneObj->attributes->set(name, value);

        return cloneObj;
    }


    public function withoutAttribute(string name)
    {
        var cloneObj;
        let cloneObj = clone this;
        cloneObj->attributes->remove(name);

        return cloneObj;
    }
    
    public function getParsedBody()
    {   
        var mediaType, body, parsed, func;
        
        if this->bodyParsed {
            return this->bodyParsed;
        }

        if !this->body {
            return null;
        }

        let mediaType = this->getMediaType();
        let body = (string)this->getBody();

        if fetch func, this->bodyParsers[mediaType] {
            let parsed = {func}(body);

            if !is_null(parsed) && !is_object(parsed) && !is_array(parsed) {
                throw new \RuntimeException("Request body media type parser return value must be an array, an object, or null");
            }
            let this->bodyParsed = parsed;
        }

        return this->bodyParsed;
    }

 
    public function withParsedBody(var data)
    {
        if !is_null(data) && !is_object(data) && !is_array(data) {
            throw new \InvalidArgumentException("Parsed body value must be an array, an object, or null");
        }
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->bodyParsed = data;

        return cloneObj;
    }
    
    public function getContentType()
    {
        var result;
        let result = this->getHeader("Content-Type");

        return result ? result[0] : null;
    }
    
    public function getMediaType()
    {
        var contentType, contentTypeParts;
        let contentType = this->getContentType();
        if contentType {
            let contentTypeParts = preg_split("/\s*[;,]\s*/", contentType);

            return strtolower(contentTypeParts[0]);
        }

        return null;
    }
    
    public function registerMediaTypeParser(string mediaType, callable callback)
    {
        if callback instanceof Closure {
            let callback = callback->bindTo(this);
        }
        let this->bodyParsers[(string)mediaType] = callback;
    }
}