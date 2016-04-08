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
	if (file_exists("private/passwd"))
	{
		$data = unserialize(file_get_contents("private/passwd"));
	}
	if ($data !== NULL AND is_exists($_POST['login'], $data) === FALSE)
	{
		echo "ERROR".PHP_EOL;
		exit ;
	}
	$data[] = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
	$serial = serialize($data);
	if (file_exists("private") === FALSE)
		mkdir("private", 0777);
	file_put_contents("private/passwd", $serial);
	echo "OK".PHP_EOL;
}
?>
