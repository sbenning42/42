<?PHP
    $name = $_GET[name];
    $value = $_GET[value];
    if ($_GET[action] == "set")
    {
        setcookie($name, $value, time() + 3600);
    }
    if ($_GET[action] == "get")
    {
        if ($_COOKIE[$name])
            echo $_COOKIE[$name]. "\n";
    }
    if ($_GET[action] == "del")
    {
		setcookie($name, $value, time() - 3600);
    }
?>
