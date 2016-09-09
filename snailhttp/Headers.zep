namespace SnailHttp;

class Headers extends Collection implements HeadersInterface
{
   
    static special = [
        "CONTENT_TYPE": 1,
        "CONTENT_LENGTH": 1,
        "PHP_AUTH_USER": 1,
        "PHP_AUTH_PW": 1,
        "PHP_AUTH_DIGEST": 1,
        "AUTH_TYPE": 1
    ];

    
    public static function createFromGlobals(array globals)
    {
        var key, value, env, data = [];
        
        let env = new Collection(globals);
        
        for key, value in env {
            let key = strtoupper(key);
            if isset self::special[key] || strpos(key, "HTTP_") === 0 {
                if key !== "HTTP_CONTENT_LENGTH" {
                    let data[key] = value;
                }
            }
        }

        return new static(data);
    }

    
    public function all()
    {
        var props, out = [], all;
        let all = parent::all();
        
        for _, props in all {
            let out[props["originalKey"]] = props["value"];
        }
        
        return out;
    }


    public function set(string key, var value)
    {
        if !is_array(value) {
            let value = [value];
        }
        
        parent::set(this->normalizeKey(key), [
            "value": value,
            "originalKey": key
        ]);
    }


    public function get(string key, var def = null)
    {
        if this->has(key) {
            return parent::get(this->normalizeKey(key))["value"];
        }

        return def;
    }


    public function getOriginalKey(string key, var def = null)
    {
        if this->has(key) {
            return parent::get($this->normalizeKey(key))["originalKey"];
        }

        return def;
    }


    public function add(string key, var value)
    {
        var oldValues, newValues;
        
        let oldValues = this->get(key, []);
        let newValues = is_array(value) ? value : [value];
        
        this->set(key, array_merge(oldValues, array_values(newValues)));
    }


    public function has(string key)
    {
        return parent::has(this->normalizeKey(key));
    }


    public function remove(string key)
    {
        parent::remove(this->normalizeKey(key));
    }

    public function normalizeKey(string key)
    {
        let key  = strtolower(key);
        let key = strtr(key, "_", "-");
        if strpos(key, "http-") === 0 {
            let key = substr(key, 5);
        }

        return key;
    }
}