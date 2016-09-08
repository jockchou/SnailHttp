namespace SnailHttp;

use Psr\Http\Message\UriInterface;

class Uri implements UriInterface 
{
    static schemeValid = ["": true, "https": true, "http": true];
    
     /**
     * Uri scheme (without "://" suffix)
     *
     * @var string
     */
    protected scheme = "";

    /**
     * Uri user
     *
     * @var string
     */
    protected user = "";

    /**
     * Uri password
     *
     * @var string
     */
    protected password = "";

    /**
     * Uri host
     *
     * @var string
     */
    protected host = "";

    /**
     * Uri port number
     *
     * @var null|int
     */
    protected port;

    /**
     * Uri path
     *
     * @var string
     */
    protected path = "";

    /**
     * Uri query string (without "?" prefix)
     *
     * @var string
     */
    protected query = "";

    /**
     * Uri fragment string (without "#" prefix)
     *
     * @var string
     */
    protected fragment = "";
    
    
    /**
     * Create new Uri.
     *
     * @param string $scheme   Uri scheme.
     * @param string $host     Uri host.
     * @param int    $port     Uri port number.
     * @param string $path     Uri path.
     * @param string $query    Uri query string.
     * @param string $fragment Uri fragment.
     * @param string $user     Uri user.
     * @param string $password Uri password.
     */
    public function __construct(
        string scheme,
        string host,
        var port = null,
        string path = "/",
        string query = "",
        string fragment = "",
        string user = "",
        string password = ""
    ){
        let this->scheme = this->filterScheme(scheme);
        let this->host = host;
        let this->port = this->filterPort(port);
        let this->path = empty path ? "/" : this->filterPath(path);
        let this->query = this->filterQuery(query);
        let this->fragment = this->filterQuery(fragment);
        let this->user = user;
        let this->password = password;
    }

    
    public function getScheme() -> string
    {
        return this->scheme;
    }

    public function getUserInfo() -> string
    {
        return this->user . (this->password ? ":" . this->password : "");
    }

    public function getAuthority() -> string
    {
        var userInfo, host, port;
        
        let userInfo = this->getUserInfo();
        let host = this->getHost();
        let port = this->getPort();
        
        return (userInfo ? userInfo . "@" : "") . host . (port !== null ? ":" . port : "");
    }

    
    public function getHost() -> string
    {
        return this->host;
    }

    
    public function getPort() -> null|int
    {
        return this->port && !this->hasStandardPort() ? this->port : null;
    }

    protected function hasStandardPort()
    {
        return (this->scheme === "http" && this->port === 80) || (this->scheme === "https" && this->port === 443);
    }
    

    public function getPath() -> string
    {
        return this->path;
    }


    public function getQuery() -> string
    {
        return this->query;
    }


    public function getFragment() -> string
    {
        return this->fragment;
    }


    public function withScheme(string scheme)
    {
        var cloneObj;
        
        let scheme = this->filterScheme(scheme);
        let cloneObj = clone this;
        let cloneObj->scheme = scheme;
        
        return cloneObj;
    }


    public function withUserInfo(string user, var password = null)
    {
        var cloneObj;
        
        let cloneObj = clone this;
        let cloneObj->user = user;
        let cloneObj->password = password ? password : "";
        
        return cloneObj;
    }


    public function withHost(string host)
    {
        var cloneObj;
    
        let cloneObj = clone this;
        let cloneObj->host = host;
        
        return cloneObj;
    }


    public function withPort(var port)
    {   
        var cloneObj;
        
        let port = this->filterPort(port);
        let cloneObj = clone this;
        let cloneObj->port = port;
        
        return cloneObj;
    }


    public function withPath(string path)
    {   
        var cloneObj;
        
        if !is_string(path) {
            throw new \InvalidArgumentException("Uri path must be a string");
        }
        
        let cloneObj = clone this;
        let cloneObj->path = this->filterPath(path);
        
        return cloneObj;
    }


    public function withQuery(string query)
    {
        var cloneObj;
        
        if !is_string(query) && !method_exists(query, "__toString") {
            throw new \InvalidArgumentException("Uri query must be a string");
        }
        
        let query = ltrim((string)query, "?");
        let cloneObj = clone this;
        let cloneObj->query = this->filterQuery(query);
        
        return cloneObj;
    }

    public function withFragment(string fragment)
    {
        var cloneObj;
        
        if !is_string(fragment) && !method_exists(fragment, "__toString") {
            throw new \InvalidArgumentException("Uri fragment must be a string");
        }
        
        let fragment = ltrim((string)fragment, "#");
        let cloneObj = clone this;
        let cloneObj->fragment = this->filterQuery(fragment);
        
        return cloneObj;
    }

    public function __toString() -> string
    {
        var scheme, authority, path, query, fragment;
        
        let scheme = this->getScheme();
        let authority = this->getAuthority();
        let path = this->getPath();
        let query = $this->getQuery();
        let fragment = $this->getFragment();
        let path = "/" . ltrim(path, "/");
        
        return (scheme ? scheme . ":" : "")
        . (authority ? "//" . authority : "")
        . path
        . (query ? "?" . query : "")
        . (fragment ? "#" . fragment : "");
    }
    
    
   
    protected function filterScheme(string scheme) -> string
    {
        if !is_string(scheme) && !method_exists(scheme, "__toString") {
            throw new \InvalidArgumentException("Uri scheme must be a string");
        }

        let scheme = str_replace("://", "", strtolower(scheme));
       
        if !isset self::schemeValid[scheme] {
            throw new \InvalidArgumentException("Uri scheme must be one of: \"\", \"https\", \"http\"");
        }

        return scheme;
    }
    
    
    protected function filterPort(var port)
    {
        if is_null(port) || (is_integer(port) && (port >= 1 && port <= 65535)) {
            return port;
        }

        throw new \InvalidArgumentException("Uri port must be null or an integer between 1 and 65535 (inclusive)");
    }
    
    protected function filterPath(string path) -> string
    {
        return preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~:@&=\+\$,\/;%]+|%(?![A-Fa-f0-9]{2}))/",
            function(array match = null) {
                return rawurlencode(match[0]);
            },
            path
        );
    }
    
    protected function filterQuery(string query) -> string
    {
        return preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~!\$&\'\(\)\*\+,;=%:@\/\?]+|%(?![A-Fa-f0-9]{2}))/",
            function (array match = null) {
                return rawurlencode(match[0]);
            },
            query
        );
    }
}