<?PHP
session_start();
function is_exists($login, $data)
{
	foreach ($data as $user)
	{
		if ($user['login'] === $login)
			return TRUE;
	}
	return FALSE;
}
include ("product_table_handle.php");
$_SESSION['cre_error'] = 0;
if ($_POST['login'] === "" OR $_POST['passwd'] === "" OR $_POST['submit'] !== "OK")
{
	header("Location: index.php");
	exit;
}
else
{
	if (!file_exists("private"))
		mkdir("private", 0777);
	else if (file_exists("private/passwd"))
		$data = unserialize(file_get_contents("private/passwd"));
	if ($data !== NULL AND is_exists($_POST['login'], $data) === TRUE)
	{
		$_SESSION['cre_error'] = 1;
		header("Location: index.php");
		exit;
	}
	$data[] = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
	$serial = serialize($data);
	file_put_contents("private/passwd", $serial);
	if (file_exists("private/user"))
		$table_user = unserialize_get_content("private/user");
	$user['id'] = $_POST['login'];
	$user['right'] = "no-right";
	$table_user[$_POST['login']] = $user;
	serialize_put_content("private/user", $table_user);
	header("Location: index.php");
}
?>
