<?PHP
switch ($_GET['action'])
{
	case "set":
	{
		setcookie($_GET['name'], $_GET['value'], time() + 3600, "", "", "", TRUE);
		break ;
	}
	case "get":
	{
		if ($_COOKIE[$_GET['name']])
		{
			echo $_COOKIE[$_GET['name']].PHP_EOL;
		}
		break ;
	}
	case "del":
	{
		setcookie($_GET['name'], "", time() - 3600);
		break ;
	}
}
?>
