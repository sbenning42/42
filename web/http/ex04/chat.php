<?PHP
session_start();
date_default_timezone_set("Europe/Paris");
if (file_exists("../htdocs/private/chat") === FALSE)
	exit ;
if (($data = unserialize(file_get_contents("../htdocs/private/chat"))) === NULL)
	exit ;
foreach ($data as $full_msg)
{
	$time = date("[H:i]", $full_msg['time']);
	$user = $full_msg['login'];
	$msg = $full_msg['msg'];
	echo "$time <b>$user</b>: $msg<br>";
}
?>
