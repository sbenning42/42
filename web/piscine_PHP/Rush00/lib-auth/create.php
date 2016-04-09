<?PHP
function is_exists($login, $data)
{
	foreach ($data as $user)
	{
		if ($user['login'] === $login)
			return FALSE;
	}
	return TRUE;
}

if ($_POST['login'] === "" OR $_POST['passwd'] === "" OR $_POST['submit'] !== "OK")
{
	echo "ERROR".PHP_EOL;
}
else
{
	if (file_exists("../htdocs/private/passwd"))
	{
		$data = unserialize(file_get_contents("../htdocs/private/passwd"));
	}
	if ($data !== NULL AND is_exists($_POST['login'], $data) === FALSE)
	{
		echo "ERROR".PHP_EOL;
		exit ;
	}
	$data[] = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
	$serial = serialize($data);
	if (file_exists("../htdocs") === FALSE)
		mkdir("../htdocs", 0777);
	if (file_exists("../htdocs/private") === FALSE)
		mkdir("private", 0777);
	file_put_contents("../htdocs/private/passwd", $serial);
	header("Location: index.html");
	echo "OK".PHP_EOL;
}
?>
