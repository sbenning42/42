<?php
	include ("auth.php");
	session_start();

	$_SESSION['loggued_on_user'] = "";
	if ($_POST['login'] == NULL OR $_POST['passwd'] == NULL OR $_POST['login'] === "" OR $_POST['passwd'] === "")
		echo "ERROR" . PHP_EOL;
	else if (auth($_POST['login'], $_POST['passwd']) === FALSE)
		echo "ERROR" . PHP_EOL;
	else
	{
		$_SESSION['loggued_on_user'] = $_POST['login'];
		echo '<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>';
		echo '<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>';
	}
?>
