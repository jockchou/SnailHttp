namespace SnailHttp;

class Cookies implements CookiesInterface
{
    protected requestCookies = [];
    protected responseCookies = [];

    protected defaults = [
        "value": "",
        "domain": null,
        "path": null,
        "expires": null,
        "secure": false,
        "httponly": false
    ];
    
    
    public function __construct(array cookies = [])
    {
        let this->requestCookies = cookies;
    }


    public function setDefaults(array settings)
    {
        let this->defaults = array_replace(this->defaults, settings);
    }
    
    
    public function get(string name, var def = null)
    {
        var cookie;
        
        if fetch cookie, this->requestCookies[name] {
            return cookie;
        }
        
        return def;
    }

    public function set(string name, var value)
    {
        if !is_array(value) {
            let value = ["value": (string)value];
        }
        let this->responseCookies[name] = array_replace(this->defaults, value);
    }

    public function toHeaders() -> array
    {   
        var name, properties, headers = [];
        
        for name, properties in this->responseCookies {
            let headers[] = this->toHeader(name, properties);
        }

        return headers;
    }   
 
    protected function toHeader(string name, array properties) -> string
    {
        var result = "", timestamp = 0, domain, path, expires;
        
        let result = urlencode(name) . "=" . urlencode(properties["value"]);
        
        if fetch domain, properties["domain"] {
            let result .= "; domain=" . domain;
        }

        if fetch path, properties["path"] {
            let result .= "; path=" . path;
        }
        
        if fetch path, properties["path"] {
            let result .= "; path=" . path;
        }
        
        if fetch expires, properties["expires"] {
            if is_string(expires) {
                let timestamp = strtotime(expires);
            } else {
                let timestamp = (int)expires;
            }
            if (timestamp !== 0) {
                let result .= "; expires=" . gmdate("D, d-M-Y H:i:s e", timestamp);
            }
        }

        if isset properties["secure"] {
            let result .= "; secure";
        }
        
        
        if isset properties["httponly"] {
            let result .= "; HttpOnly";
        }
        

        return result;
    }

    public static function parseHeader(var header) -> array
    {
        var key, value, pieces, cookie, cookies = [];
        
        if is_array(header) {
            let header = isset header[0] ? header[0] : "";
        }

        if !is_string(header) {
            throw new \InvalidArgumentException("Cannot parse Cookie data. Header value must be a string.");
        }

        let header = rtrim(header, "\r\n");
        let pieces = preg_split("@\s*[;,]\s*@", header);
        
        for cookie in pieces {
            let cookie = explode("=", cookie, 2);

            if count(cookie) === 2 {
                let key = urldecode(cookie[0]);
                let value = urldecode(cookie[1]);

                if !isset cookies[key] {
                    let cookies[key] = value;
                }
            }
        }

        return cookies;
    }
    
}