<?PHP
function error()
{
	echo "ERROR".PHP_EOL;
	exit ;
}

function exists($login, $data)
{
	$i = 0;
	if ($data == NULL)
		return FALSE;
	foreach ($data as $user)
	{
		if ($user['login'] === $login)
			return $i;
		$i++;
	}
	return FALSE;
}

if ($_POST['login'] === "" OR $_POST['oldpwd'] === "" OR $_POST['newpwd'] === "" OR $_POST['submit'] !== "OK")
	error();
if (file_exists("../htdocs/private/passwd") === FALSE)
	error();
$data = unserialize(file_get_contents("../htdocs/private/passwd"));
if (($index = exists($_POST['login'], $data)) === FALSE)
	error();
if ($data[$index]['passwd'] != hash("whirlpool", $_POST['oldpwd']))
	error();
$hash = hash("whirlpool", $_POST['newpwd']);
$data[$index]['passwd'] = $hash;
$serial = serialize($data);
file_put_contents("../htdocs/private/passwd", $serial);
header("Location: index.html");
echo "OK".PHP_EOL;
?>
