<?PHP
session_start();
$fd = -1;
$data = NULL;
date_default_timezone_set("Europe/Paris");
if ($_SESSION['loggued_on_user'] == NULL OR $_SESSION['loggued_on_user'] === "")
{
	echo "ERROR".PHP_EOL;
	exit;
}
if ($_POST['msg'] != NULL AND $_POST['msg'] !== "")
{
	$msg['login'] = $_SESSION['loggued_on_user'];
	$msg['time'] = time();
	$msg['msg'] = $_POST['msg'];
	if (file_exists("../htdocs/private/chat"))
		$data = unserialize(file_get_contents("../htdocs/private/chat"));
	$data[] = $msg;
	file_put_contents("../htdocs/private/chat", serialize($data));
}
?>
<html>
	<head>
	<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
		<style>
		body
		{
			margin: 0;
		}
		textarea
		{
			overflow: auto;
			resize: none;
			outline: none;
			height: 45px;
			width: 95%;
		}
		#submit
		{
			position: absolute;
			top: 2;
			border: none;
		}
		</style>
	</head>
	<body>
		<form action="speak.php" method="post" id="msg">
			<textarea name=msg wrap=off></textarea>
			<input type=submit name=submit value="Submit" id=submit style="width:75px; height:40px;">
		</form>
	</body>
</html>
