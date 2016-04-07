<?PHP

if ($_SERVER['PHP_AUTH_PW'] != "jaimelespetitsponeys" OR $_SERVER['PHP_AUTH_USER'] != "zaz")
{
	header("WWW-Authenticate: Basic realm=''Espace membre''");
}

if ($_SERVER['PHP_AUTH_PW'] != "jaimelespetitsponeys" OR $_SERVER['PHP_AUTH_USER'] != "zaz")
{
	header('HTTP/1.0 401 Unauthorized');
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>".PHP_EOL;
	exit;
}
else
{
	$img = file_get_contents("../img/42.png");
	$code64 = base64_encode($img);
	echo "<html><body>Bonjour Zaz<br />".PHP_EOL."<img src='data:image/png;base64," . $code64 . "'>".PHP_EOL."</body></html>".PHP_EOL;
}
?>
