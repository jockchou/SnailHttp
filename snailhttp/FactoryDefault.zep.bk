namespace SnailHttp;

use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;

class FactoryDefault implements FactoryInterface
{
    const PHP_URL_SCHEME = 0;
    const PHP_URL_HOST = 1;
    const PHP_URL_PORT = 2;
    const PHP_URL_USER = 3;
    const PHP_URL_PASS = 4;
    const PHP_URL_PATH = 5;
    const PHP_URL_QUERY = 6;
    const PHP_URL_FRAGMENT = 7;
    
    static special = [
        "CONTENT_TYPE": 1,
        "CONTENT_LENGTH": 1,
        "PHP_AUTH_USER": 1,
        "PHP_AUTH_PW": 1,
        "PHP_AUTH_DIGEST": 1,
        "AUTH_TYPE": 1
    ];
    

    public function makeRequest(array globals) -> <ServerRequestInterface>
    {
        var method, uri, headers, cookies, body, files = [], request, mediaType;
        
        let method = globals["REQUEST_METHOD"];
        let uri = this->makeUri(globals);
        let headers = this->makeHeaders(globals);
        let cookies = Cookies::parseHeader(headers->get("Cookie", []));
        let body = this->makeBody();
        let request = new Request(method, uri, headers, cookies, globals, body, files);
        let mediaType = request->getMediaType();
        
        if method === "POST" && in_array(mediaType, ["application/x-www-form-urlencoded", "multipart/form-data"]) {
            // parsed body must be $_POST
            let request = request->withParsedBody(_POST);
        }

        return request;
    }


    public function makeUri(array globals) -> <UriInterface>
    {
        var pos, env, isSecure, scheme, username, password, host, port, matches= null, requestUri, queryString, fragment;
        
        let env = new Collection(globals);

        // Scheme
        let isSecure = env->get("HTTPS");
        let scheme = (empty isSecure || isSecure === "off") ? "http" : "https";

        // Authority: Username and password
        let username = env->get("PHP_AUTH_USER", "");
        let password = env->get("PHP_AUTH_PW", "");

        // Authority: Host
        if env->has("HTTP_HOST") {
            let host = env->get("HTTP_HOST");
        } else {
            let host = env->get("SERVER_NAME");
        }

        // Authority: Port
        let port = (int)env->get("SERVER_PORT", 80);
        if preg_match("/^(\[[a-fA-F0-9:.]+\])(:\d+)?\z/", host, matches) {
            let host = matches[1];

            if matches[2] {
                let port = (int)substr(matches[2], 1);
            }
        } else {
            let pos = strpos(host, ":");
            if pos !== false {
                let port = (int)substr(host, pos + 1);
                let host = strstr(host, ":", true);
            }
        }

        // parse_url() requires a full URL. As we don't extract the domain name or scheme,
        // we use a stand-in.
        let requestUri = parse_url("http://example.com" . env->get("REQUEST_URI"), self::PHP_URL_PATH);

        // Query string
        let queryString = env->get("QUERY_STRING", "");

        // Fragment
        let fragment = "";

        // Build Uri
        return new Uri(scheme, host, port, requestUri, queryString, fragment, username, password);
    }


    public function makeHeaders(array globals) -> <HeadersInterface>
    {
        var key, value, data = [];
        
        for key, value in globals {
            let key = strtoupper(key);
            if isset self::special[key] || strpos(key, "HTTP_") === 0 {
                if key !== "HTTP_CONTENT_LENGTH" {
                    let data[key] = value;
                }
            }
        }

        return new Headers(data);
    }


    public function makeBody() -> <StreamInterface>
    {
        var stream;
        
        let stream = fopen("php://temp", "w+");
        stream_copy_to_stream(fopen("php://input", "r"), stream);
        rewind(stream);

        return new Stream(stream);
    }
}