<?PHP
function auth($login, $passwd)
{
	if (file_exists("private/passwd") === FALSE)
		return FALSE;
	if (($data = unserialize(file_get_contents("private/passwd"))) == NULL)
		return FALSE;
	$hash = hash("whirlpool", $passwd);
	foreach ($data as $user)
	{
		if ($user['login'] === $login AND $user['passwd'] === $hash)
			return TRUE;
	}
	return FALSE;
}
?>
