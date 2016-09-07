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
    
    }

    public function getUserInfo() -> string
    {
        
    }

    public function getAuthority() -> string
    {
    
    }


    public function getHost() -> string
    {
    
    }


    public function getPort() -> null|int
    {
    
    }


    public function getPath() -> string
    {
    
    }


    public function getQuery() -> string
    {
    
    }


    public function getFragment() -> string
    {
    
    }


    public function withScheme(string scheme)
    {
    
    }


    public function withUserInfo(string user, var password = null)
    {
    
    }


    public function withHost(string host)
    {
    
    }


    public function withPort(var port)
    {
    
    }


    public function withPath(string path)
    {
    
    }


    public function withQuery(string query)
    {
    
    }


    public function withFragment(string fragment)
    {
    
    }

    public function __toString() -> string
    {
    
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