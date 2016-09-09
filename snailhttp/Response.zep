namespace SnailHttp;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;


class Response extends Message implements ResponseInterface
{
    protected status = 200;
    protected reasonPhrase = "";
    static messages = [
        //Informational 1xx
        100: "Continue",
        101: "Switching Protocols",
        102: "Processing",
        //Successful 2xx
        200: "OK",
        201: "Created",
        202: "Accepted",
        203: "Non-Authoritative Information",
        204: "No Content",
        205: "Reset Content",
        206: "Partial Content",
        207: "Multi-Status",
        208: "Already Reported",
        226: "IM Used",
        //Redirection 3xx
        300: "Multiple Choices",
        301: "Moved Permanently",
        302: "Found",
        303: "See Other",
        304: "Not Modified",
        305: "Use Proxy",
        306: "(Unused)",
        307: "Temporary Redirect",
        308: "Permanent Redirect",
        //Client Error 4xx
        400: "Bad Request",
        401: "Unauthorized",
        402: "Payment Required",
        403: "Forbidden",
        404: "Not Found",
        405: "Method Not Allowed",
        406: "Not Acceptable",
        407: "Proxy Authentication Required",
        408: "Request Timeout",
        409: "Conflict",
        410: "Gone",
        411: "Length Required",
        412: "Precondition Failed",
        413: "Request Entity Too Large",
        414: "Request-URI Too Long",
        415: "Unsupported Media Type",
        416: "Requested Range Not Satisfiable",
        417: "Expectation Failed",
        418: "I\"m a teapot",
        422: "Unprocessable Entity",
        423: "Locked",
        424: "Failed Dependency",
        426: "Upgrade Required",
        428: "Precondition Required",
        429: "Too Many Requests",
        431: "Request Header Fields Too Large",
        451: "Unavailable For Legal Reasons",
        //Server Error 5xx
        500: "Internal Server Error",
        501: "Not Implemented",
        502: "Bad Gateway",
        503: "Service Unavailable",
        504: "Gateway Timeout",
        505: "HTTP Version Not Supported",
        506: "Variant Also Negotiates",
        507: "Insufficient Storage",
        508: "Loop Detected",
        510: "Not Extended",
        511: "Network Authentication Required"
    ];

    
    public function __construct(int status = 200, <HeadersInterface> headers = null, <StreamInterface> body = null)
    {
        let this->status = this->filterStatus(status);
        let this->headers = headers ? headers : new Headers();
        let this->body = body ? body : new Body(fopen("php://temp", "r+"));
    }

    public function __clone()
    {
        let this->headers = clone this->headers;
        let this->body = clone this->body;
    }

    public function getStatusCode()
    {
        return this->status;
    }


    public function withStatus(int code, string reasonPhrase = "")
    {
        var cloneObj;
        let code = this->filterStatus(code);

        if !is_string(reasonPhrase) && !method_exists(reasonPhrase, "__toString") {
            throw new \InvalidArgumentException("ReasonPhrase must be a string");
        }
        
        
        let cloneObj = clone this;
        let cloneObj->status = code;
        
        if reasonPhrase === "" && isset self::messages[code] {
            let reasonPhrase = self::messages[code];
        }

        if reasonPhrase === "" {
            throw new \InvalidArgumentException("ReasonPhrase must be supplied for this code");
        }

        let cloneObj->reasonPhrase = reasonPhrase;

        return cloneObj;
    }


    protected function filterStatus($status)
    {
        if !is_integer(status) || status < 100 || status > 599 {
            throw new \InvalidArgumentException("Invalid HTTP status code");
        }

        return status;
    }


    public function getReasonPhrase() -> string
    {   
        int code = this->status;
       
        if this->reasonPhrase {
            return this->reasonPhrase;
        }
        
        if isset self::messages[code] {
            return self::messages[code];
        }
        
        return "";
    }
    

    public function __toString()
    {
        var output, name, values;
        
        let output = sprintf(
            "HTTP/%s %s %s",
            this->getProtocolVersion(),
            this->getStatusCode(),
            this->getReasonPhrase()
        );
        
        let output .= "\n";
        
        for name, values in this->getHeaders() {
            let output .= sprintf("%s: %s", name, this->getHeaderLine(name)) . "\n";
        }
        
        let output .= "\n";
        let output .= (string)this->getBody();

        return output;
    }
    
}